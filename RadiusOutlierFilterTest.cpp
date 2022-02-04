/**
* @file RadiusOutlierFilterTest.h
* @author Olçan Satýr (152120171109)
* @date 13.01.2022
* @brief Test file of RadiusOutlierFilter class.
*
* This file is for testing purposes.
*/



#include "PointCloud.h"
#include "RadiusOutlierFilter.h"

using namespace std;


int main()
{
	PointCloud pointCloud;
	Point p(1, 1, 1);
	pointCloud.addElementToEnd(p);

	Point p1(4, 1, 10);
	pointCloud.addElementToEnd(p1);

	Point p2(100, 100, 100);
	pointCloud.addElementToEnd(p2);

	Point p3(2, 3, 0);
	pointCloud.addElementToEnd(p3);

	Point p4(56, 91, 2);
	pointCloud.addElementToEnd(p4); // it must be deleted

	Point p5(95, 97, 102);
	pointCloud.addElementToEnd(p5);

	Point p6(2,5,1);
	pointCloud.addElementToEnd(p6);

	Point p7(3, 4, 1);
	pointCloud.addElementToEnd(p7);


	RadiusOutlierFilter rof(15);
	rof.filter(pointCloud);
	pointCloud.printPoints();
}