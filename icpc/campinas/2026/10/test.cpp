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

void impm(vector<vv> a){
	ll mx=0;
	for(auto v:a)for(auto i:v)mx=max(mx,SZ(to_string(i)));
	mx+=2;
	ll n=SZ(a),m=SZ(a[0]);
	fore(i,0,n){
		fore(j,0,m){
			ll v=a[i][j];
			ll len=SZ(to_string(v));
			cout<<string(mx-len,' ');
			cout<<v;
		}
		cout<<"\n";
	}
}
ll mex(vv &a){
	ll n=SZ(a);
	vv vis(n+3);
	for(auto i:a)if(i<SZ(vis))vis[i]=1;
	ll res=0;
	while(vis[res])res++;
	return res;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<vv> a(n,vv(m));
	fore(i,0,n)fore(j,0,m){
		vv go;
		fore(r,0,i)go.pb(a[r][j]);
		fore(c,0,j)go.pb(a[i][c]);
		fore(d,1,min(i,j)+1)go.pb(a[i-d][j-d]);
		a[i][j]=mex(go);
	}
	fore(i,0,n){
		fore(j,0,m)a[i][j]-=i;
	}
	impm(a);
	return 0;
}