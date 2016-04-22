#include<cmath>
#include<iostream>
using namespace std;

int main(){
	long long T,n, r, s;
	cin>>T;
	for(int i=0;i<T;++i){
		if(i>0)cout<<endl;
		cin>>n;
		n= abs(n);
		if(n==0){cout<<3<<endl;continue;}
		r = ceil((-1+sqrt(1+8*n))/2);
		s = ((r*(r+1))>>1) - n;		
		cout<<r + (s&1)*((r&1)+1)<<endl;
	}
}

