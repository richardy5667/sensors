
/** Constants *************************************************************************/
#define I2C_SLAVE_ADDRESS 0x03

#define DELAY_MS 15000

#define LENGTH_DATA  170
#define LENGTH_WHOLE  LENGTH_DATA + 5

#define CR_ENABLE 0
#define BUFFER_SIZE_CHEMSENSE 150
#define PARAM_SIZE_CHEMSENSE 15
#define DEBUG_chemsense 0

#define LENGTH_FORMAT1  2
#define LENGTH_FORMAT2  2
#define LENGTH_FORMAT3  6
#define LENGTH_FORMAT4  3
#define LENGTH_FORMAT5  3
#define LENGTH_FORMAT6  2
#define LENGTH_FORMAT7  4
#define LENGTH_FORMAT8  2
#define MAX_FMT_SIZE 6


#define START_BYTE 0xAA
#define END_BYTE 0x55
#define HEADER_RESERVED 0x00 // Upper nibble
#define HEADER_VERSION 0x00 // Lower nibble
#define SENSOR_HEALTH_SIZE 0x04

#define ID_MAC  0x00
#define ID_TMP112  0x01
#define ID_HTU21D  0x02
#define ID_HIH4030  0x03
#define ID_BMP180  0x04
#define ID_PR103J2  0x05
#define ID_TSL250RD_1  0x06
#define ID_MMA8452Q  0x07
#define ID_SPV1840LR5HB  0x08
#define ID_TSYS01  0x09
#define ID_HMC5883L  0x0A
#define ID_HIH6130  0x0B
#define ID_APDS9006020  0x0C
#define ID_TSL260RD  0x0D
#define ID_TSL250RD_2  0x0E
#define ID_MLX75305  0x0F
#define ID_ML8511  0x10
#define ID_D6T  0x11
#define ID_MLX90614  0x12
#define ID_TMP421  0x13
#define ID_TOTAL_REDUCING_GASES  0x15
#define ID_ETHANOL  0x16
#define ID_NITROGEN_DIOXIDE  0x17
#define ID_OZONE  0x18
#define ID_HYDROGEN_SULPHIDE  0x19
#define ID_TOTAL_OXIDIZING_GASES  0x1A
#define ID_CARBON_MONOXIDE  0x1B
#define ID_SULFUR_DIOXIDE  0x1C
#define ID_SHT25 0x1D
#define ID_LPS25H 0x1E
#define ID_Si1145 0x1F
#define ID_CHEMSENSE_MAC  0x20
#define ID_HEALTH  0xFE



#define EEPROM_ADDRESS      0x50    //Address of 24LC256 EEPROM
#define PIN_CHEMSENSE_POW   47
#define PIN_DS2401          48
#define PIN_CHEMSENSE_RST   49
#define PIN_CHEMSENSE_HBT   50

#define PIN_HBT             8
#define PIN_GP2Y_OUT        A7
#define PIN_GP2Y_IN         A4
#define PIN_SPV_AMP         A5
#define PIN_SVP_SPL         A6
#define PIN_RAW_MIC         A9
#define PIN_HIH4030         A10


/**************************************************************************************/
// #define MAC_ID_include 0x01
// #define AIRSENSE_INCLUDE 0x01
#define LIGHTSENSE_INCLUDE 0x01
// #define CHEMSENSE_INCLUDE 0x01




// AirsenseBoard
#ifdef AIRSENSE_INCLUDE
    #define TMP112_include 0x01
    #define HTU21D_include 0x01
    #define BMP180_include 0x01
    #define PR103J2_include 0x01
    #define TSL250RD_1_include 0x01
    #define MMA8452Q_include 0x01
    #define SPV1840LR5HB_include 0x01
    #define TSYS01_include 0x01
    #define HIH4030_include 0x01
#endif

// Lightsense board
#ifdef LIGHTSENSE_INCLUDE
    #define HMC5883L_include 0x01
    #define HIH6130_include 0x01
    #define APDS9006020_include 0x01
    #define TSL260RD_include 0x01
    #define TSL250RD_2_include 0x01
    #define MLX75305_include 0x01
    #define ML8511_include 0x01
    #define TMP421_include 0x01
 // #define MLX90614_include 0x01
 // #define D6T_include 0x01
#endif

// Chemsense board
#ifdef CHEMSENSE_INCLUDE
    #define total_reducing_gases_include 0x01
    #define ethanol_include 0x01
    #define nitrogen_dioxide_include 0x01
    #define ozone_include 0x01
    #define hydrogen_sulphide_include 0x01
    #define total_oxidizing_gases_include 0x01
    #define carbon_monoxide_include 0x01
    #define sulfur_dioxide_include 0x01
    #define SHT25_include 0x01
    #define LPS25H_include 0x01
    #define Si1145_include 0x01
    #define chemsense_MAC_ID_include 0x01
#endif

// #define system_health_include 0x01
// #define RANDOMIZE_VALID 0x01
#define SERIAL_DEBUG 0x01
// #define PRINT_BUFFER 0x01

// #define USBSERIAL_INTERFACE 0x01
// #define I2C_INTERFACE 0x01
// #define I2C_PACKET_SIZE 163
// #define I2C_INTERFACE_CONST_SIZE 0x01
