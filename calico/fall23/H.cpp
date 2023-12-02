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
//8
ll m;
bool in(ll l, ll r, ll x){
	if(r<l){
		return(x<r||x>=l);
	}
	return x>=l&&x<r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>m>>k;
		multiset<ll> tr;
		set<vector<ll>>pas;
		ll p=0;
		vector<ll>a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		fore(i,0,n){
			a[i]--,b[i]--;
			pas.insert({a[i],i,b[i]});
		}
		ll res=0;
		fore(_,0,n){
			//imp(tr);
			if(SZ(tr)==k){
				auto d=tr.lower_bound(p);
				if(d==tr.end())d=tr.begin();
				res+=(*d-p+m)%m;
				p=*d;
				tr.erase(d);
			}
			auto d=pas.lower_bound({p,-1,-1});
			if(d==pas.end())d=pas.begin();
			auto v=*d;
			auto i=tr.lower_bound(p);
			if(SZ(tr)&&i==tr.end())i=tr.begin();
			for(;SZ(tr)&&in(p,v[0],*i);){
				i++;
				tr.erase(prev(i));
				if(SZ(tr)&&i==tr.end())i=tr.begin();
			}
			res+=(v[0]-p+m)%m;
			p=v[0];
			tr.insert(v[2]);
			pas.erase(d);
		}
		if(SZ(tr)){
			auto d=tr.lower_bound(p);
			if(d==tr.begin())d=prev(tr.end());
			else d--;
			res+=(*d-p+m)%m;
		}
		cout<<res<<"\n";
	}
	return 0;
}
