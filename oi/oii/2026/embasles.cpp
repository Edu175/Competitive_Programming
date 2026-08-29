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
const ll INF=1e18;
typedef ll node;
#define oper min
#define NEUT INF
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
ll k;
ll dodp(vv a){
	a.insert(a.begin(),0);
	ll n=SZ(a);
	vv sp(n+1); fore(i,0,n)sp[i+1]=a[i]+sp[i];
	STree st1(n+1),st2(n+1);
	st1.upd(n,0);
	st2.upd(n,sp[n]);
	ll ans=0;
	for(ll i=n-1;i>=0;i--){
		ll sac=sp[i+1];
		ll m=lower_bound(ALL(sp),sac+k+1)-sp.begin();
		ll cand1=st1.query(i+1,m);
		ll cand2=st2.query(m,st2.n)-sac-k;
		ll cur=min(cand1,cand2)+a[i];
		st1.upd(i,cur);
		st2.upd(i,cur+sp[i]);
		ans=cur;
		// cerr<<i<<" "<<m<<": "<<cur<<" "<<cur+sp[i]<<"\n";
	}
	// cerr<<ans<<" dodp: "; show(a) 
	return ans;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		vv a(n);
		ll mx=0;
		vv le(n),ri(n);
		fore(i,0,n){
			cin>>a[i];
			if(a[i]>=a[mx])mx=i;
			le[i]=mx;
		}
		mx=n-1;
		for(ll i=n-1;i>=0;i--){
			if(a[i]>=a[mx])mx=i;
			ri[i]=mx;
		}
		vv L(n),R(n);
		fore(i,0,n)for(L[i]=i-1;L[i]!=-1&&a[L[i]]<a[i];L[i]=L[L[i]]);
		for(ll i=n-1;i>=0;i--)for(R[i]=i+1;R[i]!=n&&a[R[i]]<a[i];R[i]=R[R[i]]);
		vector<vv> bus(n);
		vv lev(n,-1);
		fore(i,0,n){
			ll l=le[i],r=ri[i];
			ll v=min(a[l],a[r]);
			if(v<=a[i])continue;
			if(a[l]>=a[r])l=L[r];
			else r=R[l];
			bus[l].pb(i);
			if(lev[l]==-1)lev[l]=v;
			assert(lev[l]==v);
		}
		ll res=0;
		fore(i,0,n)if(SZ(bus[i])){
			vv b;
			for(auto j:bus[i])b.pb(lev[i]-a[j]);
			res+=dodp(b);
		}
		cout<<res<<"\n";
	}
	return 0;
}