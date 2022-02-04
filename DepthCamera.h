/**
* @file DepthCamera.h
* @author Ergün Altýndað (152120181083)
* @date 10.01.2022
* @brief Header of DepthCamera class.
*
*	This file includes all the declarations of member variables and functions for DepthCamera class.
*/

#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include "PointCloud.h"
#include "PointCloudGenerator.h"
using namespace std;

//! The DepthCamere class is the class that performs the function of reading data from outside.
/*!
 * It reads the imported data and assigns it to the PointCloud class.
*/
class DepthCamera : public PointCloudGenerator
{
private:
	string fileName;
	
public:

	/**Constructor for DepthCamera class
	* Get the name of the file where the data to be imported is kept.
	* @param _fileName is the name of the file that is wanted to read
	*/
	DepthCamera(string _fileName, Transform _transform, FilterPipe* _filterPipe) : fileName(_fileName), PointCloudGenerator(_transform, _filterPipe) { }

	/** This function is used to return the originally assigned file name.
	* @return fileName, the file name to read
	*/
	string getFileName();

	/** This function is used to change the originally assigned filename.
	* @param fileName is the name of the file that is wanted to change(set)
	*/
	void setFileName(string fileName);

	/** This function reads the imported data and assigns it to the PointCloud object and returns this object.
	* @return the point cloud that is captured from the text file
	*/
	PointCloud capture();

	PointCloud captureFor();

}; 
