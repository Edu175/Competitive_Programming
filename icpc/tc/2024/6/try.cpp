#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define imp(v) {for(auto fdkhg:v)cout<<fdkhg<<" ";cout<<"\n";}
const ll P=1777771,PI=506001883681557571;
ull fpow(ull b, ull e){
	ull res=1;
	while(e){
		if(e&1)res=res*b;
		b=b*b,e>>=1;
	}
	return res;
}
const ull phi=1ll<<63;
int main(){
	cout<<P*PI<<"\n";
}