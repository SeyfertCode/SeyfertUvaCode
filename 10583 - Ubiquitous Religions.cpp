#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
vector<int>v(MAX+10);

int find(int a){
	return v[a]==a? a:find(v[a]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}
int main(){
	int caso = 0;
	int N,M;
	while(cin>>N>>M){
		if(N==0&&M==0)break;
		caso++;
		for(int i = 1;i<=N;++i)v[i] = i;
		int x,y;
		while(M--){
			cin>>x>>y;
			Union(x,y);
		}
		set<int>ms;
		for(int i = 1;i<=N;++i){
			ms.insert(find(v[i]));
		}
		cout<<"Case "<<caso<<": "<<ms.size()<<endl;
	}
   return 0;
}

