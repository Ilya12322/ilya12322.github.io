#include<iostream>
#include<clocale>
#include<tuple>
#include<cmath>

using namespace std;

double fun_xy(const double& x, const double& y)
{
	return -2 * x * y * y + x * x - 20 * x - 14 * x * y + 3;
}

double fun_pr_x(const double& x, const double& y)
{
	return -2 * y * y + 2 * x - 20 - 14 * y;
}

double fun_pr_y(const double& x, const double& y)
{
	return -4 * x * y - 14 * x;
}

tuple<double, double, int> met_grad_descent(double x, double y, double h, double e)
{
	int max_iter = 1000000;
	double x1 = x, y1 = y, f_XY1;
	double f_XY = fun_xy(x,y), f_pr_X = fun_pr_x(x,y), f_pr_Y = fun_pr_y(x,y), grad_mod;
	grad_mod = sqrt(f_pr_X * f_pr_X + f_pr_Y * f_pr_Y);
	int i = 1;
	for (; grad_mod > e; i++)
	{
		x1 = x - h * f_pr_X / grad_mod;
		y1 = y - h * f_pr_Y / grad_mod;
		f_XY1 = fun_xy(x1, y1);
		if (f_XY1 > f_XY)
		{
			x1 = x;
			y1 = y;
			h /= 2;
		}
		else
		{
			f_pr_X = fun_pr_x(x1, y1);
			f_pr_Y = fun_pr_y(x1, y1);
			grad_mod = sqrt(f_pr_X * f_pr_X + f_pr_Y * f_pr_Y);
			x = x1;
			y = y1;
			f_XY = f_XY1;
		}
		if (i > max_iter)
			return { nan(""), nan(""), i};
	}
	return {x1, y1, i};
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	double x = -5, y = -5, h = 0.0001, e = 1e-3, Xmin, Ymin;
	int count;
	cout << "При: \nX = " << x << "\nY = " << y << "\nH = " << h << "\n";
	tie(Xmin, Ymin, count) = met_grad_descent(x, y, h, e);
	cout << "Xmin = " << Xmin << "\tYmin = " << Ymin << "\t count_i = " << count << "\n\n";

	x = -20; y = 15; h = 0.01;
	cout << "При: \nX = " << x << "\nY = " << y << "\nH = " << h << "\n";
	tie(Xmin, Ymin, count) = met_grad_descent(x, y, h, e);
	cout << "Xmin = " << Xmin << "\tYmin = " << Ymin << "\t count_i = " << count << "\n\n";

	x = -1; y = 20; h = 0.1;
	cout << "При: \nX = " << x << "\nY = " << y << "\nH = " << h << "\n";
	tie(Xmin, Ymin, count) = met_grad_descent(x, y, h, e);
	cout << "Xmin = " << Xmin << "\tYmin = " << Ymin << "\t count_i = " << count << "\n\n";

}