#include<iostream>
using namespace std;

typedef long long ll;

int gcd(ll a, ll b, ll &x, ll &y){
	if(b==0){
		x = 1,y=0;
		return a;
	}
	ll aux, r;
	r = gcd(b,a%b,x,y);
	aux = x;
	x = y;
	y = aux-a/b*y;
	return r;
	
}
int main(){
	ll a,b,x,y,r;
	while(cin>>a>>b){
		r = gcd(a,b,x,y);
		cout<<x<<" "<<y<<" "<<r<<endl;
	}
}
