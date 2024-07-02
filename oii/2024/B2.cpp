#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,0),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=(t[p]+t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=(t[l++]);
			if(r&1)res+=(t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll>fs(n,n),fb(n,-1);
	for(ll i=n-1;i>=0;i--)
		for(fs[i]=i+1;fs[i]<n&&a[i]<=a[fs[i]];fs[i]=fs[fs[i]]);
	fore(i,0,n){
		for(fb[i]=i-1;fb[i]>=0&&a[i]>=a[fb[i]];fb[i]=fb[fb[i]]);
	}
	imp(fb) imp(fs) 
	ll q; cin>>q;
	vector<ii>qu(q);
	vector<ll>ans(q);
	vector<vector<ii>>query(n+1);
	vector<vector<ll>>upd(n+1);
	vector<ll>h;
	fore(i,0,q){
		ll l,r; cin>>l>>r; l--;
		qu[i]={l,r};
		query[l].pb({r,i});
	}
	STree st(n+5);
	fore(i,0,n){
		if(fb[i]==-1)st.upd(fs[i],1);
		else upd[fb[i]].pb(fs[i]);
	}
	fore(i,0,n+1){
		for(auto [r,id]:query[i]){
			ans[id]=st.query(r,n+2);
		}
		for(auto p:upd[i])st.upd(p,1);
	}
	for(auto i:ans)cout<<i<<"\n";
	return 0;
}