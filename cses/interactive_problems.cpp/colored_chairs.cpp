#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ask(ll i){
	cout<<"? "<<i+1<<endl;
	char ret; cin>>ret;
	return ret=='B';
}

int main(){
	ll n; cin>>n;
	ll z=ask(0);
	ll l=1,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if((ask(m)^z)==(m&1))l=m+1;
		else r=m-1;
	}
	cout<<"! "<<l<<endl;
	return 0;
}