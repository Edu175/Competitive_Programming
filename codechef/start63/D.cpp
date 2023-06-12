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
const ll MAXN=3e5+5;

ll a[MAXN],w[MAXN];
ll dp[MAXN];
ll n;

ll f(ll i){
	ll &res=dp[i];
	if(res>=0)return res;
	if(i>=n)return res=0;
	res=(a[i]==1?-1:1)*w[i];
	return res+=max(f(i+1),ll(0));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		n=SZ(s);
		fore(i,0,n+3)dp[i]=-1;
		fore(i,0,n)a[i]=s[i]-'0',w[i]=(i+1)*(n-i);
		ll res=0;
		fore(i,0,n)res+=a[i]*w[i];
		ll maxi=0;
		fore(i,0,n)maxi=max(maxi,f(i));//,cout<<f(i)<<" ";
		//cout<<"\n";
		cout<<res+maxi<<"\n";
		fore(i,0,n+3)a[i]=0,w[i]=0;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
