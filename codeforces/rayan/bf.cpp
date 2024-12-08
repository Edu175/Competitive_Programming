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
bool good(vector<vv>&a){
	set<ll>st;
	ll n=SZ(a[0]),k=SZ(a);
	fore(i,0,n){
		ll sum=0;
		fore(j,0,k)sum+=a[j][i];
		st.insert(sum);
	}
	return SZ(st)==1;
}
int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<vv> all;
	vv per(n); iota(ALL(per),0);
	do{
		all.pb(per);
	}while(next_permutation(ALL(per)));
	per=vv(k,1);
	per.resize(SZ(all),0);
	sort(ALL(per));
	do{
		vector<vv>a;
		fore(i,0,SZ(all))if(per[i])a.pb(all[i]);
		if(good(a)){
			for(auto i:a)imp(i);
			cout<<endl;
		}
	}while(next_permutation(ALL(per)));
	// assert(k==3);
	// fore(i,0,SZ(all))fore(j,i+1,SZ(all)){
	// 	// fore(k,j+1,SZ(all)){
	// 	vector<vv>a;
	// 	a.pb(all[i]);
	// 	a.pb(all[j]);
	// 	// a.pb(all[k]);
	// 	// for(auto i:a)imp(i);
	// 	// 	cout<<endl;
	// 	set<ll>st;
	// 	// cout<<k<<endl;
	// 	// cout<<SZ(a)<<endl;
	// 	// cout<<a.size()<<endl;
		
	// 	// for(auto i:a)imp(i);
	// 	// 	cout<<endl;
	// 	// assert(SZ(a)==k);
		
	// }
	return 0;
}
