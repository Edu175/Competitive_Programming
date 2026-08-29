#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-7;
const ld EPS2=1e-8;

ld gcd(ld a, ld b){
	// cerr<<"gcd "<<a<<","<<b<<": ";
	while(b>EPS){
		a=remainderl(a,b);
		swap(a,b);
	}
	return a;
}
ld lcm(ld a, ld b){return a/gcd(a,b)*b;}

int main(){
	JET
	ll n; cin>>n;
	vector<ld> a(n);
	ld m=1;
	fore(i,0,n){
		cin>>a[i];
		ld k=1/a[i];
		m=lcm(k,m);
	}
	vector<ld> b(n);
	fore(i,0,n){
		b[i]=a[i]*m;
	}
	ll p=0; while(p<n&&b[p]==b[0])p++;
	if(p==n){
		fore(i,0,n)cout<<"1 ";;cout<<"\n";
		return 0;
	}
	ld r=b[p]/b[0];
	ll to=-1; //ld diff=1e9;
	fore(i,1,1e4+1){
		ld otr=i*r;
		ld cur=abs(otr-round(otr));
		// if(cur<diff)to=i,diff=cur;
		if(cur<EPS2)to=i;
	}
	// cerr<<"diff "<<diff<<"\n";
	assert(to!=-1);
	ld d=to/b[0];
	vv ans(n);
	fore(i,0,n){
		b[i]*=d;
		ans[i]=round(b[i]);
	}
	ll g=0; for(auto i:ans)g=gcd(g,i);
	for(auto i:ans){
		i/=g;
		cout<<i<<"\n";
	}
	return 0;
}