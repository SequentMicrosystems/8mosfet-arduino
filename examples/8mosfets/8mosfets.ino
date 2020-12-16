/*
 * 8mosfets
 * 
 * A 8-Mosfets cards controling example
 * This example can control 2 cards.
 * 
 * Hardware requarements except your favorite processor: 
 * 1) 8-MOSFETS 8-Layer Stackable Card for Raspberry Pi: https://sequentmicrosystems.com/product/raspberry-pi-mosfets-stackable-hat/
 * 2) S-Bridge : https://sequentmicrosystems.com/product/raspberry-pi-replacement-card/
 */
#include <SM_8mosfet.h>

SM_8mosfet mos1 = SM_8mosfet();
SM_8mosfet mos2 = SM_8mosfet();

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   Serial.print("8-Mosfets card 1 init");
  if(0 == mos1.begin(0)) // set the stack level to 0
  {
    Serial.println(" Done");
  }
  else
  {
    Serial.println(" Fail!");
  }
  
  Serial.print("8-Mosfets card 2 init");
  if(0 == mos2.begin(1)) // set the stack level to 1
  {
    Serial.println(" Done");
  }
  else
  {
    Serial.println(" Fail!");
  }

}

void loop() {
  int i;
  // put your main code here, to run repeatedly:
  for(i = 1; i < 9; i++) //turn mosfets ON, one by one 
  {
    mos1.writeChannel(i, 1);
    mos2.writeChannel(i, 1);
    delay(250);
  }
  //Serial.println(mos.readAll());
  delay (1000);
  for(i = 1; i < 9; i++)//turn mosfets OFF, one by one 
  {
    mos1.writeChannel(i, 0);
    mos2.writeChannel(i, 0);
    delay(250);
  }
  //Serial.println(mos.readAll());
  delay (1000);
}
