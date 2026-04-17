#include<bits/stdc++.h>

using namespace std;
int sumadigitos(int n){
	int res=0;
	//cout<<"suma digitos"<<" "<<n;
	while(n>0){
		res+=n%10;
		n/=10;
	}
	//cout<<" "<<res<<"\n";
	return res;
}
int main(){
	int x;
	cin>>x;
	cout<<x<<"\n";
	while(x>=10){
		x=sumadigitos(x);
		cout<<x<<"\n";
	}
	return 0;
}

