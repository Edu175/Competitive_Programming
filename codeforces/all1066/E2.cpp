#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv a;
ll n,k;

bool can(ll c){ c++;
	set<ll> st;
	ll m=3*n+5; fore(i,0,m)st.insert(i);
	vv oc(m);
	fore(i,0,n)oc[a[i]]++;
	for(ll v=2*n;v>=0;v--){
		while(oc[v]){
			ll to=*st.lower_bound(v);
			if(v+c<=to)break;
			st.erase(to);
			oc[v]--;
		}
	}
	ll mx=1;
	fore(v,0,2*n+1){
		ll fin=v+c-1;
		ll cant=oc[v]+(fin<m&&!st.count(fin));
		mx=max(mx,cant);
	}
	return mx<=k;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		a=vv(n);
		fore(i,0,n)cin>>a[i];
		ll l=-1,r=n+5;
		while(r-l>1){
			ll m=(l+r)/2;
			if(can(m))r=m;
			else l=m;
		}
		ll m=r;
		assert(can(m));
		cout<<m<<"\n";
	}
	return 0;
}
