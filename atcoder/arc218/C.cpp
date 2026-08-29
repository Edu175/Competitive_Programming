#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	// FIN;
	ll n; cin>>n;
	ll m=2;
	vector<vv> pers(2,vv(n));
	fore(i,0,n)pers[0][i]=(i-1+n)%n;
	fore(i,0,n)pers[1][i]=i;
	swap(pers[1][0],pers[1][1]);
	cout<<m<<endl;
	fore(i,0,m){
		fore(j,0,n)cout<<pers[i][j]+1<<" ";
		cout<<endl;
	}
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> ops;
	fore(_,0,n){
		fore(i,0,n){
			if(i+1<n&&a[i]>a[i+1]){
				swap(a[i],a[i+1]);
				ops.pb(1);
			}
			ops.pb(0);
		}
	}
	reverse(ALL(ops));
	cout<<SZ(ops)<<" ";
	for(auto i:ops){
		cout<<i+1<<" ";
	}
	cout<<endl;
	return 0;
}
