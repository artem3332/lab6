#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

double F(double x1, double x2)
{
	return x1 * x1 + x1 * x2 - 10 * x1 + x2 * x2 - 5 * x2 + 4;
}

int main()
{

	int i = 0;

	double X0[2] = { 1,1 };// задается начальная точка a0, b0;
	double X1[2] = { 0,0 };
	double e = 0.001;

	ofstream out;
	out.open("b.doc");
	out << X0[0] << " " << X0[1] << endl;

	//задается начальная длина шага по плоскости d0;
	double d1 = 1;
	double d2 = 1;
	double r = 0;


	while (i < 200)
	{
		i += 1;
		double l1 = 1;
		X1[0] = X0[0] + d1 * l1;
		if (F(X1[0], X1[1]) < F(X0[0], X0[1]))
		{

			X0[0] = X1[0];
			out << X0[0] << " " << X0[1] << endl;
			r = r + 1;
		}

		l1 = -1;
		X1[0] = X0[0] + d1 * l1;
		if (F(X1[0], X1[1]) < F(X0[0], X0[1]))
		{
			X0[0] = X1[0];
			out << X0[0] << " " << X0[1] << endl;
			r = r + 1;
		}

		if (r == 0)
		{
			d1 -= d1 / 10;
		}

		r = 0;
		double l2 = 1;
		X1[1] = X0[1] + d2 * l2;
		if (F(X1[0], X1[1]) < F(X0[0], X0[1]))
		{
			X0[1] = X1[1];
			out << X0[0] << " " << X0[1] << endl;
			r = r + 1;
		}
		l2 = -1;
		X1[1] = X0[1] + d2 * l2;
		if (F(X1[0], X1[1]) < F(X0[0], X0[1]))
		{
			X0[1] = X1[1];
			out << X0[0] << " " << X0[1] << endl;
			r = r + 1;
		}
		if (r == 0)
		{
			d2 -= d2 / 10;
		}
		r = 0;

		if (d1 < e || d2 < e) break;//условие выхода
	}

	cout << "(x1,x2)=" << "(" << X0[0] << "," << X0[1] << ")" << endl;
	cout << "F(x1,x2)=" << F(X0[0], X0[1]) << endl;
	cout << "itera=" << i;


	return 0;

}