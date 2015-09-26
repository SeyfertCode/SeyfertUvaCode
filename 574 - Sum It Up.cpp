#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>a, vector<int> b){
	int l = min(a.size(),b.size());
	
	for(int i=0;i<l;++i){
		if(a[i]!=b[i])return a[i]>b[i];
	}
	return a.size()<b.size();
	
	
	
}
int main(){
	int n,s,aux,cont,r,sum;
	bool flag;
	while(cin>>s>>n){
		if(n==0 && s==0)break;
		vector<int>v(n);
		for(int i = 0; i<n;++i)cin>>v[i];
		printf("Sums of %d:\n",s);
		flag = true;
		set<vector<int> >ms;
		vector<vector<int> >rpta;
		for(int i = 1;i< (1<<n);++i){
			aux = i;
			sum = 0;
			cont = 0;
			vector<int>v2;
			while(aux>0){
				r = aux&1;
				aux >>= 1;
				if(r==1)v2.push_back(v[cont]), sum += v[cont];
				cont++;
			}
			if(sum==s){
				flag = false;
				if(ms.count(v2)==0){
					rpta.push_back(v2);
					ms.insert(v2);
				}
			}
		}
		sort(rpta.begin(),rpta.end(),cmp);
		for(int i = 0;i<rpta.size();++i){
			bool f = false;
			for(int x = 0; x<rpta[i].size();++x){
				if(f)cout<<"+";
				printf("%d",rpta[i][x]);
				f=true;
			}
			printf("\n");
		}
		if(flag)cout<<"NONE"<<endl;
	}
   return 0;
}

