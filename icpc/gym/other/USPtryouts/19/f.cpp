#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a;jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end();
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int main(){
	JET
	int n; cin>>n;
	ll a[n];
	fore(i,0,n) cin>>a[i];
	sort(a,a+n);
	ll u=0;
	fore(i,0,n){
		fore(j,u+1,a[i]) if(j<a[i]) {cout<<j<<"\n"; return 0}
		u+=a[i];
	}
	cout<<u+1<<"\n";
	return 0;
}