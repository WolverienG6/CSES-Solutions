#include <bits/stdc++.h>
using namespace std;

/* 
time complexity: O(N*long(N))
space complexity: O(N)
*/

int main()
{
    int n;
    cin>>n;

    vector<int> vec(n);

    for(int i=0;i<n;i++) cin>>vec[i];

    map<int,int> mp;// map to store the last occuring index of particular value

    int cnt = 0;//to keep the count of length of sequence at any index
    int ans = 0;//final answer

    int j=0;//for index 
    int st = 0;//to store the start index of any current sequence

    while(j<n) //transversing the array
    {
        if(mp.find(vec[j]) == mp.end()) 
        {
            /* 
             if given value at particular index is occuring first time, 
             simply adding that value in current sequence.
            */
            cnt++;
            mp[vec[j]] = j; //also updating the last occurence
        }
        else
        {
            /* if already encountered once */
            /* checking if the last occurence was before the 
               start index of current sequence or not
               i.e. checking our current sequnce has that value or not
            */
            if(mp[vec[j]] < st)
            { 
                /* if before, then simply adding and updating last occurence*/   
                cnt++;
                mp[vec[j]] = j;
            }
            else
            {
                /* if after the start index, then ending the current seq
                   here itself updating the ans with cnt till now
                */
                ans = max(ans,cnt);
                cnt = j - mp[vec[j]]; //now the new seq will start from last occurence of prev seq + 1

                st = mp[vec[j]] + 1; // updating both cnt and st accordingly
                mp[vec[j]] = j;// updating last occurence
            }
        }
        j++;
    }

    ans = max(ans,cnt);

    cout<<ans<<"\n";
}
