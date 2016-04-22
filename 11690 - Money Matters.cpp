#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
vector<int>v(MAX+10);

int find(int a){
	return v[a]==a? a:find(v[a]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}
int main(){
	int caso;
	cin>>caso;
	int N,M;
	while(caso--){
		cin>>N>>M;
		vector<int>p(N);
		for(int i = 0;i<N;++i)v[i] = i;
		for(int i = 0;i<N;++i)cin>>p[i];
		int x,y;
		while(M--){
			cin>>x>>y;
			Union(x,y);
		}
		vector<int> r(N);
		for(int i = 0;i<N;++i){
			r[find(v[i])]+=p[i];
		}
		bool flag= true;
		for(int i = 0;i<N&&flag;++i){
			if(r[i]!=0)flag=false;
		}
		flag?cout<<"POSSIBLE"<<endl:cout<<"IMPOSSIBLE"<<endl;	
	}
   return 0;
}

