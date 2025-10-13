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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll INF=1e18;
typedef ii node;
#define oper min
node NEUT={INF,-1};
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll> a(n),pr(n+1);
	STree st(n);
	fore(i,0,n)cin>>a[i],st.upd(i,{a[i],i});
	fore(i,1,n+1)pr[i]=mul(pr[i-1],a[i-1]);
	auto getpr=[&](ll l, ll r){
		ll L=pr[l],R=pr[r];
		ll res=mul(R,fpow(L,MOD-2));
		return res;
	};
	while(q--){
		ll l,r,k; cin>>l>>r>>k; l--;
		ll p=st.query(l,r).snd;
		ll v=max(a[p]-k,0ll);
	}
	return 0;
}
