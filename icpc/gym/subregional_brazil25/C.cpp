#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n; n++;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	// while(!a.back())a.pop_back();
	// reverse(ALL(a)); // back es c
	ll res=0;
	while(1){
		// for(auto i:a)cout<<i<<" ";;cout<<"\n";
		while(SZ(a)&&!a.back())a.pop_back(),res++;
		if(SZ(a)==1){
			assert(a[0]==1);
			break;
		}
		vv c(SZ(a)+1);
		fore(i,0,SZ(a)){
			c[i+1]^=a[i];
			c[i]^=a[i];
		}
		c.pop_back();
		res+=2;
		swap(a,c);
	}
	cout<<res<<"\n";
	return 0;
}