#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		pair<string,ll> res={to_string('z'+1),0};
		fore(k,1,n+1){
			string l,r(n-k);
			fore(i,0,k)l.pb(s[i]);
			if((n-k)%2)reverse(ALL(l));
			fore(i,0,n-k)r[i]=s[i+k-1];
			r+=l;
			res=min(res,{r,k});
		}
		cout<<res.fst<<"\n";
	}
	return 0;
}
