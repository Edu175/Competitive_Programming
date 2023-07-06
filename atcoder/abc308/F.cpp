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
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
ll l[MAXN];
ll v[MAXN];

ll oper(ll a, ll b){ //arg max
	if(a==-1)return b;
	if(b==-1)return a;
	if(v[a]>=v[b])return a;
	return b;
}
#define NEUT -1
struct STree{
	int n; vector<ll>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=a[i];
		for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ii b[m];
	fore(i,0,m)cin>>b[i].fst;
	fore(i,0,m)cin>>b[i].snd;
	sort(a,a+n);
	sort(b,b+m);
	fore(i,0,m)l[i]=b[i].fst,v[i]=b[i].snd;
	/*imp(a);
	fore(i,0,m)cout<<l[i]<<" ";
	cout<<"\n";
	fore(i,0,m)cout<<v[i]<<" ";
	cout<<"\n";*/
	STree st(m);
	fore(i,0,m)st.upd(i,i);
	ll res=0;
	fore(i,0,n){
		ll r=upper_bound(l,l+m,a[i])-l;
		ll x=st.query(0,r);
		res+=a[i];
		if(x!=-1)res-=v[x],st.upd(x,-1);
		//cout<<i<<" "<<a[i]<<": "<<r<<" "<<x<<" "<<(x<0?"-":to_string(v[x])) <<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
