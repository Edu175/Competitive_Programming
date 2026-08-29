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
ll sq(ll a){return a*a;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll tot=0;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i],tot+=a[i];
		fore(i,0,n)cin>>b[i],tot+=b[i];
		vv dp(tot+1); dp[0]=1;
		fore(i,0,n){
			vv prox(tot+1);
			fore(v,0,SZ(dp))if(dp[v]){
				prox[v+a[i]]=prox[v+b[i]]=1;
			}
			dp=prox;
			// imp(dp)
			// cout<<endl;
		}
		ll sum=-1,val=-1;
		fore(s,0,tot+1)if(dp[s]){
			ll cur=s*(s-tot);
			if(sum==-1||cur<val)sum=s,val=cur;
		}
		// cerr<<val<<": "<<sum<<" "<<tot-sum<<": ";
		ll res=sq(sum)+sq(tot-sum);
		fore(i,0,n)res+=(n-2)*sq(a[i]);
		fore(i,0,n)res+=(n-2)*sq(b[i]);
		cout<<res<<"\n";
	}
	return 0;
}
