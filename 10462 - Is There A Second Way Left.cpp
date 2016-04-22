#include<bits/stdc++.h>

using namespace std;


vector<int>v(1000);
struct Edge{
	int x;
	int y;
	int w;	
	int n;
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

bool equal(vector<Edge>a, vector<Edge> b){
	if(a.size()!=b.size())return false;
	
	for(int i = 0;i<a.size();++i){
		if(a[i].x==b[i].x&&a[i].y==b[i].y&&a[i].w==b[i].w){
			;
		}else return false;
	}	
	return true;
}

int main(){
	int N;
	cin>>N;
	for(int caso = 1;caso<=N;++caso){
		int V,E;
		cin>>V>>E;
		vector<Edge>edge(E);
		vector<Edge>MST;
		int total=0, total2=0;
		for(int i = 1;i<=V;++i)v[i] = i;
		for(int i = 0;i<E;++i){
			cin>>edge[i].x>>edge[i].y>>edge[i].w;
			edge[i].n=i;
			total2+=edge[i].w;
		}
		sort(edge.begin(),edge.end(),cmp);
		
		for(int i = 0;i<E;++i){
			if(!sameFather(edge[i].x, edge[i].y)){
				total +=edge[i].w;
				MST.push_back(edge[i]);
				
				Union(edge[i].x,edge[i].y);
			}
		}
		cout<<"Case #"<<caso<<" : ";
		if(V-1!=MST.size()){
			cout<<"No way"<<endl;	
		}else{
			bool flag=false;
			for(int j = 0;j<MST.size();++j){
				vector<Edge>MST2;
				for(int i = 1;i<=V;++i)v[i] = i;
				int aux=0;
				for(int i = 0;i<E;++i){
					if(MST[j].x==edge[i].x&&MST[j].y==edge[i].y&&MST[j].n==edge[i].n){
					}
					else{
						if(!sameFather(edge[i].x, edge[i].y)){
							aux +=edge[i].w;
							MST2.push_back(edge[i]);
							Union(edge[i].x,edge[i].y);
						}
					}
				}
				if(V-1==MST2.size())total2=min(total2,aux), flag=true;
			}
			if(!flag)cout<<"No second way"<<endl;	
			else cout<<total2<<endl;
		}
	}
}
