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
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vv res;
		ll q=0,fg=1;
		fore(i,0,n){
			q++;
			if(i==n-1||s[i]!=s[i+1]){
				vv per(q);
				iota(ALL(per),i-q+1);
				if(s[i]=='0'){
					reverse(ALL(per));
					fg&=q>1;
				}
				for(auto i:per)res.pb(i);
				q=0;
			}
		}
		if(fg){
			cout<<"YES\n";
			for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}
