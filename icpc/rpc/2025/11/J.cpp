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
	ll n,m,k; cin>>n>>m>>k;
	vv a(n),b(m);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	while(SZ(a)&&a.back()>k)a.pop_back();
	n=SZ(a);
	
	fore(i,0,m)cin>>b[i];
	sort(ALL(b));
	while(SZ(b)&&b.back()>k)b.pop_back();
	m=SZ(b);
	// ll C=1e8+5;
	// if(m)C=1e5+5;
	ll C=105;
	ll g=0;
	fore(i,0,n)g=__gcd(g,a[i]);
	ll fg=g==1;
	fore(i,0,m)fg|=__gcd(g,b[i])==1;
	if(!fg){
		cout<<"-1\n";
		// cerr<<" gcd fails\n";
		return 0;
	}
	// now I can reach all
	vector<bool> all(C);
	if(m){
		for(auto d:b){
			vv dirs=a;
			dirs.pb(d);
			vector<bool> dp(C); dp[0]=1;
			fore(i,0,C)if(dp[i])for(auto j:dirs)if(i+j<C)dp[i+j]=1;
			fore(i,0,C)all[i]=all[i]||dp[i];
		}
	}
	else {
		vector<bool> dp(C); dp[0]=1;
		fore(i,0,C)if(dp[i])for(auto j:a)if(i+j<C)dp[i+j]=1;
		fore(i,0,C)all[i]=all[i]||dp[i];
	}
	ll mx=-1;
	fore(i,0,C)if(!all[i])mx=i;
	cout<<mx<<"\n";
	return 0;
}
