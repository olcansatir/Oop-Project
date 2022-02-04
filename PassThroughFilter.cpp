/***
* @file PassThroughFilter.cpp
* @author Kýsmet AKTAÞ (152120191088)
* @date 27.12.2021
* @brief Source file of PassThroughFilter class.
*
**	This file includes all the implementations declared in the PassThroughFilter header file.
*/

#include<iostream>
#include "PassThroughFilter.h"
#include"PointCloud.h"

using namespace std;

PassThroughFilter::PassThroughFilter(double upLX, double lowLX, double upLY,
	double lowLY, double upLZ, double lowLZ) {

	upperLimitX = upLX;
	lowerLimitX = lowLX;
	upperLimitY = upLY;
	lowerLimitY = lowLY;
	upperLimitZ = upLZ;
	lowerLimitZ = lowLZ;
}
void PassThroughFilter::setLimitX(double upperLimitX, double lowerLimitX) {

	this->upperLimitX = upperLimitX;
	this->lowerLimitX = lowerLimitX;
}
void PassThroughFilter::setLimitY(double upperLimitY, double lowerLimitY) {

	this->upperLimitY = upperLimitY;
	this->lowerLimitY = lowerLimitY;
}
void PassThroughFilter::setLimitZ(double upperLimitZ, double lowerLimitZ) {

	this->upperLimitZ = upperLimitZ;
	this->lowerLimitZ = lowerLimitZ;
}
void PassThroughFilter::filter(PointCloud& pc) {

	int newSize = 0;
	for (int i = 0; i < pc.getPointNumber(); i++)
	{
		Point p = pc.getSinglePoint(i);
		if (p.getX() <= upperLimitX && p.getX() >= lowerLimitX && p.getY() >= lowerLimitY && p.getY() <= upperLimitY && p.getZ() <= upperLimitZ && p.getZ() >= lowerLimitZ) {
			newSize++;
		}
	}
	PointCloud filtered(newSize);
	newSize = 0;
	for (int i = 0; i < pc.getPointNumber(); i++)
	{
		Point p = pc.getSinglePoint(i);
		if (p.getX() <= upperLimitX && p.getX() >= lowerLimitX && p.getY() >= lowerLimitY && p.getY() <= upperLimitY && p.getZ() <= upperLimitZ && p.getZ() >= lowerLimitZ) {
			filtered.setSinglePoint(newSize, p.getX(), p.getY(), p.getZ());
			newSize++;
		}
	}
	pc = filtered;
}