#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;

int main(){ET
	 ll n, x; cin>>n>>x;
	ll rta=1;
	ll m=1;
	vv p(n);
	fore(i,0,n){
		cin>>p[i];
		if(i>0 && abs(p[i]-p[i-1])<=x) m++;
		else m=1;
		rta=max(rta,m);
	} 
	cout<<rta<<"\n";
	
}