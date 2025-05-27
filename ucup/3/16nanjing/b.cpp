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
const ll MAXN=2e5+5;

ll cv(ll d, ll v, ll p){
	p&=1;
	if(d==0){
		if(v==2&&p==1)return 1;
		if(v==0&&p==1)return 1;
		if(v==0&&p==0)return -1;
		return 0;
	}
	if(d==1){
		if(v==2&&p==0)return 1;
		if(v==0&&p==0)return 1;
		if(v==0&&p==1)return -1;
		return 0;
	}
	if(d==2){
		if(v==2&&p==1)return 1;
		if(v==1&&p==1)return 1;
		if(v==1&&p==0)return -1;
		return 0;
	}
	if(d==3){
		if(v==2&&p==0)return 1;
		if(v==1&&p==0)return 1;
		if(v==1&&p==1)return -1;
		return 0;
	}
	assert(0);
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		vector<vv> des(4,vv(n));
		fore(d,0,4)fore(i,0,n){
			des[d][i]=cv(d,s[i]-'0',i);
		}
		vv jump(n+1,n);
		fore(d,0,4){
			vv sp(n+1);
			fore(i,1,n+1)sp[i]=sp[i-1]+des[d][i-1];
			vv par,odd;
			fore(i,0,n+1){
				if(i&1)odd.pb(i);
				else par.pb(i);
			}
			stable_sort(ALL(par),[&](ll i, ll j){return sp[i]<sp[j];});
			stable_sort(ALL(odd),[&](ll i, ll j){return sp[i]<sp[j];});
			// cout<<"\ndesigualdad "<<d<<":\n";
			// imp(des[d]);
			// imp(sp)
			// imp(par)
			// imp(odd)
			reverse(ALL(par));
			reverse(ALL(odd));
			ll mx=-1;
			for(auto i:par){
				mx=max(mx,i);
				jump[i]=min(jump[i],mx);
			}
			mx=-1;
			for(auto i:odd){
				mx=max(mx,i);
				jump[i]=min(jump[i],mx);
			}
		}
		// imp(jump);
		vv dp(n+5);
		for(ll i=n-1;i>=0;i--){
			ll &res=dp[i];
			res=dp[i+1]+1;
			ll p=jump[i];
			if(p>i)res=min(res,dp[p]);
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
