#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto a:x)cout<<a<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;

struct STree{ // range upd, point qu
	ll n; vv t;
	STree(ll N):n(N+1),t(2*n+5){}
	void __upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll __query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
	
	void upd(ll l, ll r, ll v){
		__upd(l,+v);
		__upd(r,-v);
	}
	ll query(ll p){
		return __query(0,p+1);
	}
};

ll divt(ll a, ll b){ // techo
	assert(b>0);
	if(a>=0)return (a+b-1)/b;
	a=-a;
	ll ret=a/b;
	ret=-ret;
	return ret;
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<ll> s(n-m+1);
	fore(i,0,SZ(s))cin>>s[i];
	ll q; cin>>q;
	vector<ii> qs(q);
	vector<vector<ii>> hay(n);
	fore(i,0,q){
		ll l,r; cin>>l>>r; l--;
		qs[i]={l,r};
		hay[l].pb({r,i});
	}
	
	vector<vector<array<ll,3>>> upds(n+1);
	auto agr=[&](ll l0, ll l1, ll r0, ll r1, ll v){ // all [,)
		upds[l0].pb({r0,r1,v});
		upds[l1].pb({r0,r1,-v});
	};
	
	vv d(n);
	fore(i,0,SZ(s)){
		if(i+1>=SZ(s))break;
		d[i+m]=(s[i+1]-s[i]);
	}
	vv acum(SZ(d));
	fore(i,0,SZ(acum)){
		acum[i]=(i-m<0?0:acum[i-m])+d[i];
	}
	// show(d)
	// show(acum)
	vector<set<ll>> sts(m);
	fore(i,0,m)sts[i].insert(-1),sts[i].insert(n);
	vector<ii> sted(n); fore(i,0,SZ(acum))sted[i]={acum[i],i};
	sort(ALL(sted)); reverse(ALL(sted));
	for(auto [val,i]:sted){
		auto &st=sts[i%m];
		auto it=st.lower_bound(i);
		ll r=*it,l=*(--it);
		agr(l+1,i+1, i+1,r+1, val);
		st.insert(i);
	}
	STree st(n+5);
	vv sums(q);
	fore(l,0,n){
		for(auto [s,e,v]:upds[l])st.upd(s,e,v);
		for(auto [r,i]:hay[l])sums[i]=st.query(r);
	}
	vv sp(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+acum[i-1];
	fore(i,0,q){
		// cerr<<"\n\nquery\n";
		auto &sum=sums[i];
		auto [l,r]=qs[i];
		if(r-l<m){
			cout<<"unbounded\n";
			continue;
		}
		// cerr<<l<<","<<r<<": "<<sum<<": ";
		sum-=sp[l+m]-sp[l];
		// cerr<<sum<<" "<<s[l]<<": ";
		if(r-l==m)assert(sum==0);
		ll res=divt(s[l]+sum,m);
		cout<<res<<"\n";
	}
	return 0;
}