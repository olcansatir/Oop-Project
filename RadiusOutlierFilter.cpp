/**
* @file RadiusOutlierFilter.h
* @author Ol�an Sat�r (152120171109)
* @date 13.01.2022
* @brief Source file of RadiusOutlierFilter class.
*
*This file includes all the implementations declared in the RadiusOutlierFilter header file.
*/

#include "RadiusOutlierFilter.h"

void RadiusOutlierFilter::setRadius(double radius)
{
	this->radius = radius; //D��ar�dan gelen radiusu radiusa e�itle.
}

double RadiusOutlierFilter::getRadius()
{
	return radius;
}

void RadiusOutlierFilter::filter(PointCloud& pc)  //1. noktay� �rne�in 1.2.3.4.5'ye kar��la�t�r�yor radiustan k���kse tutuyor. 
{
	list<Point> points = pc.getAllPoints();
	list<Point>::iterator it; //liste kullanmam�z� istendi�i i�in. Bu pointin ba�lang�� adresini ite at�yor.
	list<Point>::iterator it2;  //it 2 de j dedi�imiz kar��la�t�rd��� noktalar�n tamam�.
	PointCloud filtered;
	bool admit = false;
	int loop = points.size();
	for (it = points.begin(); it != points.end(); ++it) //�lk kar��la�t�r�lacak nokta 1.nokta �rne�in. ilk nokta 2.noktaya e�it de�ilse kar��la�t�rcak bunu yapmazsa noktalar�n hepsi kal�r.Sonuncuda bitcek.
	{
		for (it2 = points.begin(); it2 != points.end(); ++it2)  //�lk noktan�n kar��la�t�r�ld��� noktalar. 1.2.3.4.5 le kar��la�t�r�yor.
		{
			if (it != it2) {                           //1 le 1i kar��la�t�r�rsa 0 2 yle 2 yi kar��la�t�rd�k hepsini al�rd� filtreleme yapmazd�. bu sebeple kendiyle kar��la�t�r�lmamas� laz�m.
				if (it->distance(*it2) <= radius) { //referans olarak ald�k ��nk� de�i�ti�inde her yerde de�i�mesi i�in. yap�lan de�i�ikli�in her yerde de�i�mesi i�in.
					admit = true;  // Burada radius tan k���k e�it mi diye kontrol ediyor e�er k���kse true d�nd�rerek addElementToEnd ile ekliyor.
				}
			}
		}
		if (admit == true) {
			filtered.addElementToEnd(*it); //Noktay� bu fonksiyonla i�eri at�yoruz.
		}
		admit = false;  //Yeni bir noktaya ge�mek i�in false yapt�k.
	}
	pc = filtered;   //pc'yi filtered'a e�itlik bu sayede az �nce g�nderdi�imiz pc de�i�ti.
}