#include<iostream>

using namespace std;

int main(){
	int N;
	while(cin>>N){
		int sum = N;
		while(N>=3){
			sum += N/3;
			N = N/3 + N%3;
		}
		if(N==2)sum++;
		cout<<sum<<endl;
	}
}
