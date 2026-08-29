#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<x<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MAXN = 2e4;
ll dp[MAXN][2];
ll pot3[12];


bool win(ll mk, ll x){
	ll a[9];
	fore(i,0,9){
		a[i] = mk%3;
		mk/=3;
	}
	assert(!mk);
	fore(i,0,3){
		if(a[i+3] != a[i] || a[i+6] != a[i]) continue;
		if(a[i] == x) return true;
	}
	for(ll i = 0;i<9;i+=3){
		if(a[i+1] != a[i] || a[i+2] != a[i]) continue;
		if(a[i] == x) return true;
	}
	if(a[0] == a[4] && a[0] == a[8] && a[0] == x) return true;
	if(a[2] == a[4] && a[2] == a[6] && a[2] == x) return true;
	return false;
}


ll f(ll mk, ll p){
	// cout<<"init mk "<<mk<<endl;
	if(win(mk,p)) return 1;
	if(win(mk,!p)) return 0;
	ll &r = dp[mk][p];
	if(r != -1) return r;
	r = 0;
	ll libres[9]; fore(i,0,9)libres[i] = 0;
	ll turn = 0;
	// cout<<"ssta\n";
	ll mkk = mk;
	fore(i,0,9){
		// cout<<mkk%3<<" ";
		if(mkk%3 == 2)libres[i] = 1;
		else turn=!turn;
		mkk/=3;	
	}
	// cout<<"\n";
	fore(i,0,9){
		if(!libres[i]) continue;
		// cout<<"mks "<<mk<<" "<<mk+pot3[i]<<"\n";
		r+=(f(mk-pot3[i]*2+pot3[i]*turn,p));
	}
	return r;
}


int main(){
	JET
	pot3[0] = 1;
	fore(i,1,12)pot3[i] = pot3[i-1]*3;
	ll t; cin>>t;
	mset(dp,-1);
	while(t--){
		string s; cin>>s;
		ll mk = 0;
		ll c = 0, x = 0;
		fore(i,0,9){
			if(s[i] == 'O')mk+=pot3[i], c++;
			else if(s[i] == '.')mk+=pot3[i]*2;
			else x++;
		}
		if(c>x || x>c+1){
			cout<<"-1 -1\n";continue;
		}
		if(win(mk,0) && x!=c+1){
			cout<<"-1 -1\n";continue;
		}
		if(win(mk,1) && x!=c){
			cout<<"-1 -1\n";continue;
		}
		if(win(mk,0)&&win(mk,1)){
			cout<<"-1 -1\n";
			continue;
		}
		cout<<f(mk,0)<<" "<<f(mk,1)<<"\n";
	}
	return 0;
}

