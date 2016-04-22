#include<bits/stdc++.h>
#define MAX 10005
using namespace std;

vector<int>v(MAX);
typedef unsigned long long ull;
int find(int x){
	return x==v[x]? x:find(v[x]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}

struct Edge{
	int x;
	int y;
	ull d;
};

bool cmp(Edge a, Edge b){
	return a.d>b.d;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int N,M;
		ull sum=0;
		cin>>N>>M;
		for(int i=1;i<=N;++i)v[i] = i;
		vector<Edge> paths(M);

		for(int i = 0;i<M;++i)cin>>paths[i].x>>paths[i].y>>paths[i].d, sum+=paths[i].d;
			
		sort(paths.begin(),paths.end(),cmp);

		vector<Edge>MST;
		for(int i = 0;i<(int)paths.size();++i){
			if(find(paths[i].x)!=find(paths[i].y)){
				Union(paths[i].x,paths[i].y);
				MST.push_back(paths[i]);
				sum -= paths[i].d;
			}
		}
		cout<<sum<<endl;
		
	}
	return 0;
}
