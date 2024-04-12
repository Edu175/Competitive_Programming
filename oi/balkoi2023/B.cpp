#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,balkoi=b;i<balkoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdkj:v)cout<<sdkj<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll msb(ll x){return (x==0?-1:63-__builtin_clzll(x));}
//string cv(ii i){return to_string(i.fst)+","+to_string(i.snd);}
ii oper(ii a, ii b){
	auto [x,c]=a;
	auto [y,d]=b;
	ll ch=1;
	if(msb(x)+c!=msb(y)+d){
		ch=(msb(x)+c>msb(y)+d);
	}
	else {
		ll mn=min(c,d);
		ch=(x<<(c-mn))>(y<<(d-mn));
	}
	//cout<<"oper "<<cv(a)<<" "<<cv(b)<<": "<<ch<<"\n";
	if(ch)return a;
	return b;
}
struct STree{
	vector<ii>t; ll n;
	STree(ll n):t(2*n+5,{0,0}),n(n){}
	void upd(ll p, ii v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ii query(ll l, ll r){
		ii res={0,0};
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
const ll MAXN=5e5+5;
vector<ll>g[MAXN];
ll S[MAXN],E[MAXN],D[MAXN];
ll cnt=0;
void dfs(ll x){
	S[x]=cnt++;
	for(auto y:g[x]){
		D[y]=D[x]+1;
		dfs(y);
	}
	E[x]=cnt;
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	ll m=2*n+1;
	vector<ll>w(n+1);
	fore(i,0,n){
		fore(h,0,2){
			char c; cin>>c;
			ll x; cin>>x; x--;
			if(c=='W')x+=n;
			g[i].pb(x);
		}
	}
	dfs(0);
	//fore(i,0,m)cout<<i<<" ("<<i%n<<"): "<<D[i]<<" "<<S[i]<<","<<E[i]<<"\n";
	STree st(m);
	fore(i,0,n+1)cin>>w[i],st.upd(S[n+i],{w[i],D[n+i]});
	while(q--){
		ll ty; cin>>ty; ty--;
		if(!ty){
			ll p,v; cin>>p>>v; p--;
			w[p]=v;
			st.upd(S[p+n],{w[p],D[n+p]});
		}
		else {
			ll x; cin>>x; x--;
			auto rq=st.query(S[x],E[x]);
			rq.snd-=D[x];
			//cout<<x<<": "<<cv(rq)<<"\n";
			assert(rq.snd>=0);
			ll res=rq.fst*fpow(2,rq.snd)%MOD;
			cout<<res<<"\n";
		}
	}
	return 0;
}
