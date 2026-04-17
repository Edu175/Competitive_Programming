#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n; cin>>n;
	ll L=-5,R=2000;
	ll l=L,r=R;
	fore(i,0,n){
		ll a,b; cin>>a>>b;
		char t; cin>>t;
		ll m1=(a+b+1)/2-1;
		ll m2=(a+b)/2+1;
		ii ran;
		if(t=='A')ran={L,m1};
		if(t=='B')ran={m2,R};
		if(t=='E')ran={m1+1,m2-1};
		l=max(l,ran.fst);
		r=min(r,ran.snd);
	}
	if(r-l+1<=0)cout<<"*\n";
	else cout<<l<<" "<<r<<"\n";
	return 0;
}