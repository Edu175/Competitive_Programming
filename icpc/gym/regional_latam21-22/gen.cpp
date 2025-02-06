#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef int ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
int main(){FIN;
	ll n; cin>>n;
	cout<<n<<"\n";
	vector<vector<ii>>eds(n);
	eds[0]={{1,2}};
	fore(i,1,n){
		ll m=1ll<<i;
		ll x=rng()%m+1,y=rng()%m+m+1;
		fore(_,0,2)for(auto [x,y]:eds[i-1]){
			eds[i].pb({x+m*_,y+m*_});
		}
		eds[i].pb({x,y});
	}
	for(auto ed:eds){
		cout<<SZ(ed)+1<<"\n";
		for(auto [x,y]:ed)cout<<x<<" "<<y<<"\n";
	}
	
}