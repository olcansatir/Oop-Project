/**
* @file Transform.cpp
* @author Ahmet Ata Þentürk (152120181120)
* @date 17.01.2022
* @brief Source file of Transform class.
*
*	This file includes all the implementations declared in the Transform header file.
*/

#include "Transform.h"
#include <iomanip>

Transform::Transform(double tr[], double ang[])
{
	for (int i = 0; i < 3; i++) {
		angles[i] = ang[i];
		trans[i] = tr[i];
	}
	createTransMatrix();

}

Transform::Transform(Eigen::Vector3d tr, Eigen::Vector3d ang)
{
	trans = tr;
	angles = ang;
	createTransMatrix();

}

Transform::Transform()
{
	for (int i = 0; i < 3; i++) {
		angles[i] = 0;
		trans[i] = 0;
	}
	createTransMatrix();
}

void Transform::setTranslation(double tr[])
{
	for (int i = 0; i < 3; i++) {
		trans[i] = tr[i];
	}
	createTransMatrix();
}

void Transform::setTranslation(Eigen::Vector3d tr)
{
	trans = tr;
}

void Transform::setRotation(double ang[])
{
	for (int i = 0; i < 3; i++) {
		angles[i] = ang[i];
	}
	createTransMatrix();
}

void Transform::setRotation(Eigen::Vector3d ang)
{
	angles = ang;
}

Point Transform::doTransform(Point p)
{
	double val = 0.0;
	Eigen::Vector4d vector;
	vector << p.getX(), p.getY(), p.getZ(), 1;

	Eigen::Vector4d result;

	result = transMatrix * vector;
	Point po(result(0), result(1), result(2));
	return po;
}

PointCloud Transform::doTransform(PointCloud pc)
{
	Point po;
	PointCloud pcResult(pc.getPointNumber());
	for (int i = 0; i < pc.getPointNumber(); i++)
	{
		po = doTransform(pc.getSinglePoint(i));
		pcResult.setSinglePoint(i, po.getX(), po.getY(), po.getZ());
	}

	return pcResult;
}

void Transform::createTransMatrix()
{
	double y = angles(0);
	double b = angles(1);
	double a = angles(2);
	transMatrix << cos(a) * cos(b),		(cos(a) * sin(b) * sin(y)) - (sin(a) * cos(y)),		 (cos(a) * sin(b) * cos(y) + (sin(a) * sin(y))), trans(0),
					sin(a)* cos(b),		(sin(a) * sin(b) * sin(y) + (cos(a) * cos(y))),		 (sin(a) * sin(b) * cos(y) - (cos(a) * sin(y))), trans(1),
					-sin(b),			 cos(b)* sin(y),									  cos(b)* cos(y),								 trans(2),
					   0,						0,														 0,										 1;
}