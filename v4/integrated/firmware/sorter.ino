
byte sensorReading[1024];
int readingLength = 0;

void SortReading(byte *packet, int dataLength)
{
	PacketInit();
	BusPacketInit();
	byte *subpacket = packet + 4;  // put subpacket value as address of last packet byte
	while (subpacket < &packet[dataLength + 3])
	{
		byte type = subpacket[0];
		// byte ack = subpacket[1] & 0x80;
		byte paramLength = subpacket[1] & 0x7F;
		byte id = subpacket[2];

		byte Asubpacket[paramLength + 1];
		for (int i = 0; i < paramLength + 1; i++)
			Asubpacket[i] = subpacket[i + 1];

		for (int i = 0; i < numType; i++)
		{
			const FunctionType *ft = functype + i;
			if (ft->funcid == type)
			{
				ft->func(Asubpacket, id);
				break;
			}
		}
		subpacket += paramLength + 2;
	}
	int SensorReadingLength = ReturnPacketLength();
	int BusReadingLength = BusReturnPacketLength();
	if (SensorReadingLength > 4)
		PacketSender(0x01);
	if (BusReadingLength > 4)
		BusPacketSender(0x01);

}

void SensorInit()
{
	// Enable sensors
	pinMode(PIN_WIRE_SDA, INPUT);
	pinMode(PIN_WIRE_SCL, INPUT);
	if (digitalRead(PIN_WIRE_SDA) & digitalRead(PIN_WIRE_SCL))
	{
		Wire.begin();
		delay(100);
		ScanEnable();
	}
	else
	{
		for (int i=0; i<numSensor; i++)
		{
			bool isI2C=false;
			const Sensor *s = sensor + i;
			for (int j=0; j<I2Cnum; j++)
			{
				if (s->sensorid==(I2Cmap[j].sensorid))
				{
					isI2C=true;
					break;
				}
			}
			if (isI2C)
			{
				s->disableFunc();
			}
			else
			{
				s->enableFunc();
				s->initFunc();
			}
		}
	}
}

void ScanEnable()
{
	byte alivearray[I2Cnum];
	int numberalive=0;
	bool skipMCP342X=false;
	I2Cscan(&numberalive, alivearray);
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		bool isI2C=false;
		bool aliveI2C=false;
		for (int j=0; j<I2Cnum; j++)
		{
			if (s->sensorid==(I2Cmap[j].sensorid))
			{
				isI2C=true;
				break;
			}
			else
			{
				isI2C=false;
			}
		}
		if (isI2C)
		{
			for (int k=0; k<numberalive; k++)
			{
				if (s->sensorid==alivearray[k])
					{
						aliveI2C=true;
						break;
					}
			}
			if (!aliveI2C)
			{
				//if (s->sensorid==0x0D)
			//	{
				//	s->disableFunc();
				//	(s+1)->disableFunc();
				//	(s+2)->disableFunc();
				//	(s+3)->disableFunc();
				//	skipMCP342X=true;
				//}
				//else
				//{
					s->disableFunc();
				//}
			}
			else
			{
				s->enableFunc();
				s->initFunc();
			}
		}
		else
		{
		//	if(!skipMCP342X)
		//	{
				s->enableFunc();
				s->initFunc();
		//	}
		}
	}
}

void SensorInit(byte *data, byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->initFunc();
			break;
		}
	}
}

void SensorConfig(byte *data, byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->configFunc();
			break;
		}
	}
}

void SensorEnable(byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->enableFunc();
			break;
		}
	}
}

void SensorEnable(byte *data, byte id)
{
	SensorEnable(id);
}

void SensorDisable(byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->disableFunc();
			break;
		}
	}
}

void SensorDisable(byte *data, byte id)
{
	SensorDisable(id);
}

void SensorRead(byte *data, byte id)
{
	bool enable = GetEnable(id);

	if (!enable)
	{
		sensorReading[0] = id;
		sensorReading[1] = 0xAB;
		readingLength = 2;
		id = 0x12;
		Packetization(id, sensorReading, readingLength);
		readingLength = 0;
		return;
	}

	int paramLength = data[0] & 0x7F;
	int repeat = 0;
	int interval = 0;
	if (paramLength == 2)
		repeat = data[1];
	else if (paramLength == 3)
	{
		repeat = data[1];
		interval = 1000 / data[2];
	}

	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			if (id == 0x2A)
				repeat = 3;

			if (paramLength > 1 || id == 0x2A)
			{
				for (int i = 0; i < repeat; i++)
				{
					s->readFunc(sensorReading, &readingLength);
					Packetization(id, sensorReading, readingLength);
					delay(interval);
				}
				break;
			}

			s->readFunc(sensorReading, &readingLength);
			Packetization(id, sensorReading, readingLength);
			break;
		}
	}
	readingLength = 0;
}


void SensorWrite(byte *data, byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->writeFunc(data);
			break;
		}
	}
}





void BusInit(byte *data, byte id)
{
	for (int i = 0; i < numBus; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->initFunc(data);
			break;
		}
	}
}

void BusConfig(byte *data, byte id)
{
	for (int i = 0; i < numBus; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->configFunc(data);
			break;
		}
	}
}
void BusEnable(byte *data, byte id)
{
	for (int i = 0; i < numBus; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->enableFunc();
			break;
		}
	}
}
void BusDisable(byte *data, byte id)
{
	for (int i = 0; i < numBus; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->disableFunc();
			break;
		}
	}
}
void BusRead(byte *data, byte id)
{
	byte subLength = data[0] & 0x7F;
	// byte busType = data[1];  // receives as "id"
	byte busAddressId = data[2];

	byte params[subLength];
	for (int i = 0; i < subLength - 2; i++)
		params[i] = data[i + 3];

	if (id < 0x02)
	{
		for (int i = 0; i < numParamBus; i++)
		{
			const paramBus *pb = parambus + i;
			if (pb->bustype == id)
			{
				if (pb->busid == busAddressId)
				{
					pb->readFunc(params, sensorReading, &readingLength);
					BusPacketization(id, busAddressId, sensorReading, readingLength);
				}
			}
		}
	}
	else if (id >= 0x02)
	{
		for (int i = 0; i < numBus; i++)
		{
			const Bus *b = bus + i;
			if (b->bustype == id)
			{
				if (b->busid == busAddressId)
				{
					b->readFunc(sensorReading, &readingLength);
					BusPacketization(id, busAddressId, sensorReading, readingLength);
					break;
				}
			}
		}
	}
	readingLength = 0;
}
void BusWrite(byte *data, byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->writeFunc(data);
			break;
		}
	}
}
