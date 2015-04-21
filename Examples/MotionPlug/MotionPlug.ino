/* ------------- Motion Plug Demo Code -------------

Originally by rpicopter: https://github.com/rpicopter/ArduinoMotionSensorExample


Features:
  - uses FastWire and I2Cdev from Jeff Rowberg
  - DMP enabled
  - calculates and displays gyro and quaternions
  - This has been tested using Arduino 1.0.5, 1.6.1, a few variants of Arduino Pro Mini boards, the Modern Device Robot Board Rev E. (a mega2560), and the JeeNode SMD.

- This library is set up for the MPU9250. If you have
  a 6050, 6500, or 9150,
  change #DEFINE MPU9250 to #DEFINE MPU6050,
  #DEFINE MPU6500, or #DEFINE MPU9150 in inv_mpu.h.

- Default chip configuration values, buried in inv_mpu.h. 
  Pulled out here for reference:
    test->reg_rate_div   = 0;    // 1kHz.  
    test->reg_lpf        = 1;    // 188Hz. 
    test->reg_gyro_fsr   = 0;    // 250dps. 
    test->reg_accel_fsr  = 0x18; // 16g.
*/

#include "freeram.h"
#include "mpu.h"
#include "I2Cdev.h"

int ret;
void setup() {
    Fastwire::setup(400,0);
    Serial.begin(9600);
    ret = mympu_open(200);
    Serial.print("MPU init: "); Serial.println(ret);
    Serial.print("Free mem: "); Serial.println(freeRam());
	
}

unsigned int c = 0; //cumulative number of successful MPU/DMP reads
unsigned int np = 0; //cumulative number of MPU/DMP reads that brought no packet back
unsigned int err_c = 0; //cumulative number of MPU/DMP reads that brought corrupted packet
unsigned int err_o = 0; //cumulative number of MPU/DMP reads that had overflow bit set

void loop() {
    ret = mympu_update();
    // errorReporting(); // turn on for debug information

   if (!(c%25)) { // output only every 25 MPU/DMP reads
	    Serial.print("Y: "); Serial.print(mympu.ypr[0]);
	    Serial.print(" P: "); Serial.print(mympu.ypr[1]);
	    Serial.print(" R: "); Serial.print(mympu.ypr[2]);
	    Serial.print("\tgy: "); Serial.print(mympu.gyro[0]);
	    Serial.print(" gp: "); Serial.print(mympu.gyro[1]);
	    Serial.print(" gr: "); Serial.println(mympu.gyro[2]);
    }
}

void errorReporting(){
  if (ret != 0){
      switch (ret) {
	case 0: c++; break;
	case 1: np++; return;
	case 2: err_o++; return;
	case 3: err_c++; return; 
	default: 
		Serial.print("READ ERROR!  ");
		Serial.println(ret);
      }
      Serial.print(np);
      Serial.print("  ");
      Serial.print(err_c);
      Serial.print(" ");
      Serial.print(err_o);
      Serial.print(" ");
  }
}
