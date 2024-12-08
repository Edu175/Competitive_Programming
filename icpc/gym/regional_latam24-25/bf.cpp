#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
bool good(vv a){
	ll n=SZ(a);
	ll did=0,res=1;
	fore(i,0,n-1){
		did|=a[i]>a[i+1];
		if(did)res&=a[i]>a[i+1];
		else res&=a[i]<a[i+1];
		if(!res)return 0;
	}
	return res;
}

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv per(n); iota(ALL(per),1);
	ll did=0;
	do{
		ll flag=1;
		fore(i,0,n)if(a[i]&&per[i]!=a[i]){flag=0;break;}
		if(flag&&good(per)){
			did=1;
			imp(per);
			break;
		}
	}while(next_permutation(ALL(per)));
	if(!did)cout<<"*\n";
}