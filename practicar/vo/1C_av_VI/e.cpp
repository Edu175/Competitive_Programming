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
typedef ll node;
struct STree{
	int n;
	ll NEUT;
	vector<node>t,a;
	STree(int n):n(n),NEUT(n),t(2*n+5,NEUT){}
	ll oper(ll i, ll j){return a[i]>a[j]?i:j;}
	void init(vector<node>_a){
		a=_a;
		a.pb(-5);
		fore(i,0,n)t[n+i]=i;
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
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
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n-1)cin>>a[i],a[i]--;
	a[n-1]=n;
	// imp(a);
	STree st(n);
	st.init(a);
	ll ans=0;
	vv dp(n);
	for(ll i=n-2;i>=0;i--){
		ll &res=dp[i];
		ll to=st.query(i+1,a[i]+1);
		// cout<<i<<": "<<to<<endl;
		assert(a[to]>a[i]);
		res=dp[to]+n-a[i]+to-i-1;
		ans+=res;
	}
	cout<<ans<<"\n";
	return 0;
}
