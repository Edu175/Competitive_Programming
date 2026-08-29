#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JET
	ll n,k; cin>>n>>k;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll res=-1;
	fore(i,0,n){
		ll c=i+1;
		if(k<=c){res=a[k-1];break;}
		k-=c;
	}
	cout<<res<<"\n";
    return 0;
}
