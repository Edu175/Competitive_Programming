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

ll solve(ll ab, ll ba, vector<string>v){
	ll _tot=ab+ba;
	ll _ab=ab,_ba=ba;
	ll sum=0;
	vv vab,vba;
	for(auto s:v){
		if(SZ(s)&1)sum+=SZ(s)/2;
		else {
			if(s.substr(0,2)=="AB")vab.pb(SZ(s)/2);
			else vba.pb(SZ(s)/2);
		}
	}
	auto doit=[&](vv &v, ll &c){
		sort(ALL(v));
		for(auto i:v){
			if(c>=i)c-=i;
			else {
				i-=c;
				c=0;
				sum+=max(0ll,i-1);
			}
		}
	};
	doit(vab,ab);
	doit(vba,ba);
	
	ll q=min(ab,sum);
	ab-=q; sum-=q;
	
	q=min(ba,sum);
	ba-=q; sum-=q;
	
	return _tot-(ab+ba);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		string tmp;
		ll n=SZ(s);
		vector<string> v;
		fore(i,0,n){
			tmp.pb(s[i]);
			if(i==n-1||s[i]==s[i+1])v.pb(tmp),tmp.clear();
		}
		ll a,b,ab,ba; cin>>a>>b>>ab>>ba;
		ll us=solve(ab,ba,v);
		a+=us,b+=us;
		for(auto i:s){
			if(i=='A')a--;
			else b--;
		}
		if(a>=0&&b>=0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
