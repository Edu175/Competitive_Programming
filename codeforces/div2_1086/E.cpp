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
const ll MAXN=5005,MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
#define addig(a,b) a=add(a,b)

ll dp[MAXN][MAXN];

ll dodp(vv dob){ // 0 is useless
	ll n=SZ(dob);
	assert(n);
	// if(!n)return 1;
	ll m=accumulate(ALL(dob),0ll);
	assert(m<MAXN);
	fore(i,0,n+2)fore(j,0,m+2)dp[i][j]=0;
	dp[1][dob[0]]=1;
	fore(i,1,n)for(ll c=m;c>0;c--){
		auto now=dp[i][c];
		if(!now)continue;
		addig(dp[i+1][c+dob[i]],now); // terminal i
		if(c>0)addig(dp[i][c-1],now);
	}
	ll res=0;
	fore(c,1,m+1)addig(res,dp[n][c]);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n+1);
		ll good=1;
		fore(i,1,n+1)cin>>a[i],good&=a[i]<i;
		n++;
		
		fore(i,1,n)if(a[i]!=-1)fore(j,i+1,n)if(a[j]!=-1){
			if(a[i]<a[j]&&a[j]<i)good=0;
		}
		if(!good){
			cout<<"0\n";
			continue;
		}
		ll res=1;
		auto solve=[&](ll l, ll r, auto &&solve)->void {
			vv dob;
			ll p=r-1;
			while(p>=l){
				ll cant=1;
				while(p>l&&a[p]!=-1){
					solve(a[p],p,solve);
					cant++;
					p=a[p];
				}
				dob.pb(cant);
				p--;
			}
			assert(p==l-1);
			reverse(ALL(dob));
			// cerr<<"\n\nsolve "<<l<<","<<r<<":\n";
			// imp(dob)
			// cout<<endl;
			ll cur=dodp(dob);
			// cerr<<cur<<"\n";
			res=mul(res,cur);
		};
		solve(0,n,solve);
		cout<<res<<"\n";
	}
	return 0;
}
