#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) for(auto y:x){cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool can(vv &v){
	bool p = 0, i = 0;
	for(auto x:v){
		if(x&1) i = 1;
		else p = 1;
	}
	if(!p) return false;
	if(SZ(v)%2 == 0 || i) return true;
	for(auto &x:v) x/=2;
	return can(v);
}


int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n) cin>>a[i];
		cout<<(can(a) ? "1" :"0")<<"\n";
	}	
	return 0;
}