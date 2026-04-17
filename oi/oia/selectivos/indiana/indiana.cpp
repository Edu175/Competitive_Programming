#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=2e3+5,INF=5*MAXN*MAXN;

ll a[MAXN][MAXN];
ll cost(ll x, ll y, ll fr, ll to){
	if(fr==to)return 2;
	if(fr==a[x][y])return 1;
	return 3;
}
ll n;
ll dp[MAXN][MAXN][2];

ll f(ll x, ll y, ll fr){
	return dp[x][y][fr];
}
int main(){
	ifstream cin;cin.open("indiana.in", ios::in);
	ofstream cout; cout.open("indiana.out", ios::out);
	mset(dp,-1);
	cin>>n;
	fore(i,0,n)fore(j,0,n){
		char c; cin>>c;
		a[i][j]=(c=='A');
	}
	for(ll x=n;x>=0;x--)for(ll y=n;y>=0;y--)fore(fr,0,2){
		ll &res=dp[x][y][fr];
		if(x==n-1&&y==n&&fr==1){res=0;continue;}
		if(x>=n||y>=n){res=INF;continue;}
		res=min(cost(x,y,fr,0)+f(x+1,y,0),cost(x,y,fr,1)+f(x,y+1,1));
	}
	cout<<f(0,0,1)<<"\n";
	return 0;
}
