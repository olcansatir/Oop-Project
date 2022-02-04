/**
* @file Point.h
* @author Olçan Satýr (152120171109)
* @date 02.01.2022
* @brief Header of point class.
*
*	This files holds the coordinates of the 3D points in the point cloud.
*/

#pragma once
#include <iostream>
#include <cmath>
using namespace std;

//! Point Class
 /*!
   The Point class performs tasks such as creating x, y, z points and assigning values to these points, reading the value, calculating the distance between the points and checking the equality status.

Point sýnýfý, x, y, z noktalarý oluþturma ve bu noktalara deðer atama, deðeri okuma, noktalar arasýndaki mesafeyi hesaplama ve eþitlik durumunu kontrol etme gibi görevleri gerçekleþtirir.
 */
class Point
{
private:
	double x; /*! define x coordinate */
	double y; /*! define y coordinate */
	double z; /*! define z coordinate */
public:
	/**
	* This function initializes the x, y, z coordinates.
	* It is a constructor function.
	* @param x: x-axis value of the point
	* @param y: y-axis value of the point
	* @param z: z-axis value of the point
	*/

	Point(double _x = 0, double _y = 0, double _z = 0) :x(_x), y(_y), z(_z) {}  //Ýlk oluþtururken pointe herhangi bir deðer vermezsek 0 almasý gerek.


	/**
	* This function returns the value of the x-axis.
	* @return: Returns the x-axis value of the point.
	*/
	double getX(); //X'i döndür
	/**
    * This function returns the value of the y-axis.
    * @return: Returns the y-axis value of the point.
    */
	double getY(); //Y'yi döndür

	/**
    *This function returns the value of the z-axis.
    * @return: Returns the z-axis value of the point.
    */
	double getZ();  //Z'yi döndür

	/**
	*This function assigns a value to the x-axis.
	* @param x: The x-axis value of the point
	*/
	void setX(double x);    //X leri deðiþtiriyor

	/**
	*This function assigns a value to the y-axis.
	* @param y: The y-axis value of the point
	*/
	void setY(double y);      //Y leri deðiþtiriyor

	/**
	*This function assigns a value to the z-axis.
	* @param z: The z-axis value of the point
	*/
	void setZ(double z);          //Z leri deðiþtiriyor

	/**
	*This function checks whether two points are equal to each other.
	* @param: It is a point type variable.
	* @return: Returns true or false based on equality.
	*/
	bool operator==(const Point&); //Ýki noktanýn birbirine eþit olup olmadýðýný kontrol eder.

	/**
	*This function calculates the distance between two points.
	* @param: It is a point type variable.
	* @return: Returns the distance between two points.
	*/
	double distance(const Point&) const; //

};
