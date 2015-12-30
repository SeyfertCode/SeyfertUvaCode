#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull ackerman(ull x){
	ull c=0;
	do{
		x = (x&1)?3*x+1:x>>1;
		c++;
	}while(x>1);
	return c;
}
int main(){
	ull xa,xb;
	while(cin>>xa>>xb){
		if(xa==0&&xb==0)break;
		ull a = min(xa,xb), b = max(xa,xb);
		ull maxi=ackerman(a),maxv=a;
		for(ull i=a+1;i<=b;++i){
			ull x = ackerman(i);
			if(x>maxi)maxi = x, maxv=i;
		}
		cout<<"Between "<<a<<" and "<<b<<", "<<maxv<<" generates the longest sequence of "<<maxi<<" values."<<endl;
	}
	return 0;
}
