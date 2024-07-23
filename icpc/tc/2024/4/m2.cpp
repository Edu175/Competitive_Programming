#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll n,m;
vv b;

bool can(ll x){
	vv aux;
	fore(i,0,x) aux.pb(b[i]);
	sort(ALL(aux));
	reverse(ALL(aux));
	ll rta=0;
	for(int i=0; i<aux.size();i+=2){
		rta+=aux[i];
	}
	return rta<=m;
}

int main(){
	JET
	cin>>n>>m;
	fore(i,0,n){
		int x; cin>>x;
		b.pb(x);	
	}
	ll l=1;
	ll r=n;
	while(l<=r){
		ll mm=(l+r)/2;
		if(can(mm)) l=mm+1;
		else r=mm-1;
	}
	cout<<l-1<<"\n";
	return 0;
}