#include<iostream>
#include<vector>
using namespace std;

vector<int>v(26);
int find(int a){
	return a==v[a]?a:v[a] = find(v[a]);
}
void Union(int a, int b){
	v[find(a)] = find(b);
}
bool sameFather(int a, int b){
	return find(a) == find(b);
}
int main(){
	int T, rpta;
	string s;
	bool flag = false;
	cin>>T;
	getline(cin,s);
	getline(cin,s);
	while(T--){
		getline(cin,s);
		int x = s[0] - 'A' + 1;
		int rpta = x;
		for(int i = 0; i<x;++i)v[i] = i;
		while(getline(cin,s)&&!s.empty()){
			int n1 = s[0] - 'A';
			int n2 = s[1] - 'A';
			if(!sameFather(n1,n2)){
				Union(n1,n2);
				rpta--;
			}
		}
		if(flag)cout<<endl;
		cout<<rpta<<endl; 
		flag = true;
	}
}
