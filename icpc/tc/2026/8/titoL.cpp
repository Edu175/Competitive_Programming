#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;

struct per{
	ld L,R;
	ld P(ld x){
		return max(min((x-L)/(R-L),1.L),0.L);
	}
};
int main(){
	JET
	ll n; cin>>n;
	per P[n];
	fore(i,0,n) cin>>P[i].L>>P[i].R;
	ld rt=0.L;
	fore(i,1,10001){
		ld parc=0.L;
		fore(mk,0,1<<n){
			ld aux=1.L;
			fore(i,0,n){
				if(mk&1){
					aux*=P[i].P(i)-P[i].P(i-1);
				}
			}
		}
	}
	return 0;
}