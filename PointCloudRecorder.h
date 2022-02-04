/**
* @file PointCloudRecorder.h
* @author Ergün Altýndað (152120181083)
* @date 20.12.2021
* @brief Header of PointCloudRecorder class.
*
*	This file includes all the declarations of member variables and functions for PointCloudRecorder class.
*/
#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include <iomanip>
#include "PointCloud.h"

using namespace std;

//! The PointCloudRecorder class is the class that performs the data writing function.
/*! * Writes incoming data as text file.
*/
class PointCloudRecorder
{

private:
	string fileName;

public:
	/**Constructor for PointCloudRecorder class
	* Gets the name of the file where the data to be exported is kept.
	* If no name is given, it takes a blank value.
	* @param _fileName is the fileName of the file that is wanted to record the points
	*/
	PointCloudRecorder(string _fileName = "output.txt") :fileName(_fileName) {}

	/** This function is used to return the originally assigned file name.
	* @return the file name of the record file
	*/
	string getFileName();

	/** This function is used to change the originally assigned filename.
	* @param fileName is the file name of the file that is wanted to set
	*/
	void setFileName(string fileName);

	/** This function writes the imported data to a text file
	* @param pointCloud is the point cloud that is wanted to record to the file
	*/
	bool save(const PointCloud& pointCloud);


};

