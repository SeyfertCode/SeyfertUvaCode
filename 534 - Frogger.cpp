#include<bits/stdc++.h>
#define MAX 205
using namespace std;
vector<int>v(MAX);
int find(int x){
	return v[x] == x? x:v[x]=find(v[x]);
}

void Union(int a, int b){
	v[find(a)] = find(b);
}

struct Edge{
	int x;
	int y;
	double d;
};

bool cmp(Edge x, Edge y){
	return x.d < y.d;
}
int main(){
	int n,cases = 0;
	while(cin>>n){
		if(n==0)break;
		cases++;
		
		vector<int>vx(n),vy(n);
		for(int i = 0;i<n;++i)v[i] = i,cin>>vx[i]>>vy[i];
		
		vector<Edge> edges;
		Edge aux;
		for(int i = 0;i<n-1;++i){
			for(int j=i+1;j<n;++j){
				aux.x = i;
				aux.y = j;
				aux.d = sqrt((vx[i] - vx[j])*(vx[i] - vx[j])+(vy[i] - vy[j])*(vy[i] - vy[j]));
				edges.push_back(aux);
			}
		}
		sort(edges.begin(),edges.end(),cmp);
		
		vector<vector<double> >ady(n,vector<double>(n));
		
		vector<Edge>MST;
		for(int i = 0;i<(int)edges.size();++i){
			if(find(edges[i].x)!=find(edges[i].y)){
				Union(edges[i].x, edges[i].y);
				MST.push_back(edges[i]);
				ady[edges[i].x][edges[i].y] = edges[i].d;
				ady[edges[i].y][edges[i].x] = edges[i].d;
			}
		}
		
		queue<int>Q;
		Q.push(0);
		vector<double>dist(n);
		
		while(!Q.empty()){
			int aux = Q.front();
			Q.pop();
			if(aux==1)break;
			for(int i = 0;i<n;++i){
				if(ady[aux][i]>0&&dist[i]==0){
					Q.push(i);
					dist[i] = max(dist[aux],ady[aux][i]);
				}
			}
		}
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cases,dist[1]);
	}
   
	return 0;
}
