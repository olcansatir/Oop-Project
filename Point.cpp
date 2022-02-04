/**
* @file Point.cpp
* @author Olçan Satýr (152120171109)
* @date 20.12.2021
* @brief Source file of point class.
*
* This file includes all the implementations declared in the Point header file.
*/


#include "Point.h""

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

double Point::getZ()
{
	return z;
}

void Point::setX(double x)
{
	this->x = x;  //Dýþardan gelen xi xe eþitle.
}

void Point::setY(double y)
{
	this->y = y; 
}

void Point::setZ(double z)
{
	this->z = z;
}

bool Point::operator==(const Point& point)   // Deðiþtirmez yine. doðruysa true deðilse false parametre gelen xle içinde bulunulan objenin xi eþitmi ye bakýyoruz aslýnda eðer eþitse return true.)
{
	return (x == point.x && y == point.y && z == point.z) ? true : false;
}

double Point::distance(const Point& point) const //const Point - Dýþarýdan gelen parametreyi deðiþtiremiyoruz. Deðiþtirmemek için. Katý kod için. (Ýçerdeki const içinde bulunduðumuz objeyi deðiþtirmemek için.)
{
	return sqrt(pow((x - point.x), 2) + pow((y - point.y), 2) + pow((z - point.z), 2));   //Burada ikisi arasýndaki mesafeyi hesaplýyoruz. cmath kütüphanesini kullandýk.
}
