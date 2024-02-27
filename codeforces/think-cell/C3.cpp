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
const ll INF=1e10;

map<ll,ll>L;
ll find(ll v){
	if(!L.count(v))return v;
	return L[v]=find(L[v]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i],a[i]++;
		L.clear();
		fore(i,0,n){
			ll v=find(a[i]+i);
			L[v]=v-1;
		}
		vector<ll>res;
		for(auto i:L)res.pb(i.fst);
		reverse(ALL(res));
		imp(res);
	}
	return 0;
}
