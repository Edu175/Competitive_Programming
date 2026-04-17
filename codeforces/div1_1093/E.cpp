#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define see(v) {for(auto i:v)cout<<(i?"▮":" "); cout<<"\n";}
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vector<ll>> mat;

ll red(ll a){return (a%3+3)%3;}

const ll MAXN=5005;
ll a[MAXN][MAXN];
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)fore(j,0,n)a[i][j]=0;
		ll h=n/2;
		fore(i,0,n)a[i][n-1-i]=1;
		fore(i,h,n)fore(j,h,n)if(red(i-j)!=2)a[i][j]=1;
		forr(i,0,h)fore(j,1,n)a[i][j]=a[i][j-1]^a[i+1][j-1];
		fore(i,1,n)forr(j,0,h)a[i][j]=a[i-1][j]^a[i-1][j+1];
		// ll c=0; fore(i,0,n)fore(j,0,n)c+=a[i][j];
		// ll bound=n*n/10*3;
		// cerr<<"cant  "<<c<<"\n";
		// cerr<<"bound "<<bound<<"\n";
		fore(i,0,n){
			fore(j,0,n)cout<<a[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
