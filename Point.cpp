/**
* @file Point.cpp
* @author Ol�an Sat�r (152120171109)
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
	this->x = x;  //D��ardan gelen xi xe e�itle.
}

void Point::setY(double y)
{
	this->y = y; 
}

void Point::setZ(double z)
{
	this->z = z;
}

bool Point::operator==(const Point& point)   // De�i�tirmez yine. do�ruysa true de�ilse false parametre gelen xle i�inde bulunulan objenin xi e�itmi ye bak�yoruz asl�nda e�er e�itse return true.)
{
	return (x == point.x && y == point.y && z == point.z) ? true : false;
}

double Point::distance(const Point& point) const //const Point - D��ar�dan gelen parametreyi de�i�tiremiyoruz. De�i�tirmemek i�in. Kat� kod i�in. (��erdeki const i�inde bulundu�umuz objeyi de�i�tirmemek i�in.)
{
	return sqrt(pow((x - point.x), 2) + pow((y - point.y), 2) + pow((z - point.z), 2));   //Burada ikisi aras�ndaki mesafeyi hesapl�yoruz. cmath k�t�phanesini kulland�k.
}
