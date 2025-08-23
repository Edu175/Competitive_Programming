#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e6+5;
#define mkmx(a,b) a=max(a,b);

int main(){
	JET
	ll n; cin>>n;
	vv a(n),b(n);
	ll tot=0;
	fore(i,0,n)cin>>b[i]>>a[i],tot+=a[i];
	ll mxc=200*n+5;
	vector<vv> now(n+1,vv(mxc,-INF)),prox=now;
	now[0][0]=0;
	fore(i,0,n){
		prox=now;
		fore(k,0,n+1)fore(d,0,mxc){
			auto &res=now[k][d];
			if(k+1<=n&&d+2*b[i]-a[i]<mxc){
				mkmx(prox[k+1][d+2*b[i]-a[i]],res+a[i]);
			}
		}
		swap(prox,now);
	}
	vv ans(n+1);
	fore(k,0,n+1)fore(d,0,mxc){
		mkmx(ans[k],now[k][d]+min(tot,d));
	}
	fore(i,1,n+1){
		cout<<fixed<<setprecision(4)<<double(ans[i])/2.0<<" ";
	}
	cout<<"\n";
	return 0;
}