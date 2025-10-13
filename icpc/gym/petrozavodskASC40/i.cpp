#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int maxn = 2e5+10;
ll rta[maxn];
ll post[maxn];
set<ll> g[maxn];

int main(){
	#ifdef ONLINE_JUDGE
	freopen("intouch.in","r",stdin);     freopen("intouch.out","w",stdout);
	#endif
	
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		char c; cin>>c;
		if(c == '!'){
			ll x; cin>>x;
			x--;
			post[x]++;
		}
		else if(c == '+'){
			ll x,y; cin>>x>>y; 
			x--;y--;
			rta[x] -= post[y];
			rta[y] -= post[x];
			g[x].insert(y);
			g[y].insert(x);
		}
		else{
			ll x,y; cin>>x>>y;
			x--,y--;
			rta[x] += post[y];
			rta[y] += post[x];
			g[x].erase(y);
			g[y].erase(x);
		}
	}	
	fore(i,0,n){
		for(auto x:g[i]) rta[i] += post[x];
		cout<<rta[i]<<" ";
	}
	cout<<"\n";
	return 0;
}