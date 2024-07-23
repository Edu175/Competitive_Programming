#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll a,b,c;
	cin>>a>>b>>c;
	ll m=min(a,min(b,c));
	a-=m,b-=m,c-=m;
	if(b==0) swap(b,c);
	if(a==0) swap(a,c);
	if(a==b) {cout<<max(a-1,0ll)<<"\n"; return 0;}
	else cout<<max(2*max(a,b)-min(a,b)-2,0ll)<<"\n";
	return 0;
}