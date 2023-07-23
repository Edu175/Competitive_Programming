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
	ll t; cin>>t;
	while(t--){
		ll n=8;
		char a[n][n];
		fore(i,0,n)fore(j,0,n)cin>>a[i][j];
		string s;
		fore(i,0,n){
			fore(j,0,n)if(a[i][j]!='.')s.pb(a[i][j]);
		}
		cout<<s<<"\n";
	}
	return 0;
}
