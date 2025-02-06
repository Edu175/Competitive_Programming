#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5),n(n){}
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

int main(){
	JET
	ll n; cin>>n;
	vv a,b;
	auto init=[&](vv &a){
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		vv b;
		fore(i,0,n-1)b.pb(a[i]+a[i+1]);
		fore(i,0,n-1)if(i&1)b[i]=-b[i];
		a=b;
	};
	init(a); init(b);
	n=SZ(a);
	STree st(n);
	fore(i,0,n)st.upd(i,1);
	map<ll,queue<ll>> mp;
	fore(i,0,n)mp[a[i]].push(i);
	ll res=0;
	for(auto i:b){
		auto &q=mp[i];
		if(!SZ(q)){cout<<"-1\n";return 0;}
		ll p=q.front(); q.pop();
		res+=st.query(0,p);
		st.upd(p,0);
	}
	cout<<res<<"\n";
	return 0;
}