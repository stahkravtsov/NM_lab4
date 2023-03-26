#include <iostream>
#include "D:\NGR\лаби ЧМ\lab_3\lab03\lab3.h"
#include "lab4.h"
using namespace std;

int main()
{
		double** M;
		int n = 3, isDefolt = 1;
		cout << "Use defolt matrix? (1 - YES, 0 - NO)" << endl;
		int a;
		cin >> a;
		if (a == 1) {
				M = FillStartM();
				
		}
		else
		{
				cout << "Enter size of matrix: ";
				cin >> n;
				M = NewM(n);
				cout << "Enter matrix" << endl;
				FillFromConsole(M, n);
				cout << "Ener column of free members:" << endl;
				isDefolt = 0;
		}
		double b[100];
		FillMember(b, n, isDefolt);
		Gaus(M, n, b);
		LUMethod(M, n, b);
}
