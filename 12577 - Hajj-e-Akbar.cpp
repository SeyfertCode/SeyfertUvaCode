//LAXUS-Seyfert
#include<iostream>
using namespace std;
int main(){
	string s;
	int c = 0;
	while(cin>>s){
		if(s == "*")break;
		cout<<"Case "<<++c<<": ";
		if(s == "Hajj")cout<<"Hajj-e-Akbar"<<endl;	
		else cout<<"Hajj-e-Asghar"<<endl;		
	}
}
