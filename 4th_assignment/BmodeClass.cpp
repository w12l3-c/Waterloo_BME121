#include "BmodeClass.h"
#include <cmath>
#include <iostream>

using namespace std;

BmodeClass::BmodeClass()
{
    // default Constructor
    imparams, RFData, next = NULL;  // initialize NULL for these pointers
    line = 0;   // set scanline number to 0
}

BmodeClass::BmodeClass(imageParam *params,dataBuffer *data,int numline)
{
    // Overload Constructor
    imparams = params;  // initialize imparams as a imageParm object 
    RFData = data;  //initialize RFData as a dataBuffer object
    line = numline; // initialize numline with the current scanline number
    scanline = createScanline(imparams->getNumPixel()); // create a 1D array with numPixel size
    beamform(); // Beamform the scanline
}

BmodeClass::~BmodeClass()
{
    deleteScanline();   // destructor call delete scanline function
}

float *BmodeClass::createScanline(int numPixel)
{
    float * mem = new float [numPixel]; // initialize a numPixel size of 1D pointer array
    return mem; // return the pointer
}

void BmodeClass::beamform()
{
    // initialize the parameters as 0
    float t_forward = 0;    
    float t_backward = 0;          
    float t_total = 0;          
    int s = 0;      
    float Preal = 0;          
    float Pimag = 0; 

    // Save the params in the imageParam object
    int numSample = imparams->getNumSample();  
    int numElement = imparams->getNumElement();  
    int numPixel = imparams->getNumPixel();  
    int numScanline = imparams->getNumScanline();  
    
    // Math for beammode
    for (int i = 0; i < numPixel; i++){
        t_forward = imparams->getYPosition(line, i)/imparams->SOS;
        for (int j = 0; j < numElement; j++){
            t_backward = sqrt(pow(imparams->getYPosition(line, i), 2) + pow(imparams->getXPosition(line, i) - imparams->getElementPosition(j), 2))/imparams->SOS;
            t_total = t_forward + t_backward;
            s = floor(t_total * imparams->FS);
            if (s < numSample){     // prevent the sample > numSample and cause segmentation faulting
                Preal += RFData->getRealRFData(j, s);
                Pimag += RFData->getImagRFData(j, s);
            }
        }
        scanline[i] = sqrt(pow(Preal, 2)+pow(Pimag, 2));    // update value in the scanline pointer array
        Preal = Pimag = 0;  // reset the values to 0
    }
}

void BmodeClass::getScanline(float *data)
{
    // copy each individual data from the scanline to another pointer array
    for (int i = 0; i < imparams->getNumPixel(); i++){
        data[i] = scanline[i];
    }
}

void BmodeClass::deleteScanline()
{
    delete[] scanline;    // release the memory of scanline
}