#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXN=20*(1e6+5),LG=20;

ll tr[MAXN][2],c[MAXN]; // cant in subtree
ll qidx=0;
ll add(ll x, ll bo){
	auto &res=tr[x][bo];
	if(res!=-1)return res;
	return res=++qidx;
}

ll f(ll x, ll k){
	if(x<=0)return 0;
	assert(c[x]>=k);
	ll l=tr[x][0],r=tr[x][1];
	ll cl=l==-1?0:c[l];
	ll cr=r==-1?0:c[r];
	if(cl>=k)return f()
}

int main(){
    JET
	ll n; cin>>n;
	vv a(n);
	ll all=0;
	fore(i,0,n)cin>>a[i],all^=a[i];
	ll x=0;
	vv b={all};
	for(auto v:a){
		x^=v;
		ll r=all^x;
		ll cur=x|r;
		b.pb(cur);
	}
	sort(ALL(b));
	mset(tr,-1);
	for(auto s:b){
		ll x=0;
		c[x]++;
		for(ll j=LG-1;j>=0;j--){
			x=add(x,(s>>j&1));
			c[x]++;
		}
	}
    return 0;
}