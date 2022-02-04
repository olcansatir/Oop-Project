/**
* @file PointCloudRecorder.cpp
* @author Ergün Altýndað (152120181083)
* @date 20.12.2021
* @brief Source file of PointCloudRecorder class.
*
*	This file includes all the implementations declared in the PointCloudRecorder header file.
*/
#include "PointCloudRecorder.h"

string PointCloudRecorder::getFileName()
{
    return fileName;
}
void PointCloudRecorder::setFileName(string fileName)
{
    this->fileName = fileName;
}
bool PointCloudRecorder::save(const PointCloud& pointCloud)  {

    ofstream SaveFile(fileName);
    if (SaveFile.fail())
    {
        cout << "Error opening the file!" << endl;
        return false;
    }

    else
    {
        for (int i = 0; i < pointCloud.getPointNumber(); i++)
        {

            SaveFile << setw(10) << setprecision(5) << pointCloud.getSinglePoint(i).getX();
            SaveFile << setw(10) << setprecision(5) << pointCloud.getSinglePoint(i).getY();
            SaveFile << setw(10) << setprecision(5) << pointCloud.getSinglePoint(i).getZ();
            
            SaveFile << endl;
        }

        cout << "Successfully recorded to the file named " << fileName << "!" << endl;
        return true;
        SaveFile.close();

    }
     

    
}