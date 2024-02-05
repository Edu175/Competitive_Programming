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
const ll MOD=998244353;


int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n){
		cin>>a[i];
		if(a[i]>0)a[i]--;
	}
	ll L[n][n];
	fore(v,0,n){
		if(a[0]==v||a[0]==-1)L[v][0]=-1;
		else L[v][0]=0;
		fore(i,1,n){
			if(a[i]==v||a[i]==-1)L[v][i]=L[v][i-1];
			else L[v][i]=i;
			L[v][i]=max(L[v][i],i-v-1);
		}
	}
	/*fore(i,0,n)fore(v,0,n){
		cout<<i<<" "<<v<<": "<<L[v][i]<<"\n";
	}*/
	ll dp[n][n],sp[n][n+1],col[n+1];
	fore(i,0,n)sp[i][0]=0;
	col[0]=1;
	fore(i,0,n){
		fore(v,0,n){
			ll l=L[v][i],r=i;
			//if(i==0)dp[i][v]=(l<0?1:0);
			dp[i][v]=(col[r]-(l<0?0:col[l])-(sp[v][r]-(l<0?0:sp[v][l]))+5*MOD)%MOD;
		}
		col[i+1]=col[i];
		fore(v,0,n){
			sp[v][i+1]=(sp[v][i]+dp[i][v])%MOD;
			col[i+1]=(col[i+1]+dp[i][v])%MOD;
		}
	}
	ll res=(col[n]-col[n-1]+MOD)%MOD;
	cout<<res<<"\n";
	return 0;
}
