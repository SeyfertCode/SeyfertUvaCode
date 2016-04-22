#include<bits/stdc++.h>
#define MAX 105
using namespace std;
vector<vector<bool> >m(MAX, vector<bool>(MAX));
vector<vector<int> >ans(MAX);
int n;
void bfs(int x){
	queue<int>Q;
	Q.push(x);
	vector<int>visited(n+1);
	int cont  = n;
	while(!Q.empty()){
		int aux = Q.front();
		Q.pop();
		for(int i = 1;i<=n;++i){
			if(m[aux][i]&&!visited[i])Q.push(i),visited[i]=1, cont--;
		}
	}
	cout<<cont;
	for(int i = 1;i<=n;++i){
		if(!visited[i])cout<<" "<<i;
	}

}

int main(){
	std::ios::sync_with_stdio(false);
	int k,c,x;
	while(cin>>n){
		if(n==0)break;
		m.clear();
		m.resize(MAX, vector<bool>(MAX));

		while(cin>>k){
			if(k==0)break;
			while(cin>>x){
				if(x==0)break;
				m[k][x]=true;
			}
		}
		cin>>k;
		for(int i = 0;i<k;++i){
			cin>>c;
			bfs(c);
			cout<<"\n";
		}
	}
   
	return 0;
}

