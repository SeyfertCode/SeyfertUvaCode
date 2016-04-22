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
	for(int caso = 0;caso<n;++caso){
		int total=0;
		int precio;
		cin>>V>>E>>precio;
		vector<Edge>edge(E);
		vector<Edge>MST;
		for(int i = 1;i<=V;++i)v[i] = i;
		
		for(int i = 0;i<E;++i)cin>>edge[i].x>>edge[i].y>>edge[i].w;	
		
		sort(edge.begin(),edge.end(),cmp);
		
		for(int i = 0;i<E;++i){
			if(!sameFather(edge[i].x, edge[i].y)&&edge[i].w<precio){
				total +=edge[i].w;
				Union(edge[i].x,edge[i].y);
			}
		}
		
		vector<int>root(V+1);
		int cont=0;
		for(int i = 1;i<=V;++i)root[find(i)]++;
		for(int i = 1;i<=V;++i){
			if(root[i]>0)cont++;
		}
		cout<<"Case #"<<caso+1<<": "<<cont*precio+total<<" "<<cont<<endl;
		
	}
}
