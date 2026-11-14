#include <Arduino.h>
#include "Dobot.h"
#include "DobotControl.h"
#include "RGBSensor.h"

Dobot dobot = Dobot();

Colour colour; //Variable to store the detected colour

int redCount = 0;
int blueCount = 0;
int greenCount = 0;

void setup(){

    Serial.begin(115200); //Baud Rate of Dobot is 115200, so we need to set the same baud rate for serial communication

    dobot.begin();        //Initialize the Dobot

    ColourSensorInit();   //Initialize the Colour Sensor

    LoadingAreaUpDobot(); //Move the Dobot to the Loading Area Up position

    HomingDobot();        //Move the Dobot to the Home position   

    Serial.println("Dobot is ready to use!");
}

void loop(){

    LoadingAreaDobot(); //Move the Dobot to the Loading Area position

    SuckOnDobot(); //Turn on the suction cup to pick up the object
    delay(2000);

    LoadingAreaUpDobot(); //Move the Dobot to the Loading Area Up position

    ColourSensorPositionDobot(); //Move the Dobot to the Colour Sensor position to detect the colour of the object
    delay(1000);

    colour = DetectColour(); //Detect the colour of the object

    switch(colour){
        case RED:
            Serial.println("Red Colour Detected");
            if(redCount == 3){
                Serial.println("Red Colour Count Exceeded");
                SuckOffDobot();
                delay(2000);
            }
            else if(redCount == 0){
            StorageBay1UpDobot();
            StorageBay1Dobot();
            SuckOffDobot();
            delay(2000);
            StorageBay1UpDobot();
            redCount++;
            }
            else if(redCount == 1){
            StorageBay1UpDobot();
            StorageBay1Stack2Dobot();
            SuckOffDobot();
            delay(2000);
            StorageBay1UpDobot();
            redCount++;
            }
            else if(redCount == 2){
            StorageBay1UpDobot();
            StorageBay1Stack3Dobot();
            SuckOffDobot();
            delay(2000);
            StorageBay1UpDobot();
            redCount++;
            }
            break;
        case BLUE:
            Serial.println("Blue Colour Detected");
            if(blueCount == 3){
                Serial.println("Blue Colour Count Exceeded");
                SuckOffDobot();
                delay(2000);
            }
            else if(blueCount == 0){
            StorageBay2UpDobot();
            StorageBay2Dobot();
            SuckOffDobot();
            delay(2000);
            StorageBay2UpDobot();
            blueCount++;
            }
            else if(blueCount == 1){
            StorageBay2UpDobot();
            StorageBay2Stack2Dobot();
            SuckOffDobot();
            delay(2000);
            StorageBay2UpDobot();
            blueCount++;
            }
            else if(blueCount == 2){
            StorageBay2UpDobot();
            StorageBay2Stack3Dobot();
            SuckOffDobot();
            delay(2000);
            StorageBay2UpDobot();
            blueCount++;
            }
            break;
        case GREEN:
            Serial.println("Green Colour Detected");
            if(greenCount == 3){
                Serial.println("Green Colour Count Exceeded");
                SuckOffDobot();
                delay(2000);
            }
            else if(greenCount == 0){
            StorageBay3UpDobot();
            StorageBay3Dobot();
            SuckOffDobot();
            delay(2000);
            StorageBay3UpDobot();
            greenCount++;
            }
            else if(greenCount == 1){
            StorageBay3UpDobot();
            StorageBay3Stack2Dobot(); //change
            SuckOffDobot();
            delay(2000);
            StorageBay3UpDobot();
            greenCount++;
            }
            else if(greenCount == 2){
            StorageBay3UpDobot();
            StorageBay3Stack3Dobot(); //change
            SuckOffDobot();
            delay(2000);
            StorageBay3UpDobot();
            greenCount++;
            }
            break;
        case NONE:
            Serial.println("Unknown Colour Detected");
            SuckOffDobot();
            delay(2000);
            break;
    }
    LoadingAreaUpDobot();
    delay(2000);
}




