/***
* @file PassThroughFilterTest.cpp
* @author Kýsmet AKTAÞ (152120191088)
* @date 27.12.2021
* @brief Test file of PassThroughFilter class.
*
**	This file was written for testing purposes.
***/


#include <iostream>
#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include "DepthCamera.h"
#include "PassThroughFilter.h"

using namespace std;

int main() {

	PointCloud pointCloud(10);
	pointCloud.setSinglePoint(0, 401, 8, 1);
	pointCloud.setSinglePoint(1, 4, 402, 10);
	pointCloud.setSinglePoint(2, -5, 42, 9);
	pointCloud.setSinglePoint(3, 28, -5, 0);
	pointCloud.setSinglePoint(4, 3, 16, -47);
	pointCloud.setSinglePoint(5, 400, 8, 1);
	pointCloud.setSinglePoint(6, 4, 50, 10);
	pointCloud.setSinglePoint(7, 0, 42, 9);
	pointCloud.setSinglePoint(8, 28, 50, 0);
	pointCloud.setSinglePoint(9, 3, 16, 45);
	PassThroughFilter ptf(400, 0, 400, 0, 45, -45);
	ptf.filter(pointCloud);
	pointCloud.printPoints();

}