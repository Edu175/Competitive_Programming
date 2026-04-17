#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,p,h,a=0;
	cin>>n>>p>>h;
	vv s, m;
	bool b=false;
	fore(i,0,n){
		ll x;
		char c; cin>>c;
		if(c=='!') a++;
		else if(c=='+'){
			cin>>x;
			s.pb(x);
			b=true;
		}
		else{
			cin>>x;
			m.pb(x);
			if(x!=1) b=true;
		}
	}
	if((p==0 && SZ(s)==0) || a==0){
		cout<<"*\n";
		return 0;
	}
	if(!b){
		ll obj = h/p;
		ll it = obj+1 / a;
		ll r = it*n;
		cout<<r+obj-it*a<<"\n";
		return 0;
	}
	while(1){
		ll auxh,auxp;
		for(auto x:s){
			
		}
	}
	
	return 0;
}