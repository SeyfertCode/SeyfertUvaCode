//RANK 9!! :D
#include<bits/stdc++.h>
#define MAX 1005
#define NONE 10000
using namespace std;
int n,cant;
vector<int>vx(MAX),vy(MAX);
vector<bool>visited(MAX);
int dist(pair<int,int> x, pair<int,int>y){
	return (x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second);
}
pair<int,int>p;
bool cmp(pair<int,pair<int,int> >x, pair<int,pair<int,int> >y){
	if(dist(x.second,p)==dist(y.second,p)){
		if(x.second.first==y.second.first)return x.second.second<y.second.second;
		else return x.second.first<y.second.first;
	}else{
		return dist(x.second,p)<dist(y.second,p);
	}
}
void bfs(int x){
	visited[x] = true;
	vector<pair<int, pair<int,int> > >ans;
	p.first = vx[x];
	p.second = vy[x];
	for(int i = 0;i<n;++i){
		if(i==x)continue;
		pair<int,pair<int,int> >temp;
		temp.first = i;
		temp.second.first = vx[i];
		temp.second.second = vy[i];
		ans.push_back(temp);
		if((int)ans.size()>2){
			sort(ans.begin(),ans.end(),cmp);
			ans.erase(ans.begin()+(int)ans.size()-1);
		}
	}
	if(!visited[ans[0].first])cant++,bfs(ans[0].first);
	if(!visited[ans[1].first])cant++,bfs(ans[1].first);
	
}
int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while(cin>>n){
		if(n==0)return 0;
		
		visited.clear();
		visited.resize(MAX);
		for(int i =0;i<n;++i)cin>>vx[i]>>vy[i];
		if(n<4){cout<<"All stations are reachable.\n";continue;}
		cant = 1;
		bfs(0);
		if(cant<n)cout<<"There are stations that are unreachable.\n";
		else cout<<"All stations are reachable.\n";
		
	}
   
	return 0;
}
