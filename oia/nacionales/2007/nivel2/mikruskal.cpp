#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll>ii;

int main(){FIN;
	ll n; cin>>n;
	ll a[n][n];
	vector<pair<ll,ii>>ord;
	fore(i,0,n){
		fore(j,0,n){
			cin>>a[i][j];
			if(i<j){
				ord.pb({a[i][j],{min(i,j),max(i,j)}});
			}
		}
	}
	sort(ALL(ord));
	ll id[n];
	mset(id,-1);
	vector<vector<ll>>comp(n);
	fore(i,0,n)comp[i].pb(i);
	vector<pair<ii,ll>>res;
	for(auto it:ord){
		ll i=it.snd.fst, j=it.snd.snd, w=it.fst;
		if(id[i]!=id[j]||id[i]==-1){
			res.pb({{i,j},w});
			ll u=id[i], v=id[j];
			if(SZ(comp[u])>SZ(comp[v]))swap(u,v);
			for(auto k:comp[u]){
					comp[v].pb(k);
					id[k]=v;
			}
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res){
		cout<<i.fst.fst+1<<" "<<i.fst.snd+1<<" "<<i.snd<<"\n";
	}
	return 0;
}
