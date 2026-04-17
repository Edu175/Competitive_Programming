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
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n; cin>>n;
	vector<vv> a(2,vv(3));
	fore(i,0,2)fore(j,0,3)cin>>a[i][j],a[i][j]++;
	vector<vector<ld>> dp(n+1,vector<ld>(2));
	// dp[0][0]=0;
	ld P=a[0][0]*a[1][1]*a[0][2];
	ld Q=a[1][0]*a[0][1]*a[1][2];
	P=1./P; Q=1./Q;
	ld T=P*Q;
	ld sum=1/(1-T)-1;
	cerr<<P<<" "<<Q<<": "<<sum<<"\n";
	fore(t,0,n){
		auto &now0=dp[t][0];
		auto &now1=dp[t][1];
		cerr<<now0<<" "<<now1<<": ";
		now0+=(3+now0)*sum;
		now1+=(3+now1)*sum;
		if(!t)now1=0;
		auto _now0=now0;
		if(t)now0+=(now1+1)*Q;
		now1+=(_now0+2)*P;
		cerr<<now0<<" "<<now1<<"\n";
		fore(w,0,2){
			array<ld,3> cur;
			cur[0]=dp[t][w];
			fore(j,0,3){
				ll wh=(w+j)&1;
				ll val=a[wh][j];
				ld now=cur[j];
				ld p=1./val;
				if(j<2){
					cur[j+1]=(now+!wh)*p; // k=0
				}
				cerr<<w<<","<<j<<": "<<now<<" w,j\n";
				fore(k,1,val)dp[min(n,t+k)][wh^1]+=(now+!wh)*p;
			}
		}
	}
	ld res=dp[n][0]+dp[n][1];
	cout<<res<<"\n";
	return 0;
}
