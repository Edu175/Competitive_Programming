#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll is(ll x){
	string s=to_string(x);
	fore(i,0,SZ(s)-1){
		if(s[i]==s[i+1])return 0;
	}
	return 1;
}
ll k;
bool can(ll m){
	ll c=0;
	fore(i,1,m+1)c+=is(i);
	 cout<<"f "<<m<<": "<<c<<"\n";
	return c<=k;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>k;
		ll l=1,r=10000;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	return 0;
}
