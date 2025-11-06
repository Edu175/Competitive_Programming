#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

struct rec{
    string s;
    ll c, b; 
    rec(string s, ll c, ll b):s(s),c(c),b(b){}
};

map<string, ii> imp; // cost
map<string, vector<rec>> mp;
const ll inf = 1e18;
ii f(string s){
    if(imp.count(s)) return imp[s];
    if(!mp.count(s)) return {0,0};
    ii r = {inf,inf};
    for(auto re:mp[s]){
        ii aux = f(re.s);
        aux.fst += re.c;
        aux.snd += re.b;
		
		aux.snd*=-1;
		r=min(r,aux);
    }
	r.snd*=-1;
	
    imp[s] = r;
    return imp[s];
}

int main(){
    JET
    ll w; cin>>w;
    ll n; cin>>n;
    fore(i,0,n){
        string res, bas, k;
        int c,b; 
        cin>>res>>bas>>k>>c>>b;
        mp[res].pb(rec(bas,c,b));
    }
    for(auto [res,re] : mp)f(res);
	vector<ii> a;
	for(auto [asd,i]:imp)a.pb(i);
	n=SZ(a);
	vector<vector<ii>> dp(n+1,vector<ii>(w+3));
	fore(s,0,w+1){
		dp[n][s]={0,s};
	}
	for(ll i=n-1;i>=0;i--)fore(s,0,w+1){
		auto &res=dp[i][s];
		res=dp[i+1][s];
		auto [c,ga]=a[i];
		if(s-c>=0){
			auto go1=dp[i+1][s-c];
			go1.fst+=ga;
			res=max(res,go1);
		}
	}
	auto [gan,uso]=dp[0][w];
	uso=w-uso;
	cout<<gan<<"\n"<<uso<<"\n";
    return 0;
}