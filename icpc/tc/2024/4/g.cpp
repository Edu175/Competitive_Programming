#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll v; cin>>v;
	vector<ll>c(10);
	fore(i,1,10)cin>>c[i];
	ll b=c[1];
	fore(i,1,10)b=min(b,c[i]);
	string s;
	for(ll i=2e6+5;i>=0;i--){
		for(ll j=9;j>0;j--){
			if((v-c[j])/b>=i)s.pb('0'+j),v-=c[j];
		}
	}
	if(!SZ(s))cout<<"-1\n";
	else cout<<s<<"\n";
	return 0;
}