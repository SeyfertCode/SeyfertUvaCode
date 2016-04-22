#include<bits/stdc++.h>

using namespace std;


vector<int>v(1000010);
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
	int n;
	bool flag= false;
	while(cin>>n){
		if(flag)cout<<endl;
		flag=true;
		int total = 0,a,b,c;
		for(int i= 1;i<n;++i)cin>>a>>b>>c,total+=c;
		cout<<total<<endl;
		vector<Edge>edge;
		Edge aux;
		int K,M;
		cin>>K;
		for(int i = 0;i<K;++i)cin>>aux.x>>aux.y>>aux.w,edge.push_back(aux);	
		cin>>M;
		for(int i = K;i<M+K;++i)cin>>aux.x>>aux.y>>aux.w,edge.push_back(aux);
		
		total=0;
		
		for(int i = 1;i<=n;++i)v[i] = i;
		
		
		sort(edge.begin(),edge.end(),cmp);
		
		for(int i = 0;i<M+K;++i){
			if(!sameFather(edge[i].x, edge[i].y)){
				total +=edge[i].w;
				Union(edge[i].x,edge[i].y);
			}
		}
		
	
		cout<<total<<endl;
	}
		
}
