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
const ll MAXN=1000;

vector<vector<ll>>comp(MAXN);
vector<ll> id(MAXN);

void uf_init(ll n){fore(i,0,n)comp[i].pb(i),id[i]=i;}
bool uf_join(ll a, ll b){
	if(id[a]==id[b])return false;
	ll ida=id[a], idb=id[b];
	if(SZ(comp[ida])>SZ(comp[idb]))swap(ida,idb);
	for(auto i:comp[ida]){
		comp[idb].pb(i);
		id[i]=idb;
	}
	return true;
}

vector<pair<ll,pair<ll,ll>>>es;//edges(cost,(u,v))
ll kruskal(ll n){
	sort(ALL(es)); uf_init(n);
	ll res=0;
	for(auto i:es){
		ll a=i.snd.fst, b=i.snd.snd, w=i.fst;
		if(uf_join(a,b)){
			res+=w;
			cout<<i.snd.fst+1<<" "<<i.snd.snd+1<<" "<<i.fst<<"\n";
		}
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n][n];
	fore(i,0,n){
		fore(j,0,n){
			cin>>a[i][j];
			if(i<j){
				es.pb({a[i][j],{min(i,j),max(i,j)}});
			}
		}
	}
	cout<<n-1<<"\n";
	kruskal(n);
	/*for(auto i:es){
		cout<<i.snd.fst<<" "<<i.snd.snd<<": "<<i.fst<<"\n";
	}*/
	return 0;
}
