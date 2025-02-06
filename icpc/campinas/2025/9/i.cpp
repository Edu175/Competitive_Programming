#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n;
vv a;
bool can(ll k){
	ll l=a[0],r=a[0];
	fore(i,1,n){
		ll v=a[i];
		ll ri=r+v,li=-1;
		if(ri>k)ri=k-((ri+k)&1);
		if(v<l)li=abs(v-l);
		else if(v>r)li=abs(v-r);
		else li=(l+v)&1;
		if(li>k)return 0;
		l=li,r=ri;
		assert(l<=r);
	}
	return l==0;
}

int main(){
	JET
	cin>>n;
	a.resize(n);
	ll sl=0,sr=0;
	fore(i,0,n)cin>>a[i],sr+=a[i];
	ll res1=0;
	for(auto v:a){
		sl+=v,sr-=v;
		res1=max(res1,min(sl,sr));
	}
	
	ll l=a[0],r=sl+sr+1000;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	
	cout<<l<<"\n"<<res1<<"\n";
	return 0;
}