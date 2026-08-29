#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;

int main(){FIN;
	ll n,m,cl,ce,v; cin>>n>>m>>cl>>ce>>v;
	vv ls(cl);
	fore(i,0,cl)cin>>ls[i];
	vv es(ce);
	fore(i,0,ce)cin>>es[i];
	auto hor=[&](vv &a, ll i, ll j)->ll {
		if(i>j)swap(i,j);
		auto ptr=lower_bound(ALL(a),i);
		if(ptr!=a.end()&&*ptr<j)return j-i;
		ll res=INF;
		if(ptr!=a.begin())res=i-*prev(ptr);
		ptr=lower_bound(ALL(a),j);
		if(ptr!=a.end())res=min(res,*ptr-j);
		return 2*res+j-i;
	};
	ll q; cin>>q;
	while(q--){
		ll x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
		ll ve=abs(x1-x2);
		ll sta=hor(ls,y1,y2)+ve;
		ll ele=hor(es,y1,y2)+(ve+v-1)/v;
		ll res=min(sta,ele);
		if(!ve)res=abs(y1-y2);
		// cerr<<sta<<" "<<ele<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
