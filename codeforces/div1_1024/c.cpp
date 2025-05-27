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
const ll MAXN=2e5+5;

ll n;
vv a;
pair<ll,ll> get(vv a, ll k){
	set<ll>st;
	fore(i,0,k)st.insert(i);
	ll sum=0;
	fore(i,0,n){
		auto it=st.upper_bound(a[i]);
		if(it!=st.begin())st.erase(prev(it)),sum+=i;
		if(!SZ(st))return {i,sum};
	}
	return {n,-1};
}

pair<bool,ll> can(ll k){
	if(k==0)return {1,0};
	auto [p,sum0]=get(a,k);
	auto ra=a; reverse(ALL(ra));
	auto [q,sum1]=get(ra,k);
	q=n-1-q;
	sum1=(n-1)*k-sum1;
	if(p<q)return {1,sum1-sum0};
	return {0,-1};
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		a=vv(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		ll l=0,r=n/2+5;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m).fst)l=m+1;
			else r=m-1;
		}
		ll k=r;
		// cerr<<k<<": ";
		cout<<can(k).snd<<"\n";
	}
	return 0;
}
