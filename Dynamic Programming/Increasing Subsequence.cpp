/* 
Time Complexity: O(N logN)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

int main()
{
    int n;
    cin>>n;

    vector<int> vec(n);

    for(int i=0;i<n;i++) cin>>vec[i];

    vector<int> dp(n+1,INF);

    dp[0] = -INF;

    for(int i=0;i<n;i++)
    {
        int j = upper_bound(dp.begin(),dp.end(),vec[i]) - dp.begin();

        if(dp[j-1]<vec[i] && vec[i]<dp[j])
        {
            dp[j] = vec[i];
        }
    }

    int ans = 0;

    for(int i=0;i<=n;i++)
    {
        if(dp[i]<INF)
        {
            ans = i;
        }
    }

    cout<<ans<<"\n";
}