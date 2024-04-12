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

vector<ii>ord;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<vector<ll>>a(n,vector<ll>a(n));
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	fore(i,0,2)fore(j,0,2)ord.pb({i*2-1,j*2-1});
	
	return 0;
}
