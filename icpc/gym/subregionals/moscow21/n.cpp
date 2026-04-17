#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll a[6];
	fore(i,0,6) cin>>a[i]; 
	ll ac = a[0]*a[2];
	ll bd = a[1]*a[3];
	ll cb = a[1]*a[2];
	// cout<<ac<<" "<<bd<<" "<<cb<<"\n";
	if(ac+cb<=bd || ac+bd<=cb || cb+bd<=ac){
		cout<<-1<<"\n";
		return 0;
	}
	(ac*a[4]==bd*a[5]) ? cout<<1<<"\n" : cout<<-1<<"\n";
}