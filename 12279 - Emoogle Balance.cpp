//LAXUS.Seyfert
#include<iostream>
using namespace std;

int main(){
	int K;
	int caso =0;
	while(cin>>K){
		if(K==0)break;
		int aux;
		int t = 0, r= 0;
		for(int i = 0;i<K;++i){
			cin>>aux;
			if(aux==0)t++;
			else r++;	
		}
		cout<<"Case "<<++caso<<": "<<r-t<<endl;
	}
}
