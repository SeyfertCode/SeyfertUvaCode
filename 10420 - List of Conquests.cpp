//Laxus-Seyfert
#include<bits/stdc++.h>
using namespace std;

int main(){
   int N;
   cin>>N;
	map<string,int> m;
	map<string, int>::iterator it;
	cin.ignore();
   while(N--){
   	string s;
      getline(cin,s); 
      istringstream iss(s);   
      string country;
      iss>>country;
      m[country]++;   
   }
   for(it = m.begin(); it!=m.end();it++)cout<<it->first<<" "<<(*it).second<<endl;    

	return 0;
}
