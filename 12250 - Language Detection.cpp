//LAXUS-SeyfertCode
using namespace std;
#include<iostream>
#include<map>
using namespace std;

int main(){
	map<string,string>m;
	m["HELLO"] = "ENGLISH";
	m["HOLA"] = "SPANISH";
	m["HALLO"] = "GERMAN";
	m["BONJOUR"] = "FRENCH";
	m["CIAO"] = "ITALIAN";
	m["ZDRAVSTVUJTE"] = "RUSSIAN";
	
	string s;
	int i = 0;
	while(cin>>s){
		if(s=="#")break;
		i++;
		cout<<"Case "<<i<<": ";
		if(m[s]=="")cout<<"UNKNOWN"<<endl;
		else cout<<m[s]<<endl;
	}
	


}
