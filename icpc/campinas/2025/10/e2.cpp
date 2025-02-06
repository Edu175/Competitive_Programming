#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll maxn = 505;
const ll INF = 1e17;
ll dp[maxn][maxn][7];

vv a;

ll f(ll i, ll j, ll x){
	if(i>j) return 0;
	ll &rta = dp[i][j][x];
	if(rta!=-1) return rta;
	if(x==a[i]){
		rta = f(i+1,j,x);
		return rta;
	}
	rta=INF;
	fore(k,i,j+1){
		rta = min(rta,f(i+1,k,a[i]) + 1 + f(k+1,j,x));
	}
	return rta;
	
}

string t(string s){
	string r=s;
	r[6]=s[0];
	fore(i,0,6) r[i]=s[i+1];
	return r;
}

int main(){
	TUCUTUCUTUCUTUCU
	ll n; cin>>n;
	mset(dp,-1);
	fore(i,0,n){
		string str; cin>>str;
		string M = str;
		ll idx = 0;
		fore(j,1,7){
			string  aux = t(str);
			if(aux==M) idx=-1;
			else if(aux>M){
				M=aux;
				idx=j;
			}
			str=aux;
		}
		if(idx>=0) a.pb(idx);
	}
	cout<<f(0,SZ(a)-1,0)<<"\n";
}