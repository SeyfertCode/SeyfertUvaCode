#include<bits/stdc++.h>

using namespace std;


vector<int>v(1000);
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
	map<string,int>mm;
	while(cin>>V>>E){
		if(V==0&&E==0)break;
		vector<Edge>edge(E);
		long long total=0;
		string a,b;
		int cant=0;
		mm.clear();
		for(int i = 1;i<=V;++i){
			v[i] = i;	
			cin>>a;
			mm[a]=i;	
		}
	
		for(int i = 0;i<E;++i){
			cin>>a>>b>>edge[i].w;
			edge[i].x=mm[a];
			edge[i].y=mm[b];	
		}
		cin>>a;
		cant = V-1;
		sort(edge.begin(),edge.end(),cmp);
		for(int i = 0;i<E&&cant;++i){
			if(!sameFather(edge[i].x, edge[i].y)){
				total +=edge[i].w;
				cant--;
				Union(edge[i].x,edge[i].y);
			}
		}
		if(cant) cout<<"Impossible"<<endl;
		else cout<<total<<endl;
		
	}
}
