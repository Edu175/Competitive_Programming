#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
 
bool men(ii a, ii b){
	assert(a.snd&&b.snd);
	ll lhs=a.fst*b.snd,rhs=b.fst*a.snd;
	if((b.snd<0)^(a.snd<0)) return lhs>rhs;
	return lhs<rhs;
}

bool f(pair<ii,ll> a, pair<ii,ll> b){
    if(men(a.fst,b.fst))return 1;
    if(men(b.fst,a.fst)) return 0;
    return a.snd<b.snd;
}

ll solve(vector<pair<ii,ll>> vec, ll extra){
	ll cnt=0;
	for(auto i:vec)cnt+=i.snd==-1;
    sort(ALL(vec),f);
	ll r = cnt;
	for(auto x:vec){
		cnt+=x.snd;
		r = max(r,cnt);
	}
	return r+extra;
}

int main(){
    JET
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll mas0 = 0, menos0 = 0;
        vector<pair<ii,ll>> vec;
        fore(i,0,n){
			ll a,b,c; cin>>a>>b>>c;
			// swap(a,b);
            if(!a){
                if(b>0) menos0 ++;
                if(b<0) mas0++;
            }
            if(a > 0) vec.pb({{-b,a},-1});
            else if(a < 0) vec.pb({{-b,a},1});
        }
        sort(ALL(vec),f);
        ll r1=solve(vec,mas0);
		for(auto &i:vec)i.fst.fst*=-1;
        ll r2=solve(vec,menos0);
		ll r=max(r1,r2);
        cout<<r<<"\n";
    }
    return 0;
}