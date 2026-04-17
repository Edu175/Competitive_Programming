#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
string tap="TAP";
int main(){
	JET
	string s; cin>>s;
	ll j=0;
	for(auto i:s){
		if(j<SZ(tap)&&tap[j]==i)j++;
	}
	if(j==3)cout<<"S\n";
	else cout<<"N\n";
	return 0;
}