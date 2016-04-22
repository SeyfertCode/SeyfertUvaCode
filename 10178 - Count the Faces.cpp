#include<bits/stdc++.h>
using namespace std;

vector<int>v(100);

int find(int a){
	return a==v[a]?a:v[a]=find(v[a]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}

int main(){
	int V,E;
	map<char,int>mm;
	while(cin>>V>>E){
		int cont = 1;
		for(int i = 1;i<=V;++i)v[i] = i;
		mm.clear();
		
		for(int i = 1;i<=E;++i){
			char a,b;
			cin>>a>>b;
			if(!mm[a])mm[a]=cont++;
			if(!mm[b])mm[b]=cont++;
			Union(mm[a], mm[b]);
		}
		vector<bool> root(100);
		for(int i = 1;i<=V;++i)root[find(i)]=true;
		int k=0;
		for(int i = 1;i<=V;++i){
			if(root[i])k++;
		}
		cout<<1+k+E-V<<endl;
	}
}
