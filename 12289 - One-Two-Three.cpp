//LAXUS-Seyfert
#include<iostream>
using namespace std;
int mistakes(string a, string s);
int main(){
	int N;
	cin>>N;
	while(N--){
		string s;
		cin>>s;
		if(s.size()==5)cout<<"3"<<endl;
		else if(mistakes(s,"one")<=1)cout<<"1"<<endl;
		else cout<<"2"<<endl;	
	}
}
int mistakes(string a, string s){
	int cont = 0;
	for(int i = 0;i<a.size();++i){
		if(a[i]!=s[i])cont++;
	}
	return cont;
}
