#include<bits/stdc++.h>
using namespace std;

vector<int>v(30);

int find(int a){
	return a==v[a]?a:v[a]=find(v[a]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}

int main(){
	int N;
	string s;
	cin>>N;
	while(N--){
		vector<char>vx;
		vector<char>vy;
		map<char,int>mm;
		while(cin>>s){
			if(s[0]=='*')break;
			vx.push_back(s[1]);
			vy.push_back(s[3]);
		}
		cin>>s;
		int l = (s.size()+1)/2;
		for(int i = 1;i<=l;++i){
			mm[s[2*i-2]] = i;
			v[i] = i;	
		}
		for(int i = 0;i<vx.size();++i){
			Union(mm[vx[i]], mm[vy[i]]);
		}
		vector<int> root(30);
		for(int i = 1;i<=l;++i){
			root[find(v[i])]++;
		}
		
		int tree=0, acorn=0;
		for(int i = 1;i<=l;++i){
			if(root[i]==1)acorn++;
			else if (root[i]>0)tree++;
		}
		
		cout<<"There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s)."<<endl;
		
	}
	return 0;
}
