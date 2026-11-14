#include <Arduino.h>
#include "RGBSensor.h"

//define the pins for the TCS3200 colour sensor
const int S0 = 4; // S0 pin of the TCS3200
const int S1 = 5; // S1 pin of the TCS3200
const int S2 = 6; // S2 pin of the TCS3200
const int S3 = 7; // S3 pin of the TCS3200
const int sensorOut = 8; // OUT pin of the TCS3200

unsigned long redFrequency; // Variable to store the frequency of the red colour
unsigned long greenFrequency; // Variable to store the frequency of the green colour
unsigned long blueFrequency; // Variable to store the frequency of the blue colour
unsigned long clearFrequency; // Variable to store the frequency of the clear colour

void ColourSensorInit() {

    // Set the pin modes for the TCS3200 pins
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);

    // Set frequency scaling to 20% (Reccomended for Arduino))
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW); 
    /* frequency scaling for future reference
    100% = S0 HIGH, S1 HIGH
    20% = S0 HIGH, S1 LOW
    2% = S0 LOW, S1 HIGH
    0% = S0 LOW, S1 LOW
    */
   Serial.begin(9600); // Start the serial communication for debugging, remove after testing is complete
}
// replace "void loop()" with "Colour DetectColour()" to return the detected colour to the main program
void loop() {
    // Read the frequency of the red colour
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    redFrequency = pulseIn(sensorOut, HIGH);

    // Read the frequency of the green colour
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    greenFrequency = pulseIn(sensorOut, HIGH);

    // Read the frequency of the blue colour
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    blueFrequency = pulseIn(sensorOut, HIGH);

    // Read the frequency of the clear colour
    digitalWrite(S2, HIGH);
    digitalWrite(S3, LOW);
    clearFrequency = pulseIn(sensorOut, HIGH);

/* Implement once Values are known, replace xx with the actual values for red, green, and blue frequencies
    redFrequency = map(redFrequency, xx, xx, 0, 255);
    greenFrequency = map(greenFrequency, xx, xx, 0, 255);
    blueFrequency = map(blueFrequency, xx, xx, 0, 255);
*/

/* Implement once Values are known, replace xx with the actual values for red, green, and blue frequencies
    if (redFrequency > greenFrequency && redFrequency > blueFrequency) {
        return RED;
    } else if (greenFrequency > redFrequency && greenFrequency > blueFrequency) {
        return GREEN;
    } else if (blueFrequency > redFrequency && blueFrequency > greenFrequency) {
        return BLUE;
    } else {
        return NONE;
    }
*/
// Comment out below code once the above is implemented, this is just for testing purposes
    Serial.print("Red: ");
    Serial.print(redFrequency);
    Serial.print(" | Green: ");
    Serial.print(greenFrequency);
    Serial.print(" | Blue: ");
    Serial.println(blueFrequency);

    delay(1000); // Delay for 1 second before the next reading
}

