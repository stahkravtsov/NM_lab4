#ifndef LAB4_H
#define LAB4_H

void SwapLineKandP(double** M, int n, double b[], int k, int p);
 
void Straight(double** M, int n, double b[]);

void LineAdd(double** M, int n, double b[], int k);

void Reverse(double** M, int n, double b[], double ans[]);

void LUDecomposition(double** M, int n, double** L, double** U);

void FillZero(double** M, int n);

void LUStraight(double** M, int n, double b[], double ans[]);

void Gaus(double** MM, int n, double b[]);

void LUMethod(double** MM, int n, double b[]);

void PrintMinus(char a);

void CopyMatrix(double** M, double** N, int n);

void FillFromConsole(double** M, int n);

void FillMember(double b[], int n, int isDefolt);

#endif // !LAB4_H
