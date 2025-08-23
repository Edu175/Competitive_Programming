#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

void f(ll x, vector<ii> &v){
	ll dos = 0;
	while(!(x&1)){
		x/=2;
		dos++;
	} 
	if(dos) v.pb({2,dos});
	for(ll i = 3;i*i<=x;i+=2){
		if(x%i == 0){
			ll aux = 0;
			while(x%i == 0){
				aux++;
				x/=i;
			}
			v.pb({i,aux});
		}
	}
	if(x!=1){
		v.pb({x,1});
	}
}

// void div_rec(vector<ll> &r,vector<ii> &f, int k,ll c){
// 	if(k==SZ(f)){r.pb(c);return;}
// 	fore(i,0,f[k].snd+1)div_rec(r,f,k+1,c),c*=f[k].fst;
// }

// vector<ll> divisors(vector<ii> f){
// 	vector<ll> r;
// 	div_rec(r,f,0,1);
// 	return r;
// }


int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		// ll n = (ll)6469693230;
		vector<ii> fact;
		f(n,fact);
		ll r = 1;
		for(auto [x,y] : fact){
			// cout<<"x "<<x<<" y "<<y<<"\n";
			r*=(2*y+1);
		}
		r++;
		cout<<r/2<<"\n";
	}
	return 0;
}