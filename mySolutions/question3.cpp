// sum of three integers.

#include <iostream>

using namespace std;

int main()
{
    int K = 3;
    int N = 3;

    // X + Y + Z = N
    // how many X, Y, Z combination satisfy the above formula ?
    int X, Y, Z;
    int count = 0;
    for (int i = 0; i <= K; i++)
    {
        X = i;
        for (int j = 0; j <= K; j++)
        {
            Y = j;
            if ((X + Y) > K)
            {
                continue;
            }
            else
            {

                for (int q = 0; q <= K; q++)
                {
                    Z = q;
                    if ((X + Y + Z) == N)
                    {
                        count++;
                        cout << "X: " << X << " "
                             << "Y: " << Y << " "
                             << "Z: " << Z << endl;
                    }
                }
            }
        }
    }
    // result.
    cout << "count: " << count << endl;
    /*
    X: 0 Y: 0 Z: 3
    X: 0 Y: 1 Z: 2
    X: 0 Y: 2 Z: 1
    X: 0 Y: 3 Z: 0
    X: 1 Y: 0 Z: 2
    X: 1 Y: 1 Z: 1
    X: 1 Y: 2 Z: 0
    X: 2 Y: 0 Z: 1
    X: 2 Y: 1 Z: 0
    X: 3 Y: 0 Z: 0
    count: 10
    */
}