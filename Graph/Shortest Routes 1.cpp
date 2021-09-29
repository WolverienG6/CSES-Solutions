 
/* 

Dijkshatra Algorithm

time complexity: O(E logV) {E->edges,V->vertices}
space complexity: O(V)

*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[100001]; //storing nodes and edges
int vis[100001]; //visited array
int d[100001]; //distance array


int main()
{
	int n,m;
	cin>>n>>m;


	for(int i=0;i<m;i++)
	{
    	int x, y, z;
		cin>>x>>y>>z;
    	v[x].push_back({y, z});
	}

	for(int i=0;i<=n;i++) d[i]=1000000000LL * m + 1LL; //making the initial distance infinite
	for(int i=0;i<=n;i++) vis[i]=0;//intially all nodes unvisited

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;


	q.push({0, 1});
	
	d[1] = 0;

	while(!q.empty()){

		auto a=q.top();
		q.pop();

		int c = a.second;
		int dis = a.first; 

		if(vis[c]) continue;
		
		vis[c]=1;

		for(auto i: v[c]){

			if( d[c] + i.second < d[i.first]){
				d[i.first] = d[c] + i.second;
				q.push({d[i.first], i.first});
			}
		
		}
	}

	for(i=1;i<=n;i++) cout<<d[i]<<" ";
}
