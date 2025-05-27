#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
const ll INF=2e17;
ll a[maxn], n;
ll agarro(ll k){
	ll cnt=0;
	fore(i,0,n){
		if(a[i]<=k){cnt++; k-=a[i];}
	}
	return cnt;
}
int main(){
	JET
	ll _; cin>>_; while(_--){
		ll m; cin>>n>>m;
		fore(i,0,n) cin>>a[i];
		ll l=0, r=INF; 
		while(l<=r){
			ll h=(l+r)/2;
			if(agarro(h)<=m) l=h+1;
			else r=h-1;
		}
		if(r<0 || agarro(r)!=m) {
			assert(n!=m);
			cout<<"Impossible\n"; continue;}
		if(r>=INF) {assert(n==m);
			cout<<"Richman\n"; continue;}
		assert(n!=m);
		cout<<r<<"\n";
	}
	return 0;
}
/*Implossible
2000000000000000000
Richman
2000000000000000000
Implossible
2000000000000000000
Implossible
2000000000000000000
*/

