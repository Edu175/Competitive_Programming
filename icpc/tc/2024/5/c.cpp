#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<vv>dpf(n+5,vv(m+5)),dpc(n+5,vv(m+5)),
	spf(n+5,vv(m+5)),spc(n+5,vv(m+5));
	vector<vv>cuanf(n+5,vv(m+5)),cuanc(n+5,vv(m+5));
	vector<vector<char>>a(n,vector<char>(m));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	if(n==1&&m==1){
		cout<<"1\n";
		return 0;
	}
	for(ll i=n-1;i>=0;i--)for(ll j=m-1;j>=0;j--){
		cuanf[i][j]=cuanf[i][j+1]+(a[i][j]=='R');
		cuanc[i][j]=cuanc[i+1][j]+(a[i][j]=='R');
	}
	for(ll i=n-1;i>=0;i--)for(ll j=m-1;j>=0;j--){
		if(i==n-1&&j==m-1){
			dpf[i][j]=dpc[i][j]=(a[i][j]=='.');
		}
		else {
			ll qf=cuanf[i][j]-(a[i][j]=='R');
			ll qc=cuanc[i][j]-(a[i][j]=='R');
			dpf[i][j]=sub(spf[i][j+1],spf[i][m-qf]);
			dpc[i][j]=sub(spc[i+1][j],spc[n-qc][j]);
		}
		spf[i][j]=add(spf[i][j+1],dpc[i][j]);
		spc[i][j]=add(spc[i+1][j],dpf[i][j]);
		
	}
	cout<<add(dpf[0][0],dpc[0][0])<<"\n";
	return 0;
}