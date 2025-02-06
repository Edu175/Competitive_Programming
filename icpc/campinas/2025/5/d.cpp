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
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e6+5;
const ld EPS=1e-10;

auto compose(auto &a, vv b){
	auto c=a;
	fore(i,0,SZ(a))c[b[i]]=a[i];
	a=c;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll suma=0,sumb=0;
		vector<ld> as(n);
		vv ls(n),bs(n);
		fore(i,0,n){
			ll l,a,b; cin>>l>>a>>b;
			suma+=l*a,sumb+=l*b;
			ls[i]=l;
			as[i]=a;
			bs[i]=b;
		}
		if(suma!=sumb){
			cout<<"NIE\n";
			continue;
		}
		vv per(n); iota(ALL(per),0);
		sort(ALL(per),[&](ll i, ll j){return as[i]<as[j];});
		compose(ls,per);
		compose(as,per);
		compose(bs,per);
		for(auto i:ls)cout<<i<<" ";;cout<<"\n";
		for(auto i:as)cout<<i<<" ";;cout<<"\n";
		for(auto i:bs)cout<<i<<" ";;cout<<"\n";
		ll flag=1;
		fore(i,0,n){
			if(as[i]-EPS>(ld)bs[i])flag=0;
			cout<<i<<": "<<as[i]<<"\n";
			if(i==n-1){
				if(as[i]+EPS<(ld)bs[i])flag=0; // if this happens, at this point flag should already be 0
			}
			else {
				ld a2=(ld)ls[i]/ld(ls[i+1])*(as[i]-bs[i])+as[i+1];
				as[i+1]=a2;
				// cout<<i<<": "<<a2<<" a2\n";
			}
		}
		// cout<<"\n";
		if(flag)cout<<"TAK\n";
		else cout<<"NIE\n";
	}
	return 0;
}


/*

0: 1
1: 10

NIE
NIE
0: 5
1: 19

NIE
0: 2
1: 11

NIE
0: 4
1: 19.5
2: 49

NIE
*/