#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
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
const ll INF=1e18;
vector<vv> a;
vv ans;

void f(ll i, ll k, ll cost){
	if(i==SZ(a)){
		ans[k]=min(ans[k],cost);
		return;
	}
	fore(j,0,4){
		f(i+1,k+j,cost+a[i][j]);
	}
}

int main(){
	JET
	ll n; cin>>n;
	a=vector<vv>(n,vv(4));
	fore(i,0,n)fore(j,1,4)cin>>a[i][j];
	ans.resize(3*n+1,INF);
	f(0,0,0);
	fore(k,1,3*n+1)cout<<ans[k]<<"\n";
	return 0;
}