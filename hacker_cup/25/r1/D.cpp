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
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		ll n; cin>>n;
		string s; cin>>s;
		vv c(2);
		ll hay=0;
		for(ll i=n-1;i>=0;i--){
			c[s[i]-'A']++;
			if(c[0]>c[1])hay=1;
		}
		if(hay)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}
