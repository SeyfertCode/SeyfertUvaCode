#include<bits/stdc++.h>
using namespace std;

vector<int>v(5010);

int find(int a){
	return a==v[a]?a:v[a]=find(v[a]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}

int main(){
	int C,R;
	while(cin>>C>>R){
		if(C==0&&R==0)break;
		map<string, int>mm;
		string s;
		int cont=1;
		for(int i = 1;i<=C;++i)v[i] = i;
		for(int i = 0;i<C;++i){
			cin>>s;
			if(!mm[s])mm[s] = cont++;	
		}
		string a,b;
		for(int i = 0;i<R;++i){
			cin>>a>>b;
			Union(mm[a],mm[b]);
		}
		vector<int> root(5010);
		for(int i = 1;i<=C;++i){
			root[find(i)]++;	
		}

		int mayor = 0;
		
		for(int i = 1;i<=C;++i){
			mayor = max(mayor,root[i]);	
		}
		
		cout<<mayor<<endl;
	}
	return 0;
}
