#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
int main(){FIN;
	ll n,q;cin>>n>>q;ll a[n];
	ll x[q],k[q];
	map<ll,vector<ll>>v;
	fore(i,0,n)cin>>a[i],v[a[i]].pb(i+1);
	fore(i,0,q){
		cin>>x[i]>>k[i];
		ll sz=SZ(v[x[i]]);
		if(k[i]<=sz&&v[x[i]][k[i]-1]){
		cout<<v[x[i]][k[i]-1]<<"\n";
		}
		else cout<<"-1\n";
	}
	return 0;
}
