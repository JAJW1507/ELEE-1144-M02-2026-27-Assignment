#pragma once

void ColourSensorInit();

enum Colour
{
    NONE,
    RED,
    GREEN,
    BLUE
};

Colour DetectColour();
