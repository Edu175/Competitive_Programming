#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

set<pair<ii,ll>> libres, bajos;

void f(ll x){
	auto it = libres.begin();
	while(it!=libres.end() && (*it).fst.fst<=x){
		auto[lr,i] = (*it);
		auto [l,r] = lr;
		bajos.insert({{r,l},i});
		it = libres.erase(it);
	}
}


int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n, pos; cin>>n>>pos;
		ll rta=0;
		vv r;
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			libres.insert({{x,y},i+1});
		}
		f(pos);
		while(SZ(libres)+SZ(bajos)){
			// cout<<"caso "<<t<<" en trando con libres "<<SZ(libres)<<" y bajos "<<SZ(bajos)<<" rta "<<rta<<"\n";
			// cout<<SZ(libres)<<"   "<<SZ(bajos)<<" "<<t<<"\n";
			auto it = bajos.end();
			ll x,y,i;
            if(it == bajos.begin())x=-1;
			else{
				it--;
				x = (*it).fst.fst;
				y = (*it).fst.snd;
				i = (*it).snd;
			}
			if(x<=pos && SZ(libres)){
				auto it1 = libres.begin();
				rta+=(*it1).fst.fst-pos;
				pos = (*it1).fst.fst;
				f(pos);
			}
			else{
				bajos.erase(it);
				rta+=x-y;
				pos=x;
				r.pb(i); 
			    f(pos);
			}
		}
		cout<<rta<<"\n";
		for(auto x:r) cout<<x<<" ";
		cout<<"\n";
	}
	return 0;
}

// caso 1 entrando con libres 2 y bajos 2 rta 0
// caso 1 entrando con libres 0 y bajos 3 rta 5
// caso 1 entrando con libres 0 y bajos 2 rta 6
// caso 1 entrando con libres 0 y bajos 1 rta 9
// 11
// 3 4 1 2 
// caso 0 entrando con libres 1 y bajos 1 rta 0
// caso 0 entrando con libres 0 y bajos 2 rta 2
// caso 0 entrando con libres 0 y bajos 1 rta 4
// 6
// 2 1 
