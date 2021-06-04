#include <iostream>

using namespace std;

void func(long long N, long long cur, int use, long long &counter)
{
    // base case
    if (cur > N)
        return;
    if (use == 0b111)
        counter++;

    // use 7
    func(N, cur * 10 + 7, use | 0b001, counter);

    // use 5
    func(N, cur * 10 + 5, use | 0b010, counter);

    // use 3
    func(N, cur * 10 + 3, use | 0b100, counter);
}

int main()
{
    // long long N;
    // cin >> N;
    // long long counter = 0;
    // func(N, 0, 0, counter);
    cout << (1 | 2) << endl;
}