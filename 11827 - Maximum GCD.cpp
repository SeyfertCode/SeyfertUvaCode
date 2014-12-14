//Laxus-Seyfert
#include<bits/stdc++.h>
/********************************************************************************/
using namespace std;

typedef unsigned long long ull;
/********************************************************************************/
ull e(ull a, ull b){
   if(b==0)return a;
   return e(b,a%b);   
}
/********************************************************************************/
int main(){
   int N;
   cin>>N;
   cin.ignore();
   while(N--){
      string s;
      getline(cin,s);
      int mcd=1,b;
      vector<int>v;
      stringstream iss(s);
      int aux;
      while(iss>>aux)v.push_back(aux);  
      int maxGCD=1;
      for(int i=0;i<v.size()-1;i++){
         for(int j=i+1;j<v.size();j++){
            ull x = e(v[i],v[j]);
            if(x>maxGCD)maxGCD = x;   
         }
      }
      cout<<maxGCD<<endl;
   }
    return 0;
}

