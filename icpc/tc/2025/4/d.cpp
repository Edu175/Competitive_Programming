#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,T; cin>>n>>T;
	vector<ii>ev;
	fore(i,1,n+1){
		ll t; cin>>t;
		ll l=t-i,r=T-i;
		// cout<<l<<" "<<r<<"\n";
		if(l>=r)continue;
		ev.pb({l,1});
		ev.pb({r,-1});
	}
	ev.pb({0,0});
	sort(ALL(ev));
	ll q=0,res=0;
	// for(auto i:ev)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	fore(i,0,SZ(ev)){
		q+=ev[i].snd;
		if(i==SZ(ev)-1||ev[i].fst!=ev[i+1].fst){
			if(ev[i].fst>=0)res=max(res,q);
		}
	}
	cout<<res<<"\n";
	return 0;
}