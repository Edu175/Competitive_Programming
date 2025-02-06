#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
int main(){
	JET
	ll n,k,q; cin>>n>>k>>q;
	vv p(n,-1);
	fore(i,1,n){
		cin>>p[i]; p[i]--;
	}
	while(q--){
		vv s(n);
		fore(i,0,n)cin>>s[i];
		fore(_,0,k){
			fore(i,0,n)if(s[i]){
				ll x=p[i];
				while(x!=-1){
					s[x]^=1;
					x=p[x];
				}
			}
		}
		cout<<s[0]<<"\n";
	}
	return 0;
}