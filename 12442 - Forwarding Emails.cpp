#include<bits/stdc++.h>

using namespace std;
vector<int>v;
vector<bool>vx,vy;
int T,n,a,b;

int dfs(int x){
	int ans = 0,next;
	vy[x] = true;
	next = v[x];
	if(!vy[next])ans = dfs(next)+1;
	vx[x] = true;
	vy[x] = false;
	return ans;
	
}
int main(){
	std::ios::sync_with_stdio(false);
 
   cin>>T;
   for(int cases = 1;cases<=T;cases++){
		int maxi = 0, maxn = 1;
		cin>>n;
		v.clear();
		v.resize(n+1);
		vx.clear();
		vx.resize(n+1);
		vy.clear();
		vy.resize(n+1);
		for(int i = 0;i<n;++i)cin>>a>>b,v[a] = b;
		maxi = -1;
		for(int i = 1;i<=n;++i){
			if(vx[i])continue;
			int temp = dfs(i);
			if(temp>maxi)maxi = temp,maxn=i; 
		}
		cout<<"Case "<<cases<<": "<<maxn<<"\n";
	}
	return 0;
}
