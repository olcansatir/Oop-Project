/**
* @file TransformTest.cpp
* @author Ahmet Ata Þentürk (152120181120)
* @date 18.12.2021
* @brief Test file of Transform class.
*
*	This file is for testing purposes.
*/

#include "Transform.h"
#include <iostream>
#include <fstream>
#include "Point.h"
using namespace std;

int main()
{

	Point point(2, 5, 1);
	Eigen::Vector3d firstCameraTr;
	Eigen::Vector3d secondCameraTr;
	firstCameraTr << 100, 500, 50;
	secondCameraTr << 550, 150, 50;

	Eigen::Vector3d firstCameraRot;
	Eigen::Vector3d secondCameraRot;
	firstCameraRot << 0, 0, -90;
	secondCameraRot << 0, 0, 90;

	//Creating transform class for first camera
	Transform transform(firstCameraTr, firstCameraRot);

	//Do transform for single point
	Point po = transform.doTransform(point);
	//Printing transformed point as x, y, z
	cout << po.getX() << " " << po.getY() << " " << po.getZ();
	cout << endl << endl;

	//Creating pointCloud
	PointCloud pointCloud(5);
	pointCloud.setSinglePoint(0, 2, 5, 1);
	pointCloud.setSinglePoint(1, 4, 1, 10);
	pointCloud.setSinglePoint(2, 12, 42, 9);
	pointCloud.setSinglePoint(3, 28, 8, 0);
	pointCloud.setSinglePoint(4, 3, 16, 1);
	PointCloud pointCloud2 = pointCloud;

	//Transforming first PointCloud and printing
	pointCloud = transform.doTransform(pointCloud);
	pointCloud.printPoints();

	cout << endl << endl << endl;

	//Set transform members
	transform.setTranslation(firstCameraTr);
	transform.setRotation(firstCameraRot);

	pointCloud2 = transform.doTransform(pointCloud2);
	pointCloud2.printPoints();

	cout << endl << endl << endl;


	//Sets transform for second camera
	transform.setTranslation(secondCameraTr);
	transform.setRotation(secondCameraRot);
	PointCloud pointCloud3(5);
	pointCloud3.setSinglePoint(0, 6, 1, 19);
	pointCloud3.setSinglePoint(1, 2, 99, 0);
	pointCloud3.setSinglePoint(2, 52, 2, 18);
	pointCloud3.setSinglePoint(3, 28, 28, 93);
	pointCloud3.setSinglePoint(4, 5, 42, 11);
	//Do transform for second camera and pointCloud3
	pointCloud3 = transform.doTransform(pointCloud3);
	pointCloud3.printPoints();

	cout << endl << endl << endl;
	//Sum two transformed PointCloud and print
	 pointCloud = pointCloud2 + pointCloud3;
	 pointCloud.printPoints();
}