#include <iostream>
#include "LinearRegression.h"
using namespace std;

int main()
{
    int size = 11;
    double* x = new double[size]{ 71, 73, 64, 65, 61, 70, 65, 72, 63, 67, 64 };
    double* y = new double[size]{ 160, 183, 154, 168, 159, 180, 145, 210, 132, 168, 141 };
    //double* x = new double[5]{ 0, 1, 2, 3, 4 };
    //double* y = new double[5]{ 0, 1, 2, 3, 4 };



	LinearRegression l(x,y,size);

    double slope = 10;
    double intercept = 10;
    double dm, db;
    l.linearRegression(slope, intercept);

    cout << "y = " << slope << "x + " << intercept << endl;
    cout << "Linear Regression Cost: " << l.getCost(slope, intercept, dm, db);
}