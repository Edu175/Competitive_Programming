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
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll p[n][n];
	mset(p,0);
	fore(i,0,n){
		vector<pair<ll,ll>>d;
		fore(j,0,n)if(i!=j)d.pb({abs(a[i]-a[j]),j});
		sort(ALL(d));
		fore(j,0,SZ(d)){
			p[i][d[j].snd]=n-2-j;
		}
	}
	ll res=0;
	fore(i,0,n)fore(j,0,n)if(i!=j)res=(res+fpow(2,min(p[i][j],p[j][i])))%MOD;
	cout<<" | "; imp(a);
	fore(i,0,2*n+4)cout<<"-";
	cout<<"\n";
	fore(i,0,n){
		cout<<a[i]<<"| ";
		imp(p[i]);
	}
	cout<<res<<"\n";
	cout<<res*fpow(2,MOD-2)%MOD<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
