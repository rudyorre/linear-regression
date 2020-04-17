#ifndef LINEARREGRESSION_CPP
#define LINEARREGRESSION_CPP
#include "LinearRegression.h"

LinearRegression::LinearRegression()
{
    x = new double{ 0 };
    y = new double{ 0 };
    size = 0;
}

LinearRegression::LinearRegression(double* set_x, double* set_y, int set_size)
{
    x = set_x;
    y = set_y;
    size = set_size;
}

LinearRegression::~LinearRegression()
{
}

void LinearRegression::setValue(double* set_x, double* set_y, int set_size)
{
    x = set_x;
    y = set_y;
    size = set_size;
}

double LinearRegression::getSlope()
{
    double sum_x = 0; // x
    double sum_y = 0; // y
    double sum_xy = 0; // x*y
    double sum_xx = 0; // x^2

    // summing the different values
    for (int i = 0; i < size; i++)
    {
        sum_x += x[i];
        sum_xx += x[i] * x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
    }

    // dividing by the amount to get the mean
    double mean_x = sum_x / size;
    double mean_xx = sum_xx / size;
    double mean_xy = sum_xy / size;
    double mean_y = sum_y / size;

    // line of best fit formula derived through
    // partial differentiation of the root mean squared function
    double numerator = mean_xy - mean_x * mean_y;
    double denominator = mean_xx - mean_x * mean_x;

    if (denominator == 0)
    {
        return numeric_limits<double>::max();
    }

    return numerator / denominator; 
}

double LinearRegression::getIntercept()
{
    double sum_x = 0; // x
    double sum_y = 0; // y

    // summing the different values
    for (int i = 0; i < size; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
    }

    // dividing by the amount to get the mean
    double mean_x = sum_x / size;
    double mean_y = sum_y / size;
    double slope = getSlope();

    // rewritten y = mx + b to solve for b
    return mean_y - slope * mean_x;
}

double LinearRegression::getCost(double m, double b, double& dm, double& db)
{
    double sum_x = 0; // x
    double sum_y = 0; // y
    double sum_xy = 0; // x*y
    double sum_xx = 0; // x^2
    double sum_yy = 0; // y^2

    // summing the different values
    for (int i = 0; i < size; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
        sum_yy += y[i] * y[i];
    }

    // Cost is defined as the Root Mean Squared Function
    double cost = (sum_yy) - (2 * m * sum_xy) - (2 * b * sum_y) + (m * m * sum_xx) + (2 * m * b * sum_x) + (size * b * b);
    cost /= size;

    // partial derivatives of the Cost Function with respect to slope(m) and intercept(b)
    dm = 2 * (m * sum_xx + b * sum_x - sum_xy) / size; // change in cost with respect to slope(m)
    db = 2 * (m * sum_x + size * b - sum_y) / size; // change in cost with respect to intercept(b)

    return cost;
}

void LinearRegression::linearRegression(double& slope, double& intercept)
{
    double learning_rate = 0.0002;
    double threshold = 0.0001;
    int iteration = 0;

    while (true)
    {
        double dm = 0;
        double db = 0;
        double cost = getCost(slope, intercept, dm, db);
        if (iteration % 10000 == 0)
        {
            cout << "Iteration: " << iteration << " Cost: " << cost << " da: " << dm << " db: " << db << endl;
            //cout << "y = " << slope << "x + " << intercept << endl;
        }
        iteration++;
        if (abs(dm) < threshold && abs(db) < threshold)
        {
            break;
        }
        slope -= learning_rate * dm;
        intercept -= learning_rate * db;
    }
}



#endif //LINEARREGRESSION_CPP