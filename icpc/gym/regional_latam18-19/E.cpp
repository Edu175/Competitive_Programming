#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator%(pt p){return x*p.y-y*p.x;}
};

int main(){
	JET
	ll n; cin>>n;
	ll N=4*n+5;
	vector<pt> a(N);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	fore(i,n,SZ(a))a[i]=a[i-n];
	vector<pt> fle(SZ(a)-1);
	fore(i,0,SZ(a)-1)fle[i]=a[i+1]-a[i];
	vv r(N);
	ll ri=1;
	fore(i,0,n){
		while(fle[i]%fle[ri]>0)ri++;
		r[i]=ri;
	}
	fore(i,n,SZ(r))r[i]=r[i-n]+n;
	// for(auto i:r)cout<<i<<" ";;cout<<"\n";
	ll l=1,to=1,sum=0;
	fore(j,to,r[0])sum+=r[j];
	ll res=0;
	fore(i,0,n){
		while(!(r[l]>i+n))l++;
		while(to<r[i]&&!(r[to]>l))sum-=r[to++];
		ll q=r[i]-to;
		ll cur=sum-l*q;
		res+=cur;
		fore(j,r[i],r[i+1])sum+=r[j];
		// cout<<i<<": "<<l<<" ["<<to<<","<<r[i]<<") "<<cur<<"\n";
	}
	// cerr<<res<<"\n";
	// cout<<endl;
	assert(res%3==0);
	res/=3;
	cout<<res<<"\n";
	
	return 0;
}
