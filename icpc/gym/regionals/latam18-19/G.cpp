#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b);
		e>>=1;
	}
	return res;
}
int inv(ll a){return fpow(a,MOD-2);}
ii operator-(ii a, ii b){return {a.fst-b.fst,a.snd-b.snd};}
ii rot90(ii a){return {-a.snd,a.fst};}

int main(){
	JET
	assert(mul(5,inv(5))==1);
	ll n; cin>>n;
	vector<ii> a(n);
	map<ii,ll> rep;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,rep[a[i]]++;
	a.clear();
	for(auto i:rep)a.pb(i.fst);
	vv fc(n+1);
	fc[0]=1;
	fore(i,1,n+1)fc[i]=mul(fc[i-1],i);
	
	n=SZ(a);
	
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	
	ll multi=1;
	for(auto [asd,c]:rep)multi=mul(multi,fc[c]);
	
	map<ii,set<ll>> mp;
	fore(i,0,n)fore(j,0,n)if(i!=j){
		ii v=rot90(a[i]-a[j]);
		if(v.fst<=0||v.snd<=0)continue;
		ll g=gcd(v.fst,v.snd);
		v.fst/=g,v.snd/=g;
		mp[v].insert(i);
		mp[v].insert(j);
		// cout<<v.fst<<","<<v.snd<<": "<<i<<" "<<j<<"\n";
	}
	
	ll res=multi;
	// cout<<"multi "<<multi<<"\n";
	for(auto [v,st]:mp){
		// cout<<v.fst<<","<<v.snd<<":\n";
		map<ll,ll> cnt;
		ll otr=multi;
		for(auto i:st){
			ll val=v.fst*a[i].fst+v.snd*a[i].snd;
			cnt[val]+=rep[a[i]];
			otr=mul(otr,inv(fc[rep[a[i]]]));
			// cout<<i<<": "<<a[i].fst<<","<<a[i].snd<<": "<<v.fst<<","<<v.snd<<": "<<val<<"\n";
		}
		ll cur=otr;
		for(auto [asd,c]:cnt)cur=mul(cur,fc[c]);
		
		// cout<<cur<<"\n\n";
		cur=sub(cur,multi);
		res=add(res,cur);
	}
	cout<<res<<"\n";
	return 0;
}
