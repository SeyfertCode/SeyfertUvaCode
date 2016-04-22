#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	while(N--){
		string s;
		cin>>s;
		string r= "";
		if(s[s.size()-1]=='5'&&s[s.size()-2]=='3')r = "-";
		else if(s[0]=='9'&&s[s.size()-1]=='4')r = "*";
		else if(s[0]=='1'&&s[1]=='9'&&s[2]=='0')r = "?";
		else r= "+";
		cout<<r<<endl;
	}
}
