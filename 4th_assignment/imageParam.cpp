#include "imageParam.h"
#include <iostream>

using namespace std;

imageParam::imageParam()
{
    // default Constructor
    // initialize the parameter and create the element position and scanline position matrix
    numElement = 128;
    numSample = 3338;
    numScanline = 127;
    elementPosition = genElementPosition();
    scanlinePosition = genScanlinePosition(numScanline, PITCH, elementPosition);
}

imageParam::~imageParam()
{
    // destructor that call the delete function
    deletePositionArray();
}

// Create an array containing the element location (in x-direction) of the ultrasound transducer
float *imageParam::genElementPosition()
{
    // create new pointer with size of numElement
    int numElement = getNumElement();
    float *elementPosition = new float[numElement];
    for (int i = 0; i < numElement; i++){
        // put each element location away from the center
        elementPosition[i] = (i - ((float(numElement)-1.0)/2.0))*PITCH;
    }
    // return the array
    return elementPosition;
}

float2 **imageParam::genScanlinePosition(int numScanline, const float PITCH, float* elementLocation)
{
    // ask for user input for numPixel and desired depth of scanline
    cout << "Input desired depth" << endl;
    cin >> desiredDepth;
    cout << "Input desired number of pixels" << endl;
    cin >> numPixel;
    
    // create 2D array scanline Position of type float2 (contains x and y)
    float2 **scanlinePosition = new float2 * [numScanline];
    for (int i = 0; i < numScanline; i++){
        // set array length for each pointer in the pointer array
        scanlinePosition[i] = new float2 [numPixel];
        for (int j = 0; j < numPixel; j++){
            // input a value for each x and y
            scanlinePosition[i][j].x = (i - ((float(numScanline)-1)/2))*PITCH;
            scanlinePosition[i][j].y = (desiredDepth/(numPixel-1))*j;
        }
    }
    // return the scanline Position array
    return scanlinePosition;
}

float imageParam::getXPosition(int scanline, int pixel)
{
    // return the x value of (scanline, pixel) in scanline Position
    return scanlinePosition[scanline][pixel].x;
}

float imageParam::getYPosition(int scanline, int pixel)
{
    // return the y value of (scanline, pixel) in scanline Position
    return scanlinePosition[scanline][pixel].y;
}

float imageParam::getElementPosition(int element)
{
    // return the (element) in Element Position
    return elementPosition[element];
}

int imageParam::getNumElement()
{
    // numElement getter function
    return numElement;
}

int imageParam::getNumSample()
{
    // numSample getter function
    return numSample;
}

int imageParam::getNumScanline() 
{
    // numScanline getter function
    return numScanline;
}

int imageParam::getNumPixel() 
{
    // numPixel getter function
    return numPixel;
}

void imageParam::deletePositionArray()
{
    // release the memory of the pointer arrays
    delete elementPosition;
    for (int i = 0 ; i<numElement; i++){
        // release the memory of each pointer arrays for every pointer
        delete scanlinePosition[i];
    }
    delete scanlinePosition;
}









