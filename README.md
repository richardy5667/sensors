<!--
waggle_topic=/sensors/introduction,Waggle Sensor Ensemble
-->

# Common Waggle Sensors:

## Metsense, HW Ver: 3.1

<img src="./sensors/images/metsense.jpg" width=350 />

* Size: 55x145x15mm
* Interface: USB-Serial, I2C
* CPU: Atmel SAM3X8E ARM Cortex-M3 CPU

### Parts list
| Part Name | Measurement | Range | Accuracy | Datasheet |
| ------------- |------------- | ------------- |------------- |------------- |
| TMP112 | Temperature |-40 to +125 °C |	±1 °C | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/tmp112.pdf)|
|HTU21D | Temperature <br> Relative Humidity | -40 to +125 °C <br> 0 to 100 %RH | ±1 °C <br> ±2 %RH | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/htu21d.pdf)|
| HIH4030 | Humidity | 0 to 100 %RH | ±3.5 %RH | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/hih4030.pdf)|
| BMP180 | Temperature <br> Atmospheric Pressure | -40 to +85 °C <br> 300 to 1100 hPa | ±1.0°C <br> ±0.02 hPa | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/bmp180.pdf)|
| PR103J2 | Temperature | -55 to +80 °C | ±0.05 °C | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/pr103j2.pdf)|
| TSL250RD | Light Intensity, λp = 640nm | 0 to 124 μW/cm2 | 16 μW/cm2 | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/tsl250rd.pdf) |
| MMA8452Q | 3 axis acceleration | ±8 g | ±20 mg | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/mma8452q.pdf) |
| SPV1840LR5H-B | Instantaneous Sound Sample | Acoustic Overload Point <br> to 121 dB SPL | -38 dBV/Pa | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/spv1840lr5h-b.pdf) |
| TSYS01 | Temperature | -40°C to +125 °C | 0.5 °C | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/tsys01.pdf) |

## Lightsense, HW Ver: 3.1

<img src="./sensors/images/lightsense.jpg" width=500 />

* Size: 40x57x15mm
* Interface: I2C
* CPU: None

### Parts list
| Part Name | Measurement | Range | Accuracy | Datasheet |
| ------------- |------------- | ------------- |------------- |------------- |
| HMC5883L | 3 axis magnetic field intensity | ±8 gauss | ±0.002 gauss | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/hmc5883l.pdf) |
| HIH6130 | Temperature <br> Relative Humidity | -25 to +85 °C <br> 0 to 100 %RH | ±1.0 °C <br> ±0.05 %RH | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/hih6130.pdf) |
| APDS-9006-020 | Light Intensity, λp = 500 nm | 0 to 1000 LUX | ±0.68 % | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/apd9006020.pdf) |
| TSL260RD | Light Intensity, λp = 940 nm | 0 to 132 μW/cm2 | ±15 μW/cm2 | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/tsl260rd.pdf) |
| TSL250RD | Light Intensity, λp = 640 nm | 0 to 124 μW/cm2 | ±16 μW/cm2 | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/tsl250rd.pdf) |
| MLX75305 | Light Intensity, λp = 700 nm | 0 to 160 μW/cm2 | ±15 μW/cm2 | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/mlx75305c.pdf) |
| ML8511 | Light Intensity, λp = 365 nm | 0 to 15 mW/cm2 | ±1 % | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/ml8511.pdf) |
| TMP421 | Temperature | –55 to +127 °C | ±1.5 °C | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/tmp421.pdf) |
| MLX90614 | Temperature | -40 to +85 C | ±0.5 °C | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/mlx90614.pdf) |

## Chemsense HW Ver: Passamaquoddy Bay

<img src="./sensors/images/chemsense.jpg" width=360 />

* Size: 65x130x15mm
* Interface: USB-Serial, UART
* CPU: Intel Microprocessor

### Parts list
| Part Name | Measurement | Range | Accuracy | Datasheet |
| ------------- |------------- | ------------- |------------- |------------- |
| SHT25 | Temperature <br> Relative Humidity | -40 to +125 °C <br> 0 to 100 %RH | ±0.04 °C <br> ±0.04 %RH | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/sht25.pdf) |
| LPS25H | Temperature <br> Atmospheric Pressure | -30 to +105°C <br> 260 to 1260  hPa | ±2 °C <br> ±0.1 hPa | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/lps25h.pdf) |
| Si1145 | Light Intensity (UV) <br> Light Intensity, λp = 760 nm <br> Light Intensity, λp = 560 nm |   |   | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/si1145uv.pdf) |
| Sulfur Dioxide | SO2 Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/so2.pdf) |
| Hydrogen Sulfide | H2S Concentration | 0 to 50 ppm | ±3% of reading | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/h2s.pdf) |
| Ozone | O3 Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/o3.pdf) |
| Nitrous Oxide | NO2 Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/no2.pdf) |
| Carbon Monoxide | CO Concentration | 0 to 1,000 ppm | ±2% of reading | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/co.pdf) |
| BMI160 | 3 axis acceleration <br> 3 axis orientation | ±16g <br> 2000°/s | 300μg/√Hz <br> 0.07°/s rms| [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/bmi160.pdf) |
| Total Reducing Gases | Reducing Gases Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/) |
| Total Oxidizing Gases | Oxidizing Gases Concentration | 0 to 20 ppm | ±3% of reading | [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/) |

## Alphasense OPC-N2 (Regular-range (16 bins in 0-10 μm) and High-range/Pollen (16 bins in 0-40 μm)

<img src="./sensors/images/opcn2.jpg" width=300 />

* Size: 65x75x60mm
* Interface: USB Storage, SPI

### Parts list

| Part Name | Measurement | Range | Accuracy | Datasheet |
| ------------- |------------- | ------------- |------------- |------------- |
| OPC-N2 | PM1 in μg/m3 <br> PM2.5 in μg/m3 <br> PM10 in μg/m3 |  |  |  [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/opcn2.pdf) |

## Plantower PM Sensors

<img src="./sensors/images/pms7003.png" width="200" />

### Parts List

| Part Name | Measurement | Range | Accuracy | Datasheet |
| ------------- |------------- | ------------- |------------- |------------- |
| PMS7003 | PM1 in μg/m3 <br> PM2.5 in μg/m3 <br> PM10 in μg/m3 |  |  |  [Datasheet](https://github.com/waggle-sensor/sensors/raw/master/sensors/datasheets/pms7003.pdf) |

## Firmware

The latest release of the v4 Coresense firmware can be found [here](https://github.com/waggle-sensor/sensors/tree/94c30e90568c6cd7f0c8b42423df03ca29488834/v4/integrated/firmware).
