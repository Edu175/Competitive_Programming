#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) for(auto y:x){cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ii extendedEuclid(ll a, ll b){
	if(!b) return {1,0};
	auto p=extendedEuclid(b,a%b); ll x=p.snd,y=p.fst-(a/b)*x;
	if(a*x+b*y<0) x=-x,y=-y;
	return {x,y};
}

ii diophantine(ll a, ll b, ll r){
	ll d=gcd(a,b); a/=d;b/=d; r/=d;
	auto p=extendedEuclid(a,b); p.fst*=r,p.snd*=r;
	return p;
}
const ll INF=1e18;
ii solve(vector<ii> &A, vv &b){
	ll n=SZ(A);
	fore(i,0,n) if(A[i].fst){swap(A[0],A[i]),swap(b[0],b[i]); break;}
	if(A[0].fst){
		fore(i,1,n){
			A[i].snd=A[i].snd*A[0].fst-A[0].snd*A[i].fst;
			b[i]=b[i]*A[0].fst-b[0]*A[i].fst;
			A[i].fst=0;
		}
	}
	ll I=INF,r=INF;
	fore(i,1,n){
		if(A[i].snd){
			if(b[i]%A[i].snd) return {-INF,-INF};
			if(r==INF){
				r=b[i]/A[i].snd;
			}
			if(r!=b[i]/A[i].snd) return {-INF,-INF};
		}
		else if(b[i]) return {-INF,-INF};
	}
	if(r==INF) return {INF,INF};
	if(!A[0].fst){
		I=A[0].snd*r==b[0]?1:-INF;
		return {I,r};
	}
	I=(b[0]-A[0].snd*r)%A[0].fst?-INF:(b[0]-A[0].snd*r)/A[0].fst;
	return {I,r};
}
ll solve2(ii KT, ll S){
	auto [K,T]=KT;
	if(!K&&!T){
		if(S) return -1;
		return 1;
	}	
	if(!K){
		if(S%T) return -1;
		ll r=S/T;
		if(r<=0) r=-1;
		return r;
	}
	if(!T){
		if(S%K) return -1;
		ll I=S/K;
		if(I<=0) return -1;
		return 1;
	}
	ll g=gcd(K,T);
	if(S%g) return -1;
	auto [I,r]=diophantine(K,T,S);
	ll t=r/(K/g);
	r-=t*(K/g);
	while(r>0) r-=(K/g),t++;
	while(r<=0) r+=(K/g),t--;
	I+=t*(T/g);
	if(I<=0) return -1;
	return r;
}
int main(){
	JET
	ll n; cin>>n;
	vector<string> s(n);
	fore(i,0,n) cin>>s[i];
	ll k=-1;
	vector<ii> A; vv b;
	fore(i,0,n){
		ll cs=0,ct=0;
		if(s[i].back()=='{') k++;
		for(auto c: s[i]) {
			if(c=='s') cs++;
			if(c=='t') ct++;
		}
		A.pb({k,-ct}); b.pb(cs);
		if(s[i].back()=='}') k--;
	}
	auto [I,r]=solve(A,b);
	// cout<<I<<" "<<r<<"\n";
	if(I<=0||r<=0) {cout<<"-1\n"; return 0;}
	if(I==INF||r==INF) {cout<<solve2(A[0],b[0])<<"\n"; return 0;}
	cout<<r<<"\n";
	return 0;
}
// 10
// {
// ss{
// sts{
// tt}
// t}
// t{
// ss}
// }
// {
// }
// 1
