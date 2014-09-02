//LAXUS-Seyfert
#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i = 0; i<N;++i){
		int a,b,c;
		cin>>a>>b>>c;
		cout<<"Case "<<i+1<<": ";
		if(a<=20&&b<=20&&c<=20)cout<<"good"<<endl;
		else cout<<"bad"<<endl;
	}
}
