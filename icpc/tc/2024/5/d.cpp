#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	int t; cin>>t;
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll s=a+b+c;
		ll m=min(a,min(b,c));
		if(s%9!=0 || s/9>m){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
	return 0;
}


/*


3
3 2 4
1  1 1
10 1 7
NO
YES
NO

*/