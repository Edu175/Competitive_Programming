#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005,INF=MAXN*MAXN*2;

ll dp[MAXN][MAXN];
vector<ii>dir={{0,-1},{-1,-1},{1,-1}};
char a[MAXN][MAXN];

int main(){FIN;
	ll n,m; cin>>m>>n;
	ii s;
	fore(i,0,n)fore(j,0,m){
		cin>>a[i][j];
		if(a[i][j]=='A')s={i,j};
	}
	fore(i,0,n)dp[i][0]=-1;
	dp[s.fst][s.snd]=0;
	fore(j,1,m)fore(i,0,n){
		ll &res=dp[i][j];
		for(auto d:dir){
			ll i1=i+d.fst,j1=j+d.snd;
			if(i1<0||i1>=n)continue;
			res=max(res,dp[i1][j1]);
		}
		if(res==-1)continue;
		if(a[i][j]=='M'){
			if(!res)res=-1;
			else res=0;
		}
		if(a[i][j]=='J')res++;
	}
	return 0;
}
