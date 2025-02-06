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

set<ll> s[maxn];


ll f(ll i, ll j, ll v){
	ll &rta = dp[i][j][v];
	if(rta!=-1) return rta;
	if(i==j){
		rta = !s[i].count(v);
		return rta;
	}
	if(s[i].count(v)){
		rta = f(i+1,j,v);
		return rta;
	}
	if(s[j].count(v)){
		rta = f(i,j-1,v);
		return rta;
	}
	
	rta = INF;
	rta = min(rta,f(i+1,j,v)+1);
	for(auto x:s[i]){
		rta = min(rta,f(i+1,j,x)+1);
	}
	
	rta = min(rta,f(i,j-1,v)+1);
	for(auto x:s[j]){
		rta = min(rta,f(i,j-1,x)+1);
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
		s[i].insert(0);
		fore(j,1,7){
			string  aux = t(str);
			if(aux==M) s[i].insert(j);
			else if(aux>M){
				s[i].clear();
				M=aux;
				s[i].insert(j);
			}
			str=aux;
		}
	}
	
	ll res = f(0,n-1,0);
	// ll res = f(0,5,0);
	cout<<res<<"\n";
	
	return 0;
}