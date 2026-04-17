#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define imp(v) {cout<<#v<<": ";for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define impr(v) {cout<<#v<<": ";for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
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

int main(){
	ET
	ll k,n; cin>>k>>n;
	vv a={0};
	ll sum=0;
	fore(i,0,n){
		ll x; cin>>x;
		sum+=x;
		a.pb(sum);
	}
	n=SZ(a);
	vv vals;
	for(auto i:a)vals.pb(i),vals.pb(i+k);
	sort(ALL(vals));
	// imp(a)
	vv b;
	for(auto &i:a){
		b.pb(lower_bound(ALL(vals),i+k)-vals.begin());
		i=lower_bound(ALL(vals),i)-vals.begin();
	}
	// imp(a)
	// imp(b)
	vv r(n);
	for(ll i=n;i--;)
		for(r[i]=i+1;r[i]!=n&&a[r[i]]>=a[i];r[i]=r[r[i]]);
	STree st(SZ(vals));
	vv wh[n];
	ll res=0,cur=0;
	fore(i,0,n){
		cur+=r[i]-i-1;
		if(r[i]<n)wh[r[i]].pb(a[i]);
		else st.upd(a[i],1);
	}
	// imp(r)
	// cout<<st.query(0,st.n)<<" quey\n";
	// cout<<cur<<" inicial\n";
	vector<ii> s={{-1,n}}; // dominados: (val,pos)
	auto val=[&](ll p){
		auto [v,i]=s[p];
		ll sz=st.query(v+1,(p==SZ(s)-1?st.n:s[p+1].fst+1));
		// cout<<"val "<<p<<": "<<i<<" * "<<sz<<" = "<<i*sz<<"\n";
		return i*sz;
	};
	auto get=[&](ll v){
		return prev(lower_bound(ALL(s),ii({v,-1})))->snd;
	};
	for(ll i=n-1;i>=0;i--){
		cur-=get(a[i]);
		st.upd(a[i],-1);
		a[i]=b[i];
		cur+=get(a[i]);
		ll p=SZ(s)-1; while(s[p].fst>=a[i])p--;
		// cout<<i<<": "; impr(s)
		fore(j,p,SZ(s))cur-=val(j);
		// ,cout<<"-= ("<<j<<") "<<val(j)<<"\n";
		while(SZ(s)>p+1)s.pop_back();
		s.pb({a[i],i});
		cur+=val(p+1);
		// cout<<"+= ("<<p+1<<") "<<val(p+1)<<"\n";
		// cout<<"+= ("<<p<<") "<<val(p)<<"\n";
		cur+=val(p);
		cur-=SZ(wh[i])*i;
		for(auto v:wh[i]){
			st.upd(v,1);
			cur+=get(v);
		}
		// cout<<i<<": "<<cur<<" cur\n\n";
		if(i)res=max(res,cur);
	}
	cout<<res<<"\n";
}