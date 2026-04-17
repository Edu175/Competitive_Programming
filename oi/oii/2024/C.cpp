#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,4*n+100),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=min(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=4*n+100;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=min(res,t[l++]);
			if(r&1)res=min(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll q; cin>>q;
	vector<ii>qu;
	vector<ll>ans(q,1);
	fore(_,0,q){
		ll l,r; cin>>l>>r; l--;
		if((r-l)&1)ans[_]=a[--r]<=k;
		qu.pb({l,r});
	}
	vector<ll>can(n);
	STree st(n);
	fore(i,0,n){
		ll p=upper_bound(ALL(a),k-a[i])-a.begin();
		st.upd(i,p+i);
		// cout<<p<<" ";
	}
	// cout<<"\n";
	fore(i,0,q){
		ll res=ans[i];
		auto [l,r]=qu[i];
		res&=st.query(l,(l+r)/2)>r+l-1;
		cout<<res;
	}
	cout<<"\n";
	return 0;
}