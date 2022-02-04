/**
* @file DepthCamera.h
* @author Ergün Altýndað (152120181083)
* @date 10.01.2022
* @brief Header of PointCloudGenerator class.
*
*	This file includes all the declarations of member variables and functions for PointCloudGenerator class.
*/
#pragma once
#include "Transform.h"
#include "FilterPipe.h"
#include "PointCloud.h"

//! The PointCloudGenerator class is the class that directs the data it receives from the DepthCamere class.
/*!
 * Reads and redirects received data
*/
class PointCloudGenerator
{
protected:
	FilterPipe* filterPipe;
	Transform transform;
public:

	/**Constructor for PointCloudGenerator class
	* Retrieves the classes to which data will be transferred
	* @param _transform, _filterPipe is the name of the objects to be transferred.	
	*/
	PointCloudGenerator(Transform _transform, FilterPipe* _filterPipe);
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
};

