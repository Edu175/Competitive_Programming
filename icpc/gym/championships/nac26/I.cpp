#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v){for(auto x:v)cout<<x<<" "; cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
    ll n; cin>>n;
	ll a=0,b=0,s=0;
	fore(i,0,n){
		ll x; cin>>x;
		x%=5;
		if(x>=3)x-=5;
		s+=x;
		if(x==-2)a++;
		if(x==-1)b++;
	}
	ll res=s;
	ll q=min(a,b);
	a-=q,b-=q;
	res+=5*q;
	res+=a/2*5;
	res+=b/3*5;
	cout<<res<<"\n";
	return 0;
}
