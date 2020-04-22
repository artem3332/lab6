#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


double F(double x1, double x2)
{
	return x1 * x1 + x1 * x2 - 10 * x1 + x2 * x2 - 5 * x2 + 4;
}


double interpolation1(double x1)
{
	//metod svena
	double a = 0;
	double t = 1;
	double b = a + t;
	while (true)
	{
		if (F(x1, b) < F(x1, a))
		{
			a = b;
			b += t;
		}
		else break;
	}
	a -= t;


	double x = 0.0 + a + (b - a) / 2;
	double h = 0.01;

	//kvadratnay interpolazia
	while ((a < x) && (x < b))
	{
		if ((F(x1, x - h) > F(x1, x)) && (F(x1, x) < F(x1, x + h)))
		{
			return x;
		}
		else if (F(x1, x) > F(x1, x + h))
		{
			x = x + h;
		}
		else
		{
			x = x - h;
		}

	}
}

double interpolation2(double x2)
{

	//metod svena
	double a = 0;
	double t = 1;
	double b = a + t;
	while (true)
	{
		if (F(b, x2) < F(a, x2))
		{
			a = b;
			b += t;
		}
		else break;
	}
	a -= t;


	double x = 0.0 + a + (b - a) / 2;
	double h = 0.001;

	//kvadratnay interpolazia
	while ((a < x) && (x < b))
	{
		if ((F(x - h, x2) > F(x, x2)) && (F(x, x2) < F(x + h, x2)))
		{
			return x;
		}
		else if (F(x - h, x2) > F(x + h, x2))
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



	double eps = 0.0001;
	double x[2] = { 1,1 };
	double x_temp[2] = { 0,0 };
	int i = 0;


	ofstream out;
	out.open("b.txt");

	//metod pokoordinatnogo spuska
	while ((abs(x[0] - x_temp[0]) > eps) && (abs(x[1] - x_temp[1]) > eps))
	{

		i++;
		x_temp[0] = x[0];
		x_temp[1] = x[1];
		x[1] = interpolation1(x[0]);
		out << x[0] << " " << x[1] << endl;
		x[0] = interpolation2(x[1]);
		out << x[0] << " " << x[1] << endl;


	}
	cout <<"(x1,x2)="<<"("<< x[0]<<","<< x[1]<<")"<< endl;
	cout <<"F(x1,x2)="<< F(x[0],x[1]) << endl;
	cout <<"itera="<< i;








	return 0;
}