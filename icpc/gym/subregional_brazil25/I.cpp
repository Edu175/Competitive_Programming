#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
int main(){
	JET
	ll n; cin>>n;
	ll d[n-1];
	ll xa,ya; cin>>xa>>ya;
	fore(i,0,n-1){
		ll x,y; cin>>x>>y;
		d[i]=abs(xa-x)+abs(ya-y);
		swap(xa,x); swap(ya,y);
	}
	ll l=1, r=d[0]-1;
	ll a=d[0];
	fore(i,1,n-1){
		a+=d[i]*(i&1?-1:1);
		if(i&1){
			l=max(a+1,l);
		}
		else r=min(r,a-1);
	}
	cout<<(l<=r?r:-1)<<"\n";
	return 0;
}