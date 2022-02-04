/**
* @file PointCloudFilter.h
* @author Olçan Satýr (152120171109)
* @date 15.01.2022
* @brief Header of PointCloudFilter class.
*
* This file is used to implement depth camera functions.
*/

//Bu dosya, derinlik kamerasý iþlevlerini uygulamak için kullanýlýr.
//iki filtre için arayüz oluþturuyor.
#pragma once
#include "PointCloud.h"
class PointCloudFilter
{


public:
	/**
    * This function acts as an abstract class for RadiusOutlier and PassThrought. These two filter classes inherit from this and must write the content of this function.
    * @param pc: Retrieves the point cloud value to be filtered.
    */
	virtual void filter(PointCloud& pc) = 0; //This function is a pure virtual function. //run time polimorfizm çalýþma anýnda karar veriyor.
}; 
//Bu iþlev, RadiusOutlier ve PassThrought için soyut bir sýnýf görevi görür.Bu iki filtre sýnýfý bundan miras alýr ve bu iþlevin içeriðini yazmalýdýr.

//Buradan miras alan her class