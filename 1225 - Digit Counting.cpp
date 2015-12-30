#include<bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	vector<vector<int> >v(10005, vector<int>(10));
	for(int i = 1;i<10005;++i){
		int temp = i;
		for(int j=0;j<10;++j)v[i][j] = v[i-1][j];	
		
		while(temp>0)v[i][temp%10]++,temp/=10;
	}
	int n,x;
	cin>>n;
	while(n--){
		cin>>x;
		for(int i = 0;i<9;++i){
			cout<<v[x][i]<<" ";
		}
		cout<<v[x][9]<<"\n";
	}
   
	return 0;
}
