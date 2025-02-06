#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937_64 rng(rd());

ll solve(vector<ii> a, ll w){
	ull h=rng();
	vector<ii>ev;
	for(auto [l,r]:a){
		if(l>r)swap(l,r);
		ull h=rng();
		ev.pb({l,h});
		ev.pb({r,h});
	}
	unordered_map<ull,ll>mp;
	sort(ALL(ev));
	mp[h]+=ev[0].fst;
	fore(i,0,SZ(ev)){
		h^=ev[i].snd;
		if(i==SZ(ev)-1||ev[i].fst!=ev[i+1].fst){
			mp[h]+=(i==SZ(ev)-1?w:ev[i+1].fst)-ev[i].fst;
		}
	}
	ll res=0;
	for(auto i:mp)res=max(res,i.snd);
	// cout<<"solve ";;for(auto [l,r]:a)cout<<l<<","<<r<<" ";;cout<<"= "<<res<<"\n";
	return res;
}



int main(){
	JET
	ll n,x,y; cin>>n>>x>>y;
	vector<ii> xs,ys;
	fore(i,0,n){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		if(a>c)swap(a,c);
		if(b>d)swap(b,d);
		xs.pb({a,c});
		ys.pb({b,d});
	}
	cout<<solve(xs,x)*solve(ys,y)<<"\n";
	return 0;
}