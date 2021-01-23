//include edilecekler
#include <iostream>
#include <Eigen/Dense>
#include <igl/sortrows.h>
#include <igl/sort.h>

#include <stdio.h>     
#include <stdlib.h>    
#include <time.h> 

//namespaceler
using namespace Eigen;
using namespace std;
using namespace igl;

int main(){
//1. soru 
int rnd;
srand(time(NULL));

Eigen::Matrix<int, 5, 8> a1;

for (int i = 0; i < a1.rows(); i++)
{
	for (int j = 0; j < a1.cols(); j++)
	{
		rnd = rand() % 100 + 1;
		a1(i, j) = rnd;
	}
}
std::cout << "Soru 1: 1 ile 100 arasinda rastgele tam sayilardan olusan 5x8 matris tanimlayiniz." << std::endl << std::endl << "matris: " << std::endl << a1 << std::endl << std::endl;

//2. soru
// C++ Eigen 1D veya 2D matris tanımlasına izin verir. 3 boyutlu matris tanımlamasına C++ Eigen de yapamayız.

std::cout << "C++ Eigen 1D veya 2D matris tanımlasına izin verir. 3 boyutlu matris tanımlamasına C++ Eigen de yapamayız." << std::endl << std::endl;
//3. soru 
Eigen::Matrix<int, 10, 10> a2;

for (int i = 0; i < a2.rows(); i++)
{
	for (int j = 0; j < a2.cols(); j++)
	{
		rnd = rand() % 100 + 1;
		a2(i, j) = rnd;
	}
}

int max = a2.maxCoeff();
int min = a2.minCoeff();

std::cout << "Soru 3: Rastgele degerlerle 10x10 luk bir dizi olusturun ve minimum-maksimum degerleri bulun." << std::endl << std::endl << "matris: " << std::endl << a2 << std::endl << std::endl << "Maksimum: " << max << std::endl << "Minimum: " << min << std::endl << std::endl;

//4.soru 

std::cout << "Soru 4: 5x3 matrisi 3x2 matrisle carpin. Bu matrislerin elemanlarini karsilikli olarak carpin." << std::endl << std::endl << "Matris boyutlari uyumlu olmadigindan karşılıklı carpim gerceklestirilemez." << std::endl << std::endl;

//5.soru
Eigen::Matrix<int, 10, 1> a5;

for (int i = 0; i < a5.rows(); i++)
{
	rnd = rand() % 100 + 1;
	a5(i) = rnd;
}
std::cout << "Soru 5: 10 boyutunda rastgele vektor olusturun ve maksimum degeri 0 ile degistirin." << std::endl << std::endl << "Vektor: " << std::endl << a5 << std::endl << std::endl;
int maks = a5.maxCoeff();
for (int i = 0; i < a5.rows(); i++)
{
	if (a5(i) == maks) {
		a5(i) = 0;
	}
}
std::cout << "Maksimum degeri 0 ile degistirildi." << std::endl << a5 << std::endl << std::endl;

//6. soru

Eigen::Matrix<int, 100, 150> MM;
for (int i = 0; i < MM.rows(); i++)
{
	for (int j = 0; j < MM.cols(); j++)
	{
		MM(i, j) = i + 1;
	}
}

std::cout << "Soru 6: 100x150 boyutlu bir matrisin her bir satirindaki degerleri satir numarasi olacak sekilde MM degiskeninde tanimlayiniz." << std::endl << std::endl << "MM matrisi: " << std::endl << MM << std::endl << std::endl;

//7.soru
std::cout << std::endl << std::endl << "Soru 7:  MM matrisinin dort parcaya bolundugunu dusunun. Sag alt kose (25x25) ile sol ust koseyi(25x25), sag ust kose(25x25) ile sol alt kosedeki(25x25) degerlerin yerini degistirin." << std::endl << std::endl;
Eigen::Matrix<int, 25, 25> bottomRightCorner;
bottomRightCorner << MM.bottomRightCorner<25, 25>();
MM.bottomRightCorner<25, 25>() = MM.topLeftCorner<25, 25>();
MM.topLeftCorner<25, 25>() = bottomRightCorner;

Eigen::Matrix<int, 25, 25> topRightCorner;
topRightCorner << MM.topRightCorner<25, 25>();
MM.topRightCorner<25, 25>() = MM.bottomLeftCorner<25, 25>();
MM.bottomLeftCorner<25, 25>() = topRightCorner;

std::cout << MM << std::endl << std::endl;

//8 soru 
std::cout << "Soru8: 10x10 bir matris icinde 1'den 100'e kadar rakamlari saklayin. Bu matrisinin transpozunu yine ayni degisken icerisinde saklayin. " << std::endl << std::endl;
Eigen::MatrixXd a8(10, 10);
int sayac = 1;
for (int i = 0; i < a8.rows(); i++)
{
	for (int j = 0; j < a8.cols(); j++)
	{
		a8(i, j) = sayac;
		sayac++;
	}
}

std::cout << "Matris: " << a8 << std::endl << std::endl;

a8.transposeInPlace();

std::cout << std::endl << "Matris transpose: " << std::endl << a8 << std::endl << std::endl;

//9 soru



//10 soru 
std::cout << "Soru 10:  100x100 rastgele sayilardan olusan bir matris icerisinde sifirdan kucuk degerleri pozitif degerleri ile degistirin." << std::endl << std::endl;
Eigen::MatrixXd a10(10, 10);

for (int i = 0; i < a10.rows(); i++)
{
	for (int j = 0; j < a10.cols(); j++)
	{
		rnd = rand() % 100 - 20;
		a10(i, j) = rnd;
	}
}
std::cout << "Matris: " << std::endl << a10 << std::endl << std::endl;

for (int i = 0; i < a10.rows(); i++)
{
	for (int j = 0; j < a10.cols(); j++)
	{
		if (a10(i, j) < 0)
		{
			a10(i, j) *= -1;
		}
	}
}

std::cout << "Matris in sifirdan kucuk degerleri pozitif yapilmis hali: " << std::endl << a10 << std::endl << std::endl;

//11soru 
std::cout << "Soru 11: 10x10 rastgele tam sayilardan olusan bir matrisin satirlarindaki degerleri siralayarak ayni matriste saklayiniz." << std::endl << std::endl;
Eigen::MatrixXd a11(10, 10);

for (int i = 0; i < a11.rows(); i++)
{
	for (int j = 0; j < a11.cols(); j++)
	{
		rnd = rand() % 10 + 1;
		a11(i, j) = rnd;
	}
}

std::cout << "Matris: " << std::endl << std::endl << a11 << std::endl << std::endl;

igl::sort(a11, 2, true, a11);

std::cout << "Sirali matris:\n\n" << a11;
}