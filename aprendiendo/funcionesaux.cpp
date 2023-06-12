#include<bits/stdc++.h>

using namespace std;
int collartz(int n){
	int res;
	if(n%2==0){
		res=n/2;
	}
	else{
		res=n*3+1;
	}
	return res;
}
int main(){
	int x;
	cin>>x;
	cout<<x<<"\n";
	while(x>1){
		x=collartz(x);
		cout<<x<<"\n";
	}
	return 0;
}

