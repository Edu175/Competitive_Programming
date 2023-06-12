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

ll factor2(ll x){
	ll res=0;
	while(x%2==0){
		res++;
		x/=2;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		ll ev=0;
		ll logi=10e9;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]%2==0)ev++;
			logi=min(logi,factor2(a[i]));//(ll(log(a[i])/log(2)))
		}
		if(ev<n)cout<<ev<<"\n";
		else cout<<logi+ev-1<<"\n";
	}
	return 0;
}
