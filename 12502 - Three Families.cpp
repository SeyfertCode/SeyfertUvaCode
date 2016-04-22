#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int A,B,X;
		cin>>A>>B>>X;
		int h = A+B;
		
		A = A*3 - h;
		B = B*3 - h;
		cout<< A*X/(A+B)<<endl; 
	}
   
	return 0;
}
