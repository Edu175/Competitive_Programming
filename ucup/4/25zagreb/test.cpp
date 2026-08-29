#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n=23;
	ll res=0;
	fore(mk,0,1ll<<n){
		vv a(n);
		fore(i,0,n)a[i]=mk>>i&1;
		ll cur=(a[0]+1)*(a[n-1]+1);
		fore(i,0,n-1)if(a[i]&&a[i+1])cur*=2;
		res+=cur;
	}
	cout<<res<<"\n";
	return 0;
}