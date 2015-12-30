#include<bits/stdc++.h>
#define MAX 10005
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
	int d;
};

bool cmp(Edge a, Edge b){
	return a.d<b.d;
}

int main(){
	int c,s,q,cases=0;
	while(cin>>c>>s>>q){
		if(c==0&&s==0&&q==0)return 0;
		if(cases>0)cout<<endl;
		cases++;
		cout<<"Case #"<<cases<<endl;
		for(int i=1;i<=c;++i)v[i] = i;
		vector<Edge> paths(s);

		for(int i = 0;i<s;++i)cin>>paths[i].x>>paths[i].y>>paths[i].d;
			
		sort(paths.begin(),paths.end(),cmp);
		
		vector<Edge>MST;
		vector<vector<int> >ady(c+1,vector<int>(c+1));
		for(int i = 0;i<s&&(int)MST.size()<c-1;++i){
			if(find(paths[i].x)!=find(paths[i].y)){
				Union(paths[i].x,paths[i].y);
				MST.push_back(paths[i]);
				ady[paths[i].x][paths[i].y] = paths[i].d;
				ady[paths[i].y][paths[i].x] = paths[i].d;
			}
		}
		int a,b,rpta;
		while(q--){
			rpta = -1;
			cin>>a>>b;
			//bfs
			vector<int>dist(c+1,-1);
			dist[a] = 0;
			queue<int> Q;
			Q.push(a);
			while(!Q.empty()){
				int aux = Q.front();
				Q.pop();
				if(aux==b){
					rpta = dist[b];
					break;
				}
				for(int i =1 ;i<=c;++i){
					if(ady[aux][i]!=0&&dist[i]==-1)Q.push(i),dist[i] = max(dist[aux] , ady[aux][i]) ;
				}
			}
			if(rpta>0)cout<<rpta<<endl;
			else cout<<"no path"<<endl;
		}
		
		
	}
   

}
