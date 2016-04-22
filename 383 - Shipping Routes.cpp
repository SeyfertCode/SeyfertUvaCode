#include<bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int T,n,cont,e,q,aux;
	string a,b;
	cin>>T;
	cout<<"SHIPPING ROUTES OUTPUT"<<endl;
	for(int cases=1;cases<=T;++cases){
		cout<<endl<<"DATA SET  "<<cases<<endl<<endl;
		cont=0;
		cin>>n>>e>>q;
		vector<vector<int> >ady(n,vector<int>(n));
		map<string,int>m;
		for(int i = 0;i<n;++i)cin>>a,m[a]=cont++;
		for(int i = 0;i<e;++i)cin>>a>>b,ady[m[a]][m[b]]=1,ady[m[b]][m[a]]=1;
		for(int i = 0;i<q;++i){
			cin>>aux>>a>>b;
			//bfs
			queue<int>Q;
			vector<int>visited(n);
			Q.push(m[a]);
			bool flag = false;
			while(!Q.empty()&&!flag){
				int x = Q.front();
				Q.pop();
				if(x==m[b]){flag=true;break;}
				for(int i=0;i<n;++i){
					if(ady[x][i]>0&&visited[i]==0){
						visited[i] = visited[x]+1;
						Q.push(i);
					}
				}
			}
			if(flag)cout<<"$"<<aux*visited[m[b]]*100<<endl;
			else cout<<"NO SHIPMENT POSSIBLE"<<endl;
		}
	}
   cout<<endl<<"END OF OUTPUT"<<endl;
	return 0;
}
