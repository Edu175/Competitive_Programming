#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

inline ll remtz(ll a){
	return a>>__builtin_ctz(a);
}

ll gcd_odd(ll a, ll b){
	while(a!=b){
		if(a<b)swap(a,b);
		a=remtz(a-b);
	}
	return a;
}
ll gcd(ll a, ll b){
	if(a==0)return b;
	if(b==0)return a;
	return gcd_odd(remtz(a),remtz(b))<<min(__builtin_ctz(a),__builtin_ctz(b));
}
#define oper gcd
typedef ll node;
node t[2*MAXN];
#define NEUT 0
int n;
void st_init(vector<ll>&a){
	n=SZ(a);
	fore(i,0,n)t[i+n]=a[i];
	for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
		for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
	}
}
void upd(int p, ll v){
	for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
}
node st_query(int l, int r){
	node res=NEUT;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1)res=oper(t[l++],res);
		if(r&1)res=oper(t[--r],res);
	}
	return res;
}
/*const ll K=17;//K such that 2^k>n
ll st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1ll<<k)]);
}*/
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		//STree st(n);
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];//,st.upd(i,a[i]);
		st_init(a);
		ll res=0;
		fore(s,0,n){
			ll e=s;
			while(e<n){
				ll l=e,r=n-1;
				ll v=st_query(s,e+1);
				while(l<=r){
					ll m=(l+r)/2;
					if(st_query(s,m+1)==v)l=m+1;
					else r=m-1;
				}
				e=l;
				res=max(res,v*(e-s));
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
