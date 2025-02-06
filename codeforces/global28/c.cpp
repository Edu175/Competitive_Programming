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
		string s; cin>>s;
		ll n=SZ(s);
		ll c=0;
		fore(i,0,n){
			if(s[i]=='0')break;
			c++;
		}
		vv id(c); iota(ALL(id),0);
		ll p=c;
		fore(j,0,n-c){
			ll go=(s[c+j]-'0')^1;
			ll hay=0;
			for(auto i:id)hay|=(s[i+j]-'0'==go);
			if(!hay)go^=1;
			else {
				vv idi;
				for(auto i:id)if(s[i+j]-'0'==go)idi.pb(i);
				swap(id,idi);
			}
		}
		
		cout<<"1 "<<n<<" "<<id[0]+1<<" "<<id[0]+max(n-c,1ll)<<"\n";
	}
	return 0;
}
