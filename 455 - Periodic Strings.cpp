//Laxus - Seyfert
#include<iostream>
#include<set>
using namespace std;
int repeat(string);
int main(){
   int N;
   cin>>N;
   for(int i=0;i<N;i++){
      string s;
      if(i>0)cout<<endl<<endl;
      cin>>s;
      cout<<repeat(s);
   }
   cout<<endl;
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
   return aux;
}
