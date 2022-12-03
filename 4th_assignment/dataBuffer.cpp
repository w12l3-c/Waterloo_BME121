#include "dataBuffer.h"
using namespace std;

dataBuffer::dataBuffer()
{
    // default constructor
    // initialize the parameters
    numElement = 0;
    numSample = 0;
    scanline = 0;
    dataMatrix = NULL;
    next = NULL;
}

dataBuffer::dataBuffer( std::ifstream *imagFile, std::ifstream *realFile, int inputNumElement, int inputNumSample, int inputScanline)
{
    // Overload Constructor
    numElement = inputNumElement;
    numSample = inputNumSample;
    scanline = inputScanline;
    dataMatrix = createDataMatrix();    // create the data matrix
    loadRFData(dataMatrix, imagFile, realFile); // loading the dataMatrix
} 

dataBuffer::~dataBuffer()
{
    // Destructor to release the memory of data matrix
    deleteDataMatrix();
}

complex **dataBuffer::createDataMatrix()
{   
    // create a 2D pointer array for data Matrix of numElement by numSample
    complex **dataMatrix = new complex*[numElement];
    for(int i = 0; i < numElement; i++){
        dataMatrix[i] = new complex[numSample];
    }
    return dataMatrix;
}

int dataBuffer::loadRFData(complex **RFData, std::ifstream *imagFile, std::ifstream *realFile) 
{ 
    // initialize the variable for line and size
    const int size = 20;
    char real [20];
    char imag [20];
    
    for(int i = 0; i < numElement; i++){
        for(int j = 0; j < numSample; j++){
            // load data for real and imag file
            realFile->getline(real, size);
            imagFile->getline(imag, size);
            RFData[i][j].real = atof(real); 
            RFData[i][j].imag = atof(imag);
        }
    }
    
    return 0;
}

float dataBuffer::getRealRFData(int element,int sample){    
    return dataMatrix[element][sample].real;    // get the real part data in datamatrix (element, sample)
}

float dataBuffer::getImagRFData(int element,int sample){
    return dataMatrix[element][sample].imag;    // get the imaginery part of data in datamatrix (element, sample)
}

void dataBuffer::deleteDataMatrix(){
    // release memory each pointer array in the pointer array
    for(int i = 0; i < numElement; i++){
        delete dataMatrix[i];
    }
    // release memory for the pointer array
    delete dataMatrix;
}




