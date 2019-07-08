struct I2Caddress
{
  const byte slaveaddress;
  const byte sensorid;
};

const I2Caddress I2Cmap[]={
  {0x48,0x01},
  {0x40,0x02},
  {0x77,0x04},
  {0x1C,0x07},
  {0x76,0x09},
  {0x1E,0x0A},
  {0x27,0x0B},
  {0x69,0x0C},
  {0x68,0x0D},
  {0x68,0x0E},
  {0x68,0x0F},
  {0x68,0x10},
  {0x4C,0x13}
};

const int I2Cnum = sizeof(I2Cmap)/sizeof(I2Cmap[0]);
