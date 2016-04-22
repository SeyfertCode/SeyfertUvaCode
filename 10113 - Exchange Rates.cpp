#include<bits/stdc++.h>
#define MAX 65
using namespace std;
typedef long long ull;
vector<vector<ull> >v(MAX, vector<ull>(MAX,0));
ull cont;

ull gcd(ull a, ull b){
	if(b==0)return a;
	return gcd(b,a%b);
}
pair<ull,ull> bfs(ull x, ull y){
	pair<ull,ull>ans;
	vector<ull>visn(MAX,-1),visd(MAX,-1);
	queue<ull>Q;
	Q.push(x);
	visn[x]=1;
	visd[x]=1;
	while(!Q.empty()){
		ull temp = Q.front();
		Q.pop();
		if(temp==y){
			ull g = gcd(visn[temp],visd[temp]);
			visn[temp]/=g;visd[temp]/=g;
			ans.first = visn[temp];
			ans.second = visd[temp];
			v[x][y] = ans.second;
			v[y][x] = ans.first;
			return ans;
		}
		for(ull i = 1;i<cont;++i){
			if(v[temp][i]!=0&&visn[i]==-1){
				visn[i] = visn[temp]*v[i][temp];
				visd[i] = visd[temp]*v[temp][i];
				ull g = gcd(visn[i],visd[i]);
				visn[i]/=g;visd[i]/=g;
				Q.push(i);
			}
		}
	}
	ans.first = -1;
	ans.second = -1;
	return ans;
}
int main(){
   std::ios::sync_with_stdio(false);
   char c;
   map<string,ull>m;

   ull a,b;
   cont=1;
   string sa,sb;
   while(cin>>c){
		if(c=='.')return 0;
		else if(c=='!'){
			
			cin>>a>>sa>>c>>b>>sb;
			ull g = gcd(a,b);
			
			if(!m[sa])m[sa]=cont++;
			if(!m[sb])m[sb]=cont++;
			
			v[m[sa]][m[sb]] = b/g;
			v[m[sb]][m[sa]] = a/g; 
			
		}else{
			cin>>sa>>c>>sb;
			pair<ull,ull>p = bfs(m[sa], m[sb]);
			if(p.first ==-1)cout<<"? "<<sa<<" = ? "<<sb<<endl;
			else cout<<p.first<<" "<<sa<<" = "<<p.second<<" "<<sb<<endl;
		}
	}
}
