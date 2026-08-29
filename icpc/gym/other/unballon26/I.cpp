#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e6+5;
const ll P=100019,MOD=998244353,PI=291431979;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
ll n;
ll a[MAXN];

vv seq,comp;
ll pn;
ll geth(vv &a){
	ll p=pn;
	ll res=0;
	for(auto i:a){
		res=(res+p*i)%MOD;
		p=p*PI%MOD;
	}
	// cerr<<"geth: "<<res<<"\n";
	return res;
}
void proba(ll l, ll r){
	fore(j,l,r)comp.pb(a[j]);
	fore(j,r+1,n)comp.pb(a[j]);
	// cerr<<"\n\nproba "<<l<<","<<r<<":\n";
	// show(seq)
	// show(comp)
	if(SZ(seq)&&geth(seq)<geth(comp)){
		show(seq);
		exit(0);
	}
	fore(j,l,r)comp.pop_back();
	fore(j,r+1,n)comp.pop_back();
}
void f(ll i){
	unordered_set<ll> vis;
	while(1){
		ll mn=-1;
		vv pos;
		fore(j,i,n)if(!vis.count(j)){
			if(mn==-1||a[j]<a[mn])mn=j,pos.clear();
			if(a[j]==a[mn])pos.pb(j);
		}
		if(mn==-1)break;
		for(auto j:pos){
			seq.pb(a[j]);
			proba(i,j);
			seq.pop_back();
		}
		vis.insert(mn);
		// lo pongo
		seq.pb(a[mn]);
		fore(j,i,mn)comp.pb(a[j]);
		f(mn+1);
		seq.pop_back();
		fore(j,i,mn)comp.pop_back();
	}
}

int main(){FIN;
	assert(mul(P,PI)==1);
	cin>>n;
	fore(i,0,n)cin>>a[i];
	ll p=1;
	fore(i,0,n)p=mul(p,P);
	pn=p;
	f(0);
	cout<<"-1\n";
	return 0;
}
