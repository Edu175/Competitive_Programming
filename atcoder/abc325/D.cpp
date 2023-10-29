#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	ii a[n];
	//vector<pair<ii,ll>>ev;
	map<ll,vector<ii>>ev;
	fore(i,0,n){
		ll t,d; cin>>t>>d;
		a[i].fst=t,a[i].snd=t+d;
		ev[a[i].fst].pb({1,i});
		ev[a[i].snd].pb({-1,i});
		//ev.pb({{a[i].fst,1},i});
		//ev.pb({{a[i].snd,-1},i});
	}
	//sort(ALL(ev));
	set<ii>st;
	ll res=0;
	for(auto [t,v]:ev){
		for(auto [j,i]:v){
			if(j==1)st.insert({a[i].snd,i});
		}
		//cout<<j.fst<<": ";
		//for(auto i:st)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		if(!SZ(st))continue;
		//cout<<"saco "<<st.begin()->fst<<","<<st.begin()->snd<<"\n";
		res++;
		st.erase(st.begin());
		for(auto [j,i]:v){
			if(j==-1)st.erase({a[i].snd,i});
		}
	}
	cout<<res<<"\n";
	return 0;
}
