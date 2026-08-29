#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n){
		char c; cin>>c;
		a[i]=c-'0';
	}
	vv f(10);
	fore(i,1,10)cin>>f[i];
	ll p=n;
	fore(i,0,n)if(f[a[i]]>a[i]){p=i;break;}
	fore(i,p,n){
		if(f[a[i]]<a[i])break;
		a[i]=f[a[i]];
	}
	fore(i,0,n)cout<<a[i];;cout<<"\n";
	return 0;
}