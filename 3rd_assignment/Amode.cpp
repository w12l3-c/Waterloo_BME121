#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

float **createDataMatrix(int numElement, int numSample)
{
    // Create a 2D data matrix of size numElement and numSample
    float **RFData = new float *[numElement]; // load pointer into double pointer
    for (int i = 0 ; i < numElement; i++){
        RFData[i] = new float [numSample];  // load the array inside of each pointer
    }
    return RFData;
}

int loadRFData(float **RFData, const char *fileName, int numElement, int numSample)
{
    // Open the text file fileName, read the data and store into RFData
    // You can use the getline() command to extract the data lines from the txt files
    // open file
    ifstream infile;
    infile.open(fileName);
    // check if file open correctly
    if (infile.fail()){
        return -1;
    }

    char line[20];  // char arrays to store the line
    const int length = 20;  // Max size of the line 
    
    // check if the file is empty
    if(!infile.eof()){
        for (int i = 0; i<numElement; i++){
            for (int j = 0; j<numSample; j++){
                // get the text line
                infile.getline(line, length);
                // save the converted float line into 2D pointer
                RFData[i][j] = atof(line);
            }
        }
    }
    // close file
    infile.close();
    return 0;
}

// Create an array containing the depth location (in z-direction) for each pixel on the scanline
float *genScanlineLocation(int &numPixel)
{
    int save;   // store the value of numPixel because it cannot be modified directly
    float depth;    // store the value of scan line depth

    // prompt user input 
    cout << "Please enter scanline depth: " << endl;
    // save the scanline depth
    cin >> depth;
    // prompt user input
    cout << "Please enter how many pixels inside of the scanline: " << endl;
    // save the number of pixels
    cin >> save;
    
    // save the value into the numPixel
    numPixel = save;
    
    // create a pointer with size of numPixel
    float *scanlineLocation = new float [numPixel];
    for (int i = 0; i < numPixel ; i++){
        // put each scanline location into pointer based on the number of pixels
        scanlineLocation[i] = (depth/(numPixel-1))*i;
    }
    return scanlineLocation;
}

// Create an array containing the element location (in x-direction) of the ultrasound transducer
float *genElementLocation(int numElement, float PITCH)
{
    // create new pointer with size of numElement
    float *eleLocation = new float[numElement];
    for (int i = 0; i <= numElement-1; i++){
        // put each element location away from the center
        eleLocation[i] = (i - ((float(numElement)-1)/2))*PITCH;
    }
    return eleLocation;
}

// Allocate memory to store the beamformed scanline
float *createScanline(int numPixel)
{
    // create pointer to store the value later
    float *scanline = new float [numPixel];
    return scanline;
}

// Beamform the A-mode scanline
void beamform(float *scanline, float **realRFData, float **imagRFData, float *scanlinePosition, float *elementPosition, int numElement, int numSample, int numPixel, float FS, float SoS)
{
    // create all the arrays to hold the intermediate steps
    float *t_forward = new float [numPixel];
    float **t_backward = new float *[numPixel];
    float **t_total = new float *[numPixel];
    int **s = new int *[numPixel];
    float *Preal = new float [numElement];
    float *Pimag = new float [numElement];
    float *mag = new float [numElement];
    float real = 0;
    float imag = 0;

    for (int i = 0; i < numPixel; i++){
        // add array into the pointer of t_back, t_total and s
        t_backward[i] = new float [numElement];
        t_total[i] = new float [numElement];
        s[i] = new int [numElement];
        // equation of t_forward
        t_forward[i] = scanlinePosition[i]/SoS;
        for (int k = 0; k < numElement; k++){
            // equation of t_backward
            t_backward[i][k] = sqrt(pow(scanlinePosition[i], 2)+pow(elementPosition[k], 2))/SoS;
            // equation of t_total
            t_total[i][k] = t_forward[i] + t_backward[i][k];
            // equation of samples
            s[i][k] = floor(t_total[i][k]*FS);  
            // check if the sample value is larger so that it doesn't try to access illegal memory
            if (s[i][k] < numSample){
                // sum up each real term of the element
                real += realRFData[k][s[i][k]];
                // sum up each imaginary term of the element
                imag += imagRFData[k][s[i][k]];
            }   
        }
        // save the sum of real into real pointer
        Preal[i] = real;
        // save the sum of imaginary into imaginary pointer
        Pimag[i] = imag;
        // reset the sums
        real = imag = 0;
        // find magnitude
        scanline[i] = sqrt(pow(Preal[i], 2)+pow(Pimag[i], 2));
    }
}

// Write the scanline to a csv file
int outputScanline(const char *fileName, float *scanlinePosition, float *scanline, int numPixel)
{
    // output file
    ofstream outfile;
    outfile.open(fileName);
    // check if the file doesn't open
    if (outfile.fail()){
        return -1;
    }
    // output title
    outfile << "scanlinePosition, scanline" << endl;
    for (int i = 0; i < numPixel; i++){
        // output each scan line posisiotn with its respected magnitude
        outfile << double(scanlinePosition[i]) << ", " << double(scanline[i]) << endl;
    }
    // close output file
    outfile.close();
    return 0;
}

// Destroy all the allocated memory
void destroyAllArrays(float *scanline, float **realRFData, float **imagRFData, float *scanlinePosition, float *elementPosition, int numElement, int numSample, int numPixel)
{   
    // delete of 2D pointers
    for (int i = 0; i < numElement; i++){
        delete realRFData[i];
        delete imagRFData[i];
    }
    // delete of 1D pointers
    delete scanline;
    delete scanlinePosition;
    delete elementPosition;
}