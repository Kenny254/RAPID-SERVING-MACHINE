
// Include Libraries
#include "Arduino.h"


// Pin Definitions
#define IRPROXIMITY_1_PIN_VOUT	A3
#define IRPROXIMITY_2_PIN_VOUT	A1
#define IRPROXIMITY_3_PIN_VOUT	A5
#define IRPROXIMITY_4_PIN_VOUT	A4
#define RELAYMODULE4CH_PIN_IN1	2
#define RELAYMODULE4CH_PIN_IN2	3
#define RELAYMODULE4CH_PIN_IN3	4
#define RELAYMODULE4CH_PIN_IN4	5



// Global variables and defines
//define an array for the 4ch relay module pins
int RelayModule4chPins[] = { RELAYMODULE4CH_PIN_IN1, RELAYMODULE4CH_PIN_IN2, RELAYMODULE4CH_PIN_IN3, RELAYMODULE4CH_PIN_IN4 };
// object initialization



// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pinMode(RELAYMODULE4CH_PIN_IN1, OUTPUT);
    pinMode(RELAYMODULE4CH_PIN_IN2, OUTPUT);
    pinMode(RELAYMODULE4CH_PIN_IN3, OUTPUT);
    pinMode(RELAYMODULE4CH_PIN_IN4, OUTPUT);
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {}
    // Disclaimer: The Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #1 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    else if(menuOption == '2') {}
    // Disclaimer: The Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #2 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    else if(menuOption == '3') {}
    // Disclaimer: The Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #3 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    else if(menuOption == '4') {}
    // Disclaimer: The Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #4 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    else if(menuOption == '5') {
    // Relay Module 4-Ch - Test Code
    //This loop will turn on and off each relay in the array for 0.5 sec
    for (int i = 0; i < 4; i++) { 
      digitalWrite(RelayModule4chPins[i],HIGH);
      delay(500);
      digitalWrite(RelayModule4chPins[i],LOW);
      delay(500);
    }
    }
    
    
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #1"));
    Serial.println(F("(2) Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #2"));
    Serial.println(F("(3) Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #3"));
    Serial.println(F("(4) Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #4"));
    Serial.println(F("(5) Relay Module 4-Ch"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {
            if(c == '1') 
    		{
    			Serial.println(F("Now Testing Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #1 - note that this component doesn't have a test code"));
    		}			
    		else if(c == '2') 
    		{
    			Serial.println(F("Now Testing Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #2 - note that this component doesn't have a test code"));
    		}			
    		else if(c == '3') 
    		{
    			Serial.println(F("Now Testing Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #3 - note that this component doesn't have a test code"));
    		}			
    		else if(c == '4') 
    		{
    			Serial.println(F("Now Testing Infrared Proximity Sensor Long Range - Sharp GP2Y0A02YK0F #4 - note that this component doesn't have a test code"));
    		}			
    		else if(c == '5') 
    			Serial.println(F("Now Testing Relay Module 4-Ch"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
