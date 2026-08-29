#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x)  for(auto a:x){cout<<a<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;

ll a[4];
vv ite = {3,3,2,0};


vv aux;
bool cero(){
	aux.clear();
	fore(it,0,4){
		ll  i = ite[it];
		while(i>=0 && !a[i]) i--;
		if(i<0){
			for(auto x:aux)a[x]++;	
			return false;
		}
		a[i]--;
		aux.pb(i);
	}
	return true;
}

bool unouno(){
	// show(a);
	fore(_,0,2) if(!a[1]--)return false;
	fore(it,1,3){
		ll i = ite[it];
		while(i>=0 && !a[i]) i--;
		if(i<0) return false;
		a[i]--;
	}
	return true;
}


int main(){
	JET
	ll t; cin>>t;
	while(t--){
		mset(a,0);
		ll n; cin>>n;
		fore(i,0,n){
			char x; cin>>x;
			if(x == '0')a[0]++;
			else if(x == '1')a[1]++;
			else if(x<='5')a[2]++;
			else a[3]++;
		}
		ll cnt = 0;
		while(cero())cnt++;
		while(unouno())cnt++;
		cout<<cnt<<"\n";
	}
	return 0;
}