/**
* @file FilterPipe.h
* @author Ol�an Sat�r (152120171109)
* @date 15.01.2022
* @brief Header of FilterPipe class.
*
* This file is used to implement depth camera functions.
*/


//Birden fazla filtreden ge�mesi noktan�n filtreleme i�lemini yapar.
#pragma once
#include "PointCloud.h"
#include "PointCloudFilter.h"
#include <vector>
class FilterPipe
{
private:
	vector<PointCloudFilter*> filters;  //FilterPipeda tek bir tipte toplad�k.
public:
    FilterPipe();
	/**
	* This function adds the objects of the function to the vector.
	* @param filter: Retrieves the object of the filter to add.
	*/
    void addFilter(PointCloudFilter* filter); //fonksiyonun nesnelerini vekt�re ekler.

    /**
	* This function applies the filters thrown to the vector to the incoming point cloud points.
	* @param pc: Retrieves the point cloud to which filters will be applied.
	*/
    void filterOut(PointCloud& pc);  //vekt�re at�lan filtreleri gelen nokta bulutuna uyguluyor.
};

