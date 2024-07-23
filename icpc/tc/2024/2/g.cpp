#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e15;
#define NEUT INF
#define oper min
struct STree{
	ll n; vector<ll>t;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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
	ll n; cin>>n;
	vector<ii>p(n);
	vector<ll>a;
	fore(i,0,n)cin>>p[i].fst>>p[i].snd,a.pb(p[i].fst);
	sort(ALL(p));
	sort(ALL(a));
	// for(auto i:a)cout<<i<<" ";;cout<<"\n";
	STree stmas(n),st(n);
	ll ans=-1,sum=0;
	fore(i,0,n)sum+=p[i].snd;
	for(ll i=n-1;i>=0;i--){
		ll res=0;
		if(i==n-1){
			res=0;
		}
		else {
			ll k=upper_bound(ALL(a),p[i].fst+p[i].snd)-a.begin();
			res=min(st.query(i+1,k),
				stmas.query(k,n)-p[i].fst-p[i].snd);
			// cout<<i<<": "<<k<<" "<<res<<"\n";
		}
		ans=res;
		stmas.upd(i,res+a[i]);
		st.upd(i,res);
	}
	cout<<ans+sum<<"\n";
	
}


/*
1 2 4 
1: 2 0
0: 3 6
6


*/