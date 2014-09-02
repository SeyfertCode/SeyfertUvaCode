//LAXUS-Seyfert
#include<iostream>
using namespace std;

int main(){
	int total = 0;
	int N;
	cin>>N;
	while(N--){
		string s;
		cin>>s;
		int aux;
		if(s=="donate")cin>>aux,total+=aux;
		else cout<<total<<endl;
	}
}
