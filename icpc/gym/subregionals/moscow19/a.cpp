#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
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
	ll n,a,b; cin>>n>>a>>b;
	ll q=0;
	ll pot=1;
	while(!(b/a<pot))q++,pot*=2;
	if(q>n)cout<<"-1\n";
	else cout<<q<<"\n";
    return 0;
}