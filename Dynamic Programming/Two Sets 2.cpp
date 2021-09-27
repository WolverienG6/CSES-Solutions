/* 
space complexity: O(n^2)
time complexity: O(n^2)
*/


#include<bits/stdc++.h>

using namespace std;

const int mod = ((int)1e9+7);

long long dp[501][501*501];

int main()
{
    int n;
    cin>>n;

    // sum of n natural number
    int s = (n*(n+1))/2;

    // if sum is odd two equal sum subset not possible 
    if(s%2!=0)
    {
        cout<<0<<"\n";
        return 0;
    }

    dp[0][0] = 1;

    for(int i=1;i<=n;i++)
    {
        //looping upto natural number sum till 'i'
        //that is ((i)*(i+1))/2 
        for(int j=0;j*2<=i*(i+1);j++)
        {
            //first column will always be 1 as 0 sum is always a reachable
            if(j==0)
            {
                dp[i][j] = 1;continue;
            }

            //when 'i' is not taken into account
            dp[i][j] = dp[i-1][j];

            //when is 'i' is also taken in account
            if(j>=i)
            {
                dp[i][j] += dp[i-1][j-i];
            }

            // taking mod
            dp[i][j]%=mod;

        }
    }

    /* 

    1) As s = 1+2+....n, but we need to find out the subset whose sum
       is equals to s/2, so we will take the value of ans as dp[n][s/2]

    2) But.. we need to furtger devide ans by 2 because we have taken each 
       pair of subset twice.
       for eg: for n=4 sum=5 we have only one pair: 
       {2,3} &  {1,4} but in our dp array it will come 2
       because it considering {2,3},{1,4} & {1,4},{2,3} as different.
       So we will divide by 2

    3) As told above we needed to divide by 2, but here as we have alreayd used modulo 
       so we cannot directly divide now, instead of that I will multiply by modulo inverse of 2
       which is 500000004 (found through internet) and take the mod
    */

    cout<<((dp[n][s/2])*500000004)%mod<<"\n";
}

