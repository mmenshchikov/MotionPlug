#pragma once

/*
 * Board setup.
 */
#ifndef MPU6050
#define MPU6050
#endif

/*
 * Enable MPU debugging.
 */
#ifndef MPU_DEBUG
#define MPU_DEBUG
#endif

/* Used i2c implementation (see I2Cdev.h) */
#ifndef I2CDEV_IMPLEMENTATION
#define I2CDEV_IMPLEMENTATION       I2CDEV_ARDUINO_WIRE
#endif

/*
 * Comment this out if you are using a non-optimal IDE/implementation setting
 * but want the compiler to shut up about it.
 */
#ifndef I2CDEV_IMPLEMENTATION_WARNINGS
#define I2CDEV_IMPLEMENTATION_WARNINGS
#endif

/*
 * Arduino-style "Serial.print" debug constant (uncomment to enable)
 */
#ifndef I2CDEV_SERIAL_DEBUG
//#define I2CDEV_SERIAL_DEBUG
#endif
