
#include<bits/stdc++.h>
using namespace std;

int editdistace(string x , string y)
{
    int m = x.length();
    int n = y.length();

    int dp[101][101];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i-1]== y[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j]= 1+min({
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1]
                });
            } 
        }
    }
    return dp[m][n];
}

int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;

    int result = editdistace (s1,s2);
    cout << "minimum edit distance:" << result;
}