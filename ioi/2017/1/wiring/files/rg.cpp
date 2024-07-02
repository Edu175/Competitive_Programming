#include "wiring.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define forr(i,a,b) for(ll i=b-1,ioi=a;i>=ioi;i--)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhg:v)cout<<dfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;


int main(){
	ll N,M,V; srand((ll)&N); cin>>N>>M>>V;
	ll n=rand()%N+1,m=rand()%M+1;
	cout<<n<<" "<<m<<"\n";
	ll s=0;
	vector<ll>h,a,b,per;
	fore(i,0,n+m)per.pb(i);
	// random_shuffle(ALL(per));
	fore(i,0,n+m){
		h.pb(s+=rand()%V+1);
	}
	fore(i,0,n)a.pb(h[per[i]]);
	fore(i,n,n+m)b.pb(h[per[i]]);
	sort(ALL(a));
	sort(ALL(b));
	imp(a);
	imp(b);
	return 0;
}