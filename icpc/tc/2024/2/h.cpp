#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv a;

ll check(int i, int j,int aa){
	ll aux=1e13;
	int l=i;
	int r=j-aa;
	//cout<<l<<" "<<r<<"\n";
	while(r<=j){
		aux=min(max(a[l],a[r]),aux);
		l++;
		r++;
	}
	return aux;
}

ll quebien(int p){
	ll ret=0;
	fore(i,0,p+1){
		ret=max(ret,a[i]);
	}
	for(int i=SZ(a)-1;i>=SZ(a)-1-p;i--){
		ret=max(ret,a[i]);
	}
	return ret;
}

int main(){
	JET
	int t; cin>>t;
	while(t--){
		int n,p,k; cin>>n>>p>>k;
		ll ma=0;
		
		fore(i,0,n){
			ll x; cin>>x;
			a.pb(x);
			ma=max(ma,x);
		}
		if(k+1>=p){
			cout<<quebien(p-1)<<"\n";
		}
		else{
			ll rta=0;
			fore(i,0,k+1){
				rta=max(rta,check(i,i+(n-k-1),p-k-1));
			}		
			cout<<rta<<"\n";
		}
		a.clear();
		
	}
}

