#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn=1005;
ll mod=1000000007;
char a[maxn][maxn];
ll h;
ll w;
ll dp[maxn][maxn];

ll f(ll x,ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==h-1&&y==w-1)return res=1;
	if(x==h||y==w)return res=0;
	if(a[x+1][y]=='#'){
		if(a[x][y+1]=='#')res=0;
		if(a[x][y+1]=='.')res=f(x,y+1);
	}
	if(a[x+1][y]=='.'){
		if(a[x][y+1]=='.'){
			res=(f(x+1,y)+f(x,y+1))%mod;
		}
		if(a[x][y+1]=='#')res=f(x+1,y);
	}
	return res;
}
int main(){FIN;
	cin>>h;
	ll sum=0;
	fore(t,0,2*h+1){
		w=t;
		fore(i,0,h){
			fore(j,0,w)/*cin>>a[i][j]*/a[i][j]='.';
			a[i][w]='#';
		}
		fore(i,0,w+1)a[h][i]='#';
		mset(dp,-1);
		cout<<f(0,0)<<"\n";
		sum+=f(0,0);
	}
	cout<<sum<<"\n";
	return 0;
}
