#include <iostream>
#include <vector>

using namespace std;

int factorial(int N)
{
    // basecase
    if (N == 1)
        return 1;
    return N * factorial(N - 1);
}

//calculate the number of digits of K.
int digits_of_K(int K)
{
    int count = 1;

    while (true)
    {
        K /= 10;
        count++;
        if (K <= 9)
            break;
    }
    return count;
}

// aCb
int comb(int a, int b)
{
    int result;
    int numerator = factorial(a);
    int denominator = factorial(b) * factorial(a - b);
    result = numerator / denominator;
    return result;
}

// 重複あり並び方パターン
vector<int> seq_list;
int seq_pattern(vector<int> list_753)
{
    // ex) [5,3,7,5,3,7,5,]
    int count_pattern;
    int count_3 = 0;
    int count_5 = 0;
    int count_7 = 0;

    for (int i = 0; i < list_753.size(); i++)
    {
        int num = list_753[i];
        if (num == 3)
            count_3++;
        else if (num == 5)
            count_5++;
        else if (num == 7)
            count_7++;
    }

    int numerator = factorial(list_753.size());
    int denominator = factorial(count_3) * factorial(count_5) * factorial(count_7);

    count_pattern = numerator / denominator;
    return count_pattern;
}

int pattern_list(vector<int> num_list, int K)
{
}

int main()
{
    int K = 3153;
    int count = digits_of_K(K);
    vector<int> a;
    a.push_back(7);
    a.push_back(7);
    a.push_back(5);
    a.push_back(3);
    cout << seq_pattern(a) << endl;
}