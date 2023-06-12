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
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		if(b>a)swap(a,b);
		ll d=a-b;
		a-=d*2;
		b-=d;
		if((a>=0&&b>=0)&&(a%3==0&&b%3==0))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
