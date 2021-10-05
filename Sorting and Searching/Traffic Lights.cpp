/*
Space Complexity: O(n)
Time Complexity: O(n logn) 
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,n;
    cin>>x>>n;

    multiset<int> st;
    multiset<int> mst;

    st.insert(0);
    st.insert(x);
    mst.insert(x);

    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        
        auto itr = st.upper_bound(a);
        auto it1 = itr;

        it1--;

        int diff = *itr - *it1;

        mst.erase(mst.find(diff));

        st.insert(a);
        mst.insert(*itr - a);
        mst.insert(a - *it1);

        cout<<*mst.rbegin()<<"\n";
    }
}

//0 3 6 8