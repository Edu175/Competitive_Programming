#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,hgfmdg=b;i<hgfmdg;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sldhg:v)cout<<sldhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,0),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		STree st(2*n);
		fore(i,0,n)st.upd(p[i],1),st.upd(p[i]+n,1);
		ll res=0;
		for(ll i=n-1;i>=0;i--){
			st.upd(p[i],0),st.upd(p[i]+n,0);
			if(i==n-1)continue;
			ll l=p[i],r=p[i+1];
			if(l>r)r+=n;
			res+=st.query(l,r)*(n-1-i);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}