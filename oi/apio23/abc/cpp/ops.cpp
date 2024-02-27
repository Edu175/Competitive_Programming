#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,apio=b;i<apio;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto slkdh:v)cout<<slkdh<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll f(ll p, ll a, ll b){
	return (p/(1ll<<(a+2*b)))&1;
}
int main(){
	cout<<"p a b | r\n";
	fore(p,0,16)fore(a,0,2)fore(b,0,2){
		if(a+b==0)cout<<"\n";
		cout<<p<<(p<10?"  ":" ")<<a<<" "<<b<<" | "<<f(p,a,b)<<"\n";
	}
	return 0;
}
