//LAxus-Seyfert
#include<bits/stdc++.h>
using namespace std;

int main(){
   int x;  
   while(cin>>x){
   	string auxs;
      getline(cin,auxs);
      string s;
      getline(cin,s);
      stringstream iss(s);
      int aux;
      vector<int>v;
      while(iss>>aux)v.push_back(aux);   
      
      int n=v.size()-1;
      v[n] = 0;
      //derivamos:
      for(int i=0;i<v.size()-1;i++)v[i] = v[i]*(n-i);
      int sum = v[0];
      for(int i=1;i<v.size()-1;i++)sum = (sum)*x + v[i];        
      
      cout<<sum<<endl;
   }
    return 0;
}
