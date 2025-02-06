#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll n,m,k;
vv a;
vector<ii> mvs;

bool can(ll x, ll obj){
	for(auto [c,m] : mvs){
		if(a[x]==c) x+=m;
		if(x==obj) return true;
		if(x==-1 || x==n) return false;
	}
	return false;
}


int main(){
	TUCUTUCUTUCUTUCU
	
	cin>>n>>m>>k;
	a.resize(n);
	fore(i,0,n){
		cin>>a[i];
	}
	mvs.resize(k);
	fore(i,0,k){
		cin>>mvs[i].fst>>mvs[i].snd;
	}
	
	ll l = 0, r = n-1;
	while(l<r){
		ll m = (l+r)/2;
		if(!can(m,-1)) r=m;
		else l = m+1;
	}
	ll izq = r;	
	
	l = 0, r = n;
	while(l<r){
		ll m = (l+r)/2;
		if(can(m,n)) r = m;
		else l = m+1;
	}
	
	ll der = n-r;
	
	cout<<min(n,izq+der)<<"\n";
	
	return 0;
}

