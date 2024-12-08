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
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		vv c(2);
		for(auto i:s)c[i-'0']++;
		vv ops;
		fore(i,0,n-1){
			c[s[i]-'0']--;
			ops.pb(c[1]-c[0]);
		}
		sort(ALL(ops));
		reverse(ALL(ops));
		ll res=SZ(ops);
		fore(i,0,SZ(ops)){
			if(k<=0){res=i;break;}
			k-=ops[i];
		}
		res++;
		if(k>0)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
