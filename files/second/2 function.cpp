#include<iostream>
#include<cmath>
#include<clocale>

using namespace std;

double function(double x)
{
	return tan(3 * x * x * x);

}

double rec(double a, double b, int n)
{
	double h, x, sum = 0;
	h = (b - a) / n;
	x = a + h / 2;


	for (int i = 1; i <= n; i++) {

		sum += function(x);
		x += h;
	}
	x = a + h / 2;

	return sum * h;
}

double trap(double a, double b, int n)
{
	double h, x, fun_trap, sum = 0;
	h = (b - a) / n;
	x = a + h;

	for (int i = 1; i < n; i++) {
		sum += function(x);
		x += h;
	}
	fun_trap = (function(a) + function(b)) / 2 + sum;
	return fun_trap * h;
}

double sim(double a, double b, int n)
{
	double h, x, sum_1 = 0, sum_2 = 0, fun_sim = 0;
	h = (b - a) / (2 * n);
	x = a + h;

	for (int i = 1; i < n * 2; i += 2)
	{
		sum_1 += function(x);
		x += 2 * h;
	}

	x = a + 2 * h;

	for (int i = 2; i < n * 2; i += 2)
	{
		sum_2 += function(x);
		x += 2 * h;
	}

	fun_sim = function(a) + function(b) + 4 * sum_1 + 2 * sum_2;
	return (fun_sim * h) / 3;
}



//������� ����� ��� �������������� � �������
double run_1(double I1, double I2) {
	return (I2 - I1) / (2 * 2 - 1);
}


//������� ����� ��� �������
double run_2(double I1, double I2) {
	return (I2 - I1) / (2 * 2 * 2 * 2 - 1);
}

// ���������� ������������ ��������
double app(double I1, double R) {
	return I1 + R;
}



int main()
{
	//2 �������

	setlocale(LC_CTYPE, "rus");


	double a = 0.1, b = 0.75;
	int n = 10;



	//������������� 

	double re�tangle_1 = rec(a, b, n); //��� n = 10
	n = 20;
	double rectangle_2 = rec(a, b, n);//��� n = 20

	double rec_runge = run_1(re�tangle_1, rectangle_2);
	double rec_approx = app(rectangle_2, rec_runge);

	cout << "�������������\n";
	cout << "��� n(10) = " << re�tangle_1 << "\n";
	cout << "��� n(20) = " << rectangle_2 << "\n";
	cout << "���������� ������������ �������� = " << rec_approx << "\n";
	cout << "������ �� ����� =  " << rec_runge << "\n";

	//��������
	n = 10;
	double trapezoid_1 = trap(a, b, n);
	n = 20;
	double trapezoid_2 = trap(a, b, n);

	double trap_runge = run_1(trapezoid_1, trapezoid_2);
	double trap_approx = app(trapezoid_2, trap_runge);

	cout << "��������\n";
	cout << "��� n(10) = " << trapezoid_1 << "\n";
	cout << "��� n(20) = " << trapezoid_2 << "\n";;
	cout << "���������� ������������ �������� = " << trap_approx << "\n";
	cout << "������ �� ����� = " << trap_runge << "\n";

	//������� �������
	n = 10;
	double simcon_1 = sim(a, b, (n / 2));
	n = 20;
	double simcon_2 = sim(a, b, (n / 2));

	double simcon_runge = run_2(simcon_1, simcon_2);
	double simcon_approx = app(simcon_2, simcon_runge);

	cout << "������� ������� \n";
	cout << "��� n(10) = " << simcon_1 << "\n";
	cout << "��� n(20) = " << simcon_2 << "\n";;
	cout << "���������� ������������ �������� = " << simcon_approx << "\n";
	cout << "������ �� ����� =  " << simcon_runge << "\n";
}