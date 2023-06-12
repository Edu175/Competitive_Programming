#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e10;
set<ii>st;
set<ii>dis;
map<ll,ll>t;
ll s;
void saco(ll x){
	ll l=x-(s-t[x]),r=x+(s-t[x]);
	
}
void meto(ll x){
	
}
void inicializar(int N) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
}

vector<int> tiempo(int x) {
	s+=t;
	for(ll x=)
}

vector<int> jugador(int e) { // asumiendo rangos disjuntos
	vector<int>res;
	auto lwb=st.lower_bound(pair({e+s+1,-1}));
	if(lwb!=st.begin()){
		lwb--;
		ll x=(*lwb).snd,l=(*lwb)-s,r=l+2*(s-t[x]);
		if(l<=e&&e<=r){
			saco(x),res.pb(x);
			return res;
		}
		else {
			lwb++;
			ll a=x,b=;
		}
	}
	
}
