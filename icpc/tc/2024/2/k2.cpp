#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,m; cin>>n;
	ii a[n];
	ll b[n];
	fore(i,0,n){
		cin>>a[i].fst;
		b[i]=a[i].fst;
		a[i].snd=-i;
	}
	
	sort(a,a+n);
	reverse(a,a+n);
	cin>>m;
	fore(i,0,m){
		ll x,y; cin>>x>>y;
		ll aux[x];
		fore(i,0,x){
			aux[i]=-a[i].snd;
		}
		//cout<<aux[0];
		sort(aux,aux+x);
		cout<<b[aux[y-1]]<<"\n";
	}
}