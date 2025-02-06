#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;
int main(){
	ll n; cin>>n;
	ll k; cin>>k;
	ll a[n]; fore(i,0,n) cin>>a[i];
	ll mk=0;
	ii mi[n-1]; fore(i,0,n-1) mi[i]={INF,INF};
	while(mk<(1<<(n-1))){
		ll tot=a[0], s=a[0], c=1;
		fore(i,1,n){
			if(mk&(1<<(i-1))){
				tot+=a[i];
				s=a[i];
				c=1;
			}
			else{
				tot-=s*c;
				s+=a[i]; c++;
				tot+=s*c;
			}
			assert(tot>=0);
		}
		mi[__builtin_popcountll(mk)]=min(mi[__builtin_popcountll(mk)],{tot,mk});
		mk++;
	}
	cout<<mi[k].fst<<"\n";
	ll j=mi[k].snd;
	while(j){
		cout<<(j&1);
		j>>=1;
	}
}