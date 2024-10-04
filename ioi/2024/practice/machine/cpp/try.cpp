#include "machine.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll B=8;
ll find(ll n){
	vector<ll>s(B);
	ll m=n+2;
	fore(i,0,m)fore(j,0,B)s[j]+=i>>j&1;
	vector<ll>us;
	fore(i,0,m)fore(j,i+1,m){
		auto c=s;
		auto erase=[&](ll v){
			fore(j,0,B)c[j]-=v>>j&1;
		};
		erase(i);
		erase(j);
		// erase(k);
		ll flag=1;
		fore(i,0,B){
			flag&=c[i]!=n-c[i];
		}
		if(flag)return 1;
	}
	return 0;
}
int main(){
	ll N; cin>>N;
	fore(n,3,N+1)if(!find(n))cout<<n<<" :(\n";
}
