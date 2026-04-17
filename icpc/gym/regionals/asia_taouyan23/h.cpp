#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vv v;
vv w;
ll dp[105][1005];
int n;
ll C;

ll f(ll i, ll c){
	if(i==n) return 0;
	ll &rta=dp[i][c];
	if(rta!=-1) return rta;
	rta=f(i+1,c); 
	if(c-w[i]>=0) rta=max(rta,f(i+1,c-w[i])+v[i]);
	return rta;
}

int main(){
	JET
	mset(dp,-1);
	cin>>C;
	vv a;
	ll x;
	while(cin>>x){
		a.pb(x);
	}
	if(SZ(a)%2==1)a.pb(x);
	fore(i,0,SZ(a)){
		if(i<SZ(a)/2) v.pb(a[i]);
		else w.pb(a[i]);
	}
	n=SZ(v);
	cout<<f(0,C)<<"\n";
	return 0;
}