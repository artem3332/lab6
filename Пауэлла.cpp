#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

double F(double x1, double  x2)
{
	return x1 * x1 + x1 * x2 - 10 * x1 + x2 * x2 - 5 * x2 + 4;
}
double L(double l, double  X0[], double  df[])//преобразуем функцию от нескольких переменны в функцию от одной переменной
{
	return F((X0[0] + l * df[0]), (X0[1] + l * df[1]));
}
double  KI(double x0, double  y0, double  x, double y, double x1, double y1)//квадратичная интерполяция
{
	double a = (((y1 - y0) / (x1 - x0) * (x1 - x)) - ((y - y0) / (x - x0) * (x1 - x))) * 100;
	double b = (y - y0) / (x - x0) - a * (x + x0);
	return -b / (2 * a);
}

double  SO(double X0[], double  df[])//метод скользящего окна
{
	double h = 0.1;//шаг окна
	double x = 0;//начальная точка
	while (-50 < x && x < 50)
	{
		if (L(x - h, X0, df) > L(x, X0, df) && L(x, X0, df) < L(x + h, X0, df))
		{
			//с помощью квадратичной интерполяции находим минимум на данном отрезке 
			return KI(x - h, L(x - h, X0, df), x, L(x, X0, df), x + h, L(x + h, X0, df));
			break;
		}

		else if (L(x - h, X0, df) > L(x + h, X0, df))//перемещаем окно влево или вправо
		{
			x = x + h;
		}
		else
		{
			x = x - h;
		}
	}
}
int main()
{
	int i = 0;
	double e = 0.01;

	double X0[2] = { 4,3 };
	double X1[2] = { 0,0 };
	double X2[2] = { 0,0 };
	double X3[2] = { 0,0 };

	ofstream out;
	out.open("a.doc");
	out << X0[0] << " " << X0[1] << endl;

	double s1[2] = { 1,0 };
	double s2[2] = { 0,1 };
	double s3[2] = { 0,0 };

	while (i < 5)
	{
		i += 1;

		double	l = SO(X0, s1);//находим минимальную лямду 
		X1[0] = X0[0] + l * s1[0];//находим последующую точку 
		X1[1] = X0[1] + l * s1[1];

		l = SO(X1, s2);//находим минимальную лямду 
		X2[0] = X1[0] + l * s2[0];//находим последующую точку 
		X2[1] = X1[1] + l * s2[1];

		l = SO(X2, s1);//находим минимальную лямду 
		X3[0] = X2[0] + l * s1[0];//находим последующую точку 
		X3[1] = X2[1] + l * s1[1];
		X0[0] = X3[0];
		X0[1] = X3[1];
		out << X0[0] << " " << X0[1] << endl;

		s3[0] = X3[0] - X1[0];
		s3[1] = X3[1] - X1[1];

		s3[0] /= sqrt(s3[0] * s3[0] + s3[1] * s3[1]);
		s3[1] /= sqrt(s3[0] * s3[0] + s3[1] * s3[1]);
		s1[0] = s2[0];
		s1[1] = s2[1];
		s2[0] = s3[0];
		s2[1] = s3[1];
	}
	cout << "(x1,x2)=" << "(" << X0[0] << "," << X0[1] << ")" << endl;
	cout << "F(x1,x2)=" << F(X0[0], X0[1]) << endl;
	cout << "itera=" << i;

	return 0;
}