#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=2e5+5;

vv a[9];
ll n;


void cuad(int x, int y, int i){
	if(x<= n/3 && y<=n/3) a[0].pb(i);
	if(x<= n/3 && y<=n/3) a[0].pb(i);
	if(x<= n/3 && y<=n/3) a[0].pb(i);
	if(x<= n/3 && y<=n/3) a[0].pb(i);
	if(x<= n/3 && y<=n/3) a[0].pb(i);
	
}

int main(){
	JET	
	cin>>n;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		cuad(x,y);
	}
	return 0;
}