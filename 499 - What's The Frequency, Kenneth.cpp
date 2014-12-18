//Laxus-Seyfert
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(getline(cin,s)){
		int freq=0;
		map<char,int>m;
		for(int i = 0; i<s.size();++i){
			if((s[i]>='a'&&s[i]<='z')or (s[i]>='A'&&s[i]<='Z')){
				m[s[i]]++;
				if(m[s[i]]>freq)freq = m[s[i]];
			}
		}
		for(map<char,int>::iterator it = m.begin(); it!=m.end();it++){
			if(it->second == freq)cout<<it->first;
		}
		cout<<" "<<freq<<endl;
	}	
	return 0;
}
