#include<bits/stdc++.h>
using namespace std;

//please, check this input: http://www.algorithmist.com/index.php/UVa_793

vector<int>v(100000);

int find(int a){
	return a==v[a]?a:v[a]=find(v[a]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}

bool sameFather(int a, int b){
	return find(a)==find(b);
}
int main(){
	int N;
	char x;
	int n;
	cin>>n;
	string aux;
	
	for(int cas = 0;cas<n;++cas){
		cin>>N;
		int a,b;
		int T=0,F=0;
		for(int i = 1;i<=N;++i)v[i] = i;
		cin.get();
		while(getline(cin,aux)){
			if(aux=="")break;
			stringstream ss(aux);
			ss>>x>>a>>b;
			
			if(x=='c'){
				Union(a,b);	
			}else{
				if(sameFather(a,b))T++;
				else F++;
			}	
		
		}
		if(cas>0)cout<<endl;
		cout<<T<<","<<F<<endl;
	}
}
