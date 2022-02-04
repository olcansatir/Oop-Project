/**
* @file PointCloudFilter.h
* @author Ol�an Sat�r (152120171109)
* @date 15.01.2022
* @brief Header of PointCloudFilter class.
*
* This file is used to implement depth camera functions.
*/

//Bu dosya, derinlik kameras� i�levlerini uygulamak i�in kullan�l�r.
//iki filtre i�in aray�z olu�turuyor.
#pragma once
#include "PointCloud.h"
class PointCloudFilter
{


public:
	/**
    * This function acts as an abstract class for RadiusOutlier and PassThrought. These two filter classes inherit from this and must write the content of this function.
    * @param pc: Retrieves the point cloud value to be filtered.
    */
	virtual void filter(PointCloud& pc) = 0; //This function is a pure virtual function. //run time polimorfizm �al��ma an�nda karar veriyor.
}; 
//Bu i�lev, RadiusOutlier ve PassThrought i�in soyut bir s�n�f g�revi g�r�r.Bu iki filtre s�n�f� bundan miras al�r ve bu i�levin i�eri�ini yazmal�d�r.

//Buradan miras alan her class