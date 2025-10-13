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
	
	string s; cin>>s;
	
	vector<string> a={"b","a"};
	while(SZ(a.back())<9*SZ(s)+100){
		ll i=SZ(a);
		a.pb(a[i-1]+a[i-2]);
	}
	
	ll n=SZ(a);
	
	vector<vv> pre(n),suf(n);
	
	fore(_,0,n){
		string b=a[_];
		ll m=SZ(b);
		auto &p=pre[_];
		auto &u=suf[_];
		p=u=vv(m+1);
		auto doit=[&](vv &p){
			ll k=0;
			fore(j,1,m+1){
				if(k<SZ(s)&&b[j-1]==s[k])k++;
				p[j]=k;
			}
		};
		doit(p);
		reverse(ALL(b));
		reverse(ALL(s));
		doit(u);
		reverse(ALL(s));
	}
	
	fore(i,0,n)fore(j,0,n){
		
	}
	
	return 0;
}
