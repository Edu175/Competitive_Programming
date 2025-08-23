#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

set<ll> vis;
const ll INF = 1e10;
ll obj;

void f(ll s){
	vis.insert(s);
	ll p = 1;
	if(vis.count(obj)) return;
	if(s>INF) return;
	fore(i,0,10){
		ll x = (s/p)%10;
		if(x<5){
			ll aux = s - x*p;
			if(!vis.count(aux)) f(aux);
		}		
		else{
			ll aux =s+(10-x)*p;
			if(!vis.count(aux)) f(aux);
		}
		p*=10;
	}
}

int main(){
	ll s;
	cin>>s;
	vv rta;
	fore(i,0,3333333){
		cout<<"clear "<<i<<"\n";
		vis.clear();
		f(i);
		if(vis.count(s)) rta.pb(i);
	}
	// f(1499);
	for(auto x:rta) cout<<x<<"\n";
	cout<<SZ(rta)<<"\n";
}