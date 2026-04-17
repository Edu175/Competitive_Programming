#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
const ll MAXN=305;
ll a[MAXN];
vector<ll>s;
ll n;
ll r=0;
void change(ll i, ll j){
	if(i)r-=max(a[i-1],a[i]);
	if(i<n-1)r-=max(a[i],a[i+1]);
	if(j)r-=max(a[j-1],a[j]);
	if(j<n-1)r-=max(a[j],a[j+1]);
	swap(a[i],a[j]);
	if(i)r+=max(a[i-1],a[i]);
	if(i<n-1)r+=max(a[i],a[i+1]);
	if(j)r+=max(a[j-1],a[j]);
	if(j<n-1)r+=max(a[j],a[j+1]);
}
ll SA(){
	ll sd; srand((long long)&sd);
	auto s_=s; random_shuffle(ALL(s_));
	vector<ll>_a(n); fore(i,0,n)_a[i]=a[i];
	fore(i,0,SZ(s))a[s[i]]=_a[s_[i]];
	fore(i,0,n-1)r+=max(a[i],a[i+1]);
	if(SZ(s)<2)return r;
	ll best=r;
	double t=1e9;
	while(clock()<=1.99*CLOCKS_PER_SEC){
		ll i=s[rand()%SZ(s)],j=s[rand()%SZ(s)];
		ll old=r;
		change(i,j);
		if(r<best)best=r;
		if(r>=old&&exp((old-r)/t)<(double)rand()/RAND_MAX)change(i,j);
		t*=0.999995;
	}
	//cout<<t<<endl;
	return best;
}
int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	vector<ll>is(n);
	fore(i,0,k){
		ll x; cin>>x; x--; is[x]=1;
	}
	fore(i,0,n)if(!is[i])s.pb(i);
	cout<<SA()<<"\n";
	return 0;
}
