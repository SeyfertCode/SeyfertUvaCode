#include<iostream>
#include<algorithm>

using namespace std;
int main(){
	string a,b;
	while(getline(cin,a)){
		getline(cin,b);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int la = a.size();
		int lb = b.size();
		for(int i = 0, j = 0 ;i<la&&j<lb;){
				if(a[i]==b[j])cout<<a[i],++i,++j;
				else if(a[i]>b[j])++j;
				else ++i;			
		}
		cout<<endl;
	}
}
