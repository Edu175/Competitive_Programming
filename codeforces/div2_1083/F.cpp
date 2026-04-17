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
const ll MAXN=4e5+5;

int uf[MAXN];
void uf_init(ll n){fore(i,0,n)uf[i]=-1;}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

ll N,M;
ll cv(ll i, ll j){
	assert(i<N&&j<M);
	assert(i>=0&&j>=0);
	return M*i+j;
}
ii cv(ll x){return {x/M,x%M};}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		N=n-1,M=m-1;
		vector<vv> w(n-1,vv(m)),p=w;
		fore(i,0,n-1)fore(j,0,m)cin>>w[i][j];
		vector<vv> v(n,vv(m-1)),q=v;
		fore(i,0,n)fore(j,0,m-1)cin>>v[i][j];
		
		fore(i,0,n-1)fore(j,0,m){
			char c; cin>>c;
			p[i][j]=c-'0';
		}
		fore(i,0,n)fore(j,0,m-1){
			char c; cin>>c;
			q[i][j]=c-'0';
		}
		
		ll nodes=N*M;
		uf_init(nodes);
		vv bad(nodes),we(nodes);
		
		fore(i,0,n-1)fore(j,0,m-1){
			ll x=cv(i,j);
			ll s=w[i][j]+v[i][j]-w[i][j+1]-v[i+1][j];
			we[x]=s;
			ll bo=0;
			ll L=p[i][j];
			ll U=q[i][j];
			ll R=p[i][j+1];
			ll D=q[i+1][j];
			bo|=(!j&&!L);
			bo|=(!i&&!U);
			bo|=(j+1==m-1&&!R);
			bo|=(i+1==n-1&&!D);
			bad[x]=bo;
			
			if(j+1<m-1&&!R){
				ll y=cv(i,j+1);
				uf_join(x,y);
			}
			if(i+1<n-1&&!D){
				ll y=cv(i+1,j);
				uf_join(x,y);
			}
		}
		vector<vv> h(nodes);
		fore(x,0,nodes)h[uf_find(x)].pb(x);
		ll res=0;
		fore(x,0,nodes){
			auto v=h[x];
			if(!SZ(v))continue;
			ll bo=0,s=0;
			for(auto i:v)bo|=bad[i],s+=we[i];
			if(!bo&&s>0)res+=s;
		}
		cout<<res<<"\n";
	}
	return 0;
}
