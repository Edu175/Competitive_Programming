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

vector<ll> fse(vector<ll>&a){ //index of first smaller element to the left (-1 if none)
//for bigger change for condition, for right reverse a, then f, and indexes (n-1-x)
	ll n=SZ(a);
	vector<ll>f(n,-1);
	fore(i,0,n){
		ll x=i-1;
		for(;x!=-1&&!(a[x]<a[i]);x=f[x],f[i]=x);
		f[i]=x;
	}
	return f;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>s(n+1);
		fore(i,1,n+1)s[i]=s[i-1]+a[i-1];
		reverse(ALL(s));
		vector<ll>to=fse(s);
		reverse(ALL(s)); reverse(ALL(to));
		for(auto &i:to)i=SZ(s)-1-i;
		//imp(s);
		//imp(to);
		ll dp[n+5];
		ll x=n+1;
		dp[n+1]=0;
		for(ll i=n;i>=0;i--){
			dp[i]=0;
			if(to[i]<=n)dp[i]=s[i]-s[to[i]]+dp[to[i]];
			if(dp[i]>=dp[x])x=i;
			//cout<<i<<": "<<to[i]<<" "<<dp[i]<<endl;
		}
		//cout<<x<<"\n";
		cout<<s[x]<<"\n";
	}
	return 0;
}
