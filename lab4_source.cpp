#include <iostream>
#include <math.h>
#include "D:\NGR\כאבט ׳ּ\lab_3\lab03\lab3.h"
#include "lab4.h"
using namespace std;

void Straight(double** M, int n, double b[]) {

		int ColumnMax = 0, ColumnIdMax = 0;
		for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {

						if (i == j) {
								ColumnMax = fabs(M[j][i]);
								ColumnIdMax = j;
						}

						if (ColumnMax < fabs(M[j][i])) {
								ColumnMax = fabs(M[j][i]);
								ColumnIdMax = j;
						}
				}
				SwapLineKandP(M, n, b, i, ColumnIdMax);
				cout << "After swapping, step " << i << endl;
				PrintM(M, 3);
				cout << endl << "After adding" << endl;
				LineAdd(M, n, b, i);
				PrintM(M, 3);
				cout << endl;
		}
		return;
}

void SwapLineKandP(double** M, int n, double b[], int k, int p) {
		double c = b[k];
		b[k] = b[p];
		b[p] = c;
		double* a = M[k];
		M[k] = M[p];
		M[p] = a;
		return;
}

void LineAdd(double** M, int n, double b[], int k) {

		for (int i = k + 1; i < n; i++) {
				double K = M[i][k] / M[k][k];
				for (int j = k; j < n; j++) {
						M[i][j] -= (M[k][j] * K);
				}
				b[i] -= (b[k] * K);
		}
}

void Reverse(double** M, int n, double b[], double ans[]) {
		for (int i = n - 1; i >= 0; i--) {

				for (int j = i + 1; j < n; j++) {
						b[i] -= M[i][j] * ans[j];
				}
				ans[i] = b[i] / M[i][i];
		}
}

void LUDecomposition(double** M, int n, double** L, double** U) {
		for (int i = 0; i < n; i++) L[i][0] = M[i][0];
		for (int i = 0; i < n; i++) U[i][i] = 1;
		for (int i = 1; i < n; i++) U[0][i] = (M[0][i] / (M[0][0]));

		for (int i = 1; i < n; i++) {
				for (int j = i; j < n; j++) {
						double Product = 0;
						for (int k = 0; k < i; k++)
						{
								Product += (L[j][k] * U[k][i]);
						}
						L[j][i] = (M[j][i] - Product);
				}

				for (int j = i + 1; j < n; j++) {
						double Product = 0;
						for (int k = 0; k < i; k++)
						{
								Product += (L[i][k] * U[k][j]);
						}
						U[i][j] = (1 / L[i][i]) * (M[i][j] - Product);
				}
		}
}

void FillZero(double** M, int n)
{
		for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
						M[i][j] = 0;
}

void LUStraight(double** M, int n, double b[], double ans[]) {
		for (int i = 0; i < n; i++) {
				for (int j = i - 1; j >= 0; j--) {
						b[i] -= M[i][j] * ans[j];
				}
				ans[i] = b[i] / M[i][i];
		}
}

void Gaus(double** MM, int n, double bb[]) {
		cout << "GAUS METHOD" << endl << endl;
		double** M = NewM(n);
		double b[100];
		for (int i = 0; i < n; i++) b[i] = bb[i];
		CopyMatrix(M, MM, n);
		double ans[100] = {};
		cout << "Start matrix" << endl;
		PrintM(M, n);
		cout << endl << endl << "STRAIGHT MOVE" << endl;
		PrintMinus('+');
		Straight(M, n, b);
		PrintMinus('+');
		cout << endl << "Tringle matrix" << endl;
		PrintM(M, n);
		cout << endl;
		Reverse(M, n, b, ans);

		FreeM(M, n);
		cout << "Answers" << endl;
		for (int i = 0; i < n; i++)
		{
				cout << ans[i] << endl;
		}
		cout << endl;
}

void LUMethod(double** MM, int n, double b[]) {
		PrintMinus('-');
		cout << "LU METHOD" << endl << endl;
		double** M = NewM(n);
		CopyMatrix(M, MM, n);
		double Lans[100] = {}, Uans[100] = {};
		double** L = NewM(n);
		double** U = NewM(n);
		FillZero(L, n);
		FillZero(U, n);

		cout << endl << "Start matrix" << endl;
		PrintM(M, n);

		LUDecomposition(M, n, L, U);
		FreeM(M, n);
		cout << endl << endl << "L matrix" << endl;
		PrintM(L, n);

		cout << endl << endl << "U matrix" << endl;
		PrintM(U, n);
		cout << endl;


		LUStraight(L, n, b, Lans);
		cout << "Y = " << endl;
		for (int i = 0; i < n; i++)
		{
				cout << Lans[i] << endl;
		}
		cout << endl;

		Reverse(U, 3, Lans, Uans);

		cout << "Answers" << endl;
		for (int i = 0; i < n; i++)
		{
				cout << Lans[i] << endl;
		}
		cout << endl;

		FreeM(U, n);
		FreeM(L, n);
}

void PrintMinus(char a)
{
		for (int i = 0; i < 25; i++)
		{
				cout << a;
		}
		cout << endl;
}

void CopyMatrix(double** M, double** N, int n) {
		for (int i = 0; i < n; i++)
		{
				for (int j = 0; j < n; j++)
				{
						M[i][j] = N[i][j];
				}
		}
}

void FillFromConsole(double** M, int n) {
		for (int i = 0; i < n; i++)
		{
				for (int j = 0; j < n; j++)
				{
						cin >> M[i][j];
				}
		}
}

void FillMember(double b[], int n, int isDefolt) {
		if (isDefolt == 1) {
				b[0] = 1.32;
				b[1] = -0.44;
				b[2] = 0.64;
		}
		else
		{
				for (int i = 0; i < n; i++)
				{
						cin >> b[i];
						cout << endl;
				}
		}
}