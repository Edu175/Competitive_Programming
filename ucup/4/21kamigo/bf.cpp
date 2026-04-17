#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		ll did=0;
		iota(ALL(a),0);
		do{
			ll dif3=0;
			fore(i,0,n)fore(j,i+1,n)fore(k,j+1,n){
				if(a[i]<a[j]&&a[j]<a[k])dif3++;
				if(a[i]>a[j]&&a[j]>a[k])dif3--;
			}
			ll dif2_same=0;
			// ll dif2_opu=0;
			fore(i,0,n)fore(j,i+1,n){
				if(a[i]<a[j])dif2_same++;
				if(a[i]>a[j])dif2_same--;
				// ll ti=(a[i]>=n/2);
				// ll tj=(a[j]>=n/2);
				// if(ti==tj){
				// 	if(!ti&&a[i]<a[j])dif2_same++;
				// 	if(ti&&a[i]>a[j])dif2_same--;
				// }
				// else {
				// 	if(a[i]<a[j])dif2_opu++;
				// 	if(a[i]>a[j])dif2_opu--;
				// }
			}
			if(!dif3&&!dif2_same){
				for(auto i:a)cout<<i-2<<" ";;cout<<"\n";
				did=1;
				// break;
			}
		}while(next_permutation(ALL(a)));
		if(!did)cout<<"-1\n";
	}
	return 0;
}
