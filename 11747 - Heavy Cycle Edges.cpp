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
	int V,E;
	while(cin>>V>>E){
		if(V==0&&E==0)break;
		vector<Edge>edge(E);
		vector<int>noUsado;
		for(int i = 0;i<V;++i)v[i] = i;
		for(int i = 0;i<E;++i)cin>>edge[i].x>>edge[i].y>>edge[i].w;	
		
		sort(edge.begin(),edge.end(),cmp);
		
		for(int i = 0;i<E;++i){
			if(!sameFather(edge[i].x, edge[i].y)){
				Union(edge[i].x,edge[i].y);
			}else{
				noUsado.push_back(edge[i].w);
			}
		}
		
		
		if(noUsado.size()==0)cout<<"forest"<<endl;
		else{
			sort(noUsado.begin(),noUsado.end());
			for(int i = 0;i<noUsado.size();++i){
				if(i>0)cout<<" ";
				cout<<noUsado[i];
			}
			cout<<endl;
		}
	}
}

