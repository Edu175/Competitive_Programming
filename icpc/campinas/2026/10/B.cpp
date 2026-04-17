#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll mex(vv &a){
	ll n=SZ(a);
	vv vis(n+3);
	for(auto i:a)if(i<SZ(vis))vis[i]=1;
	ll res=0;
	while(vis[res])res++;
	return res;
}

ll MOD=768,C=3*MOD;

int main(){FIN;
	ll N=25,M=C+MOD;
	vector<vv> a(N,vv(M));
	fore(i,0,N)fore(j,0,M){
		vv go;
		fore(r,0,i)go.pb(a[r][j]);
		fore(c,0,j)go.pb(a[i][c]);
		fore(d,1,min(i,j)+1)go.pb(a[i-d][j-d]);
		a[i][j]=mex(go);
	}
	fore(i,0,N)fore(j,0,M)a[i][j]-=j;
	auto get=[&](ll i, ll j){
		ll _j=j;
		if(j>=M)j=j%MOD+C;
		ll ret= a[i][j]+_j;
		// cout<<"get "<<i<<","<<j<<": "<<ret<<"\n";
		return ret;
	};
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>n>>n;
		ll x=0;
		fore(_,0,n){
			ll i,j; cin>>i>>j; i--,j--;
			x^=get(i,j); 
		}
		if(x)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}