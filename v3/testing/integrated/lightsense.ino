#ifdef LIGHTSENSE_INCLUDE

void lightsense_acquire ()
{
// #ifdef SERIAL_DEBUG
//     SerialUSB.print("\n");
//     SerialUSB.println("Acquiring LightSense Data");
// #endif

//****** defined in a new function
// #ifdef HMC5883L_include
//     sensors_event_t event;
//     HMC5883_Magnetometer.getEvent(&event);

//     HMC5883L[1] = (1 << 7) | (LENGTH_FORMAT8 * 3);

//     format8(event.magnetic.x);
//     HMC5883L[2] = formatted_data_buffer[0];
//     HMC5883L[3] = formatted_data_buffer[1];

// #ifdef SERIAL_DEBUG
//     for (j = 0; j < LENGTH_FORMAT8; j++)
//         SerialUSB.print(formatted_data_buffer[j],HEX);
// #endif

//     format8(event.magnetic.y);
//     HMC5883L[4] = formatted_data_buffer[0];
//     HMC5883L[5] = formatted_data_buffer[1];

// #ifdef SERIAL_DEBUG
//     for (j = 0; j < LENGTH_FORMAT8; j++)
//         SerialUSB.print(formatted_data_buffer[j],HEX);
// #endif

//     format8(event.magnetic.z);
//     HMC5883L[6] = formatted_data_buffer[0];
//     HMC5883L[7] = formatted_data_buffer[1];

// #ifdef SERIAL_DEBUG
//     for (j = 0; j < LENGTH_FORMAT8; j++)
//         SerialUSB.print(formatted_data_buffer[j],HEX);
// #endif

// #ifdef SERIAL_DEBUG
//     SerialUSB.print("HMC5883L X:");
//     SerialUSB.print(event.magnetic.x);
//     SerialUSB.print(", Y:");
//     SerialUSB.print(event.magnetic.y);
//     SerialUSB.print(", Z:");
//     SerialUSB.println(event.magnetic.z);
// #endif
// #endif
//****** defined in a new function


#ifdef HIH6130_include
    HIH_fetch_humidity_temperature();

    HIH6130[1] = (1 << 7) | (LENGTH_FORMAT6 * 2);

    format6(Temp_float[0]);
    HIH6130[2] = formatted_data_buffer[0];
    HIH6130[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

    format6(Temp_float[1]);
    HIH6130[4] = formatted_data_buffer[0];
    HIH6130[5] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif

// #ifdef SERIAL_DEBUG
//     SerialUSB.print("HIH6130 RH%:");
//     SerialUSB.print(Temp_float[1]);
//     SerialUSB.print("  Temperature:");
//     SerialUSB.println(Temp_float[0]);
// #endif
#endif


#ifdef APDS9006020_include
    mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_2.readADC());

    APDS9006020[1] = (1 << 7) | LENGTH_FORMAT1;
    APDS9006020[2] = formatted_data_buffer[0];
    APDS9006020[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("APDS9006020: ");
    // SerialUSB.println(mcp3428_2.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef TSL260RD_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    TSL260RD[1] = (1 << 7) | LENGTH_FORMAT1;
    TSL260RD[2] = formatted_data_buffer[0];
    TSL260RD[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("TSL260RD: ");
    // SerialUSB.println(mcp3428_1.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef TSL250RD_2_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    TSL250RD_2[1] = (1 << 7) | LENGTH_FORMAT1;
    TSL250RD_2[2] = formatted_data_buffer[0];
    TSL250RD_2[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("TSL250RD_2: ");
    // SerialUSB.println(mcp3428_1.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


#ifdef MLX75305_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    MLX75305[1] = (1 << 7) | LENGTH_FORMAT1;
    MLX75305[2] = formatted_data_buffer[0];
    MLX75305[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("MLX75305: ");
    // SerialUSB.println(mcp3428_1.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

#ifdef ML8511_include
    mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
    format1(mcp3428_1.readADC());

    ML8511[1] = (1 << 7) | LENGTH_FORMAT1;
    ML8511[2] = formatted_data_buffer[0];
    ML8511[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("ML8511: ");
    // SerialUSB.println(mcp3428_1.readADC());

    for (i = 0; i < LENGTH_FORMAT1; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif


#ifdef TMP421_include
    Temp_float[0] = TMP421_Sensor.GetTemperature();
    format6(Temp_float[0]);

    TMP421[1] = (1 << 7) | LENGTH_FORMAT6;
    TMP421[2] = formatted_data_buffer[0];
    TMP421[3] = formatted_data_buffer[1];

#ifdef SERIAL_DEBUG
    // SerialUSB.print("TMP421: ");
    // SerialUSB.println(Temp_float[0]);

    for (i = 0; i < LENGTH_FORMAT6; i++)
        SerialUSB.print(formatted_data_buffer[i],HEX);
#endif
#endif

}

void lightsense_avg()
{
#ifdef HMC5883L_include
    sensors_event_t event;
    HMC5883_Magnetometer.getEvent(&event);

    if (repeat == 1)
    {
        prev_HMC[0] = event.magnetic.x;
        prev_HMC[1] = event.magnetic.y;
        prev_HMC[2] = event.magnetic.z;
    }
    else
    {
        curr_HMC[0] = (event.magnetic.x + prev_HMC[0])/2;
        curr_HMC[1] = (event.magnetic.y + prev_HMC[1])/2;
        curr_HMC[2] = (event.magnetic.z + prev_HMC[2])/2;

        prev_HMC[0] = curr_HMC[0];
        prev_HMC[1] = curr_HMC[1];
        prev_HMC[2] = curr_HMC[2];

        HMC5883L[1] = (1 << 7) | (LENGTH_FORMAT8 * 3);

        format8(curr_HMC[0]);
        HMC5883L[2] = formatted_data_buffer[0];
        HMC5883L[3] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (j = 0; j < LENGTH_FORMAT8; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
    #endif

        format8(curr_HMC[1]);
        HMC5883L[4] = formatted_data_buffer[0];
        HMC5883L[5] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (j = 0; j < LENGTH_FORMAT8; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
    #endif

        format8(curr_HMC[2]);
        HMC5883L[6] = formatted_data_buffer[0];
        HMC5883L[7] = formatted_data_buffer[1];

    #ifdef SERIAL_DEBUG
        for (j = 0; j < LENGTH_FORMAT8; j++)
            SerialUSB.print(formatted_data_buffer[j],HEX);
    #endif
    }

#ifdef SERIAL_DEBUG
    SerialUSB.print("HMC5883L X:");
    SerialUSB.print(event.magnetic.x);
    SerialUSB.print(", Y:");
    SerialUSB.print(event.magnetic.y);
    SerialUSB.print(", Z:");
    SerialUSB.println(event.magnetic.z);
#endif
#endif
}
#endif