#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s,r; cin>>s;
		ll n=SZ(s),did=0;
		fore(i,0,n-1){
			r.pb(s[i]);
			if(s[i]==s[i+1]&&!did){
				if(s[i]=='a')r.pb('b');
				else r.pb('a');
				did=1;
			}
		}
		r.pb(s.back());
		if(!did){
			if(s.back()=='a')r.pb('b');
			else r.pb('a');
		}
		cout<<r<<"\n";
	}
	return 0;
}