#include <iostream>
#include <cmath>
using namespace std;

void check(int a[][4])
{
    if (fabs(a[0][0]) > fabs(a[0][1]) + fabs(a[0][2]) + fabs(a[0][3]) &&
        fabs(a[1][1]) > fabs(a[1][0]) + fabs(a[1][2]) + fabs(a[1][3]) &&
        fabs(a[2][2]) > fabs(a[2][1]) + fabs(a[2][0]) + fabs(a[2][3]) &&
        fabs(a[3][3]) > fabs(a[3][1]) + fabs(a[3][2]) + fabs(a[3][0]))
        cout << "The convergence condition is not violated" << endl;
    else
    {
        cout << "The convergence condition is violated" << endl;
        exit(0);
    }
}
void view( double b1, double b2, double b3, double b4)
{
    cout << 4 << "*x1 + " << 1 << "*x2 + " << 1 << "*x3 + " << 1 << "*x4 = " << b1 << endl;
    cout << 1 << "*x1 + " << 4 << "*x2 + " << 1 << "*x3 + " << 1 << "*x4 = " << b2 << endl;
    cout << 1 << "*x1 + " << 1 << "*x2 + " << 4 << "*x3 + " << 1 << "*x4 = " << b3 << endl;
    cout << 1 << "*x1 + " << 1 << "*x2 + " << 1 << "*x3 + " << 4 << "*x4 = " << b4 << endl;
}
void f(int a[][4], double b1, double b2, double b3, double b4, double x1, double x2, double x3, double x4, double x1n, double x2n, double x3n, double x4n, double eps, int count)
{
    do
    {
        x1n = (b1 - (a[0][1] * x2 + a[0][2] * x3 + a[0][3] * x4)) / a[0][0];
        x2n = (b2 - (a[1][0] * x1 + a[1][2] * x3 + a[1][3] * x4)) / a[1][1];
        x3n = (b3 - (a[2][0] * x1 + a[2][1] * x2 + a[2][3] * x4)) / a[2][2];
        x4n = (b4 - (a[3][0] * x1 + a[3][1] * x2 + a[3][2] * x3)) / a[3][3];
        if (fabs(x1n - x1) < eps &&
            fabs(x2n - x2) < eps &&
            fabs(x3n - x3) < eps &&
            fabs(x4n - x4) < eps) break;
        count = count + 1;
        x1 = x1n;
        x2 = x2n;
        x3 = x3n;
        x4 = x4n;

    } while (1);
    x1 = x1n;
    x2 = x2n;
    x3 = x3n;
    x4 = x4n;
    check(a);
    view(b1, b2, b3, b4);
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    cout << "x4 = " << x4 << endl;
    cout << "Number of iterations: " << count << endl;
}


int main()
{
    int a[4][4] = { {4, 1, 1, 1},
                    {1, 4, 1, 1},
                    {1, 1, 4, 1},
                    {1, 1, 1, 4} };

    double b1{ 1 }, b2{ 2 }, b3{ 3 }, b4{ 4 }; // столбец свободных членов
    double x1{ 0 }, x2{ 0 }, x3{ 0 }, x4{ 0 }; // начальное приближение

    double x1n{ 0 }, x2n{ 0 }, x3n{ 0 }, x4n{ 0 };
    double eps;
    cout << "eps: ";
    cin >> eps;
    int count{ 0 };
    f(a, b1, b2, b3, b4, x1, x2, x3, x4, x1n, x2n, x3n, x4n, eps, count);
}
