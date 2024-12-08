#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ld alp; ll n; cin>>alp>>n;
	alp=alp/180*acosl(-1);
	// cout<<alp<<" alp\n";
	vector<pair<ld,ll>>ev;
	fore(i,0,n){
		ll l,h; cin>>l>>h;
		ld x=h/tan(alp);
		ld r=l+x;
		ev.pb({l,1});
		ev.pb({r,-1});
		// cout<<i<<": "<<l<<","<<r<<"\n";
	}
	sort(ALL(ev));
	ld res=0;
	ll q=0;
	fore(i,0,SZ(ev)){
		q+=ev[i].snd;
		if(q>0)res+=ev[i+1].fst-ev[i].fst;
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}