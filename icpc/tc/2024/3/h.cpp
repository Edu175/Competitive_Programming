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
bool ask(ll a, ll b){
	cout<<"? "<<a<<" "<<b<<endl;
	char ret; cin>>ret;
	if(ret=='e')exit(0);
	return ret=='x';
}
int main(){
	JET
	while(1){
		string s; cin>>s;
		if(s!="start")break;
		ll n=1ll;
		while(true){
			if(!ask(n,2*n)){
				n=2*n+1;
			}
			else break;
		}
		ll l=n-1, r=2*n;
		while(r-l>1){
			ll h=(l+r)/2;
			if(ask(l,h)){
				r=h;
			}
			else l=h;
		}
		if(ask(0,r))cout<<"! "<<r<<endl;
		else cout<<"! "<<l<<endl;
	}
	return 0;
}