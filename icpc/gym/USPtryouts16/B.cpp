#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define imp(v) for(auto messi:v) cout << messi << " ";cout << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;

int main(){FIN;
	ll n; cin>>n;
	ll dp[2][n+5][n+5][n+5][n+5];
	mset(dp,0);
	dp[1][0][1][1][1]=1;
	ll ans=1;
	fore(i,1,n+1)ans=ans*i%MOD;
	
	fore(m,2,n+1){
		vector<ll>a(4);
		a[0]=0;
		for(a[1]=min((ll)1,m);a[1]<=m;a[1]++)
		for(a[2]=min(a[1]+1,m);a[2]<=m;a[2]++)
		for(a[3]=min(a[2]+1,m);a[3]<=m;a[3]++){
			ll &res=dp[m%2][a[0]][a[1]][a[2]][a[3]];
			res=0;
			cout<<"\n"<<m<<": "; imp(a);
			fore(i,0,4){
				vector<ll>ai=a;
				fore(j,i+1,4)ai[j]--;
				fore(j,a[i],(i==3?m:ai[i+1])){
					ai[i]=j;
					res+=dp[(m+1)%2][ai[0]][ai[1]][ai[2]][ai[3]];
					imp(ai);
				}
				if(a[i]==m)break;
			}
			if(m==n&&a[0]!=m&&a[1]!=m&&a[2]!=m)ans=(ans-res+MOD)%MOD;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
