#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
vector<int>v(MAX);
int find(int a){
	return v[a]==a?a:v[a]=find(v[a]);
}

void Union(int a, int b){
	v[find(a)] = find(b);	
}

bool parents(int a, int b){
	return find(a)==find(b);
}
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		for(int i=0;i<n;++i)v[i] = i;
		int k, x,y;
		while(m--){
			cin>>k;
			cin>>x;
			while(k-->1){
				cin>>y;
				if(!parents(x,y))Union(x,y);
			}
		}
		//buscamos al padre de '0'.
		int r = find(0);
		int cont = 0;
		for(int i = 0;i<n;++i){
			if(find(v[i])==r)cont++;
		}
		
		cout<<cont<<endl;
	}
   return 0;
}

