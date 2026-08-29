#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n; cin>>n;
	vector<vv> a(n,vv(n));
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	ll res=-1;
	fore(_,0,4){
		ll good=1;
		fore(i,0,n)fore(j,0,n){
			if(i)good&=a[i-1][j]<=a[i][j];
			if(j)good&=a[i][j-1]<=a[i][j];
		}
		if(good){
			res=_;
			break;
		}
		auto _a=a;
		fore(i,0,n)fore(j,0,n){
			a[n-1-j][i]=_a[i][j];
		}
	}
	assert(res!=-1);
	cout<<res<<"\n";
	return 0;
}