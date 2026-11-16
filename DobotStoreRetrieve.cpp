#include <Arduino.h>
#include "DobotControl.h"
#include "Dobot.h"
#include "DobotStoreRetrieve.h"
#include "RGBSensor.h"

int redCount = 0;
int blueCount = 0;
int greenCount = 0;

void StoreBlock(){

    LoadingAreaDobot(); //Move the Dobot to the Loading Area position

    SuckOnDobot(); //Turn on the suction cup to pick up the object
    delay(2000);

    LoadingAreaUpDobot(); //Move the Dobot to the Loading Area Up position

    ColourSensorPositionDobot(); //Move the Dobot to the Colour Sensor position to detect the colour of the object
    delay(1000);

    Colour colour = DetectColour(); //Detect the colour of the object

    switch(colour){
        case RED:
            Serial.println("Red Colour Detected");
            if(redCount == 3)
            {
                Serial.println("Red Colour Count Exceeded");
                SuckOffDobot();
                delay(2000);
            }
            else if(redCount == 0)
            {
                StorageBay1UpDobot();
                StorageBay1Dobot();
                SuckOffDobot();
                delay(2000);
                StorageBay1UpDobot();
                redCount++;
            }
            else if(redCount == 1)
            {
                StorageBay1UpDobot();
                StorageBay1Stack2Dobot();
                SuckOffDobot();
                delay(2000);
                StorageBay1UpDobot();
                redCount++;
            }
            else if(redCount == 2)
            {
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
            if(blueCount == 3)
            {
                Serial.println("Blue Colour Count Exceeded");
                SuckOffDobot();
                delay(2000);
            }
            else if(blueCount == 0)
            {
                StorageBay2UpDobot();
                StorageBay2Dobot();
                SuckOffDobot();
                delay(2000);
                StorageBay2UpDobot();
                blueCount++;
            }
            else if(blueCount == 1)
            {
                StorageBay2UpDobot();
                StorageBay2Stack2Dobot();
                SuckOffDobot();
                delay(2000);
                StorageBay2UpDobot();
                blueCount++;
            }
            else if(blueCount == 2)
            {
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
            if(greenCount == 3)
            {
                Serial.println("Green Colour Count Exceeded");
                SuckOffDobot();
                delay(2000);
            }
            else if(greenCount == 0)
            {
                StorageBay3UpDobot();
                StorageBay3Dobot();
                SuckOffDobot();
                delay(2000);
                StorageBay3UpDobot();
                greenCount++;
            }
            else if(greenCount == 1)
            {
                StorageBay3UpDobot();
                StorageBay3Stack2Dobot();
                SuckOffDobot();
                delay(2000);
                StorageBay3UpDobot();
                greenCount++;
            }
            else if(greenCount == 2)
            {
                StorageBay3UpDobot();
                StorageBay3Stack3Dobot();
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

void RetrieveBlock(Colour retrieveColour)
{

    switch(retrieveColour)
    {
        case RED:
        {
            Serial.println("Red Block Retrieval");
            if(redCount == 0)
            {
                Serial.println("No Red Blocks to Retrieve");
            }
            else if(redCount == 1)
            {
                StorageBay1UpDobot();
                StorageBay1Dobot();
                SuckOnDobot();
                delay(2000);
                StorageBay1UpDobot();
                LoadingAreaUpDobot();
                LoadingAreaDobot();
                SuckOffDobot();
                delay(2000);
                redCount--;
            }
            else if(redCount == 2)
            {
                StorageBay1UpDobot();
                StorageBay1Stack2Dobot();
                SuckOnDobot();
                delay(2000);
                StorageBay1UpDobot();
                LoadingAreaUpDobot();
                LoadingAreaDobot();
                SuckOffDobot();
                delay(2000);
                redCount--;
            }
            else if(redCount == 3)
            {
                StorageBay1UpDobot();
                StorageBay1Stack3Dobot();
                SuckOnDobot();
                delay(2000);
                StorageBay1UpDobot();
                LoadingAreaUpDobot();
                LoadingAreaDobot();
                SuckOffDobot();
                delay(2000);
                redCount--;
            }
            break;
        }
        case BLUE: 
        {
            Serial.println("Blue Block Retrieval");
            if(blueCount == 0)
            {
                Serial.println("No Blue Blocks to Retrieve");
            }
            else if(blueCount == 1)
            {
                StorageBay2UpDobot();
                StorageBay2Dobot();
                SuckOnDobot();
                delay(2000);
                StorageBay2UpDobot();
                LoadingAreaUpDobot();
                LoadingAreaDobot();
                SuckOffDobot();
                delay(2000);
                blueCount--;
            }
            else if(blueCount == 2)
            {
                StorageBay2UpDobot();
                StorageBay2Stack2Dobot();
                SuckOnDobot();
                delay(2000);
                StorageBay2UpDobot();
                LoadingAreaUpDobot();
                LoadingAreaDobot();
                SuckOffDobot();
                delay(2000);
                blueCount--;
            }
            else if(blueCount == 3)
            {
                StorageBay2UpDobot();
                StorageBay2Stack3Dobot();
                SuckOnDobot();
                delay(2000);
                StorageBay2UpDobot();
                LoadingAreaUpDobot();
                LoadingAreaDobot();
                SuckOffDobot();
                delay(2000);
                blueCount--;
            }
            break;
        }
        case GREEN: 
        {
            Serial.println("Green Block Retrieval");
            if(greenCount == 0)
            {
                Serial.println("No Green Blocks to Retrieve");
            }
            else if(greenCount == 1)
            {
                StorageBay3UpDobot();
                StorageBay3Dobot();
                SuckOnDobot();
                delay(2000);
                StorageBay3UpDobot();
                LoadingAreaUpDobot();
                LoadingAreaDobot();
                SuckOffDobot();
                delay(2000);
                greenCount--;
            }
            else if(greenCount == 2)
            {
                StorageBay3UpDobot();
                StorageBay3Stack2Dobot();
                SuckOnDobot();
                delay(2000);
                StorageBay3UpDobot();
                LoadingAreaUpDobot();
                LoadingAreaDobot();
                SuckOffDobot();
                delay(2000);
                greenCount--;
            }
            else if(greenCount == 3)
            {
                StorageBay3UpDobot();
                StorageBay3Stack3Dobot();
                SuckOnDobot();
                delay(2000);
                StorageBay3UpDobot();
                LoadingAreaUpDobot();
                LoadingAreaDobot();
                SuckOffDobot();
                delay(2000);
                greenCount--;
            }
        break;
        }
    }
    LoadingAreaUpDobot();
    delay(2000);
}