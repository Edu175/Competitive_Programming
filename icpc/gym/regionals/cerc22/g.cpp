#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n; cin>>n;
	vector<ii> c,d;
	while(n%8){
		c.pb({500,500});
		d.pb({500,500});
		n--;
	}
	ll i = 1;
	while(n){
		fore(j,0,3) c.pb({i,1001-i}), d.pb({i,1001-i});
		i++;
		c.pb({i,1001-i}), d.pb({i,1002-i});
		i++;
		c.pb({i,1001-i}), d.pb({i,1002-i});
		i++;
		fore(j,0,3) c.pb({i,1002-i}), d.pb({i,1002-i});
		i++;
		n-=8;
		assert(i<500);
	}
	for(auto [w,y] : c)cout<<w<<" "<<y<<"\n";
	cout<<"\n";
	for(auto [w,y] : d) cout<<w<<" "<<y<<"\n";
	return 0;
}