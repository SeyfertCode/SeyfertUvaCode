#include<bits/stdc++.h>
#define MAX 1000
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
	int N;

	while(cin>>N){
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

		int q,a,b;
		cin>>q;
		double sum=0.0;
		while(q--){
			cin>>a>>b;
			Union(a,b);
		}
		vector<Edge>MST;
		for(int i = 0;i<(int)paths.size();++i){
			if(find(paths[i].x)!=find(paths[i].y)){
				Union(paths[i].x,paths[i].y);
				MST.push_back(paths[i]);
				q++;
				sum += paths[i].d;
			}
		}
		printf("%.2f\n",sum);
	}
	return 0;
}
