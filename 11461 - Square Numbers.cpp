#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef unsigned long long ull;
int main(){
	vector<ull>v(MAX);
   for(int i = 1;i<MAX;++i)v[i] = i*i;
   int a,b;
   while(cin>>a>>b){
		if(a==0&&b==0)break;
		cout<<upper_bound(v.begin(),v.end(),b) - lower_bound(v.begin(),v.end(),a)<<endl;
	}
	return 0;
}
