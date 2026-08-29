#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define dbg(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXV=1e6+1,B=1 + 700;

ll ask(ll i, ll j){
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

int main(){
	// FIN;
	vv cr(MAXV,-1); // smallest prime divisor
	vv nums;
	fore(i,2,MAXV)if(cr[i]==-1){
		if(i<B){
			ll pot=1; while(pot*i<B)pot*=i;
			nums.pb(pot);
		}
		cr[i]=i;
		for(ll j=i*i;j<MAXV;j+=i)cr[j]=i;
	}
	vv valid(MAXV,1); valid[0]=0;
	fore(i,1,MAXV){
		map<ll,ll>mp;
		ll n=i;
		while(n>1){
			ll p=cr[n];
			mp[p]++;
			n/=p;
		}
		for(auto [p,e]:mp){
			ll pot=1; fore(_,0,e)pot*=p;
			valid[i]&=pot<B;
		}
	}
	// cerr<<"hay "<<count(ALL(valid),1)<<" numeros validos\n";
	const ll B1=20,B2=18;
	vv goods;
	fore(i,1,MAXV)if(valid[i])goods.pb(i);
	assert(SZ(goods)>>B2);
	// cerr<<"sz: "<<SZ(nums)<<"\n";
	// show(nums)
	// exit(0);
	string ty; cin>>ty;
	if(ty=="first"){
		ll t; cin>>t;
		while(t--){
			ll n; cin>>n;
			vv a(n);
			fore(i,0,n)cin>>a[i];
			vv bits;
			fore(i,0,n)fore(j,0,B1)bits.pb(a[i]>>j&1);
			vv b;
			for(ll s=0;s<SZ(bits);s+=B2){
				ll e=min(s+B2,(ll)SZ(bits));
				ll x=0;
				fore(i,0,e-s)x|=ll(bits[s+i])<<i;
				assert(x<SZ(goods));
				b.pb(goods[x]);
			}
			ll k=(n*10+8)/9;
			assert(SZ(b)<=k);
			for(auto i:nums)b.pb(i);
			cout<<SZ(b)<<"\n";
			show(b)
		}
	}
	else { // second
		ll t; cin>>t;
		while(t--){
			ll n,k; cin>>n>>k;
			vv bits;
			ll m=k-SZ(nums);
			// cerr<<"n k "<<n<<" "<<k<<"\n";
			fore(i,0,m){
				ll x=1;
				fore(j,m,k)x*=ask(i,j);
				x=lower_bound(ALL(goods),x)-goods.begin();
				fore(j,0,B2)bits.pb(x>>j&1);
			}
			vv a;
			for(ll s=0;s<SZ(bits);s+=B1){
				ll e=s+B1;
				if(e>SZ(bits)){
					fore(i,s,SZ(bits))assert(!bits[i]);
					break;
				}
				ll x=0;
				fore(i,0,B1)x|=ll(bits[s+i])<<i;
				a.pb(x);
			}
			// cerr<<"llego bits: "; dbg(bits)
			// cerr<<"llego a: "; dbg(a)
			assert(SZ(a)==n);
			cout<<"! "; show(a);
		}
	}
	return 0;
}
