//Laxus-Seyfert
#include<bits/stdc++.h>
using namespace std;
int repeat(string);

int main(){
   string s;
   while(cin>>s){
      if(s[0]=='.')break;   
      cout<<repeat(s)<<endl;
   }
   return 0;
}
int repeat(string s){
   
   int aux=1,lon=s.length();   
   while(aux<lon){
      set<string>mySet;
      if(lon%aux!=0){
         aux++;
         continue;   
      }
      for(int i=0;i<lon;i+=aux)mySet.insert(s.substr(i,aux));        
      
      if(mySet.size()==1)break;
      aux++;      
   }
   return lon/aux;
}
