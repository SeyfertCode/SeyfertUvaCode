#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int cases=0;
	while(cin>>n){
		cin.get();
		string a,b;
		map<string,int>m;
		int cont = 0;
		vector<string>vd;
		vector<string>v1,v2;
		for(int i = 0;i<n;++i){
			cin>>a>>b;
			v1.push_back(a),v2.push_back(b);
			if(!m[a])m[a] = cont++,vd.push_back(a);
			if(!m[b])m[b] = cont++,vd.push_back(b);	
		}
		cin>>a>>b;
		if(!m[a])m[a] = cont++,vd.push_back(a);
		if(!m[b])m[b] = cont++,vd.push_back(b);
		vector<vector<bool> >ady(cont,vector<bool>(cont));
		
		for(int i = 0;i<n;++i){
			ady[m[v1[i]]][m[v2[i]]] = true;
			ady[m[v2[i]]][m[v1[i]]] = true;
		}
		
		//bfs
		vector<vector<string> >v(cont);//path
		vector<bool>visited(cont);
		queue<int>Q;
		Q.push(m[a]);
		visited[m[a]] = true;
		while(!Q.empty()){
			int aux = Q.front();
			Q.pop();
			if(aux==m[b])break;
			for(int i = 0;i<cont;++i){
				if(ady[aux][i]&&!visited[i]){

					for(int ci = 0;ci<(int)v[aux].size();++ci)v[i].push_back(v[aux][ci]);
					v[i].push_back(vd[aux] + " " + vd[i]);
					Q.push(i);
					visited[i] = true;
				}
			}
		}
		if(cases++>0)cout<<endl;
		if((int)v[m[b]].size()==0)cout<<"No route"<<endl;
		else{
			for(int i =0;i<(int)v[m[b]].size();++i)cout<<v[m[b]][i]<<endl;
		}
		
	}
  
	return 0;
}
