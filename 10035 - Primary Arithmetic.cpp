#include<bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	unsigned long long int a,b,acarrea,n_acarrea;
	while(cin>>a>>b){
		if(a==0&&b==0)break;
		acarrea = 0;
		n_acarrea = 0;
		while(a>0||b>0){
			acarrea = (acarrea+b%10+a%10)/10;
			if(acarrea>0)n_acarrea++;  
			a/=10;
			b/=10;         
		}
		if(n_acarrea==0)cout<<"No carry operation."<<endl;
		else if(n_acarrea==1)cout<<"1 carry operation."<<endl;
		else cout<<n_acarrea<<" carry operations."<<endl;       
   }
	return 0;
}
