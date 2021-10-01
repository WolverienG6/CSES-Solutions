/*
Time Complexity: O(N logN)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

/////////////////////////////////\\\\\\\\

int main()
{
    int n;
    cin>>n;

    vector<int> vec;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;

        auto p = upper_bound(vec.begin(),vec.end(),a);

        if(p!=vec.end())
        {
            *p = a;
        }
        else
        {
            vec.push_back(a);
        }
    }

    cout<<vec.size()<<"\n";
}