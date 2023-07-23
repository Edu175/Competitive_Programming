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
//musical chairs
const ll MOD=1e9+7;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		ll c[n];
		map<ll,ll>id;
		fore(i,0,n)cin>>c[i],id[c[i]]=-1;
		ll col=0;
		for(auto &i:id)i.snd=col++;
		fore(i,0,n)c[i]=id[c[i]];
		set<ll>op;
		ll sum=0;
		fore(i,0,k){
			ll x; cin>>x;
			sum=(sum+x)%n;
			op.insert(sum);
		}
		ll h[n][col]={};
		ll qz[n];
		fore(i,0,n){
			for(auto j:op)h[i][c[(i+j)%n]]=1;
			qz[i]=0;
			fore(j,0,col)if(!h[i][j])qz[i]++;
		}
		ll p[n]={}; //probabiltiy of staying alive
		ll res=0;
		fore(i,0,n){
			p[i]=(qz[i]+m-col)*fpow(m,MOD-2)%MOD;
			res=(res+p[i])%MOD;
		}
		fore(i,0,n){
			ll x,y; cin>>x>>y; x--;
			ll pi=p[x];
			if(!id.count(y))p[x]=1;
			else {
				y=id[y];
				if(h[x][y])p[x]=0;
				else p[x]=1;
			}
			res=(res-pi+p[x]+MOD)%MOD;
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
