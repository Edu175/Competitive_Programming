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
ii dp2[MAXN][MAXN];
string cv(ii i){return to_string(i.fst)+","+to_string(i.snd);}
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
	fore(i,0,n)fore(j,0,n){
		ii &res=dp2[i][j];
		if(i==0&&j==0){res={0,0};continue;}
		res={INF,5};
		fore(ni,0,i+1)fore(nj,0,j+1)if(i!=ni||j!=nj){
			ll s=dp2[ni][nj].snd,c=dp1[ni][nj][i][j];
			ii resi={dp2[ni][nj].fst,0};
			if(s>=c)resi.snd=s-c;
			else {
				c-=s;
				ll m=a[ni][nj];
				resi.fst+=(c+m-1)/m;
				resi.snd=(m-c%m)%m;
			}
			resi.snd*=-1;
			res=min(res,resi);
		}
		res.snd*=-1;
		//cout<<i<<","<<j<<": "<<cv(dp2[i][j])<<"\n";
	}
	ll res=dp2[n-1][n-1].fst;
	res+=2*(n-1);
	cout<<res<<"\n";
	return 0;
}
