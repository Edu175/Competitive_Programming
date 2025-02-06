#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;

const ld EPS=1e-8;
int main(){
	JET
	ll n; cin>>n;
	ll a[n],b[n],c[n],l[n+1];
	l[n]=0;
	map <ll,ll> m;
	ll p[n]; iota(p,p+n,0);
	vv pos;
	pos.pb(n);
	ll A=0,B=0,C=0;
	fore(i,0,n){
		cin>>a[i]>>b[i]>>c[i]>>l[i];
		if(!m.count(l[i])) {m[l[i]]=i; pos.pb(i);}
		else{
			ll j=m[l[i]]; p[i]=j; a[j]+=a[i];b[j]+=b[i]; c[j]+=c[i];
		}
		A+=a[i];B+=b[i];C+=c[i];
	}
	ld M=C;
	sort(ALL(pos),[&](ll i, ll j){return l[i]<l[j];});
	fore(i,1,SZ(pos)){
		ll e1=l[pos[i]];
		ll e2=l[pos[i-1]];
		ld M1=max(e1*e1*A+e1*B+C,e2*e2*A+e2*B+C);
		if(A<0){
			ld x=(ld(B)/(-2.0*(ld)A));
			if(x>=e2-EPS&&x<=e1+EPS)M1=max(M1,x*x*A+x*B+C);
		}
		A-=a[pos[i]];B-=b[pos[i]];C-=c[pos[i]];
		M=max(M,M1);
	}
	cout<<fixed<<setprecision(7)<<M<<"\n";
	return 0;
}