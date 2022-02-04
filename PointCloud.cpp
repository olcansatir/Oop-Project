/**
* @file PointCloud.cpp
* @author Ahmet Ata Þentürk (152120181120)
* @date 17.01.2022
* @brief Source file of PointCloud class.
*
*	This file includes all the implementations declared in the PointCloud header file.
*/

#include "PointCloud.h"

PointCloud::PointCloud(int size)
{
	for (int i = 0; i < size; i++)
	{
		Point point;
		points.push_back(point);
	}
}

int PointCloud::getPointNumber() const
{
	return points.size();

}

PointCloud PointCloud::operator+(PointCloud& pointCloud)
{
	int size = points.size() + pointCloud.getPointNumber();
	PointCloud pointCl(size);
	std::list<Point>::iterator it = pointCl.points.begin();


	for (int i = 0; i < points.size(); i++) {
		*it = getSinglePoint(i);
		it++;
	}
	int k = 0;

	it = pointCl.points.begin();
	for (int i = 0; i < points.size(); i++) {
		it++;
	}
	std::list<Point>::iterator it2 = pointCloud.points.begin();

	for (int i = points.size(); i < size; i++) {
		*it = *it2;
		it++;
		it2++;
	}
	return pointCl;
}

Point PointCloud::getSinglePoint(int i)
{
	try 
	{
		if (i >= 0 && i < points.size()) {
			list<Point>::iterator it = points.begin();
			advance(it, i);
			return *it;
		}

	}
	catch (exception ex) {
		throw ex.what();
	}
}

void PointCloud::printPoints()
{
	list<Point>::iterator it;
	cout << "Points" << endl;
	if (points.size() > 0) {
		for (it = points.begin(); it != points.end(); ++it) {
			cout << setw(5) << setprecision(5) << "x:" << it->getX() << setw(5) << setprecision(5) << "y:" << it->getY() << setw(5) << setprecision(5) << "z:" << it->getZ() << endl;
		}
	}
	else cout << "There is no Point in this Point Cloud" << endl;
	
}

void PointCloud::setSinglePoint(int index, double x, double y, double z)
{
	if (index < points.size()) {
		std::list<Point>::iterator it = points.begin();
		advance(it, index);
		it->setX(x);
		it->setY(y);
		it->setZ(z);
	}
	else {
		cout << "Index "<< index <<" is out of range\n";
		return;
	}
}

PointCloud PointCloud::operator=(const PointCloud& copyPointCloud)
{
	PointCloud tempPc = copyPointCloud;
	try {
		points.clear();
		list<Point>::iterator it = tempPc.points.begin();
		for (it = tempPc.points.begin(); it != tempPc.points.end(); ++it) {
			points.push_back(*it);
		}
	}
	
	catch (bad_array_new_length) {
		cout << "This object is already created\n";
	}
	return *this;
}

void PointCloud::setPointNumber(int size)
{
	points.clear();
	for (int i = 0; i < size; i++)
	{
		Point point;
		points.push_back(point);
	}
}

void PointCloud::addElementToEnd(Point p)
{
	points.push_back(p);
}

void PointCloud::erasePoint(int index)
{
	if (index < points.size()) {
		list<Point>::iterator it = points.begin();
		advance(it, index);
		points.erase(it);
	}
	else cout << "There is no point at intex: " << index << endl;

}

list<Point> PointCloud::getAllPoints()
{
	return points;
}
