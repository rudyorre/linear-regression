#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H
#include <iostream>
#include <vector>
using namespace std;

class LinearRegression
{
private:
	double* x, * y;
	int size;
public:
	LinearRegression();
	LinearRegression(double* set_x, double* set_y, int set_size);
	~LinearRegression();
	void setValue(double* set_x, double* set_y, int set_size);
	double getSlope();
	double getIntercept();
	double getCost(double a, double b, double& da, double& db);
	void linearRegression(double& slope, double& intercept);
};

#endif //LINEARREGRESSION_H