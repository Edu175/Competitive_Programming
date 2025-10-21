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

ll k;
char C(char c, ll sig){
	ll p=c-'a';
	p=(p+sig+k)%k;
	c='a'+p;
	return c;
}

char get(char c){
	char ret=min({c,C(c,1),C(c,-1)});
	return ret;
};


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		string a; cin>>a;
		string mn(n,'.');
		fore(i,0,n)mn[i]=get(a[i]);
		vector<string> dp(n+1);
		for(ll i=n-1;i>=0;i--){
			auto &res=dp[i];
			res=string(1,mn[i])+dp[i+1];
			// cout<<i<<": "<<res<<"\n";
			if(i+3<=n){
				string tmp;
				tmp.pb(a[i+2]);
				tmp.pb(mn[i]);
				tmp.pb(a[i+1]);
				tmp+=dp[i+3];
				res=min(res,tmp);
			}
			if(i+2<=n){
				ll fg=0;
				char v=a[i];
				if(a[i+1]=='a')v=mn[i],fg=1;
				ll p=n,inv=0;
				fore(j,i+2,n){
					if(v<=a[j]){p=j;break;}
					if(j>i+2&&a[j-1]>a[j]){inv=1,p=j+1;break;}
				}
				string tmp=a.substr(i+1,p-(i+1));
				tmp.pb(v);
				if(inv){
					ll sz=SZ(tmp);
					assert(sz>=4);
					swap(tmp[sz-3],tmp[sz-2]);
					swap(tmp[sz-2],tmp[sz-1]);
				}
				if(!fg)tmp[0]=mn[i+1];
				tmp+=dp[p];
				res=min(res,tmp);
				cout<<i<<" salto "<<p<<": "<<tmp<<"\n";
			}
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
