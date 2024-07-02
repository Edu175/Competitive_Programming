#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef ll node;
const ll INF=1e15;
#define oper max
#define NEUT -INF
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
	ll t; cin>>t;
	while(t--){
		ll n,l,r; cin>>n>>l>>r; r++;
		vector<ll>a(n),sp(n+1);
		fore(i,0,n)cin>>a[i];
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		vector<ll>dp(n+1);
		dp[n]=0;
		STree st(n+5);
		st.upd(n,0);
		for(ll i=n-1;i>=0;i--){
			ll s=lower_bound(ALL(sp),l+sp[i])-sp.begin();
			ll e=lower_bound(ALL(sp),r+sp[i])-sp.begin();
			dp[i]=max(dp[i+1],1+st.query(s,e));
			st.upd(i,dp[i]);
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
