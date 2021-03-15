#include <iostream>
using namespace std;

namespace test
{
	int a = 10;
}
 
int a = 10;
using namespace test;
int main()
{
	int a = 5;
	cout << a << endl;
	// bu halda biz bilmir ki hansi feyiseninin qiymetin vercek ona gorede biz 
	// namespace-den istifade edirik.
	cout << test::a << endl;
	// birdeki biz namespacelerden ona gore istifade ediriki misal namespacein 
	// daxilinde her hansi bir deyisen olsun funksiya olsun cagirimadan evvel 
	// using edib  cagiririq adinin qarsindan namespace-ni yazmaga ehtiyyac yoxdu.
	//  Beli ola biler ki hemin anda eyni adli qlobal deyishenimiz ola biler ve 
	// bizi casdira biler ona gorede hemin namespace-in adi yazilir.
	cout << a << endl;
	cout << test::a << endl;
}