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

vector<ll> divs(ll x){
	vector<ll>res;
	for(int i=1; i*i<=x;i++){
		if(x%i==0)res.pb(i),res.pb(x/i);
		if(i*i==x)res.pop_back();
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll mex=1;
		vector<ll>d=divs(n);
		sort(ALL(d));
		for(auto i:d)if(i==mex)mex++;
		fore(i,0,n)cout<<char('a'+(i%mex));
		cout<<"\n";
	}
	return 0;
}
