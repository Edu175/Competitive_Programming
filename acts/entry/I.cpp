#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu.fst<<","<<edu.snd<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e6;
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ii>a;
	fore(i,0,m){
		ll s,e; cin>>s>>e; s--;
		a.pb({s,-e});
	}
	ll r=-5;
	sort(ALL(a));
	vector<ii>b;
	for(auto [s,e]:a){
		e=-e;
		if(e>r)r=e,b.pb({s,e});
	}
	ll res=1;
	r=b[0].snd;
	cout<<b[0].fst<<","<<b[0].snd<<"\n";
	while(1){
		ll p=lower_bound(ALL(b),(ii){r,INF})-b.begin()-1;
		if(b[p].snd<=r)break;
		res++;
		r=b[p].snd;
		cout<<b[p].fst<<","<<b[p].snd<<"\n";
	}
	//imp(b);
	cout<<res<<"\n";
	return 0;
}
