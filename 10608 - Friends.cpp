#include<iostream>
#include<vector>
using namespace std;
vector<int>v(500001);
int find(int n){
	return n==v[n]? n: v[n] = find(v[n]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,r;
		cin>>n;
		for(int i = 0; i<n;++i)v[i] = i;
		cin>>r;
		while(r--){
			int a,b;
			cin>>a>>b;
			Union(a-1,b-1);				
		}
		vector<int>raiz(n);
		for(int i = 0; i<n;++i)raiz[find(i)]++;//buscamos la longitud
		//buscamos el mayor
		int mayor = raiz[0];
		for(int i = 0; i<n;++i){
			if(mayor<raiz[i])mayor = raiz[i];
		}
		cout<<mayor<<endl;
	}
}
