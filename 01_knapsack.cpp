
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,w;
    cin >> n >> w;

    int valu[101], weight[101];
    for (int i = 0; i < n; i++)
    {
        cin >> valu[i] >> weight[i];
    }
    
    int dp[101][101];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j< w; j++)
        {
            dp[i][j] =0;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j<= w; j++)
        {
            if(weight[i-1] <= j)
            {
                dp[i][j]= max(dp[i-1][j], valu[i-1]+dp[i-1][j-weight[i-1]]);
            }
            else
            {
                dp[i][j]= dp[i-1][j];
            }
        }
        
    }
    cout << dp[n][w];
}