#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll NEUT=0;
ll oper(ll a, ll b){return a+b;}
struct STree{
	vector<ll> t; ll n;
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

int main(){
	JET 
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		STree st(n);
		fore(i,0,n){
			cin>>a[i]; a[i]--;
		}
		// vv oc(n);
		ll cur=0,mx=a[0],cant=1,fal=0;
		st.upd(a[0],1);
		cout<<0;
		fore(i,1,n){
			ll x=a[i];
			st.upd(a[i],1);
			// cerr<<"agrego "<<a[i]<<"\n";
			if(x==mx)cant++;
			if(x>mx){
				cur++; // first chain increases
				swap(x,mx);
				cur+=fal;
				// cerr<<"cambia max 1 + "<<cant-1<<"\n";
				cant=1; fal=0;
			}
			if(cant>1)fal++;
			ll del=st.query(x+1,n);
			cur+=del;
			// cerr<<i<<": put "<<x<<": "<<del<<"\n";
			cout<<" "<<cur;
			// cerr<<"\n\n";
		}
		cout<<"\n";
	}
	return 0;
}

