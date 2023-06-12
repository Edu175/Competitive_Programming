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
	ll comp[n];
	mset(comp,-1);
	vector<vector<ll>>componente;
	vector<pair<ii,ll>>res;
	ll m=0;
	for(auto it:ord){
		ll i=it.snd.fst, j=it.snd.snd, w=it.fst;
		if(comp[i]!=comp[j]||comp[i]==-1){
			res.pb({{i,j},w});
			if(comp[i]==-1&&comp[j]==-1){
				comp[i]=m;
				comp[j]=m;
				m++;
				componente.pb({i,j});
			}
			else if((comp[i]>=0)xor(comp[j]>=0)){
				ll v,e;
				if(comp[i]>=0)v=j,e=i;
				else v=i, e=j;
				comp[v]=comp[e];
				componente[e].pb(v);
			}
			else{
				ll s=max(comp[i],comp[j]), e=min(comp[i],comp[j]);
				for(auto k:componente[s]){
					componente[e].pb(k);
					comp[k]=e;
				}
			}
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res){
		cout<<i.fst.fst+1<<" "<<i.fst.snd+1<<" "<<i.snd<<"\n";
	}
	return 0;
}
