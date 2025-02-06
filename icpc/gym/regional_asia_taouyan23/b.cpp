#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
ii sum(ii a, ii b){
	ll m=a.snd*b.snd;
	ll n=a.fst*(m/a.snd)+b.fst*(m/b.snd);
	return {n,m};
}
ii redu(ii a){
	ll g=gcd(a.fst,a.snd);
	a.fst/=g;
	a.snd/=g;
	return a;
}
ll get(string s){
	ll res=0;
	fore(i,0,SZ(s))res=res*10+(s[i]-'0');
	return res;
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll c,d; cin>>c>>d;
		string s,t; cin>>s>>t;
		ll a=get(s),b=get(t);
		// cout<<a<<" "<<b<<"\n";
		ll nue=0,die=1;
		fore(i,0,d)nue=nue*10+9;
		fore(i,0,c)die=die*10;
		ii l={b,nue*die},r={a,die};
		l=sum(l,r);
		l=redu(l);
		cout<<l.fst<<" "<<l.snd<<"\n"; 
	}
	return 0;
}