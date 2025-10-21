#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll a, ll b){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=1e6+5; // 50 is enough
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}

ll nCr(ll n, ll k){
	if(n<k||n<0||k<0)return 0;
	assert(k<MAXF);
	ll res=1;
	// cerr<<"nCr "<<n<<","<<k<<": ";
	fore(i,0,k)res=mul(res,(n-i)%MOD);//,cerr<<n-i<<" ";
	// cerr<<fci[k]<<" i\n";
	res=mul(res,fci[k]);
	// cout<<"= "<<res<<"\n";
	return res;
}

ll ceb(ll c, ll b){
	// cerr<<"\nceb "<<c<<","<<b<<":\n";
	return nCr(b+c-1,b);
}

vector<ii> getf(ll n){
	vector<ii> ans;
	for(ll i=2;i*i<=n;i++){
		ll e=0;
		while(n%i==0){
			e++;
			n/=i;
		}
		if(e)ans.pb({i,e});
	}
	if(n>1)ans.pb({n,1});
	return ans;
}

vector<ii> pr;

vv coef;
ll a;
ll ans=0;

void f(ll i, ll val, ll res){ // O(divs)
	if(i==SZ(pr)){
		if(val<=a){
			ans=add(ans,res);
			// cout<<"sumo "<<val<<": "<<res<<"\n";
		}
		return;
	}
	ll lim=pr[i].snd;
	fore(e,0,lim+1){
		ll cur=mul(coef[e],coef[lim-e]);
		f(i+1,val,mul(res,cur));
		val*=pr[i].fst;
		// if(rec)cout<<i<<" "<<val<<": "<<e<<" "<<lim-e<<" "<<cur<<" antes\n";
		// cur=mul(cur,rec);
		// res=add(res,cur);
		// if(cur)cout<<i<<" "<<val<<": "<<e<<" "<<cur<<"\n";
	}
	// return res;
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		ll n,b; cin>>n>>a>>b;
		pr=getf(b);
		ll mx=0;
		for(auto i:pr)mx=max(mx,i.snd);
		// for(auto i:pr)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		mx++;
		coef=vv(mx);
		fore(c,0,mx)coef[c]=ceb(n,c);
		// cout<<"coef "<<coef[2]<<"\n";
		ans=0;
		f(0,1,1);
		cout<<ans<<"\n";
	}
	return 0;
}
