#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll NEUT=0;
ll oper(ll a, ll b){return a+b;}
struct STree{
	vv t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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

// int add(int a, int b){}
int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vv up(n);
	STree st(n);
	for(ll i=n-1;i>=0;i--){
		up[i]=st.query(a[i],n);
		st.upd(a[i],1);
	}
	vector<ld> top(n);
	fore(i,0,n)top[i]=ld(up[i])/2;
	ld res=n;
	res+=top[0];
	fore(i,0,n-1){
		ll j=i+1;
		ld otr=(top[i]+top[j]);
		if(a[i]<a[j])otr-=1.0/2; // el j molesta
		otr/=2;
		ld sam=0;
		if(a[i]<a[j]){
			sam=top[i]-top[j]-1.0/2; // el j molesta
		}
		else {
			sam=top[j]-top[i];
		}
		sam/=2;
		res+=otr+sam;
	}
	cout<<fixed<<setprecision(15);
	cout<<res<<"\n";
	return 0;
}