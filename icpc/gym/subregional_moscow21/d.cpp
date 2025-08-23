#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n; cin>>n;
	vv a[n];
	ll mn=0;
	fore(i,0,n){
		ll m; cin>>m;
		a[i].resize(m);
		fore(j,0,m)cin>>a[i][j];
		if(m<SZ(a[mn]))mn=i;
	}
	rotate(a,a+mn,a+n);
	// fore(i,0,n){
	// 	fore(j,0,SZ(a[i]))cout<<a[i][j]<<" ";
	// 	cout<<"\n";
	// }
	set<ll>ban;
	vv ap(n);
	ap[0]=a[0][0];
	fore(i,1,SZ(a[0]))ban.insert(a[0][i]);
	fore(i,1,n){
		if(count(ALL(a[i]),ap[i-1]))ap[i]=ap[i-1];
		else {
			ap[i]=-1;
			for(auto j:a[i])if(!ban.count(j))ap[i]=j;
			assert(ap[i]!=-1);
		}
	}
	// for(auto i:ap)cout<<i<<" ";;cout<<"\n";
	// cout<<mn<<"\n";
	rotate(ap.begin(),ap.begin()+n-mn,ap.begin()+n);
	for(auto i:ap)cout<<i<<" ";;cout<<"\n";
}