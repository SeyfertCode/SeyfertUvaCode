//Laxus-Seyfert
#include<iostream>
#include<cstring>

using namespace std;
typedef unsigned long long ull;
bool isMulti(string, ull, ull);

int main(){

   string s;
   string aux = "";
   while(cin>>s){
      aux+=s;
      if(aux[aux.size()-1]=='#'){
         (isMulti(aux,2,131071))?cout<<"YES"<<endl:cout<<"NO"<<endl;   
         aux="";
      }          
   }
   return 0;
}

bool isMulti(string s, ull n, ull m){
   ull res = 1;
   ull mod = 0;
   for(int i= s.size()-2;i>=0;i--){
      mod += ((s[i]-48)*res)%m;
      mod = mod%m;
      res = (res*n)%m;
   }
   return mod==0?true:false;
}
