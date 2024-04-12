#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define forr(i,a,b) for(ll i=b-1,ggdem=a;i>=ggdem;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll MAXN=82,INF=MAXN*2*(1e9+5);
ll n;
ll a[MAXN][MAXN];
ll R[MAXN][MAXN],D[MAXN][MAXN];
ll dp1[MAXN][MAXN][MAXN][MAXN];

set<ii>p;
vector<ii>cas[MAXN*2];
ll s;
ll SA(){
	
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	fore(i,0,n)fore(j,0,n-1)cin>>R[i][j];
	fore(i,0,n-1)fore(j,0,n)cin>>D[i][j];
	forr(Di,0,n)forr(Dj,0,n)forr(i,0,n+1)forr(j,0,n+1){
		ll &res=dp1[i][j][Di][Dj];
		if(i>=n||j>=n)res=INF;
		else if(i==Di&&j==Dj)res=0;
		else {
			res=min(D[i][j]+dp1[i+1][j][Di][Dj],R[i][j]+dp1[i][j+1][Di][Dj]);
		}
	}
	fore(i,0,n)fore(j,0,n)cas[i+j].pb({i,j});
	res+=2*(n-1);
	cout<<res<<"\n";
	return 0;
}
