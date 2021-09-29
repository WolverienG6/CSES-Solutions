#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp(501,vector<long long> (501,LONG_MAX));

int main()
{
    int n,m,q;
    cin>>n>>m>>q;

    while(m--)
    {
        int a,b;long long c;
        cin>>a>>b>>c;
        dp[a][b] = min(dp[a][b],c);
        dp[b][a] = min(dp[b][a],c);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(j==k)
                {
                    dp[j][k] = 0;continue;
                }

                if(dp[j][i]==LONG_MAX || dp[i][k]==LONG_MAX) continue;

                dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }

    while(q--)
    {
        int a,b;
        cin>>a>>b;

        if(dp[a][b]==LONG_MAX)
        {
            cout<<-1<<"\n";
            continue;
        }

        cout<<dp[a][b]<<"\n";
    }

}