#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5,K=17,INF=1e10;
#define NEUT INF
#define oper min
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){
	JET
	ll n,c; cin>>n>>c;
	vector<ll>a(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	vector<ll>dp(n+1);
	STree st(n);
	fore(i,0,n)st.upd(i,a[i]);
	for(ll i=n-1;i>=0;i--){
		if(i+c<=n)dp[i]=st.query(i,i+c)+dp[i+c];
		/*if(i%c!=n%c)*/dp[i]=max(dp[i],dp[i+1]);
		// cout<<i<<": "<<dp[i]<<"\n";
	}
	cout<<sum-dp[0]<<"\n";
	return 0;
}