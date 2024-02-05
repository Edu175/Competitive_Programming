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
const ll MAXN=105;

ll dp[MAXN][MAXN][MAXN];
ll a[MAXN];
ll n,x;
vector<ll>pos[MAXN];
typedef ll node;
#define oper min
#define NEUT 1e10
struct STree{
	int n; vector<node>t;
	STree(){}
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){
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
STree st[MAXN][MAXN];
ll f(ll l, ll r, ll k){
	ll &res=dp[l][r][k];
	if(res!=-1){
		return res;
	}
	if(l>=r){
		res=0;
		st[l][r].upd(k,res);
		return res;
	}
	auto ps=lower_bound(ALL(pos[k]),l);
	auto pe=lower_bound(ALL(pos[k]),r);
	if(ps==pe){
		res=1;
		st[l][r].upd(k,res);
		return res;
	}
	ll s=*ps,e=*prev(pe);
	res=min(f(l,s,k)+f(s+1,r,k),f(l,e,k)+f(e+1,r,k));
	fore(i,0,x)if(i!=k)res=min(res,f(s,e+1,i)+1);
	res=min(res,st[s][e+1].query(0,k)+st[s][e+1].query(k+1,x)+1);
	st[l][r].upd(k,res);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>x;
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n+3)fore(j,0,n+3){
			fore(k,0,x+3)dp[i][j][k]=-1;
			st[i][j]=STree(x+5);
		}
		fore(i,0,x)pos[i].clear();
		fore(i,0,n)pos[a[i]].pb(i);
		fore(r,0,n)for(ll l=n;l;l--)fore(k,0,x){
			f(l,r,k);
		}
		ll res=n+5;
		fore(i,0,x)res=min(res,f(0,n,i));
		cout<<res<<"\n";
	}
	return 0;
}
