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
const ll MAXN=3e5+5;

string s,l,r;
ll n,m;

ll dp[MAXN][12];
ll go[MAXN][12];
ll f(ll i, ll j){
	ll &res=dp[i][j];
	if(res!=-1)return res;
	if(i==n+1)return res=1;
	if(j==m)return res=0;
	res=0;
	fore(k,l[j]-'0',r[j]-'0'+1){
		res=max(res,f(go[i][k]+1,j+1));
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>s;
		n=SZ(s);
		cin>>m>>l>>r;
		fore(i,0,n+3)fore(j,0,m+1)dp[i][j]=-1;
		fore(i,0,10)go[n][i]=n;
		for(ll i=n-1;i>=0;i--){
			fore(j,0,10)go[i][j]=go[i+1][j];
			go[i][s[i]-'0']=i;
		}
		if(f(0,0))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
