/**
* @file PointTest.cpp
* @author Olçan Satýr (152120171109)
* @date 20.12.2021
* @brief Test file of point class.
*
* This file is for testing purposes.
*/


#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	Point point1(2, 3, 4);    //point yarattýk 
	Point point2(2, 6, 4);            //2 nesneyi karþýlaþtýrmak için x,y,z nin eþit olmasý için overload yaptýk.
	if (point1 == point2) {
		cout << "point1 and point2 is equal" << endl;
	}
	else {
		cout << "point1 and point2 is not equal" << endl;
	}

	Point point3(2, 3, 4);
	if (point1 == point3) {
		cout << "point1 and point3 is equal" << endl;
	}
	else {
		cout << "point1 and point3 is not equal" << endl;
	}

	Point point4(1, 6, 8);
	Point point5(6, 9, 3);
	cout << "Distance between point4 and point5 :  " << point4.distance(point5) << endl;  //Point 4'ün distanceýný çaðýr point 5 ver. Point 4 ve 5 arasýndaki mesafeyi döndürüyor.

	point1.setX(1); //2,3,4 olan koordinatlarý 1,6,8 ile deðiþtirdik.
	point1.setY(6);
	point1.setZ(8);

	cout << point1.getX() << " " << point1.getY() << " " << point1.getZ() << endl;  //burada bastýrdýk.

	if (point1 == point4) {
		cout << "point1 and point4 is equal" << endl; //Point1 Point4'e eþit eþit mi overload neden kullandýk? nesneleri karþýlaþtýramadýðýmýz için overload kullandýk.
	}
	else {
		cout << "point1 and point4 is not equal" << endl;
	}


}