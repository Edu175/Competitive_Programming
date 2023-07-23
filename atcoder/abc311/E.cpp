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
const ll MAXN=3005;

ll sp[MAXN][MAXN];
ll get(ll i0, ll j0, ll i1, ll j1){
	return sp[i1][j1]-sp[i0][j1]-sp[i1][j0]+sp[i0][j0];
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	ll a[n][m]={};
	fore(i,0,k){
		ll u,v; cin>>u>>v; u--,v--;
		a[u][v]=1;
	}
	fore(i,1,n+1)fore(j,1,m+1)sp[i][j]=sp[i][j-1]+a[i-1][j-1];
	fore(i,1,n+1)fore(j,1,m+1)sp[i][j]+=sp[i-1][j];
	ll res=0;
	fore(i,0,n)fore(j,0,m){
		//cout<<i<<","<<j<<": "<<i+k<<","<<j+k<<": "<<get(i,j,i+k,j+k)<<"\n";
		ll l=0,r=min(n-i,m-j);
		while(l<=r){
			ll m=(l+r)/2;
			if(get(i,j,i+m,j+m)==0)l=m+1;
			else r=m-1;
		}
		//cout<<i<<","<<j<<": "<<r<<"\n";
		res+=r;
	}
	cout<<res<<"\n";
	return 0;
}
