#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
int main(){
	JET
	ll n,q; cin>>n>>q;
	vv a(n),c(n);
	fore(i,0,n)cin>>a[i]>>c[i];
	while(q--){
		ll d; cin>>d;
		ll res=-1;
		fore(i,0,n)fore(j,0,n){
			ll x=a[i],y=a[j];
			if(c[i]!=c[j]&&x+d==y){
				if(res==-1||i<res)res=i;
			}
		}
		cout<<res+1<<"\n";
	}
	
	return 0;
}