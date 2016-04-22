#include<bits/stdc++.h>
#define MAX 105
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
	std::ios::sync_with_stdio(false);
	int N,M,cases=0;
	while(cin>>N>>M){
		if(N==0&&M==0)break;
		
		for(int i=1;i<=N;++i)v[i] = i;
		vector<Edge> paths(M);

		for(int i = 0;i<M;++i)cin>>paths[i].x>>paths[i].y>>paths[i].d, paths[i].d--;
			
		sort(paths.begin(),paths.end(),cmp);

		vector<Edge>MST;
		vector<vector<int> >ady(N+1,vector<int>(N+1));
		for(int i = 0;i<(int)paths.size();++i){
			if(find(paths[i].x)!=find(paths[i].y)){
				Union(paths[i].x,paths[i].y);
				MST.push_back(paths[i]);
				ady[paths[i].x][paths[i].y] = paths[i].d;
				ady[paths[i].y][paths[i].x] = paths[i].d;
			}
		}
	
		int a,b,t;
		cin>>a>>b>>t;
		vector<int>visit(N+1,-1);
		//bfs
		queue<int>Q;
		Q.push(a);
		visit[a] = 1e9;
		while(!Q.empty()){
			int aux = Q.front();
			Q.pop();
			if(aux==b)break;;
			for(int i = 1;i<=N;++i){
				if(ady[aux][i]!=0&&visit[i]==-1){
					Q.push(i);
					visit[i] = min(ady[aux][i],visit[aux]);
				}
			}
		}
		cout<<"Scenario #"<<++cases<<endl;
		cout<<"Minimum Number of Trips = ";
		if(t%visit[b]>0)cout<<t/visit[b] + 1<<endl<<endl;
		else cout<<t/visit[b]<<endl<<endl;
	}
	return 0;
}
