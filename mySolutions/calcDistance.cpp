#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// calculate the distance between two points.
double calc_distance(double x_value1, double y_value1, double x_value2, double y_value2)
{
    double distance = sqrt((x_value1 - x_value2) * (x_value1 - x_value2) + (y_value1 - y_value2) * (y_value1 - y_value2));
    return distance;
}

void print_vector(vector<double> vctr)
{

    for (int i = 0; i < vctr.size(); i++)
        cout << setw(4) << vctr[i];
    cout << "\n";
}

int main()
{
    srand(time(NULL));

    int POINTS_SIZE = 10;

    vector<double> vector_x(POINTS_SIZE), vector_y(POINTS_SIZE);

    // initialize the values of x and y.
    for (int i = 0; i < POINTS_SIZE; i++)
    {
        vector_x[i] = rand() % 100;
        vector_y[i] = rand() % 100;
    }

    // print the values.
    cout << "print the values of vector_x" << endl;
    print_vector(vector_x);

    cout << "print the values of vector_y" << endl;
    print_vector(vector_y);

    // calc minimam distance between points.
    double min_distance = 1000000;
    for (int i = 0; i < POINTS_SIZE; i++)
    {
        double x_value1 = vector_x[i];
        double y_value1 = vector_y[i];
        for (int j = 0; j < POINTS_SIZE; j++)
        {
            if (i == j)
                continue;
            else
            {
                double x_value2 = vector_x[j];
                double y_value2 = vector_y[j];
                double distance = calc_distance(x_value1, y_value1, x_value2, y_value2);
                if (distance < min_distance)
                    min_distance = distance;
            }
        }
    }

    // result.
    cout << "the minimum value is: " << setprecision(3) << min_distance << endl;
}