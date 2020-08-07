#include <Arduino.h>
#include <OneWire.h>
#include <Keyboard.h>

OneWire ds(10);  // on pin 10 (a 4.7K resistor is necessary)

void setup(void) {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop(void) {
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  char str[20];
  float celsius, fahrenheit;

  if ( !ds.search(addr)) {
    Serial.println("No more addresses.");
    Serial.println();
    ds.reset_search();
    delay(250);
    return;
  }

  Serial.print("ROM =");
  for( i = 0; i < 8; i++){
    sprintf(str,"%x",addr[7-i]);
    Serial.print(str);
    Keyboard.print(str);

    if(addr[7-i] == 0){
      Serial.print(0);
      Keyboard.print(0);
    }

  }

    Keyboard.println();
}