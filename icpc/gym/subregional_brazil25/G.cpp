#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vv obj;
const ll inf = 1e17;
const int maxn = 4110;                               
ll dp[maxn][1<<7];
ll act,n;

ll f(ll x, ll mk){
	mk&=((1<<7)-1);
	if(x == SZ(obj)) return 0;
	ll &r = dp[x][mk];
	if(r != -1) return r;
	ll uso=f(x+1, ((mk<<1)^act)) + 1;
	ll sigo=f(x+1,(mk<<1));
	if(x < 7){
		r = min(uso, sigo);
		return r;
	}
	if(obj[x] != (mk>>6&1)){
		if(!(act & (1<<7))) return inf;
		else r = uso;
	}	
	else{
		if(act & (1<<7)) r = sigo;
		else r = min(uso,sigo);
	}
	return r;
}


ll solve(){
	return f(0,0);
}

string bin(ll x){
	string s;
	fore(i,0,8)s.pb((x>>i&1)+'0');
	reverse(ALL(s));
	return s;
}

int main(){
	JET
	cin>>n;
	obj.resize(n+7);
	fore(i,0,7) obj[i] = 0;
	string s; cin>>s;
	fore(i,0,n) obj[i+7] = s[i] == '1';
	bool uno = false, cero = false;
	fore(i,0,n){
		if(obj[i]) uno = true;
		else cero = true;
	}
	if(!uno){
		fore(i,0,8) cout<<0;
		cout<<" 0\n";
		return 0;
	}
	if(!cero){
		fore(i,0,8) cout<<1;
		cout<<" "<<(n+7)/8<<"\n";
		return 0;
	}
	ii rta = {inf, 0};	
	fore(i,1,1<<8){
		act = i;
		mset(dp,-1);
		ll k = solve();
		rta = min(rta,{k,i});
		// cout<<rta.fst<<" "<<rta.snd<<"\n";
	}
	cout<<bin(rta.snd)<<" "<<rta.fst<<"\n";
	return 0;
}