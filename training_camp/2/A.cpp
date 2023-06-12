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
vector<ll>a(105);
ll dp[105][305];
bool vis[105][305];

ll f(ll i, ll v){
	ll lnds;
	if(i!=-1){
		if(vis[i][v])return dp[i][v];
		vis[i][v]=1;
	}
	if(i==n)return dp[i][v]=0;
	fore(j,i+1,n){
		if(a[j]>=v)lnds=max(lnds,f(j,a[i])+1);
	}
	if(i!=-1)return dp[i][v]=lnds;
	else return lnds;
}

int main(){FIN;
	ll t; cin>>n>>t;
	vector<ll> b(n);
	ll c[301];
	mset(c,0);
	ll maxi=0;
	fore(i,0,n){
		cin>>a[i];
		b[i]=a[i];
		c[a[i]]++;
		maxi=max(maxi,a[i]);
	}
	/* 
	1 2 3 5 4 1 1 1 1 1 1 
	*/
	sort(ALL(a));
	if(t==1){
		cout<<f(-1,0);
	}
	else{
		if(a==b)cout<<(t-1)*c[maxi]+n;
		else cout<<(t-2)*c[maxi]+n;
	}
	fore(i,0,105){
		fore(j,0,305)vis[i][j]=0;
	}
	return 0;
}
