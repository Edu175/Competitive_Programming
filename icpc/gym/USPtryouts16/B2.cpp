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
const ll MOD=1e9+7,MAXN=65;

ll dp[MAXN][MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN][MAXN];
ll n,ans=1;
void bfs(pair<ll,vi>s){
	queue<pair<ll,vi>>q;
	q.push(s);
	while(SZ(q)){
		auto [m,a]=q.front(); q.pop();
		ll &res=dp[m][a[1]][a[2]][a[3]];
		//cout<<"\n"<<m<<", "; imp(a); cout<<res<<":\n";
		if(m==n){
			if(a[0]!=m&&a[1]!=m&&a[2]!=m)ans=(ans-res+MOD)%MOD;
			//cout<<-res<<"---\n";
			continue;
		}
		
		fore(x,0,m+1){
			ll j=lower_bound(ALL(a),x)-a.begin();
			if(j>=SZ(a))continue;
			vector<ll>ai=a;
			ai[j]=x;
			fore(i,j+1,SZ(ai))ai[i]++;
			dp[m+1][ai[1]][ai[2]][ai[3]]=(dp[m+1][ai[1]][ai[2]][ai[3]]+res)%MOD;
			//cout<<m+1<<", "; imp(ai);
			if(!vis[m+1][ai[1]][ai[2]][ai[3]]){
				q.push({m+1,ai});
				vis[m+1][ai[1]][ai[2]][ai[3]]=1;
			}
		}
		
	}
}

int main(){FIN;
	cin>>n;
	dp[1][1][1][1]=1;
	fore(i,1,n+1)ans=ans*i%MOD;
	bfs({1,{0,1,1,1}});
	cout<<ans<<"\n";
	return 0;
}
