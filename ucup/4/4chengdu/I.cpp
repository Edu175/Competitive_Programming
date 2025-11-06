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
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
void tle(bool b){
	if(!b){
		ll start=clock();
		while(clock()-start<30*CLOCKS_PER_SEC);
		cout<<"pinga\n";
	}
}
struct pt {
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ld operator%(pt p){return x*p.y-y*p.x;}
	ll left(pt p, pt q){ // how left is it to the directed line pq?
		return (q-p)%(*this-p);}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pt>a(3*n);
		fore(i,0,n)cin>>a[i].x>>a[i].y;
		fore(i,0,SZ(a))a[i]=a[i%n];
		
		ll m; cin>>m;
		vector<pt>b(3*m);
		fore(i,0,m)cin>>b[i].x>>b[i].y;
		fore(i,0,SZ(b))b[i]=b[i%m];
		
		auto val=[&](ll i, ll r, ll po){
			return b[po].left(a[i],a[r]);
		};
		
		auto actuP=[&](ll i, ll r, ll &po){
			while(val(i,r,po+1)<val(i,r,po))po++;
		};
		
		auto actuR=[&](ll i, ll &r, ll &po){ // PRE: P is actu'ed
			actuP(i,r,po);
			while(val(i,r,po)>=0)r++,actuP(i,r,po);
		};
		
		vv r(n);
		ll po=0,ri=1;
		fore(i,0,m)if(val(0,ri,i)<val(0,ri,po))po=i;
		
		fore(i,0,n){
			// actuP(i,ri,po);
			actuR(i,ri,po);
			r[i]=ri;
		}
		
		// imp(r)
		
		r.resize(3*n);
		fore(i,n,SZ(r))r[i]=r[i-n]+n;
		
		// imp(r)
		
		ll l=0,to=0;
		fore(i,0,n)if(r[i]>n){l=i;break;}
		to=1;
		ll sum=0,cant=0; // [to,r[i])
		fore(i,to,r[0])sum+=r[i],cant++;
		ll res=0;
		fore(i,0,n){
			while(!(r[l]>n+i))l++;
			while(to<r[i]&&!(r[to]>l))sum-=r[to],cant--,to++;
			
			tle(cant>=0&&cant==r[i]-to);
			ll cur=sum-l*cant;
			res+=cur;
			
			// cout<<i<<": "<<l<<" "<<to<<": "<<cant<<" "<<sum<<": "<<cur<<"\n";
			
			fore(j,r[i],r[i+1])sum+=r[j],cant++;
		}
		assert(res%3==0);
		res/=3;
		cout<<res<<"\n";
	}
	return 0;
}
