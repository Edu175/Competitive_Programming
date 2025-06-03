#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll sig(ll n, ll *a){ // devuelve 0 o 1, a tiene que ser una permutacion de 0,1 ... n-1
	vv vis(n);
	ll c=0;
	fore(x,0,n)if(!vis[x]){
		c++;
		for(ll y=x;!vis[y];y=a[y])vis[y]=1;
	}
	return (n-c)&1;
}
void res(ll d){
	cout<<(d&1?"A":"B");
}
int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n; cin>>n;
		ll a[n],b[n];
		fore(i,0,n){ cin>>a[i]; a[i]--;}
		fore(i,0,n) {cin>>b[i];b[i]--;}
		ll d=sig(n,a)+sig(n,b);
		
		res(d);
		fore(i,0,n-1){
			ll l,r,d2; char trash;
			cin>>trash>>l>>r>>d2;
			d+=(r-l+1-gcd(r-l+1,d2));
			res(d);
		}
		cout<<"\n";
	}
	return 0;
}
/*BAA
ABA
AAB
AAB
ABBBABBBAB
*/
