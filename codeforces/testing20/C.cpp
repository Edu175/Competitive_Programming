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
const ll n=20;

void first(){
	ll t; cin>>t;
	while(t--){
		ll x; cin>>x; x--;
		vv a(n);
		fore(i,0,15)a[i]=x>>i&1;
		fore(j,0,4)fore(i,0,15){
			if((i+1)>>j&1)a[15+j]^=a[i];
		}
		fore(j,15,19)a[n-1]^=a[j];
		vv s;
		fore(i,0,n)if(a[i])s.pb(i+1);
		cout<<SZ(s)<<"\n";
		imp(s)
	}
}

void second(){
	ll t; cin>>t;
	while(t--){
		ll k; cin>>k;
		vv a(n);
		fore(i,0,k){
			ll p; cin>>p; p--;
			a[p]=1; 
		}
		fore(j,15,19)a[n-1]^=a[j];
		if(!a[n-1]){ // el cambio fue en los primeros 15
			// cout<<"prim\n";
			ll w=0;
			fore(j,0,4){
				fore(i,0,15)if((i+1)>>j&1)a[15+j]^=a[i];
				if(a[15+j])w|=(1ll<<j);
			}
			if(w){ // hubo cambio
				// cout<<"hubo\n";
				// cout<<w<<" w\n";
				w--;
				a[w]^=1;
			}
		}
		ll x=0;
		fore(i,0,15)x|=a[i]<<i;
		cout<<x+1<<"\n";
	}
}
int main(){FIN;
	string ty; cin>>ty;
	if(ty=="first")first();
	else second();
	return 0;
}
