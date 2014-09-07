#include<iostream>
using namespace std;
typedef unsigned long long ull;
int main(){
	int N;
	cin>>N;
	while(N--){
		int p;
		cin>>p;
		ull sum = 0,a,b;
		while(p--){
			cin>>a>>b>>b;
			sum+=a*b;
		}
		cout<<sum<<endl;
	}
	return 0;
}
