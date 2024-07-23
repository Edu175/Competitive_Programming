#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
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

int main(){JET
	ll n,x; cin>>n>>x;
	if(x>=n){
		cout<<"-1\n";
		return 0;
	}
	vector<ll> prim[n];
	vv sec[n];
	fore(i,0,n){
		fore(j,1,x+1){
			prim[i].pb(i*x+j);
			sec[(i+j)%n].pb(i*x+j);
		}
	}
	fore(i,0,n){
		fore(j,0,SZ(prim[i])) cout<<prim[i][j]<<" ";
		fore(j,0,SZ(sec[i])) cout<<sec[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}


/*

3 2
p 0 -> 0
s 0 -> 1
p 1 -> 0
s 1 -> 2
p 2 -> 1
s 2 -> 0
p 3 -> 1
s 3 -> 2
p 4 -> 2
s 4 -> 0
p 5 -> 2
s 5 -> 1
1 2 3 5 
3 4 1 6 
5 6 2 4

*/