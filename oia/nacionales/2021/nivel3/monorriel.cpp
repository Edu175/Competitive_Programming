#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll c,m; cin>>c>>m;
	vector<ii> a(m);
	vector<pair<ii,ll>> ev;
	fore(i,0,m){
		ll l,r; cin>>l>>r;
		a[i]={l,r};
		ev.pb({{l,1},i});
		ev.pb({{r,-1},i});
	}
	sort(ALL(ev));
	set<ii>st;
	vector<ll>us(m,1);
	for(auto [p,i]:ev){
		if(p.snd==1)st.insert({a[i].snd,i});
		else st.erase({a[i].snd,i});
		//cout<<p.fst<<","<<p.snd<<" "<<i<<": ";
		//for(auto i:st)cout<<i.fst<<","<<i.snd<<" ";
		if(SZ(st)>c){
			ll j=prev(st.end())->snd;
			us[j]=0;
			st.erase({a[j].snd,j});
		}
		//cout<<"| ";
		//for(auto i:st)cout<<i.fst<<","<<i.snd<<" ";
		//cout<<"\n";
	}
	ll res=0;
	for(auto i:us)res+=i;
	cout<<res<<"\n";
	imp(us);
	return 0;
}
