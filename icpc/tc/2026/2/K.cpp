#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vv ocho,nocho;
	fore(i,0,n){
		char x; cin>>x;
		if(x == '8') ocho.pb(i);
		else nocho.pb(i);
	}
	reverse(ALL(ocho));
	reverse(ALL(nocho));
	ll t = 0;
	while(SZ(ocho) + SZ(nocho) > 11){
		if(!t){
			if(!SZ(ocho)){
				cout<<"NO\n";
				return 0;
			}
			ocho.pop_back();	
		}
		else{
			if(!SZ(nocho)){
				cout<<"YES\n";
				return 0;
			}
			nocho.pop_back();
		}
		t^=1;
	}
	if(!SZ(nocho)) cout<<"YES\n";
	else if(!SZ(ocho)) cout<<"NO\n";
	else cout<<(ocho.back() < nocho.back() ? "YES" : "NO")<<"\n";
	return 0;
}