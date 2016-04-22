#include<bits/stdc++.h>

using namespace std;
struct Player{
	string name;
	int a,d;
};

bool cmp(Player a, Player b){
	if(a.a==b.a){
		if(a.d==b.d) return a.name<b.name;
		else return a.d>b.d;
	}else return a.a>b.a;
}
int main(){
	int n;
	cin>>n;
	for(int cases=1;cases<=n;cases++){
		vector<Player>v(10);
		vector<bool>at(10);
		int maxiA=0,maxiD=0;
		for(int i = 0;i<10;++i){
			cin>>v[i].name>>v[i].a>>v[i].d;
			maxiD+=v[i].d;
		}
		sort(v.begin(),v.end(),cmp);
		
		for(int i=0;i<5;++i)maxiA+=v[i].a;
		int ansA=0;
		for(int i = 31;i<1024 ; i++){
			int tempA = 0,aux=i,cA=0,c=0,sumA=0,sumD=0;
			while(aux>0){
				if(aux&1){
					sumA+=v[c].a;
					sumD+=v[c].d;
					cA++;
					tempA = tempA*10+c;
				}
				aux>>=1;
				c++;
			}
			if(cA==5&&maxiA==sumA){
				if(maxiD>sumD)maxiD= sumD, ansA = tempA;
			}
		}
		vector<string>names;
		while(ansA>0){
			int pos = ansA%10;
			names.push_back(v[pos].name);
			ansA/=10;
			at[pos]=true;
		}
		cout<<"Case "<<cases<<":"<<endl;
		if((int)names.size()<5)names.push_back(v[0].name),at[0]=true;
		sort(names.begin(),names.end());
		cout<<"("<<names[0]<<", "<<names[1]<<", "<<names[2]<<", "<<names[3]<<", "<<names[4]<<")"<<endl;
		names.clear();
		for(int i = 0;i<10;i++){
			if(!at[i])names.push_back(v[i].name);
		}
		sort(names.begin(),names.end());
		cout<<"("<<names[0]<<", "<<names[1]<<", "<<names[2]<<", "<<names[3]<<", "<<names[4]<<")"<<endl;
		
		
	}	
   
	return 0;
}
