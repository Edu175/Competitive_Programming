#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
	ll n,x,y; cin>>n>>x>>y;
	int a[x];
	fore(i,0,x) cin>>a[i];
	fore(i,0,y){
		int z; cin>>z;
		n+=z;
	}
	ll rta=y;
	fore(i,0,x){
		n-=a[i];
		if(n>=0) rta++;
		else break;
	}
	cout<<rta<<"\n";
	return 0;
}