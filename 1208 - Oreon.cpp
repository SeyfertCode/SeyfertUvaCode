#include<bits/stdc++.h>

using namespace std;


vector<int>v(1000000);
struct Edge{
	int x;
	int y;
	int w;	
};

bool cmp(Edge a, Edge b){
	if(a.w==b.w){
		if(a.x==b.x)return a.y<b.y;
		else return a.x<b.x;
	}else return a.w<b.w;
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
	int n,V;
	cin>>n;
	for(int caso = 1;caso<=n;++caso){
		cin>>V;
		vector<Edge>edge;
		vector<Edge>MST;
		Edge e;
		char coma;
		for(int i = 0;i<V;++i)v[i] = i;
		int aux;
		for(int i = 0;i<V;++i){
			for(int j = 0;j<V;++j){
				cin>>aux;
				if(j<V-1)cin>>coma;
				if(aux>0){
					e.x=i;
					e.y=j;
					e.w=aux;
					edge.push_back(e);		
				}
			}
		}
		sort(edge.begin(),edge.end(),cmp);
		
		for(int i = 0;i<edge.size();++i){
			if(!sameFather(edge[i].x, edge[i].y)){
				MST.push_back(edge[i]);
				Union(edge[i].x,edge[i].y);
			}
		}
		cout<<"Case "<<caso<<":"<<endl;
		for(int i = 0;i<MST.size();++i){
			cout<<char(MST[i].x+'A')<<"-"<<char(MST[i].y+'A')<<" "<<MST[i].w<<endl;
		}
	
	}
}
