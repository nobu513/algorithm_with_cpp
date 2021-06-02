#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<long long> memo;

// fibonacci seq review.
long long fibonacci(int N)
{
    // basecase
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;

    if (memo[N] != -1)
        return memo[N];

    return memo[N] = fibonacci(N - 1) + fibonacci(N - 2);
}

int main()
{
    // 50 * -1
    memo.assign(50, -1);
    memo[0] = 0;
    memo[1] = 1;

    // write memo.
    fibonacci(49);

    // call the sequence of number from memo.
    cout << "size of memo is " << memo.size() << endl;
    for (int i = 0; i < memo.size(); ++i)
        cout << "No." << setw(2) << i << " " << setw(10) << memo[i] << endl;
}