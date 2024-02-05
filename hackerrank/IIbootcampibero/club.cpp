#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

map<ll,vector<ll>>mp;
set<ii>st;
map<ll,ll>is;
vector<ll>a;
void put(ll i){ //index
	st.insert({*upper_bound(ALL(mp[a[i]]),i),a[i]});
	is[a[i]]=i;
}

void out(ll v){ //value
	ll i=is[v];
	is[v]=-1;
	st.erase({*upper_bound(ALL(mp[a[i]]),i),a[i]});
}

int main(){FIN;
	ll n,k,c; cin>>n>>k>>c;
	a.resize(n);
	fore(i,0,n)cin>>a[i],mp[a[i]].pb(i),is[a[i]]=-1;
	for(auto& [i,v]:mp)v.pb(n);
	fore(i,0,k){
		put(i);
	}
	ll res=0;
	fore(i,k,n){
		if(is[a[i]]!=-1){
			out(a[i]);
			put(i);
		}
		else {
			ll v=prev(st.end())->snd;
			out(v);
			put(i);
			res++;
		}
	}
	cout<<res*c<<"\n";
	return 0;
}
