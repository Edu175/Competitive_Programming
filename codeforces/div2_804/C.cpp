#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
ll MOD=1000000007;

ll factorial(ll x){
	ll res=1;
	fore(i,1,x+1)res=(res*i)%MOD;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		ll oc[2];
		fore(i,0,n){
			cin>>a[i];
			if(a[i]==0)oc[0]=i;
			if(a[i]==1)oc[1]=i;
		}
		if(n>1){
			ll l=n-1-a[0],r=n-1-a[n-1];
			if(l==0||a[0]<=1)l=1;
			if(r==0||a[n-1]<=1)r=1;
			cout<<factorial(abs(oc[1]-oc[0])-1)*l*r<<"\n";
		}
		else cout<<1<<"\n";
	}
	return 0;
}
