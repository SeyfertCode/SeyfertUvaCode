//LAXUS-Seyfert
#include<iostream>

using namespace std;

typedef unsigned long long ull;
ull square(ull x){return x*x;}
ull bigMod(ull a, ull b, ull m){
    if(b==0)return 1;
    if(b&1) return a*bigMod(a,b-1,m)%m;    
    else return square(bigMod(a,b/2,m)%m)%m;
}
int main()
{
	ull a,b,m;
	while(cin>>a>>b>>m){  
        cout<<bigMod(a,b,m)<<endl;
    }
	return 0;
}
