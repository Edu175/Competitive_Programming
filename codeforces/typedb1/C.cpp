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
const ll MAXN=2e5+5;

ll n,s;
ll a[MAXN], ran[MAXN][2];
ll dp[MAXN][3];
ll f(ll i,ll b){
	ll &res=dp[i][b];
	if(res!=-1)return res;
	ll y=a[i-1]-ran[i-1][b];
	if(i==n-1)return res=a[n-1]*y;
	 res=min(y*ran[i][0]+f(i+1,0),y*ran[i][1]+f(i+1,1));
	//cout<<i<<" "<<b<<": "<<y<<": "<<ran[i][0]<<"="<<y*ran[i][0]+f(i+1,0)<<" "<<ran[i][1]<<"="<<y*ran[i][1]+f(i+1,1)<<": "<<res<<"\n";
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>s;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]>=2*s)ran[i][0]=s,ran[i][1]=a[i]-s;
			else ran[i][0]=max((ll)0,a[i]-s),ran[i][1]=min(a[i],s);
			fore(j,0,3)dp[i][j]=-1;
		}
		ran[0][0]=0,ran[0][1]=0;
		/*fore(i,0,n-1)cout<<ran[i][0]<<","<<ran[i][1]<<" ";
		cout<<"\n";*/
		cout<<f(1,0)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
