#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vv a;
vv d;

ll can(ll x){
	set<ll> s;
	vv aux=a;
	set<ll> flag;
	fore(i,0,SZ(a)){
		if(flag.count(i)){
			
		}
		if(aux[i]<x){
			s.insert(i);
		}
		if(aux[i]>x){
			auto it=s.lower_bound(i-d[i]);
			ll need=aux[i]-x;
			while(it!=s.end()){
				ll p=*it;
				ll help=x-aux[p];
				if(help<=need){
					aux[p]+=help;
					aux[i]-=help;
					need-=help;
					it=s.erase(it);
				}
				else{
					aux[p]-=need;
					aux[i]-=need;
					need-=need;
					break;
				}
			}
			if(need>0){
				flag.insert(i+1);
			}
		}
	}
}

int main(){
	JET
	int n;
	cin>>n;
	a.resize(n);
	d.resize(n);
	fore(i,0,n) cin>>a[i];
	fore(i,0,n) cin>>d[i];
	ll l=0;
	ll r=1e12;
	while(l<r){
		ll m=(l+r)/2;
		if(can(m)) r=m;
		else l=m;
	}
	return 0;
}