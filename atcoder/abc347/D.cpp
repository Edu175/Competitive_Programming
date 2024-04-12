#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll B=60;

ll ppc(ll x){return __builtin_popcountll(x);}
vector<ll> cv(ll x){
	vector<ll>ret;
	fore(i,0,B)ret.pb(x%2),x/=2;
	return ret;
}
ll cv(vector<ll>a){
	ll x=0;
	fore(i,0,B)x|=a[i]<<i;
	return x;
}
void fail(){
	cout<<"-1\n";
	exit(0);
}
int main(){FIN;
	ll a,b,C; cin>>a>>b>>C;
	ll sw=0,d=ppc(C);
	auto c=cv(C);
	if(b>a)swap(a,b),sw=1;
	ll e=a-b;
	//cout<<d<<"\n";
	if(d>(a+b)||d<e||(a+b)%2!=d%2)fail();
	//cout<<"passed\n";
	vector<ll>x(60),y(60);
	ll k=0;
	for(ll i=0,j=0;i<B;i++){
		if(c[i]){
			if(j<e||j%2)x[i]=1;
			else y[i]=1,k++;
			j++;
		}
	}
	fore(i,0,B){
		if(!c[i]&&k<b){
			x[i]=y[i]=1;
			k++;
		}
	}
	if(k<b)fail();
	//cout<<"passed "<<k<<"<"<<b<<"\n";
	//imp(c); imp(x); imp(y);
	ll r0=cv(x),r1=cv(y);
	if(sw)swap(a,b),swap(r0,r1);
	if(ppc(r0)==a&&ppc(r1)==b&&(r0^r1)==C)cout<<r0<<" "<<r1<<"\n";
	else fail();
	return 0;
}
