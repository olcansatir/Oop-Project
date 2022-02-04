/**
* @file DepthCamera.cpp
* @author Ergün Altýndað (152120181083)
* @date 10.01.2022
* @brief Source file of DepthCamera class.
*
*	This file includes all the implementations declared in the DepthCamera header file.
*/
#include "DepthCamera.h"
string DepthCamera::getFileName()
{
    return fileName;
}
void DepthCamera::setFileName(string fileName)
{
    this->fileName = fileName;
}

PointCloud DepthCamera::capture() {

    ifstream ReadFile;
    ReadFile.open(fileName);
    PointCloud pointCloud;
    string text;
    int size = 0;
    int i = 0;
    double x, y, z;


    if (!ReadFile)
    {
        cout << "Error opening the file!" << endl;

    }
    while (ReadFile >> x >> y >> z) {
        Point p(x, y, z);
        pointCloud.addElementToEnd(p);
    }
    ReadFile.close();

    return pointCloud;
    
}

PointCloud DepthCamera::captureFor()
{
    PointCloud pointCloud = this->capture();
    filterPipe->filterOut(pointCloud);
    pointCloud = transform.doTransform(pointCloud);
    return pointCloud;
}
