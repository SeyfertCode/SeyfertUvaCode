#include<iostream>

using namespace std;

int main()
{
	long long N;
	while(cin>>N){
		long long n = (N+1)/2;
		n = n*n;
		n = 6*n-9;
		cout<<n<<endl;
	}

}
