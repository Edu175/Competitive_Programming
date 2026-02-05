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

void alt(ll l, ll r, string &s){
	char c='(';
	fore(i,l,r){
		s[i]=c;
		c^=1;
	}
}
map<char,ll> delta={{'(',1},{')',-1}};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; n<<=1;
		string s; cin>>s;
		vector<string> ans;
		auto mop=[&](string op){ // depth is O(1)
			// cerr<<"mop "<<op<<"\n";
			fore(l,0,n){
				ll c=0,bad=0,R=-1;
				fore(r,l,n){
					c+=delta[op[r]];
					if(c<0){bad=1;break;}
					if(c==0){R=r;break;}
				}
				if(!bad){
					// cerr<<"swap ["<<l<<","<<R<<"]\n";
					fore(i,l,R+1)s[i]^=1;
				}
			}
			ans.pb(op);
			// cerr<<s<<"\n";
		};
		ll good=1;
		auto dow=[&](ll w){
			vv v;
			fore(i,0,n-1)if(i%2==w&&s[i]!=s[i+1])v.pb(i);
			if(SZ(v)&1){good=0;return;}
			// cerr<<"dow "<<w<<": "; imp(v)
			string op(n,'.');
			alt(0,n,op);
			vv xr(n);
			fore(i,0,SZ(v))if(i%2==0){
				ll l=v[i],r=v[i+1]+1;
				op[l]='('; op[r]=')';
				alt(l+1,r,op);
			}
			mop(op);
		};
		dow(1);
		dow(0);
		if(!good){
			cout<<"-1\n";
			continue;
		}
		assert(s==string(n,s[0]));
		if(s[0]=='1'){
			string op(n,'.');
			alt(0,n,op);
			mop(op);
		}
		assert(s==string(n,'0'));
		cout<<SZ(ans)<<"\n";
		for(auto s:ans)cout<<s<<"\n";
	}
	return 0;
}
