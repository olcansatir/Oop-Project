/**
* @file PointCloud.h
* @author Ahmet Ata Þentürk (152120181120)
* @date 17.01.2022
* @brief Header of PointCloud class.
*
*	This file includes all the declarations of member variables and functions for PointCloud class.
*/
#pragma once
#include <iostream>
#include <iomanip>
#include "Point.h"
#include <list>
#include <iterator>
using namespace std;

//!  PointCloud class is a cloud of the points and holds the array of Point objects.
/*!
 * Every PointCloud holds the points and this class allows us setting, getting and creating a cloud of points.
 * The size of the point array is also a member of the class
*/
class PointCloud
{
private:
	list<Point> points; //!< points member
public:

	/** Constructor for PointCloud class
	* If size is not given in parameter, size will be 0 for the points array.
	* @param size while creating the class, it allows us set the size.
	*/
	PointCloud(int size = 0);

	/** Returns the point number of the points array.
	* @return pointNumber, the size of the array.
	*/
	int getPointNumber() const;

	/** Sum two PointCloud and returns that.
	* @param pointCloud is a PointCloud object for summing.
	* @return the class that is summed.
	*/
	PointCloud operator+(PointCloud& pointCloud);

	/** This function returns single point at specific index.
	* @param i is the index that is wanted to return.
	* @return Point object at 'i' index.
	*/
	Point getSinglePoint(int i);

	/** This function allows us to print every point in the pointcloud.
	* prints the array formatted like x: , y: , z: .
	*/
	void printPoints();

	/** This function sets the point at specific index.
	* @param index is the index that is wanted to set.
	* @param x is the x value of the point.
	* @param y is the y value of the point.
	* @param z is the z value of the point.
	*/
	void setSinglePoint(int index, double x, double y, double z);

	/** Overload = operator to copy object.
	* @param pointCloud is the object that is wanted to copy.
	*/
	PointCloud operator=(const PointCloud& pointCloud);

	/** 
	* Sets the size of array of points
	*/
	void setPointNumber(int size);

	/** Adds the point to the end of the array of points
	* @param p is the point that must be added to the end of the points array
	*/
	void addElementToEnd(Point p);

	/** Deletes the point at specific index
	* @param index is the index of the point that is wanted to be removed
	*/
	void erasePoint(int index);

	/** Returns the all points in the point cloud
	* It basically returns the list of the points in this point cloud
	*/
	list<Point> getAllPoints();
};

