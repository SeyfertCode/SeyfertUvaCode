#include<iostream>
using namespace std;
int main(){
	int n,m,v,d,temp;
	char x[]={'R','L'};
	string r;
	while(cin>>n>>m){
		d = 0;
		r = "";
		if(n==1&&m==1)break;
		do{
			v = n/m;
			for(int i = 0;i<v;++i)r+=x[d];
			d = (d+1)%2;
			temp = m;
			m = n -v*m;
			n = temp;
		}while(n!=1);
		for(int i = 0;i<r.size()-1;++i)cout<<r[i];
		cout<<endl;
	}
}
