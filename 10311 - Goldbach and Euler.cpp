#include<iostream>
#include<vector>
using namespace std;
int c = 100000000;
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
		if(N<4){
			cout<<N<<" is not the sum of two primes!."<<endl;
			continue;
		}
		if(N&1){
			if(!v[N-2])cout<<N<<" is the sum of "<<2<<" and "<<N-2<<"."<<endl;
			else cout<<N<<" is not the sum of two primes!."<<endl;
		}else{
			int centro = N/2;
			if(N==centro*2)centro--;
			bool flag = false;
			for(int i = centro; i>=3;--i){
				if(!v[i] && !v[N-i]){
					cout<<N<<" is the sum of "<<i<<" and "<<N-i<<"."<<endl;
					flag = true;
					break;
				}
			}
			if(!flag)cout<<N<<" is not the sum of two primes!."<<endl;
		}
	}
}
