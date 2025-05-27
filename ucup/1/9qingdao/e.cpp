#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll n,m;
vv a;

bool can(ll x){
	ll cnt=0;
	ll d[n];
	mset(d,0);
	fore(i,0,n){
		if(d[i]>=x && i==n-1) continue;
		cnt++;
		d[i]+=a[i];
		ll y = x-d[i];
		if(cnt>m) return false;
		if(y<=0) continue;
		ll uso = (y+a[i]-1)/a[i];
		cnt+=uso*2;
		if(i<n-1) d[i+1] += uso*a[i+1];
		if(cnt>m) return false;
	}
	// cout<<"estoy en "<<x<<" y hago "<<cnt<<" pasos\n";
	return cnt<=m;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		a.clear();
		a.resize(n);
		fore(i,0,n) cin>>a[i];
		
		ll l = 1, r = 1e18;
		// ll l = 1, r = 10; cout<<"DEBUG\n";
		
		while(l<r){
			// cout<<"l , r inicial:  "<<l<<" "<<r<<"\n";
			ll m = (l+r)/2;
			if(!can(m)) r=m;
			else l = m+1;
			// cout<<"l , r final:  "<<l<<" "<<r<<" probo "<<m<<"\n";
			
		}
		// can(9);
		cout<<r-1<<"\n";
	}
	
	
	return 0;
}
/*
2
4 8
3 2 6 6
3 9
10 10 1
DEBUG
l , r inicial:  1 10
l , r final:  1 5 probo 5
l , r inicial:  1 5
l , r final:  1 3 probo 3
l , r inicial:  1 3
l , r final:  3 3 probo 2
2
DEBUG
l , r inicial:  1 10
l , r final:  1 5 probo 5
l , r inicial:  1 5
l , r final:  4 5 probo 3
l , r inicial:  4 5
l , r final:  5 5 probo 4
4
*/