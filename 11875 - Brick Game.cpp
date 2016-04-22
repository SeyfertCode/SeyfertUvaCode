#include<bits/stdc++.h>

using namespace std;

int main(){
	int T,N;
	cin>>T;
	for(int cases=1;cases<=T;++cases){
		cin>>N;
		vector<int>v(N);
		for(int i=0;i<N;++i)cin>>v[i];
		sort(v.begin(),v.end());
		cout<<"Case "<<cases<<": "<<v[N>>1]<<endl;
	}
   

}
