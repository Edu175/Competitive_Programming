#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll n;
ll count(vv a){
	vv p(n,-1);
	fore(i,0,SZ(a))p[a[i]]=i;
	STree st(n);
	ll res=0;
	// cout<<"count ";
	// imp(a);
	fore(i,0,n)if(p[i]!=-1){
		ll pos=p[i];
		// cout<<i<<": "<<pos<<" "<<st.query(pos,n)<<"\n";
		res+=st.query(pos,n);
		st.upd(pos,1);
	}
	return res;
}
int main(){FIN;
	ll k; cin>>n>>k;
	vv a(n),p(n);
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	
	vv cl(n,-1),cr(n,-1);
	STree st(n);
	for(ll i=n-1;i>=0;i--){
		ll pos=p[i];
		ll l=pos-k+1;
		if(l>=0)cl[pos]=st.query(l,pos);
		st.upd(pos,1);
	}
	st=STree(n);
	fore(i,0,n){
		ll pos=p[i];
		ll r=pos+k;
		if(r<=n)cr[pos]=st.query(pos,r);
		st.upd(pos,1);
	}
	// imp(cl)
	// imp(cr)
	ll tot=count(a),cant=n-k+1;
	// cout<<tot<<" tot\n";
	vv prefix;
	fore(i,0,k)prefix.pb(a[i]);
	ll inv=count(prefix);
	ll res=0;
	auto calc=[&](){
		// cout<<"calc "<<inv<<": "<<tot-inv<<"\n";
		ll resi=add((tot-inv)%MOD,mul(mul(k,k-1),fpow(4,MOD-2)));
		res=add(res,mul(resi,fpow(cant,MOD-2)));
	};
	calc();
	fore(e,k,n){
		ll s=e-k;
		inv-=cr[s];
		inv+=cl[e];
		calc();
	}
	cout<<res<<"\n";
	return 0;
}
