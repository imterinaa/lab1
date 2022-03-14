#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;




int main()
{
	setlocale(LC_ALL, "ru");


	TPolinom p1;
	p1.AddMonom(TMonom(1, 1, 2, 3));
	p1.AddMonom(TMonom(1, 1, 1, 1));
	cout << "p1 = ";
	cout << p1 << endl;


	TPolinom p2;
	p2.AddMonom(TMonom(1, 1, 2, 3));
	p2.AddMonom(TMonom(-1, 1, 1, 1));
	cout << "P2 = "; cout << p2 << endl;
	cout << "P1 + P2 = " << (p1 + p2) << endl;

	cout << "\nP2 * 2 = " << (p2 * 2) << endl;
	cout << "P2 * 2x^2y^2z^2 = " << (p2.MultMonom(TMonom(2, 2, 2, 2))) << endl;
	cout << "P1 * P2 = " << (p1 * p2) << endl;

	cout << "¬ведите полином" << endl;
	TPolinom p4;
	cin >> p4;

	cout << "P4 + P2  = " << p4 + p2 << endl;
	

}