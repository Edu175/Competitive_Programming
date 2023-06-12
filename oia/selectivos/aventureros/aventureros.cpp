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
typedef long long ll;
const ll MAXN=4e5+5;

int ft[MAXN+1];
void upd(int i0, int v){ // add v to i0th element (0-based)
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){ // get sum of range [0,i0)
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
	return get(i1)-get(i0);
}
ll pos(ll p){ // log(n)**2, last element = p //upper bound -1
	ll l=0,r=MAXN;
	while(l<=r){
		ll m=(l+r)/2;
		if(get(m)<p+1)l=m+1;
		else r=m-1;
	}
	return r;
}
int main(){FIN;
	ifstream cin;   cin.open("aventureros.in", ios::in);
	ofstream cout; cout.open("aventureros.out", ios::out);
	ll n; cin>>n;
	ll a[n-1];
	fore(i,0,n-1)cin>>a[i];
	fore(i,0,n)upd(i,1);
	ll p=0;
	vector<ll>res;
	fore(i,0,n-1){
		ll m=n-i;
		p=(p+a[i])%m;
		ll x=pos(p);
		res.pb(x);
		upd(x,-1);
	}
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n"<<pos(0)+1<<"\n";
	return 0;
}
