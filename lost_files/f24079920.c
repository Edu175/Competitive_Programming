#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ii> g[MAXN];
ll v[MAXN];

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>v[i];
	fore(i,0,n-1){
		ll u,d,v; cin>>u>>d>>v; u--,v--;
		
	}
	return 0;
}
