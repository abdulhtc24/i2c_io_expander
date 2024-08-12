#include <Wire.h>
const int ADS1115 = 0x48; //I2C addess with ADDR pin tied to GND
const int conv_reg_set = 0x00; //Address pointer register configuration for conversion register
const int config_reg_set = 0x01; //Config reg setting
const int configA = 0x00; //Config register value 0000000010000011
const int configB = 0x83; //Config register value 0000000010000011

float getAnalogValue(){
  uint16_t val;
  uint8_t crc;
  Wire.requestFrom(ADS1115,2);
  val = Wire.read();
  val |= (Wire.read()<<8);  
  //return (((float)val)/65536);
  return(float)val;
  }
  
void setup() {
  pinMode(3,OUTPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
  digitalWrite(3,LOW);
  delay(1);
  digitalWrite(3,HIGH);
  Wire.begin();
  delay(1);
  Wire.beginTransmission(ADS1115);
  Wire.write(config_reg_set);
  //Wire.endTransmission();
  //delay(1);
  //Wire.beginTransmission(ADS1115);
  Wire.write(configA);
  Wire.write(configB);
  Wire.endTransmission();
  delay(1);
  Wire.beginTransmission(ADS1115);
  Wire.write(conv_reg_set);
  Wire.endTransmission();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getAnalogValue());
  //Serial.println(analogRead(A1));
  delay(500);
  /*
  Wire.beginTransmission(slave_address);
  Wire.write(data);
  Wire.endTransmission;

  Wire.requestFrom(slave_address, num_bytes);

  while(Wire.available()){
    char c = Wire.read();
    }
*/
}
