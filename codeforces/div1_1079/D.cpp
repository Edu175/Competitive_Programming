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

ll typ(char c){
	if(c=='['||c=='(')return 0;
	return 1;
}
ll wh(char c){
	if(c=='('||c==')')return 0;
	return 1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vector<vv> pos(2);
		vv vis(n);
		fore(i,0,n){
			char c=s[i];
			auto &v=pos[wh(c)];
			if(!typ(c))v.pb(i);
			else {
				if(SZ(v)){
					ll j=v.back();
					v.pop_back();
					vis[j]=vis[i]=1;
				}
			}
		}
		vv b;
		fore(i,0,n)if(!vis[i])b.pb(typ(s[i]));
		ll u=count(ALL(b),1);
		ll z=count(ALL(b),0);
		assert((u+z)%2==0);
		ll is=0;
		fore(i,0,SZ(b)-1)is|=!b[i]&&b[i+1];
		ll res=(u+z)/2;
		if(u%2&&!is)res++;
		cout<<res<<"\n";
	}
	return 0;
}
