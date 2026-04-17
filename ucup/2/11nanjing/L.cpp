#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll A;
ll rta = 0;
vector<ii> uno,dos;


void doit(vector<ii> &a, ll w, ll c, ll f, ll &acc){
	a.pop_back();
	ll sobra = A-acc;
	if(c*w <= sobra){
		// cout<<"en mi viaje voy a agregar "<<c*w<<" de peso "<<w<<" q habitaban en el piso "<<f<<"\n";
		// cout<<"se elimino ese grupo\n";
		acc+=c*w;
	}
	else{
		ll put =sobra/w;
		// cout<<"en mi viaje meto "<<put<<" del grupo q vive en el piso "<<f<<" con peso "<<w<<"\n";
		c -= put;
		acc += put*w;
		a.pb({f,c});
	}
	// cout<<"tras hacer eso mi acc es "<<acc<<"\n";
}

void start_ride(ll acc){
	while(SZ(uno) && SZ(dos) && acc!=A){
		auto [f1,c1] = uno.back();
		auto [f2,c2] = dos.back();
		if(acc+1 == A){
			if(!SZ(uno)) break;
			auto [f1,c1] = uno.back();
			doit(uno,1,c1,f1,acc);
		}
		else if(f1>f2) doit(uno,1,c1,f1,acc);
		else doit(dos,2,c2,f2,acc);
	}
	while(SZ(uno) && acc!=A){
		auto [f1,c1] = uno.back();
		doit(uno,1,c1,f1,acc);
	}
	if(acc + 1 == A) return;
	while(SZ(dos) && acc<A-1){
		auto [f2,c2] = dos.back();
		doit(dos,2,c2,f2,acc);
	}
}

void go(vector<ii> &a, ll w){
	ll entran = A/w;
	auto [f,c] = a.back();
	rta+=(c/entran)*f;
	// cout<<"hago speedrun de viajes a "<<f<<" con las de peso "<<w<<" en total "<<c/entran*f<<" viajes \n";
	c%=entran;
	ll x = c*w;
	a.pop_back();
	if(x){
		// cout<<"inicio un nuevo viaje hacia "<<f<<" con peso "<<x<<"\n";
		start_ride(x);
		rta+=f;
	}
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>A;
		fore(i,0,n){
			ll c,w,f; cin>>c>>w>>f;
			if(w == 1)uno.pb({f,c});
			else dos.pb({f,c});
		}
		sort(ALL(uno)); sort(ALL(dos)); rta = 0;
		while(SZ(uno) && SZ(dos)){
			if(uno.back().fst > dos.back().fst) go(uno,1);
			else go(dos,2);
		}
		while(SZ(uno))go(uno,1);
		while(SZ(dos))go(dos,2);
		cout<<rta<<"\n";
	}
	return 0;
}


