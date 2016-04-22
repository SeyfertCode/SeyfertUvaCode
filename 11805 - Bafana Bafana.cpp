#include<bits/stdc++.h>

using namespace std;

int main(){
	int N,K,P,T;
	cin>>T;
	for(int i=0;i<T;++i){
		cin>>N>>K>>P;
		cout<<"Case "<<i+1<<": "<<((K+P)%N==0)*N + (K+P)%N<<endl;
	}
   

}
