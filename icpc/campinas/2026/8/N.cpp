#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef double ld;

const ll MAXN=103;

ld dp[2][MAXN+2][MAXN+2][MAXN+2];
ld sum[MAXN][MAXN][MAXN];

int main(){
	JET
	dp[0][0][0][0]=1;
	fore(bl,0,MAXN)fore(ne,0,MAXN)fore(x,0,MAXN)fore(u,0,MAXN){
		auto &now=dp[bl&1][ne][x][u];
		if(!now)continue;
		dp[(bl+1)&1][ne][x+1+(u==x+1)][u]+=now*(bl+1)/(bl+1+ne);
		dp[bl&1][ne+1][x==0][x]+=now*(ne+1)/(bl+ne+1);
		sum[bl][ne][x]+=now;
		now=0;
	}
	
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll m=MAXN*2;
		vector<ld> cur(m); cur[0]=1;
		fore(i,0,n){
			vector<ld> prox(m);
			fore(x,0,MAXN){
				ld coef=sum[b[i]][a[i]][x];
				if(!coef)continue;
				fore(y,0,m)if(cur[y])prox[x^y]+=cur[y]*coef;
			}
			swap(cur,prox);
		}
		ld res=accumulate(cur.begin()+1,cur.end(),0.l);
		cout<<fixed<<setprecision(6)<<res<<"\n";
	}
	return 0;
}