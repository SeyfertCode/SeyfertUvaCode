#include<bits/stdc++.h>
using namespace std;
#define MAX 500
vector<int>v(MAX+10);


int find(int a){
	return v[a]==a? a:find(v[a]);
}
bool parents(int a, int b){
	return find(a)==find(b);	
}
void Union(int a, int b){
	if(!parents(a,b)){
		v[find(a)] = find(b);	
	}
}
struct Edge{
	int x;
	int y;
	int d;	
};

int dist(string a, string b){
	int sum=0;
	for(int i=0;i<a.size();++i){
		int d= min((10+a[i]-b[i])%10,(10+b[i]-a[i])%10);
		sum+=d;
	}
	return sum;
}

bool cmp(Edge a, Edge b){
	return a.d<b.d;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vector<string>vs(N);
		vector<Edge>ve;
		vector<Edge>MST;
		for(int i=0;i<N;++i)v[i]=i,cin>>vs[i];
		for(int i = 0;i<N-1;++i){
			for(int j=i+1;j<N;++j){
				Edge e;
				e.x = i;
				e.y = j;
				e.d = dist(vs[i],vs[j]);
				ve.push_back(e);
			}
		}
		sort(ve.begin(),ve.end(),cmp);
		int rpta = 0;
		
		for(int i = 0;i<ve.size();++i){
			if(!parents(ve[i].x,ve[i].y)){
				rpta += ve[i].d;
				Union(ve[i].x,ve[i].y);
				MST.push_back(ve[i]);
			}
		}
		int dmin = 1e9;
		for(int i = 0;i<N;++i){
			dmin = min(dmin, dist(vs[i],"0000"));
		}
		
		
		cout<<rpta+dmin<<endl;
	}
   return 0;
}

