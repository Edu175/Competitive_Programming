#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto dfh:v)cout<<dfh<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=4005,MAXK=805,INF=1e9;

ll n,k;
ll a[MAXN][MAXN],sp[MAXN][MAXN];

ll get(ll i0, ll j0, ll i1, ll j1){
	return sp[i1][j1]-sp[i1][j0]-sp[i0][j1]+sp[i0][j0];
}
ll cost(ll l, ll r){
	//if(l==r)return INF;
	return get(l,l,r,r)/2;
}
ll dp[MAXN][MAXK];
ll f(ll i, ll j, ll ki){
	if(ki>k)return INF;
	return cost(i,j+1)+dp[j+1][ki+1];
}
void dnc(ll l, ll r, ll s, ll e, ll ki){ //s,e start,end of search
	//cout<<ki<<": ["<<l<<","<<r<<") ["<<s<<","<<e<<"): ";
	ll m=(l+r)/2;
	ll opt=l;
	ll &res=dp[m][ki];
	fore(j,s,e)if(f(m,j,ki)<res){opt=j,res=f(m,j,ki);}
	//cout<<"("<<m<<"): "<<res<<" "<<opt<<"\n";
	if(r-l>1)dnc(l,m,s,opt+1,ki),dnc(m+1,r,opt,e,ki);
}
int main(){FIN;
	cin>>n>>k;
	char u[n][n];
	fore(i,0,n)fore(j,0,n)cin>>u[i][j];
	fore(i,0,n)fore(j,0,n)a[i][j]=u[i][j]-'0';
	fore(i,1,n+1)fore(j,1,n+1)sp[i][j]=a[i-1][j-1]+sp[i][j-1];
	fore(i,1,n+1)fore(j,1,n+1)sp[i][j]+=sp[i-1][j];
	fore(i,0,n+3)fore(j,0,k+3)dp[i][j]=INF;
	dp[n][k]=0;
	//fore(ki,0,k+1)dp[n][ki]=0; //suboptimal
	for(ll ki=k+1;ki>=0;ki--){
		dnc(0,n,0,n,ki);
		//cout<<"\n";
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}
