#include <iostream>
#include <vector>
#include <string>

using namespace std;

void chmin(int &a, int b)
{
    if (a > b)
        a = b;
}

int main()
{
    string S = "logistic";
    string T = "algorithm";
    int inf = 100;
    vector<vector<int>> dp(S.length() + 1, vector<int>(T.length() + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < S.length() + 1; ++i)
    {
        for (int j = 0; j < T.length() + 1; ++j)
        {
            // edit
            if (i > 0 && j > 0)
            {
                if (S[i - 1] == T[j - 1])
                {
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                }
                else
                {
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            // insert
            if (j > 0)
            {

                chmin(dp[i][j], dp[i][j - 1] + 1);
            }

            // delete
            if (i > 0)
            {
                chmin(dp[i][j], dp[i - 1][j] + 1);
            }
        }
    }

    cout << dp[S.length()][T.length()] << endl;
}