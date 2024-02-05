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

ll fqrt(ll x){ //if ceil change to r*r<x and return r
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}

int main(){FIN;
	ll t; srand((ll)&t); cin>>t;
	while(t--){
		ll n; cin>>n;
		string s(n-3,'0');
		s+="169";
		vector<ll>res;
		do{
			if(s[0]=='0')continue;
			ll x=stoll(s);
			if(fqrt(x)*fqrt(x)==x)res.pb(x);
		}
		while(next_permutation(ALL(s)));
		cout<<SZ(res)<<": "; imp(res);
	}
	return 0;
}
