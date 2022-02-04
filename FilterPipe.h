/**
* @file FilterPipe.h
* @author Olçan Satýr (152120171109)
* @date 15.01.2022
* @brief Header of FilterPipe class.
*
* This file is used to implement depth camera functions.
*/


//Birden fazla filtreden geçmesi noktanýn filtreleme iþlemini yapar.
#pragma once
#include "PointCloud.h"
#include "PointCloudFilter.h"
#include <vector>
class FilterPipe
{
private:
	vector<PointCloudFilter*> filters;  //FilterPipeda tek bir tipte topladýk.
public:
    FilterPipe();
	/**
	* This function adds the objects of the function to the vector.
	* @param filter: Retrieves the object of the filter to add.
	*/
    void addFilter(PointCloudFilter* filter); //fonksiyonun nesnelerini vektöre ekler.

    /**
	* This function applies the filters thrown to the vector to the incoming point cloud points.
	* @param pc: Retrieves the point cloud to which filters will be applied.
	*/
    void filterOut(PointCloud& pc);  //vektöre atýlan filtreleri gelen nokta bulutuna uyguluyor.
};

