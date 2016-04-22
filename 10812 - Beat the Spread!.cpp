#include<iostream>

using namespace std;

int main(){
	int K;
	cin>>K;
	while(K--){
		int a,b;
		cin>>a>>b;
		int x = a+b;
		if(a<b or x&1)cout<<"impossible"<<endl;
		else x>>=1,cout<<x<<" "<<a-x<<endl;		
	}
}
