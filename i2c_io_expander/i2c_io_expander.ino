#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin(address);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(slave_address);
  Wire.write(data);
  Wire.endTransmission;

  Wire.requestFrom(slave_address, num_bytes);

  while(Wire.available()){
    char c = Wire.read();
    }

}
