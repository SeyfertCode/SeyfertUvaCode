#include<bits/stdc++.h>

using namespace std;
int dif(string a, string b){
	int cont=0;
	for(int i =0;i<(int)a.size();++i){
		if(a[i]!=b[i])cont++;
		if(cont>1)return false;
	}
	return true;
}
int main(){
	
	int T;
	cin>>T;
	for(int cases=0;cases<T;cases++){
		string s;
		map<string,int>m;
		vector<string>vs;
		int cont = 0;
		while(cin>>s&&s[0]!='*')vs.push_back(s),m[s]=cont++;
		
		vector<vector<bool> >ady(cont, vector<bool>(cont));
		
		for(int i = 0;i<cont-1;++i){
			for(int j = i+1;j<cont;++j){
				if(dif(vs[i],vs[j]))ady[m[vs[i]]][m[vs[j]]] = true, ady[m[vs[j]]][m[vs[i]]] = true;
			}
		}
		if(cases>0)cout<<endl;
		cin.get();
		while(getline(cin,s)&&(int)s.size()>0){
			string a,b;
			stringstream ss(s);
			ss>>a;ss>>b;
			
			//bfs
			queue<int>Q;
			vector<int>v(cont);
			Q.push(m[a]);
			while(!Q.empty()){
				int aux = Q.front();
				Q.pop();
				if(aux==m[b])break;
				for(int i = 0;i<cont;++i){
					if(ady[aux][i]&&v[i]==0){
						Q.push(i);
						v[i] = v[aux] + 1;
					}
				}
			}
			
			cout<<a<<" "<<b<<" "<<v[m[b]]<<endl;
		}
	}
   
	return 0;
}

