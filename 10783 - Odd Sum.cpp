//Laxus-Seyfert
#include<bits/stdc++.h>

using namespace std;

int main(){
   int N;
   cin>>N;
	int a, b;
	for(int X=1;X<=N;X++){
   	cin>>a>>b;
      if(a%2==0)a++;
      if(b%2==0)b--;
      int sum=0;
      for(int i=a;i<=b;i=i+2)sum+=i;  
      cout<<"Case "<<X<<": "<<sum<<endl;  
    }
	return 0;
}
