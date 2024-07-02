#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

#define oper max
ii NEUT={0,-1};

struct STree{
	vector<ii>st; vector<ll>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,0),n(n){}
	
	void push(ll k, ll s, ll e){
		if(!lazy[k])return;
		st[k].fst+=lazy[k];
		if(s+1<e){
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v, ll idx){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v;
			if(s+1==e&&idx!=-1)st[k].snd=idx;
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v,idx);
		upd(2*k+1,m,e,a,b,v,idx);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ii query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v, ll idx){
		upd(1,0,n,a,b,v,idx);
	}
	ii query(ll a, ll b){
		return query(1,0,n,a,b);
	}
};

const ll MAXN=1e5+5;

vector<ll> g[MAXN];

ll F[MAXN],D[MAXN],S[MAXN],E[MAXN];
ll vis[MAXN];
ll cnt=0;
void dfs(ll x){
	S[x]=cnt++;
	for(auto y:g[x]){
		D[y]=D[x]+1;
		F[y]=x;
		dfs(y);
	}
	E[x]=cnt;
}
STree st(0);
void saco(ll x){
	ll d=st.query(S[x],S[x]+1).fst;
	for(auto y:g[x])if(!vis[y])st.upd(S[y],E[y],-d,-1);
	st.upd(S[x],S[x]+1,-d,-1);
	vis[x]=1;
}

void pinto(ll x){
	while(x!=-1&&!vis[x]){
		saco(x);
		x=F[x];
	}
}

int main(){
	FIN
	ll n,k; cin>>n>>k;
	st=STree(n);
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
	}
	D[0]=0,F[0]=-1;
	dfs(0);
	fore(i,0,n)st.upd(S[i],S[i]+1,D[i],i);
	ll res=1;
	fore(_,0,k){
		auto [d,x]=st.query(0,n);
		if(d<=0)break;
		pinto(x);
		res+=d;
		// cout<<"pinte "<<x<<" += "<<d<<"\n";
	}
	cout<<res<<"\n";
	return 0;
} 