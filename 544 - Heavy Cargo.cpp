#include<bits/stdc++.h>
#define MAX 205
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

	int N,M,cases=0;
	while(cin>>N>>M){
		if(N==0&&M==0)break;
		for(int i=1;i<=N;++i)v[i] = i;
		vector<Edge> paths(M);
		string ca,cb;
		map<string,int>m;
		int cities = 0;
		for(int i = 0;i<M;++i){
			cin>>ca>>cb;
			if(!m[ca])m[ca] = ++cities;
			if(!m[cb])m[cb] = ++cities;
			paths[i].x = m[ca];
			paths[i].y = m[cb];
			cin>>paths[i].d;
		}
		sort(paths.begin(),paths.end(),cmp);
		vector<vector<int> >ady(N+1,vector<int>(N+1));
		vector<Edge>MST;
		for(int i = 0;i<(int)paths.size();++i){
			if(find(paths[i].x)!=find(paths[i].y)){
				Union(paths[i].x,paths[i].y);
				MST.push_back(paths[i]);
				ady[paths[i].x][paths[i].y] = paths[i].d;
				ady[paths[i].y][paths[i].x] = paths[i].d;
			}
		}
		//bfs
		cin>>ca>>cb;
		int a = m[ca], b = m[cb];
		vector<int>dist(N+1,-1);
		dist[a] = 1000000;
		int rpta=0;
		queue<int> Q;
		Q.push(a);
		while(!Q.empty()){
			int aux = Q.front();
			Q.pop();
			if(aux==b){
				rpta = dist[b];
				break;
			}
			for(int i =1 ;i<=N;++i){
				if(ady[aux][i]!=0&&dist[i]==-1)Q.push(i),dist[i] = min(dist[aux] , ady[aux][i]) ;
			}
		}
		cases++;
		cout<<"Scenario #"<<cases<<endl<<rpta<<" tons"<<endl<<endl;
		
	}
	return 0;
}
