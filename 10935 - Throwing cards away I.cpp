#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n,x;
	queue<int>q;
	bool flag;
	while(cin>>n){
		if(n==0)break;
		for(int i = 1;i<n+1;++i)q.push(i);
		cout<<"Discarded cards:";
		flag = false;
		while(q.size()>1){
			if(flag)cout<<",";
			flag= true;
			x = q.front();
			cout<<" "<<x;
			q.pop();
			x = q.front();
			q.pop();
			q.push(x);
		}
		cout<<endl<<"Remaining card: "<<q.front()<<endl;
		q.pop();
	}
}
