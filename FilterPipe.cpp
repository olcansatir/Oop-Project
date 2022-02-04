/**
* @file FilterPipe.cpp
* @author Olçan Satýr (152120171109)
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
	for (int i = 0; i < filters.size(); i++) //ikisininde filter fonksiyonunu çaðýrýyor. ilk olarak radiustan geçiyor sonra filter 1 arttý passthrought filtresinden geçti
	{
		filters[i]->filter(pc);
	}
}

//Proje nokta ve noktabulutlarýnýn eylemlerinden oluþmaktadýr. Kamera 1 ve kamera 2 farklý koordinat ve açýlara sahiptir. Bu 2 farklý noktadan okunan pointcloudý tek bir düzlemde birleþtirmek.
//2 Point cloudu transform sýnýfýný kullanarak tek bir düzlemde birleþtiriyoruz. Ýzdüþümlerini alarak tek bir düzlemde topluyoruz.