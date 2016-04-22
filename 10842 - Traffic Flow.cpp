#include<bits/stdc++.h>

using namespace std;


vector<int>v(1000000);
struct Edge{
	int x;
	int y;
	int w;	
};

bool cmp(Edge a, Edge b){
	return a.w<b.w;
}

int find(int a){
	return a==v[a]?a:v[a]=find(v[a]);
}
void Union(int a, int b){
	v[find(a)]=find(b);
}

bool sameFather(int a, int b){
	return find(a)==find(b);
}

int main(){
	int V,E,n;
	cin>>n;
	for(int caso=1;caso<=n;++caso){
		cin>>V>>E;
		vector<Edge>edge(E);
		vector<Edge>MST;
		int total=0;
		for(int i = 0;i<V;++i)v[i] = i;
		
		for(int i = 0;i<E;++i)cin>>edge[i].x>>edge[i].y>>edge[i].w, edge[i].w*=-1;	
		
		sort(edge.begin(),edge.end(),cmp);
		
		for(int i = 0;i<E;++i){
			if(!sameFather(edge[i].x, edge[i].y)){
				total +=edge[i].w;
				MST.push_back(edge[i]);
				Union(edge[i].x,edge[i].y);
			}
		}
		
		int mini = MST[0].w;
		for(int i = 1;i<MST.size();++i){
			mini=max(mini,MST[i].w);
		}
		cout<<"Case #"<<caso<<": "<<-mini<<endl;
		
	}
}
