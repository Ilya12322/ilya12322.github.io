//#include<iostream>
//#include<vector>
//#include<cmath>
//
//using namespace std;
//
//double fun(const double& x) // записываетс€ сама функци€ 
//{
//	return 2 * x * x * x * x * x + x * x * x * x - 2 * x * x * x;
//	//  3 * x * x * x * x - 2 * x * x * x - 5;
//}
//
//double fun_SUM(double Xi, const double& h, const int& n, const int& i)
//{
//	double sum_f_Xi = 0;
//	if (i == 0) {
//		for (int i = 1; i <= n; i++)
//		{
//			sum_f_Xi += fun(Xi);
//			Xi += h;
//		}
//	}
//	else if (i == 1) {
//		for (int i = 1; i <= n; i += 2)
//		{
//			sum_f_Xi += fun(Xi);
//			Xi += 2 * h;
//		}
//	}
//	else if (i==2)
//	{
//		for (int i = 2; i <= n; i += 2)
//		{
//			Xi += h;
//			sum_f_Xi += fun(Xi);
//			Xi += h;
//		}
//
//	}
//	return sum_f_Xi;
//}
//
//double fun_PR(const double& a, const double& b, const int& n)
//{
//	double h, Xi, sum_f_Xi;
//	h = (b - a) / n;
//	Xi = a + h / 2;
//	sum_f_Xi = fun_SUM(Xi, h, n, 0);
//	return sum_f_Xi * h;
//}
//
//double fun_TR(const double& a, const double& b, const int& n)
//{
//	double h, Xi, sum_f_Xi, f_X;
//	h = (b - a) / n;
//	Xi = a + h;
//	sum_f_Xi = fun_SUM(Xi, h, n-1,0);
//	f_X = (fun(a) + fun(b)) / 2 + sum_f_Xi;
//	return h * f_X;
//}
//
//double fun_Simpson(const double& a, const double& b,int n)
//{
//	double h, Xi, sum_f_Xi_even, sum_f_Xi_odd, f_X;
//	h = (b - a) / (2 * n);
//	n*=2;
//	Xi = a + h;
//	sum_f_Xi_odd = fun_SUM(Xi, h, n - 1, 1);
//	sum_f_Xi_even = fun_SUM(Xi, h, n - 1,2);
//	f_X = fun(a) + fun(b) + 4 * sum_f_Xi_odd + 2 * sum_f_Xi_even;
//	return (h * f_X) / 3;
//}
//
//void Error_fun(const double& A, const double& Ao)
//{
//	cout << "\tPrecise_answer = " << Ao << "\n";
//	cout << "\tApproximate_answer = " << A << "\n";
//	cout << "\tAbsolute error = " << abs(A - Ao) << "\n";
//	cout << "\tRelative error = " << abs(A - Ao)/A << "\n\n\n";
//	/*Relative error
//	absolute error*/
//}
//
//
//int main()
//{
//	double a, b; // измен€емые данные 
//	int n; // измен€емые данные 
//	double precise_answer = 6.1; // расчитываетс€ аналитически 
//	double approximate_answer;
//	a = -2; b = 1; n = 10;
//	cout << "Rectangle method:" << "\n";
//	approximate_answer = fun_PR(a, b, n);
//	Error_fun(approximate_answer, precise_answer);
//
//	cout << "Trapezoid method:" << "\n";
//	approximate_answer = fun_TR(a, b, n);
//	Error_fun(approximate_answer, precise_answer);
//
//	cout << "Simpson's method:" << "\n";
//	approximate_answer = fun_Simpson(a, b, 5);
//	Error_fun(approximate_answer, precise_answer);
//}