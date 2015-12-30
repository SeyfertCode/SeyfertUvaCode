#include<bits/stdc++.h>
#define MAX 505
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
	int c,s;
	int N;
	cin>>N;
	while(N--){
		while(cin>>c>>s){

			for(int i=0;i<s;++i)v[i] = i;
			vector<Edge> paths;
			Edge aux;
			vector<int>vx(s),vy(s);
			for(int i = 0;i<s;++i)cin>>vx[i]>>vy[i];
			for(int i = 0;i<s-1;++i){
				for(int j = i+1;j<s;++j){
					aux.x = i;
					aux.y = j;
					aux.d = sqrt((vx[i]-vx[j])*(vx[i]-vx[j]) + (vy[i]-vy[j])*(vy[i]-vy[j]));
					paths.push_back(aux);
				}
			}
				
			sort(paths.begin(),paths.end(),cmp);
			
			vector<Edge>MST;
			for(int i = 0;(int)MST.size()<s-1;++i){
				if(find(paths[i].x)!=find(paths[i].y)){
					Union(paths[i].x,paths[i].y);
					MST.push_back(paths[i]);
				}
			}
			
			printf("%.2f\n",MST[s-c-1].d);
		}
   }
	return 0;
}
