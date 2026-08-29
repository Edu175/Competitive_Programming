#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;

#define maxig(a,b) a=max(a,b)

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		if(m==1){
			cout<<"0\n";
			continue;
		}
		assert(n>1);
		ll fij=0;
		if(a[0]!=0)fij++,a[0]=0;
		if(a[n-1]!=m-1)fij++,a[n-1]=m-1;
		vv dp(n,-INF);
		vv suf(n,-INF); ll acum=-INF;
		vv pre(n,-INF);
		vv ul(2*n,-1); // i-a[i]
		fore(i,0,n){
			maxig(acum,suf[i]);
			auto &cur=dp[i];
			if(!i)cur=0;
			else {
				maxig(cur,acum);
				if(i-a[i]-1>=0)maxig(cur,pre[i-a[i]-1]);
				ll p=i-a[i]+n;
				if(ul[p]!=-1)maxig(cur,dp[ul[p]]);
			}
			cur++;
			ul[i-a[i]+n]=i;
			pre[i]=max((i?pre[i-1]:0ll),cur);
			ll p=i+m-a[i];
			if(p<n)maxig(suf[p],cur);
		}
		ll res=dp[n-1];
		res=n-res+fij;
		cout<<res<<"\n";
	}
	return 0;
}
