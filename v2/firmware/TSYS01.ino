#ifdef TSYS01_include

float retVal = 0.0;

void TSYS01_CONFIG()
{
    TSYS01INIT();
    TSYS_Get_Coeff();
}

void TSYS01_read()
{
    TSYS01GetTemp();
}

void TSYS01INIT()
{
    Wire1.beginTransmission(TSYS01Address);
    Wire1.write(0x1E);
    Wire1.endTransmission();
    delay(50);
}


void TSYS_Get_Coeff()  //gathers calibration coefficients to array
{
    for (uint8_t n = 0; n < 5; n++)
    {
        Wire1.beginTransmission(TSYS01Address);
        Wire1.write(0xA2 + (n * 2));
        Wire1.endTransmission();
        Wire1.requestFrom(TSYS01Address, 2);
        uint8_t Ai = Wire1.read();
        uint8_t Bi = Wire1.read();
        uint16_t x = (uint16_t)Ai << 8;
        x += Bi;
        TSYS_coefficents[n] = x;
    }
}


float TSYS_ScaleTemp_C(uint16_t rawAdc)
{

    retVal =
    (-2) * (float)TSYS_coefficents[TSYS_K4] * (float)pow(10, -21) * pow(rawAdc, 4) +
    4 * (float)TSYS_coefficents[TSYS_K3] * (float)pow(10, -16) * pow(rawAdc, 3) +
    (-2) * (float)TSYS_coefficents[TSYS_K2] * (float)pow(10, -11) * pow(rawAdc, 2) +
    1 * (float)TSYS_coefficents[TSYS_K1] * (float)pow(10, -6) * rawAdc +
    (-1.5) * (float)TSYS_coefficents[TSYS_K0] * (float)pow(10, -2);

    return retVal;

}

void TSYS01GetTemp()
{
    Wire1.beginTransmission(TSYS01Address);
    Wire1.write(TSYS01StartReg); //Start measurement process
    Wire1.endTransmission();
    delay(10);

    Wire1.beginTransmission(TSYS01Address);
    Wire1.write(TSYS01TempReg); //Request measurement
    Wire1.endTransmission();

    Wire1.requestFrom(TSYS01Address,3); //read in 24 bit output

    bool able = true;
    if (Wire1.available() <= 0)
        able = false;

    Temp_byte[0] = Wire1.read();
    Temp_byte[1] = Wire1.read();
    Temp_byte[2] = Wire1.read(); //not used but necessary if 24bit conversion method is found (shifts below return 24bit output / 256 per TSYS01 datasheet conversion equations

    if (able == false)
    {
        for (int i = 0; i < 3; i++)
            Temp_byte[i] = 255;
    }

    Temp_float[0] = TSYS_ScaleTemp_C((((unsigned long)Temp_byte[0] << 8) | ((unsigned long)Temp_byte[1]))); //convert and cast to Temp with scaling equation
}

#endif