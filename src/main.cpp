#include <Arduino.h>
int n=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // n++;
  Serial.println("SEAN đã test xong");
  delay(10);
}
