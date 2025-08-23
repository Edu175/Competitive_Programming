#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll inf = 1e14;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll med = n/2;
		ll a[n][n];
		fore(i,0,n)fore(j,0,n) cin>>a[i][j];
		ll x = a[med][med], b=inf,c = inf,d = inf,e = inf,f = inf, g = inf, h = inf, iii = inf;
		fore(i,0,med+1) b = min(b,a[med][i]);
		fore(i,med,n) c = min(c,a[med][i]);
		fore(i,0,med+1) d = min(d,a[i][med]);
		fore(i,med,n) e = min(e,a[i][med]);
		fore(i,0,med+1)fore(j,0,med+1) f= min(f,a[i][j]);
		fore(i,0,med+1)fore(j,med,n) g = min(g,a[j][i]);
		fore(i,med,n)fore(j,0,med+1) h = min(h,a[j][i]);
		fore(i,med,n)fore(j,med,n) iii = min(iii,a[i][j]);
		// cout<<"asndoasd"<<endl;
		d = min(d,f+h);
		e = min(e,g+iii);
		b = min(b,f+g);
		c = min(c,h+iii);
		x = min(x,b+c);
		x = min(x,d+e);
		cout<<x<<"\n";
	}
	
	return 0;
}