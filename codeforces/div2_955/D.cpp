#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=505;
ll sp[MAXN][MAXN];
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		ll a[n][m];
		char b[n][m];
		fore(i,0,n)fore(j,0,m)cin>>a[i][j];
		fore(i,0,n)fore(j,0,m)cin>>b[i][j];
		// ll sp[n+1][n+1]; mset(sp,0);
		fore(i,0,n+1)fore(j,0,m+1)sp[i][j]=0;
		fore(i,1,n+1)fore(j,1,m+1)sp[i][j]=b[i-1][j-1]-'0'+sp[i][j-1];
		fore(i,1,n+1)fore(j,1,m+1)sp[i][j]+=sp[i-1][j];
		auto get=[&](ll i, ll j){
			return sp[i+k][j+k]-sp[i][j+k]-sp[i+k][j]+sp[i][j];
		};
		ll dif=0;
		fore(i,0,n)fore(j,0,m){
			if(b[i][j]=='1')dif+=a[i][j];
			else dif-=a[i][j];
		}
		dif=abs(dif);
		ll g=0;
		fore(i,0,n-k+1)fore(j,0,m-k+1){
			ll c=get(i,j);
			ll c2=k*k-c;
			ll d=abs(c-c2);
			g=gcd(g,d);
			// cout<<i<<","<<j<<": "<<d<<"\n";
		}
		// cout<<g<<" "<<dif<<"\n";
		if(dif%(g?g:dif+1)==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
