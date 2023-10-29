#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<vector<ll>>pos(n);
	fore(i,0,3*n){
		ll x; cin>>x; x--;
		pos[x].pb(i);
	}
	vector<ii>a;
	fore(i,0,n)a.pb({pos[i][1],i});
	sort(ALL(a));
	fore(i,0,n)cout<<a[i].snd+1<<" ";
	cout<<"\n";
	return 0;
}
