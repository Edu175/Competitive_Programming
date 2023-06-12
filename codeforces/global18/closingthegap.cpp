#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int sumOfArray(ll arr[], ll n) {

    ll s = 0;
    for (int i = 0; i < n; i++) {
        s = s + arr[i];
    }
    return s;
}

int main(){FIN;
	ll t; cin>>t;
	fore(i,0,t){
		ll n; cin>>n; ll a[n];
		fore(i,0,n){
			cin>>a[i];
		}
		if(sumOfArray(a,n)/n*n==sumOfArray(a,n)){
			cout<<0<<"\n";
		}else{
			cout<<1<<"\n";
		}
	}
	 return 0;
}
