/**
* @file RadiusOutlierFilterTest.h
* @author Olçan Satır (152120171109)
* @date 13.01.2022
* @brief Header file of RadiusOutlierFilter class.
*
* The task of this file is to filter the data in Pointcloud according to radius and throw it into pointcloud.
*/


//RadiusOutlier her bir noktanın 25 yarıçaplık bir top oluşturuyor eğer o 25 yarıçap içinde bir nokta yok ise onu çıkartıyor.
//Bu dosyanın görevi Pointcloud'daki verileri yarıçapa göre filtrelemek ve pointcloud'a atmaktır.

#pragma once
#include<iostream>
#include"PointCloud.h"
#include"PointCloudFilter.h"
using namespace std;
//! RadiusOutlierFilter class.
/*!
*This class assigns radius filtered values ​​to point cloud.
*/

class RadiusOutlierFilter : public PointCloudFilter
{
private:
	double radius; //! @param radius: Radius value(double data type)

public:
	/** A constuructor. // kendi sınıfı ile aynı isme sahip
	* While creating the task of this function, it takes radius and makes this radius its own radius.
	* @param _radius: Radius value to be used in filtering(double data type)
	*/
	RadiusOutlierFilter(double _radius) :radius(_radius) {}  //radius alıyor. Sıfır alamaz. Bir yarıçap değeri alır ve bu yarıçapı kendi yarıçapı yapar.

	/**
	* This function assigns the value to be used in filtering to radius.
	* @param radius: Radius value
	*/
	void setRadius(double radius);   //filtrelemede Kullanılacak yarıçapı alır.

	/**
	* This function returns radius(double data type).
	* @return: Returns the radius value.
	*/
    double getRadius();   //radius değerini dönderir.
    
	/**
    * This function filters the received values by radius.
    * @param pc: PointCloud object.
    */
	void filter(PointCloud& pc);
	//alınan değerleri yarıçapa göre filtreleme işlemi yapar.
};


