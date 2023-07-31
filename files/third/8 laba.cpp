//#include<iostream> 
//#include<clocale>
//#include<vector>
//#include<fstream>
//#include<cmath>
//
//using namespace std;
//
//
//
//vector<double> metod_Gauss(vector<vector<double>> vv)
//{
//	// Вывод для проверки
//		/*for (auto& vv1 : vv)
//		{
//			for (auto elem : vv1)
//				cout << elem << " ";
//			cout << "\n";
//		}
//		cout << "\n";*/
//	const int n = vv.size(), m = vv[0].size();
//	double abs_max;
//	int imax;
//	vector<double> v(n);
//	double bi;
//
//	// прямой ход
//	for (int k = 0; k < n-1; k++)
//	{
//		imax = k;
//		abs_max = vv[imax][k];
//		for (int i = k+1; i < n; i++)
//		{
//			if (abs(vv[i][k]) > abs(abs_max))
//			{ 
//				abs_max = abs(vv[i][k]);
//				imax = i;
//			}
//		}
//		if (abs_max == 0)
//			return { nan("") }; // не имеет решений или имеет бесконечное множество решений
//		
//		swap(vv[k], vv[imax]);
//		
//		for (int j = k; j < m; j++)
//			vv[k][j] /= abs_max;
//
//		for (int i = k + 1; i < n; i++) 
//		{
//			double x = -vv[i][k];
//			for (int j = k; j < m; j++)
//			{
//				vv[i][j] += vv[k][j] * x;
//			}
//		}
//	}
//
//	//обратный ход
//	for (int i = n-1; i >= 0; i--)
//	{
//		bi = vv[i][m-1];
//		for (int j = m-2; j > i; j--)
//		{
//			bi -= vv[i][j] * v[j];
//		}
//		bi /= vv[i][i];
//		v[i] = bi;
//	}
//
//
//	return v;
//}
//
//vector<double> metod_iter(vector<vector<double>> vv, const double& e = 1e-4)
//{
//	const int n = vv.size(), m = vv[0].size();
//	vector<double> v(n, 0);
//	int count_flag, count_iter = 100000;
//	int k = 0;
//	double del, Xv, sum;
//	bool flag;
//
//	for (int i = 0; i < n; i++) 
//	{
//		del = vv[i][i];
//		for (int j = 0; j < m; j++)
//		{
//			if (j != i)
//				vv[i][j] /= del;
//			else
//				vv[i][j] = 0;
//		}
//	}
//
//	do
//	{
//		flag = true;
//		for (int i = 0; i < n; i++)
//		{
//			
//			Xv = v[i];
//			sum = 0;
//			for (int j = 0; j < i; j++)
//			{
//				sum += vv[i][j] * v[j];
//			}
//
//			for (int j = i+1; j < m-1; j++)
//			{
//				sum += vv[i][j] * v[j];
//			}
//			v[i] = vv[i][m - 1] - sum;
//			if (fabs(v[i] - Xv) > e)
//			{
//				flag = false;
//			}
//		}
//		k++;
//	} while (!flag && k <= count_iter);
//
//	return v;
//}
//
//int main()
//{
//	setlocale(LC_CTYPE, "rus");
//	ifstream fin{ "input.txt" };
//	double e = 1e-4;
//	int lengs;
//	fin >> lengs;
//	vector<vector<double>> v_v(lengs, vector<double>(lengs + 1));
//
//	for(int i = 0; i < lengs; i++)
//		for (int j = 0; j < lengs + 1; j++)
//		{
//			fin >> v_v[i][j];
//		}
//
//	cout << "Array:\n";
//	for (auto& v :v_v)
//	{
//		for (auto elem : v)
//			cout << elem << " ";
//		cout << std::endl;
//	}
//
//	cout << " \n\nMetod_Gauss:\n";
//	vector<double> v = metod_Gauss(v_v);
//	for (int i = 0; i < lengs; i++)
//	{
//		cout << "X[" << i + 1 << "] = " << v[i] << "\n";
//	}
//
//	cout << " \n\nMetod_iter:\n";
//	vector<double> v2 = metod_iter(v_v, e);
//	for (int i = 0; i < lengs; i++)
//	{
//		cout << "X[" << i + 1 << "] = " << v2[i] << "\n";
//	}
//}