#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	cout<<"1\n";
	ll n=2e5-1,q=2e5;
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n){
		if(i)cout<<" ";
		cout<<"1";
	}
	cout<<"\n";
	vector<ii>qs;
	for(ll r=n;r>1;r-=2)qs.pb({1,r});
	for(ll l=1;l<n;l+=2)qs.pb({l,n});
	qs.resize(q,{1,n});
	for(auto i:qs)cout<<i.fst<<" "<<i.snd<<"\n";
	return 0;
}
