#include<iostream>
#include<vector>
using namespace std;
int c = 1000000;
vector<bool>v(c);
void sieve(){
	v[0]=1;
	v[1]=1;
	for(int i = 2; i*i<=c;++i){
		if(!v[i]){
			for(int j = i*i;j<c;j+=i)v[j] = true;
		}
	}
}
int main(){
	sieve();
	int N;
	while(cin>>N){
		if(N==0)break;
		int centro = N/2;
		bool flag = false;
		for(int i = 0; i<=centro;++i){
			if(!v[i] && !v[N-i]){
				cout<<N<<" = "<<i<<" + "<<N-i<<endl;
				flag = true;
				break;
			}
		}
		if(!flag)cout<<"Goldbach's conjecture is wrong."<<endl;//nunca ocurrirá esto :P
	}
}
