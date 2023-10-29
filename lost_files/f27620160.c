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
const ll MAXN=1005;

ii dp[MAXN][MAXN]; // {sin M, con M}
vector<ii>dir={{0,1},{1,1},{-1,1}};
char a[MAXN][MAXN];

ii f(ll i, ll j){
	ll &res=dp[i][j];
	if(res!=-1)return res;
	if(j==n)return res={0,0};
	fore(d,0,SZ(dir)){
		ll i1=i+dir[d].fst,j1=j+dir[d].snd;
		if(i1<0||i1>=n)continue;
		if(a[i1][j1]=='M')
	}
}

int main(){FIN;
	ll n,m; cin>>m>>n;
	ii s;
	fore(i,0,n)fore(j,0,m){
		cin>>a[i][j];
		if(a[i][j]=='A')s={i,j};
	}
	
	return 0;
}
