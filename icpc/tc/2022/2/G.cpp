#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
ll n;
ll a[101];
ll dp[101][301];
bool vis[101][301];
ll op;

ll f(ll i, ll v){
	op++;
	//ll lnds=0;
	//cout<<i<<" "<<v<<"\n";
	//if(vis[i][v])return dp[i][v];
	//vis[i][v]=1;
	ll nxt=lower_bound(a+i,a+n,v)-a;
	if(nxt==n)return dp[i][v]=0;
	else return dp[i][v]=max(f(nxt+1,a[nxt])+1,f(nxt+1,v));
}

int main(){FIN;
	ll t; cin>>n>>t;
	ll b[n];
	ll c[301];
	mset(c,0);
	ll maxi=0;
	fore(i,0,n){
		cin>>a[i];
		b[i]=a[i];
		c[a[i]]++;
		maxi=max(maxi,a[i]);
	}
	sort(b,b+n);
	if(t==1){
		ll lnis=0;
		fore(i,0,n)lnis=max(lnis,f(i+1,a[i])+1);
		cout<<lnis;//<<" "<<op;
	}
	else{
		ll flag=1;
		fore(i,0,n)if(a[i]!=b[i])flag=0;
		if(flag)cout<<(t-1)*c[maxi]+n;
		else cout<<(t-2)*c[maxi]+n;
	}
	/*fore(i,0,105){
		fore(j,0,305)vis[i][j]=0;
	}*/
	return 0;
}
