#pragma once
/**
* @file Transform.h
* @author Ahmet Ata Þentürk (152120181120)
* @date 17.01.2022
* @brief Header of Transform class.
*
*	This file includes all the declarations of member variables and functions for Transform class.
*/

#include <iostream>
#include <cmath>
#include "Point.h"
#include "PointCloud.h"
#include "Eigen/Dense"
using namespace std;

//!  Transform class allows us to transforming proccess in single point or points cloud.
/*!
* It simply includes the process of converting the point or points taken from the cameras on two different planes to the base coordinate system.
*/
class Transform
{
private:
	Eigen::Vector3d angles; //!< Eigen::Vector3d angles member, it holds the rotation angles of camera
	Eigen::Vector3d trans; //!< Eigen::Vector3d trans member, it holds distance between the origins of two coordinate axes
	Eigen::Matrix4d transMatrix; //!< Eigen::Vector3d transMatrix member, created by processing according to certain equations, anglesand trans

public:

	/** First constructor for Transform class
	* It takes trans and angles array while creating
	* @param tr is distance between the origin of two coordinate axes as x, y, z in array.
	* @param ang is rotation angles of camera
	*/
	Transform(double tr[], double ang[]);

	/** Second constructor for Transform class
	* It takes trans and angles vector3d objects from the 'Eigen' library
	* @param tr is vector3d object that holds the distances between the origin of two coordinate axes as x, y, z in array.
	* @param ang is vector3d object that holds rotation angles of camera
	*/
	Transform(Eigen::Vector3d tr, Eigen::Vector3d ang);

	/** Last constructor for Transform class when does not take parameter
	* If it is not given trans and angles array as parameter, coordinate will be 0,0,0 and angles are all 0 for x, y, z
	*/
	Transform();

	/** Sets the trans array
	* @param tr is trans array
	*/
	void setTranslation(double tr[]);

	/** Sets the trans vector3d
	* @param tr is trans vector3d object
	*/
	void setTranslation(Eigen::Vector3d tr);

	/** Sets the angles array
	* @param ang is rotation array
	*/
	void setRotation(double ang[]);
	
	/** Sets the angles vector3d
	* @param ang is angles vector3d object
	*/
	void setRotation(Eigen::Vector3d ang);

	/** Do transform and convert point on two different coordinate to the base coordinate.
	* Creates a new point by matrix multiplication of the transformation matrix and the received point vector
	* @param p is the single point that is wanted to transform
	* @return the single point that is transformed
	*/
	Point doTransform(Point p);

	/** Do transform and convert points on two different coordinate to the base coordinate.
	* Creates a new point by matrix multiplication of the transformation matrix and the received point vector
	* It simply calls single point doTransform function for every points in pointCloud.
	* @param pc is the point cloud that is wanted to transform
	* @return the point cloud that is transformed
	*/
	PointCloud doTransform(PointCloud pc);

	/** Creates the transMatrix
	* Generates the transMatrix according to the rotation matrix generation equations for y,b,a
	*/
	void createTransMatrix();
};

