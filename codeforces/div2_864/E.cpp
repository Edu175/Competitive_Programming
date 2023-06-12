#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}	
const ll MAXV=5e6+5;

int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nlog²(n))
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
vector<ll> fact(int n){  // must call init_cribe before		O(log(n))
	vector<ll> r;
	while(cr[n]>=0)r.pb(cr[n]),n/=cr[n];
	if(n>1)r.pb(n);
	sort(ALL(r));
	vector<ll>res;
	fore(i,0,SZ(r))if(!i||r[i]!=r[i-1])res.pb(r[i]);
	//cout<<r<<": "<<res<<"\n";
	return res;
}
ll dp[MAXV];
void phi(ll &x){// can optimize
	ll &res=dp[x];
	if(res!=-1)x=res;
	else if(x==1)x=res=1;
	else{
		vector<ll> f=fact(x);
		for(auto i:f)x=x/i*(i-1);
		res=x;
	}
}
struct node{
	ll q,d,x,res;
	node(){}
	node(ll q, ll d, ll x, ll res):q(q),d(d),x(x),res(res){}
	node(ll v):q(1),d(0),x(v),res(0){
		while(v!=1)phi(v),d++;
	}
}; 
void phi(node &v){
	if(v.x==1)return;
	v.d--,phi(v.x);
}
node oper(node a, node b){
	if(a.q==-1)return b;
	if(b.q==-1)return a;
	node r;
	r.q=a.q+b.q;
	ll ad=a.d,bd=b.d;
	while(a.x!=b.x){
		if(a.d>b.d)phi(a);
		else phi(b);
	}
	r.d=a.d;
	r.x=a.x;
	r.res=a.res+b.res+a.q*(ad-r.d)+b.q*(bd-r.d);
	return r;
}
node NEUT=node(-1,-1,-1,-1);
struct STree{
	ll n; vector<node>t;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=node(a[i]);
		for(ll s=1ll<<(64-__builtin_clzll(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(ll i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}
	void upd(ll p, ll v){
		for(p+=n,phi(t[p]);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
int main(){FIN;
	init_sieve();
	mset(dp,-1);
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	set<ll>pos;
	fore(i,0,n){
		cin>>a[i];
		if(a[i]!=1)pos.insert(i);
	}
	STree st(n);
	st.init(a);
	while(q--){
		//imp(a);
		//imp(pos);
		ll ty,l,r; cin>>ty>>l>>r; ty--,l--;
		if(!ty){
			vector<ll>rem;
			for(auto i=pos.lower_bound(l);i!=pos.end()&&*i<r;i++){
				st.upd(*i,1);
				//assert(*i<n&&*i>=0);
				phi(a[*i]);
				if(a[*i]==1)rem.pb(*i);
			}
			for(auto i:rem)pos.erase(i);
		}
		else{
			cout<<st.query(l,r).res<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
