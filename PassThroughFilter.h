/**
* @file PassThroughFilter.h
* @author Kýsmet AKTAÞ (152120191088)
* @date 27.12.2021
* @brief Header of class PassThroughFilter class.
*
* This file includes all the declarations of member variables and functions for class PassThroughFilter class.
*/

#pragma once
#include<iostream>
#include"PointCloud.h"

using namespace std;

//!  The PassThroughFilter class filters on the point cloud. With the filter function
/*!
*	it takes the point cloud and returns its filtered form. In this filtering process,
*	if at least one of the x, y and z values of the point is outside the limits,
*	that point is removed from the point cloud
*/
class PassThroughFilter
{
private:
	double upperLimitX;
	double lowerLimitX;
	double upperLimitY;
	double lowerLimitY;
	double upperLimitZ;
	double lowerLimitZ;

public:

	/**	Constructor for PassThroughFilter class.
	* @param upLX allows us to define the upper bound of the X coordinate when creating the class.
	* @param lowLX allows us to define the lower bound of the X coordinate when creating the class.
	* @param upLY allows us to define the upper bound of the Y coordinate when creating the class.
	* @param lowLY allows us to define the lower bound of the Y coordinate when creating the class.
	* @param upLZ allows us to define the upper bound of the Z coordinate when creating the class.
	* @param lowLZ allows us to define the lower bound of the Z coordinate when creating the class.
	*/
	PassThroughFilter(double upLX=0, double lowLX=0, double upLY=0,	double lowLY=0, double upLZ=0, double lowLZ=0);

	/**	
	* This function sets the lower and upper limit values of the X coordinate.
	* @param upperLimitX is the upper limit of the X coordinate values.
	* @param lowerLimitX is the lower limit of the X coordinate values. 
	*/
	void setLimitX(double upperLimitX,double lowerLimitX);

	/**
	* This function sets the lower and upper limit values of the Y coordinate.	
	* @param upperLimitY is the upper limit of the Y coordinate values.
	* @param lowerLimitY is the lower limit of the Y coordinate values.
	*/
	void setLimitY(double upperLimitY, double lowerLimitY);

	/**	
	* This function sets the lower and upper limit values of the Z coordinate.	
	* @param upperLimitZ is the upper limit of the Z coordinate values.
	* @param lowerLimitZ is the lower limit of the Z coordinate values.
	*/
	void setLimitZ(double upperLimitZ, double lowerLimitZ);

	/*	
	* This function returns the point cloud that comes to it as a parameter by filtering.		
	* @param pc is the filtered version of the point cloud that comes as a parameter.
	*/
	void filter(PointCloud& pc);
};

