#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int>v(101);
	for(int i=1;i<101;++i)v[i] = v[i-1] + i*i;
	int N;
	while(cin>>N){
		if(N==0)break;
		cout<<v[N]<<endl;
	}
   return 0;
}
