#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXC=2025;
ll to2(ll n){return n*(n-1)/2;}
ll cuad(ll n){
	return to2(n)*to2(n);
}
ll cub(ll n, ll z){
	return to2(z)*(2*n+1);
}
void tle(bool b){
	if(!b){
		auto start=clock();
		while(clock()-start<30*CLOCKS_PER_SEC);
		cout<<"chottaaa\n";
	}
}
int main(){
	JET
	ll k; cin>>k;
	ll n=0;
	while(cuad(n+1)<=k)n++;
	k-=cuad(n);
	assert(k>=0);
	ll z=0;
	while(cub(n,z+1)<=k)z++;
	k-=cub(n,z);
	vv a;
	while(k>0){
		ll u=-1;
		fore(l,2,MAXC+1)if(to2(l)<=k)u=l;
		a.pb(u);
		k-=to2(u);
	}
	assert(k==0);
	// assert(SZ(a)<=7);
	ll w=0;
	if(SZ(a))w=*max_element(ALL(a));
	w=max(w,n+2);
	tle(w<=MAXC);
	vector<string> res;
	for(auto l:a){
		fore(_,0,2)res.pb(string(l,'#')+string(w-l,'.'));
		res.pb(string(w,'.'));
	}
	fore(_,0,z)res.pb(string(w-(n+2),'.')+string(n+2,'#'));
	fore(_,0,n-z)res.pb(string(w-n,'.')+string(n,'#'));
	ll h=SZ(res);
	tle(h<=MAXC);
	fore(i,0,h)tle(SZ(res[i])==w);
	cout<<h<<" "<<w<<"\n";
	fore(i,0,h)cout<<res[i]<<"\n";
	return 0;
}