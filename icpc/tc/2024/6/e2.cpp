#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n; cin>>n;
	set<ll> s;
	fore(i,0,n){
		ll x; cin>>x;
		s.insert(x);
	}
	for(auto x:s){
		ll d=1;
		fore(i,0,40){
			if(s.count(x+d) && s.count(x+d+d)){
				cout<<3<<"\n"<<x<<" "<<x+d<<" "<<x+d+d<<"\n";
				return 0;
			}
			d*=2;
		}
	}
	for(auto x:s){
		ll d=1;
		fore(i,0,40){
			if(s.count(x+d)){
				cout<<2<<"\n"<<x<<" "<<x+d<<"\n";
				return 0;
			}
			d*=2;
		}
	}
	cout<<1<<"\n"<<*s.begin()<<"\n";
	
}