/**
* @file RadiusOutlierFilter.h
* @author Olçan Satýr (152120171109)
* @date 13.01.2022
* @brief Source file of RadiusOutlierFilter class.
*
*This file includes all the implementations declared in the RadiusOutlierFilter header file.
*/

#include "RadiusOutlierFilter.h"

void RadiusOutlierFilter::setRadius(double radius)
{
	this->radius = radius; //Dýþarýdan gelen radiusu radiusa eþitle.
}

double RadiusOutlierFilter::getRadius()
{
	return radius;
}

void RadiusOutlierFilter::filter(PointCloud& pc)  //1. noktayý örneðin 1.2.3.4.5'ye karþýlaþtýrýyor radiustan küçükse tutuyor. 
{
	list<Point> points = pc.getAllPoints();
	list<Point>::iterator it; //liste kullanmamýzý istendiði için. Bu pointin baþlangýç adresini ite atýyor.
	list<Point>::iterator it2;  //it 2 de j dediðimiz karþýlaþtýrdýðý noktalarýn tamamý.
	PointCloud filtered;
	bool admit = false;
	int loop = points.size();
	for (it = points.begin(); it != points.end(); ++it) //Ýlk karþýlaþtýrýlacak nokta 1.nokta örneðin. ilk nokta 2.noktaya eþit deðilse karþýlaþtýrcak bunu yapmazsa noktalarýn hepsi kalýr.Sonuncuda bitcek.
	{
		for (it2 = points.begin(); it2 != points.end(); ++it2)  //Ýlk noktanýn karþýlaþtýrýldýðý noktalar. 1.2.3.4.5 le karþýlaþtýrýyor.
		{
			if (it != it2) {                           //1 le 1i karþýlaþtýrýrsa 0 2 yle 2 yi karþýlaþtýrdýk hepsini alýrdý filtreleme yapmazdý. bu sebeple kendiyle karþýlaþtýrýlmamasý lazým.
				if (it->distance(*it2) <= radius) { //referans olarak aldýk çünkü deðiþtiðinde her yerde deðiþmesi için. yapýlan deðiþikliðin her yerde deðiþmesi için.
					admit = true;  // Burada radius tan küçük eþit mi diye kontrol ediyor eðer küçükse true döndürerek addElementToEnd ile ekliyor.
				}
			}
		}
		if (admit == true) {
			filtered.addElementToEnd(*it); //Noktayý bu fonksiyonla içeri atýyoruz.
		}
		admit = false;  //Yeni bir noktaya geçmek için false yaptýk.
	}
	pc = filtered;   //pc'yi filtered'a eþitlik bu sayede az önce gönderdiðimiz pc deðiþti.
}