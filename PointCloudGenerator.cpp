#include "PointCloudGenerator.h"
/**
* @file DepthCamera.cpp
* @author Ergün Altýndað (152120181083)
* @date 10.01.2022
* @brief Source file of PointCloudGenerator class.
*
*	This file includes all the implementations declared in the PointCloudGenerator header file.
*/
PointCloudGenerator::PointCloudGenerator(Transform _transform, FilterPipe* _filterPipe)
{
	transform = _transform;
	filterPipe = _filterPipe;
}