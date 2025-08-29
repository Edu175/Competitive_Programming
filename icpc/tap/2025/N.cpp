#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n; cin>>n;
	vv mx(2,-1),mn(2,1e9);
	fore(i,0,n)fore(j,0,2){
		ll x; cin>>x;
		mn[j]=min(mn[j],x);
		mx[j]=max(mx[j],x);
	}
	ll res=0;
	fore(j,0,2){
		ll d=mx[j]-mn[j]+2;
		res+=2*d;
	}
	cout<<res<<"\n";
	return 0;
}