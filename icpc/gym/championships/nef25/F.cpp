#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size()) 
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET 
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll dos=0,uno=0;
		fore(i,0,n){
			if(a[i]>1)dos++;
			else uno++;
		}
		ll w=0;
		if(!dos)w=!(uno&1);
		else w=uno&1;
		if(!w)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
    return 0;
}
