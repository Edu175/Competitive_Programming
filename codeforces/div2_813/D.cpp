#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

bool desort(pair<pair<ll,ll>,ll>p1, pair<pair<ll,ll>,ll>p2){
	return p1.snd<p2.snd;
}

bool comp(pair<pair<ll,ll>,ll>p1, pair<pair<ll,ll>,ll>p2){
	if(p1.fst.fst==p2.fst.fst)return p1.fst.snd > p2.fst.snd;
	else return p1.fst.fst < p2.fst.fst;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<pair<pair<ll,ll>,ll>> a(n);
		ll inf=1000000000;
		fore(i,0,n){
			cin>>a[i].fst.fst;
			a[i].snd=i;
			ll adj=0;
			if(i){
				if(a[i-1].fst.fst<a[i].fst.fst)adj=inf;
				else adj=a[i-1].fst.fst;
			}
			if(i<n-1){
				if(a[i+1].fst.fst<=a[i].fst.fst)adj=inf;
				else adj=max(adj,a[i+1].fst.fst);
			}
			a[i].fst.snd=adj;
		}
		if(k>=n){
			cout<<inf<<"\n";
			continue;
		}
		sort(ALL(a), comp);
		fore(i,0,k){
			a[i].fst.fst=inf;
		}
		ll mini=a[k].fst.fst;
		sort(ALL(a),desort);
		ll maxi=0;
		fore(i,0,n-1)maxi=max(maxi,min(a[i].fst.fst,a[i+1].fst.fst));
		cout<</*mini<<" "<<maxi<<" "<<*/min(2*mini,maxi)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
