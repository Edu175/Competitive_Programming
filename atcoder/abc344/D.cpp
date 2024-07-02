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
const ll MAXN=105;

string t;
ll dp[MAXN][MAXN];
ll n;
ll a[MAXN];
vector<string> s[MAXN];

ll f(ll p, ll i){
	ll &res=dp[p][i];
	if(res!=-1)return res;
	if(p==SZ(t))return res=0;
	if(i==n)return res=MAXN;
	res=f(p,i+1);
	//cout<<p<<" "<<i<<endl;
	fore(j,0,a[i]){
		ll np=p+SZ(s[i][j]),flag=1;
		fore(k,0,SZ(s[i][j])){
			if(p+k>=SZ(t)||s[i][j][k]!=t[p+k])flag=0;
		}
		if(flag)res=min(res,1+f(np,i+1));
	}
	return res;
}

int main(){FIN;
	mset(dp,-1);
	cin>>t>>n;
	fore(i,0,n){
		cin>>a[i];
		s[i].resize(a[i]);
		fore(j,0,a[i])cin>>s[i][j];
	}
	/*fore(i,0,n){
		cout<<a[i]<<" "<<SZ(s[i])<<endl;
		fore(j,0,a[i])cout<<s[i][j]<<endl;
		cout<<endl;
	}*/
	ll res=f(0,0);
	if(res>=MAXN)res=-1;
	cout<<res<<"\n";
	return 0;
}
