#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(string a, string b){
	return (a+b)>(b+a);
}
int main(){
	int N;
	while(cin>>N){
		if(N==0)break;
		vector<string>v(N);
		for(int i = 0; i<N;++i)cin>>v[i];
		//ordenamos
		sort(v.begin(),v.end(),compare);
		//mostramos
		for(int i = 0;i<N;++i)cout<<v[i];
		cout<<endl;
	}
}
