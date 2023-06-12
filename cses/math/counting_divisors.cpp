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
//Hay que hacer criba si o si
ll cdiv(ll x){
	ll ret=1;
	for(int i=2;i*i<=x;i++){
		ll e=1;
		while(x%i==0)x/=i,e++;
		ret*=e;
	}
	if(x>1)ret*=2;
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		ll x; cin>>x;
		cout<<cdiv(x)<<" ";
	}
	return 0;
}
