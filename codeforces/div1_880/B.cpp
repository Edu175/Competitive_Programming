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
const ll MAXN=1e6+5; 

ll sp[MAXN];

ll get(ll l, ll r){//[]
	return sp[r+1]-sp[l];
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	map<ll,ll>mp;
	fore(i,0,n){
		ll x; cin>>x;
		mp[x]++;
		if(x)mp[x-1];
		if(x<m)mp[x+1];
	}
	vector<ll>c,p;
	for(auto i:mp){
		c.pb(i.snd),p.pb(i.fst);
	}
	if(p.back()<m)c.pb(0),p.pb(m);
	fore(i,1,SZ(c))sp[i]=sp[i-1]+c[i-1];
	fore(i,0,SZ(c)){
		ll x=p[i];
		
	}
	return 0;
}
