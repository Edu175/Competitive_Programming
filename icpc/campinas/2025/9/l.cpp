#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll to2(ll n){return n*(n-1)/2;}

int main(){
	JET
	int n,q; cin>>n>>q;
	vector<int> c(n);
	fore(i,0,n)c[i]=n-1-i;
	ll tot=n*ll(n-1)*(n-2)/6;
	ll res=0;
	fore(i,0,n)res+=to2(c[i]);
	while(q--){
		int u,v; cin>>u>>v; u--,v--;
		res-=to2(c[u]);
		res-=to2(c[v]);
		c[u]--,c[v]++;
		res+=to2(c[u]);
		res+=to2(c[v]);
		
		cout<<tot-res<<"\n";
	}
	return 0;
}