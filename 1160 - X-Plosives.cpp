#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

vector<int>v(MAX);
int find(int x){
	return v[x] == x? x:v[x]=find(v[x]);
}

void Union(int x, int y){
	v[find(x)] = find(y);
}
int main(){
	int x,y, ans;
	while(cin>>x){
		ans= 0;
		for(int i = 0;i<MAX;++i)v[i] = i;
		while(x!=-1){
			cin>>y;
			if(find(x)==find(y))ans++;
			else Union(x,y);
			cin>>x;
		}
		cout<<ans<<endl;
	}
   
	return 0;
}
