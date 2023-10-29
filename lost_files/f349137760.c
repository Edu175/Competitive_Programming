#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
	ll N,U; srand((ll)&N); cin>>N>>U;
	ll n=rand()%N+1,u=rand()%U+1,q=(u+1)*n;
	vector<ll>a;
	fore(i,0,n)a.pb(i);
	random_shuffle(ALL(a));
	imp(a);
	fore(i,0,n)cout<<"5 "<<i<<"\n";
	fore(i,0,u){
		ll t=rand()%4
		fore(j,0,n)cout<<"5 "<<j<<"\n";
	}
}
