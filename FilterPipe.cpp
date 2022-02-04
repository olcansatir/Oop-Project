/**
* @file FilterPipe.cpp
* @author Ol�an Sat�r (152120171109)
* @date 15.01.2022
* @brief Source file of FilterPipe class.
*
* This file includes all the implementations declared in the FilterPipe header file.
*/


#include "FilterPipe.h"

FilterPipe::FilterPipe()
{
}

void FilterPipe::addFilter(PointCloudFilter* filter)
{
	filters.push_back(filter);
}

void FilterPipe::filterOut(PointCloud& pc)
{
	for (int i = 0; i < filters.size(); i++) //ikisininde filter fonksiyonunu �a��r�yor. ilk olarak radiustan ge�iyor sonra filter 1 artt� passthrought filtresinden ge�ti
	{
		filters[i]->filter(pc);
	}
}

//Proje nokta ve noktabulutlar�n�n eylemlerinden olu�maktad�r. Kamera 1 ve kamera 2 farkl� koordinat ve a��lara sahiptir. Bu 2 farkl� noktadan okunan pointcloud� tek bir d�zlemde birle�tirmek.
//2 Point cloudu transform s�n�f�n� kullanarak tek bir d�zlemde birle�tiriyoruz. �zd���mlerini alarak tek bir d�zlemde topluyoruz.