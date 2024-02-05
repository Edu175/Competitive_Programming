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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;

ll a[MAXN];
ll n,m;
vector<ll>dir,man;
ll vis[MAXN];
ll dis[MAXN];
ll did=0,D;
ll go(ll x, ll d, ll w){
	if(w==0){
		if(d==0&&x/m==0)return -1;
		if(d==1&&x%m==0)return -1;
		if(d==2&&x%m==m-1)return -1;
		if(d==3&&x/m==n-1)return -1;
		return x+man[d];
	}
	else {
		if(d<3&&x/m==0)return -1;
		if(d%3==0&&x%m==0)return -1;
		if(d%3==2&&x%m==m-1)return -1;
		if(d>=6&&x/m==n-1)return -1;
		if(dir[d]==0)return -1;
		return x+dir[d];
	}
}
ll bl[MAXN];
void dfs1(ll x){
	if(bl[x]||dis[x]<D||a[x]==2)return;
	bl[x]=1;
	fore(d,0,SZ(man)){
		ll y=go(x,d,0);
		if(y!=-1)dfs1(y);
	}
}
void dfs2(ll x){
	if(vis[x]||bl[x])return;
	vis[x]=1;
	did|=a[x]==2;
	fore(d,0,SZ(dir)){
		ll y=go(x,d,1);
		if(y!=-1)dfs2(y);
	}
}
void bfsv(){
	queue<ll>q;
	mset(dis,-1);
	fore(i,0,n*m)if(a[i]==1)dis[i]=0,q.push(i);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		fore(d,0,SZ(man)){
			ll y=go(x,d,0);
			if(y==-1||dis[y]!=-1)continue;
			dis[y]=1+dis[x];
			q.push(y);
		}
	}
}
bool can(ll mid, ll x){
	D=mid;
	mset(vis,0); mset(bl,0); did=0;
	dfs1(x);
	fore(i,0,n*m)if(i/m==0||i%m==0||i%m==m-1||i/m==n-1)dfs2(i);
	return !did;
}


int main(){FIN;
	cin>>n>>m;
	ll q; cin>>q;
	dir={-m-1,-m,-m+1,-1,0,1,m-1,m,m+1};
	man={-m,-1,1,m};
	fore(i,0,n*m){
		char c; cin>>c;
		if(c=='#')a[i]=2;
		if(c=='v')a[i]=1;
	}
	bfsv();
	while(q--){
		ll i,j; cin>>i>>j; i--,j--;
		ll x=m*i+j;
		ll l=0,r=1e6;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m,x))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	return 0;
}
