#include<iostream>

using namespace std;

int main(){
	int K;
	cin>>K;
	while(K--){
		int x;
		cin>>x;
		int a = 0, b= 0;
		int aux = x;
		while(aux>0){
			a += aux&1;
			aux>>=1;
		}
		int c;
		aux = x;
		while(aux>0){
			c = aux%10;
			aux/=10;
			while(c>0){
				b+=c&1;
				c>>=1;
			}
		}
		cout<<a<<" "<<b<<endl;
	}

}
