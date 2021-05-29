#include <iostream>
#include <iomanip>
#include <ctime>
#include <tuple>

using namespace std;

void print_list(int lista[10])
{
    for (int i = 0; i < 10; i++)
        cout << setw(4) << lista[i];
    cout << "\n";
}

int return_min(int lista[10])
{
    int min = 100000;
    for (int i = 0; i < 10; i++)
    {
        if (lista[i] < min)
            min = lista[i];
    }
    return min;
}

int return_max(int lista[10])
{
    int max = -1;
    for (int i = 0; i < 10; i++)
    {
        if (lista[i] > max)
            max = lista[i];
    }
    return max;
}

int rand_val(int start_value, int end_value)
{
    srand(time(NULL));
    int value;
    while (true)
    {
        value = rand() % end_value + 1;
        if ((start_value <= value) && (value <= end_value))
            return value;
    }
}

tuple<int, int, int> min_pair(int lista[10], int listb[10], int K)
{
    int min_a;
    int min_b;
    int min = 100000;

    for (int i = 0; i < 9; i++)
    {
        int a = lista[i];
        for (int j = 0; j < 9; j++)
        {
            int b = listb[j];
            if (((a + b) < min) && ((a + b) >= K))
            {
                min = a + b;
                min_a = a;
                min_b = b;
            }
        }
    }
    return make_tuple(min, min_a, min_b);
}

int main()
{
    int a[10];
    int b[10];

    srand(time(NULL));
    for (int i; i < 10; i++)
    {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }
    cout << "print list a." << endl;
    print_list(a);
    cout << "print list b." << endl;
    print_list(b);

    // decide K at random under the condition.
    // min_a + min_b <= K <= max_a + max_b
    cout << "print K." << endl;
    int min_a = return_min(a);
    int max_a = return_max(a);
    int min_b = return_min(b);
    int max_b = return_max(b);
    srand(time(NULL));
    int K = rand_val(min_a + min_b, max_a + max_b);
    cout << K << endl;

    // result.
    // clang++ question2.cpp -std=c++17 && ./a.out
    int x, y, z;
    tie(x, y, z) = min_pair(a, b, K);
    cout << "min: " << x << " min_a: " << y << " min_b: " << z << endl;

    /*

    print list a.  
    41  81  67  10  33  27  61  90  20  74
    print list b.
    46  34  47  71  83  37  97  10  80  67
    print K.
    35
    min: 37 min_a: 27 min_b: 10

    */
}
