#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii operator-(ii a, ii b){return {a.fst-b.fst,a.snd-b.snd};}
ii operator/(ii a, ll t){return {a.fst/t,a.snd/t};}

int main(){
	JET
	ll n,s; cin>>n>>s; s--;
	ii Isum={0,0},Fsum=Isum;
	ii Is={0,0};
	vector<ii> qs;
	fore(i,0,n){
		ll px,py,qx,qy; cin>>px>>py>>qx>>qy;
		ii p={px,py};
		ii q={qx,qy};
		Isum=Isum+p;
		Fsum=Fsum+q;
		qs.pb(q);
		if(i==s)Is=p;
	}
	ii Fu=(Fsum-Isum)/2+Is;
	ll pos=find(ALL(qs),Fu)-qs.begin();
	cout<<pos+1<<"\n";
	return 0;
}