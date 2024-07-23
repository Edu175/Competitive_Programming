#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXV=1e6+5,MAXN=2e5+5,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,b);
		b=mul(b,b),e>>=1;
	}
	return r;
}
ll cr[MAXV];
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]==-1)
		for(LL j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
vector<ii> fact(ll x){
	vector<ii>r;
	while(x>1){
		ll c=0,p=cr[x]==-1?x:cr[x];
		while(x%p==0)x/=p,c++;
		r.pb({p,c});
	}
	return r;
}
ll a[MAXN];

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,1),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=mul(t[p],v);p>1;p>>=1)
			t[p>>1]=mul(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=1;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=mul(res,t[l++]);
			if(r&1)res=mul(res,t[--r]);
		}
		return res;
	}
}; 

int main(){JET
	init_sieve();
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	vector<ii> qs[n];
	ll nq; cin>>nq;
	vector<ll>ans(nq);
	fore(i,0,nq){
		ll l,r; cin>>l>>r; l--;
		qs[l].pb({r,i});
	}
	vector<ll>last(MAXV,-1);
	STree st(n);
	for(ll i=n-1;i>=0;i--){
		for(auto [p,k]:fact(a[i])){
			if(last[p]!=-1){
				st.upd(last[p],mul(p,fpow(p-1,MOD-2)));
			}
			st.upd(i,mul(p-1,fpow(p,k-1)));
			last[p]=i;
		}
		for(auto [r,idx]:qs[i]){
			ans[idx]=st.query(i,r);
		}
	}
	fore(i,0,nq)cout<<ans[i]<<"\n";
	return 0;
}