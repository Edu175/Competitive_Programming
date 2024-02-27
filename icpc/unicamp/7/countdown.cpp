#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll m; cin>>m;
	map<string,string>mp;
	fore(i,0,m){
		string s; cin>>s;
		auto sa=s;
		sort(ALL(sa));
		if(!mp.count(sa)||mp[sa]>s)mp[sa]=s;
	}
	ll q; cin>>q;
	while(q--){
		string s; cin>>s;
		sort(ALL(s));
		string res;
		fore(mk,1,1ll<<9){
			string si;
			fore(i,0,9)if((mk>>i)&1)si.pb(s[i]);
			string resi=mp[si];
			if(SZ(resi)>SZ(res)||(SZ(resi)==SZ(res)&&resi<res))res=resi;
		}
		if(SZ(res))cout<<res<<"\n";
		else cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
