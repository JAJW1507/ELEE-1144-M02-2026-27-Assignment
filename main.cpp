#include <Arduino.h>
#include "Dobot.h"
#include "DobotControl.h"
#include "RGBSensor.h"
#include "DobotStoreRetrieve.h"

Dobot dobot = Dobot();

void setup(){

    Serial.begin(115200); //Baud Rate of Dobot is 115200, so we need to set the same baud rate for serial communication

    dobot.begin();        //Initialize the Dobot

    ColourSensorInit();   //Initialize the Colour Sensor

    HomingDobot();        //Move the Dobot to the Home position   

    LoadingAreaUpDobot(); //Move the Dobot to the Loading Area Up position

    Serial.println("Dobot is ready to use!");
}

void loop()
{
    if (Serial.available() > 0) // Check if there is any data available in the serial buffer
    { 
        char command = Serial.read(); 
        if (command == 's') 
        { 
            StoreBlock();
        } else if (command == 'r') 
        {
            RetrieveBlock(RED);
        }
        else if (command == 'b') 
        {
            RetrieveBlock(BLUE);
        } 
        else if (command == 'g') 
        {
            RetrieveBlock(GREEN);
        }
        else
        {
            Serial.println("Invalid command. Please enter 's' to store a block, 'r' to retrieve a red block, 'b' to retrieve a blue block, or 'g' to retrieve a green block.");
        }
    }
}







