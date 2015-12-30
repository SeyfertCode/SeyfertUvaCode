#include<bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int N;
	while(cin>>N){
		if(N==0)break;
		int sum = 0;
		while(N>=3){
			sum += N/3;
			N = N/3 + N%3;
		}
		if(N==2)sum++;
		cout<<sum<<endl;
	}
}
