#include<bits/stdc++.h>
#define MAX 760
using namespace std;

vector<int>v(MAX);

int find(int x){
	return x==v[x]? x:find(v[x]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}

struct Edge{
	int x;
	int y;
	double d;
};

bool cmp(Edge a, Edge b){
	return a.d<b.d;
}

int main(){
	int T,N,P;
	cin>>T;
	for(int cases= 0;cases<T;cases++){
		cin>>N;

		for(int i=1;i<=N;++i)v[i] = i;
		vector<Edge> paths;
		Edge aux;
		vector<int>vx(N),vy(N);
		for(int i = 0;i<N;++i)cin>>vx[i]>>vy[i];
		for(int i = 0;i<N-1;++i){
			for(int j = i+1;j<N;++j){
				aux.x = i+1;
				aux.y = j+1;
				aux.d = sqrt((vx[i]-vx[j])*(vx[i]-vx[j]) + (vy[i]-vy[j])*(vy[i]-vy[j]));
				paths.push_back(aux);
			}
		}
		sort(paths.begin(),paths.end(),cmp);
		cin>>P;
		int a,b,d=0;
		for(int i=0;i<P;++i){
			cin>>a>>b;
			if(find(a)!=find(b))Union(a,b),d++;
		}
		
		vector<Edge>MST;
		for(int i = 0;(int)MST.size()+d<N-1;++i){
			if(find(paths[i].x)!=find(paths[i].y)){
				Union(paths[i].x,paths[i].y);
				MST.push_back(paths[i]);
			}
		}
		if(cases>0)cout<<endl;
		if(MST.size()==0)cout<<"No new highways need"<<endl;
		else for(int i=0;i<(int)MST.size();++i)cout<<MST[i].x<<" "<<MST[i].y<<endl;
   }
	return 0;
}
