#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;

/*bool overlap(ll l, ll r, ll s, ll e){
	ll flag=0;
	if((l<=s&&s<=r)||(l<=e&&e<=r))flag=1;
	if((s<=l&&l<=e)||(s<=r&&r<=e))flag=1;
	return flag;
}*/
int main(){FIN;
	ll n,m; cin>>n>>m;
	ii a[m];
	fore(i,0,m){
		cin>>a[i].fst>>a[i].snd; a[i].fst--,a[i].snd--;
	}
	ll res=0;
	fore(i,0,n){ // max anticadena por punto comun (no funca por los rangos raros)
		ll resi=0;
		fore(j,0,m)resi+=(a[j].fst<=i&&i<=a[j].snd);
		res=max(res,resi);
	}
	/*fore(i,0,m){ // max anticadena por rango incluído
		ll l=a[i].fst,r=a[i].snd;
		ll resi=0;
		fore(j,0,m){
			if(overlap(l,r,a[j].fst,a[j].snd))
				resi++,l=max(l,a[j].fst),r=min(r,a[j].snd),
		}
		res=max(res,resi);
	}*/
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
