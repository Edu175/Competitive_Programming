#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x)  for(auto a:x){cout<<a<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;
const ll maxn=2e5+5;
ll n;
ll a[maxn],ina[maxn],b[maxn],inb[maxn];

ll subm(ll x, ll y){x-=y; return x<0?x+n:x;}

ll dist(ll i){
	if(i<0)return ina[b[0]];
	if(i==n-1) return 0;
	return subm(ina[b[i+1]],ina[b[i]])-1;
}

ll calc(ll i){
	return dist(i-1)+dist(i);
}

int main(){
	JET
	ll d; cin>>n>>d;
	fore(i,0,n) cin>>a[i];
	fore(i,0,n) cin>>b[i];
	fore(i,0,n) ina[--a[i]]=i,inb[--b[i]]=i;
	ll r=0;
	fore(i,-1,n) r+=dist(i);
	cout<<r<<"\n";
	fore(i,1,d){
		ll c,x,y; cin>>c>>x>>y; c--,y--,x--;
		if(c){
			ll bx=b[x];
			ll by=b[y];
			r-=calc(x);
			b[x]=by;
			r+=calc(x);
			r-=calc(y);
			b[y]=bx;
			r+=calc(y);
			swap(inb[bx],inb[by]);
			cout<<r<<"\n";
		}
		else{
			ll ax=a[x];
			ll ay=a[y];
			r-=calc(inb[ax]);
			ina[ax]=y;
			r+=calc(inb[ax]);
			r-=calc(inb[ay]);
			ina[ay]=x;
			r+=calc(inb[ay]);
			swap(a[x],a[y]);
			cout<<r<<"\n";
		}
	}
	return 0;
}