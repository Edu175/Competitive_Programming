#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,v,n) for(ll i=v, edu=n; i<edu; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(i,1,n){
		if(a[i]<a[i-1]){
			res+=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	cout<<res;
	return 0;
}
