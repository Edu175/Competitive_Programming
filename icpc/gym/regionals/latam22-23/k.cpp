#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll n=100;

int main(){
	ET
	vector<ii> mancha,lib;
	fore(i,0,n)fore(j,0,n){
		if(!i||j%3==0)mancha.pb({i,j});
		else lib.pb({i,j});
	}
	// cout<<SZ(lib)<<"\n";
	ll k; cin>>k;
	if(k==1){
		cout<<"0\n";
		return 0;
	}
	if(k==2){
		cout<<"1\n1 1 1\n";
		return 0;
	}
	 // k >= 3
	ll pot=1;
	ll b=0;
	while(pot<k)pot*=2,b++;
	cout<<b<<"\n";
	if(pot!=k)k--;
	// return 0;
	fore(i,0,b){
		vector<ii> puta=mancha;
		fore(mk,0,k)if(mk>>i&1)puta.pb(lib[mk]);
		cout<<SZ(puta)<<" ";
		for(auto [x,y]:puta)cout<<x+1<<" "<<y+1<<" ";
		cout<<"\n";
	}
}