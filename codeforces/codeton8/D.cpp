#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e3+5;
ll a[MAXN][MAXN];


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n)fore(j,i,n)cin>>a[i][j];
		vector<ll> dp[n+5][2];
		fore(i,0,2)dp[n][i]={0};
		for(ll i=n-1;i>=0;i--)fore(b,0,2){
			priority_queue<ii>pq;
			vector<ll>p(n+5);
			fore(j,i+1,n+1)
				if(p[j]<SZ(dp[j][b^1]))
					pq.push({dp[j][b^1][p[j]]+b*a[i][j-1],j});
			auto &res=dp[i][b];
			while(SZ(pq)&&SZ(res)<k){
				auto [c,j]=pq.top(); pq.pop();
				res.pb(c);
				p[j]++;
				if(p[j]<SZ(dp[j][b^1]))
					pq.push({dp[j][b^1][p[j]]+b*a[i][j-1],j});
			}
		}
		vector<ll>best=dp[0][0];
		for(auto i:dp[0][1])best.pb(i);
		sort(ALL(best)); reverse(ALL(best));
		fore(i,0,k)cout<<best[i]<<" ";;cout<<"\n";
	}
	return 0;
}
