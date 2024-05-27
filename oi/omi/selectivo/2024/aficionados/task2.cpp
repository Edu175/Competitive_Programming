#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfkjhg:v)cout<<dfkjhg.fst<<","<<dfkjhg.snd<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct STree{
	ll n,C; vector<ll>t,bag;
	STree(ll N):n(2*(N+5)),C(N+5),t(2*n+5,n){}
	void upd(ll p, ll v, ll ac=1){
		if(ac)bag.pb(p);
		p+=C;
		p+=n;
		if(ac)t[p]=min(t[p],v);
		else t[p]=v;
		for(;p>1;p>>=1)t[p>>1]=min(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=n;
		for(l+=C+n,r+=C+n;l<r;l>>=1,r>>=1){
			if(l&1)res=min(res,t[l++]);
			if(r&1)res=min(res,t[--r]);
		}
		return res;
	}
	void reset(){
		for(auto i:bag)upd(i,n,0);
		bag.clear();
	}
};

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n),c;
	fore(i,0,n)cin>>a[i],c.pb(a[i]);
	sort(ALL(c));
	auto _c=c;
	c.clear();
	for(auto i:_c)if(!SZ(c)||i!=c.back())c.pb(i);
	auto id=[&](ll x){
		return lower_bound(ALL(c),x)-c.begin();
	};
	fore(i,0,n)a[i]=id(a[i]);
	
	vector<vector<ll>>pos(n);
	fore(i,0,n)pos[a[i]].pb(i);
	ll res=0;
	STree st(n);
	fore(v,0,n)if(SZ(pos[v])){
		auto p=pos[v];
		ll m=SZ(p);
		vector<ll>c(m);
//		cout<<"color "<<v<<"\n";
		fore(i,0,m){
			c[i]=i+1-(p[i]-i);
			ll j=st.query(-st.C,c[i]);
//			cout<<i<<" ("<<p[i]<<"): "<<c[i]<<" , "<<j<<"\n";
			if(j<i){
				ll resi=p[i]-p[j]+1;
				ll s=c[i]-(c[j]-1);
//				cout<<s<<" | "<<resi<<" + "<<s-1<<" = "<<resi+s-1<<"\n";
				resi+=s-1;
				res=max(res,resi);
			}
			st.upd(c[i]-1,i);
		}
		st.reset();
	}
	res=min(res,n);
	cout<<res<<"\n";
	return 0;
}
