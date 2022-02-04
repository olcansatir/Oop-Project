/**
* @file PointCloudTest.cpp
* @author Ahmet Ata Þentürk (152120181120)
* @date 18.12.2021
* @brief Test file of PointCloud class.
*
*	This file is for testing purposes.
*/

#include <iostream>
#include "PointCloud.h"
#include <list>
#include <iterator>
using namespace std;

int main()
{
	//Implementing point cloud using add element to the end function
	PointCloud pointCloud;
	Point p(3, 8, 1);
	pointCloud.addElementToEnd(p);
	Point p1(4, 1, 10);
	pointCloud.addElementToEnd(p1);
	Point p2(12, 42, 9);
	pointCloud.addElementToEnd(p2);
	Point p3(28, 8, 0);
	pointCloud.addElementToEnd(p3);
	Point p4(3, 16, 11);
	pointCloud.addElementToEnd(p4);

	//Implementing point cloud using set single point function
	PointCloud pointCloud2(3);
	pointCloud2.setSinglePoint(0, 1, 6, 11);
	pointCloud2.setSinglePoint(1, 9, 27, 16);
	pointCloud2.setSinglePoint(2, 61, 0, 19);

	//Realization of + and = operator for point clouds
	PointCloud pointCloud3 = pointCloud + pointCloud2;

	//Printing the summed points
	pointCloud3.printPoints();

	cout << endl << endl << endl;

	PointCloud pointCloud4;
	pointCloud4.printPoints();

	cout << endl << endl << endl;

	pointCloud4 = pointCloud;
	
	//Realization of get all points function
	list<Point> points = pointCloud4.getAllPoints();
	list<Point>::iterator it;
	for (it = points.begin(); it != points.end(); ++it) {
		cout << it->getX() << " " << it->getY() << " " << it->getZ() << endl;
	}
	cout << endl << endl;

	//Erase point at index 2
	pointCloud4.erasePoint(2);
	
	//Erase point at index 4. Note: Exception::There is no point at index 4!
	pointCloud4.erasePoint(4);
	pointCloud4.printPoints();

	cout << endl << endl;


	cout << pointCloud4.getSinglePoint(1).distance(pointCloud4.getSinglePoint(2));

	cout << endl << endl << endl;
}
