#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v).sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0)cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	int a,b,c; cin>>a>>b>>c;
	int x,y,z; cin>>x>>y>>z;
	ll r=0; if(x>a) r+=x-a; if(y>b) r+=y-b; if(z>c) r+=z-c;
	cout<<r<<"\n";
	
}