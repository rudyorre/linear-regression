#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H
#include <iostream>
#include <vector>
using namespace std;

class LinearRegression
{
private:
	vector<double> x, y;
public:
	LinearRegression();
	LinearRegression(vector<double>& set_x, vector<double>& set_y);
	~LinearRegression();
	void setValue(vector<double>& set_x, vector<double>& set_y);
	double getSlope();
	double getIntercept();
	double getCost(double a, double b, double& da, double& db);
	void linearRegression(double slope = 1, double intercept = 0);
};

#endif //LINEARREGRESSION_H