#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<long long> memo;

//  tribonacci seq review.
long long tribonacci(int N)
{
    // basecase
    if (N == 0)
        return 0;
    else if (N == 1)
        return 0;
    else if (N == 2)
        return 1;

    if (memo[N] != -1)
        return memo[N];

    return memo[N] = tribonacci(N - 1) + tribonacci(N - 2) + tribonacci(N - 3);
}

int main()
{
    // 50 * -1
    memo.assign(50, -1);
    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 1;

    // write memo.
    tribonacci(49);

    // call the sequence of number from memo.
    cout << "size of memo is " << memo.size() << endl;
    for (int i = 0; i < memo.size(); ++i)
        cout << "No." << setw(2) << i << " " << setw(10) << memo[i] << endl;
}