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

ll dist(pair<ll,ll> p, pair<ll,ll> q){
	return abs(p.fst-q.fst)+abs(p.snd-q.snd);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		char a[n][m];
		vector<pair<ll,ll>b;
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
				if(a[i][j]=='B')b.pb({i,j});
			}
		}
		pair<ll,ll>maxd1={0,0};
		pair<ll,ll>maxd2={0,0};
		for(auto i:b){
			for(auto j:b)if(dist(i,j)>)
		}
	}
	return 0;
}
