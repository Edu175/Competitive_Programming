#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7,MAXF=6e6+5;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=mul(ret,b);
		e>>=1,b=mul(b,b);
	}
	return ret;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(i,fc[i-1]);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}
ll nCr(ll n, ll k){
	if(n<0||k<0||n-k<0)return 0;
	return mul(fc[n],mul(fci[k],fci[n-k]));
}

// ll simul(ll u, ll z, ll i, ll e){ // ta bem
// 	ll res=0,ex=0,in=0;
// 	while(e--){
// 		if(u)u--,res++;
// 		else if(ex)ex--,res+=2;
// 		else if(z)ex++,z--;
// 	}
// 	// u+=ex; // =
// 	assert(!(u&&ex));
// 	while(i--){
// 		if(z)res++,z--,in++;
// 		else if(u)u--;
// 		else if(ex)ex--,res++;
// 		else if(in)in--,res--;
// 	}
// 	return res;
// }

int main(){
	ET
	factos();
	ll n,G,I,E; cin>>n>>G>>I>>E;
	if(G>=2*n){
		cout<<2*n<<"\n";
		return 0;
	}
	ll tot=nCr(2*n,G);
	// cout<<tot<<" tot\n";
	ll invtot=fpow(tot,MOD-2);
	ll res=0;
	ll sum=0;
	fore(d,0,n+5){
		ll u=G-2*d;
		if(u<0)continue;
		ll prob=mul(nCr(n,d),mul(nCr(n-d,u),fpow(2,u)));
		prob=mul(prob,invtot);
		if(!prob)continue;
		ll resi=G;
		ll e=E,z=(n-u-d); // z = parejas de 0
		// ll sol=G+simul(u,z,I,E);
		// cout<<e<<" e\n";
		ll U=u,Z=z;
		if(u>=e){
			// cout<<"primer if\n";
			resi+=e; u-=e;
			// no e
			ll i=I,q=min(i,z);
			// cout<<z<<" "<<q<<" z q\n";;
			ll in=q; i-=q;
			// cout<<i<<" i\n";
			ll me=q;
			q=min(i,u);
			// cout<<"salvo "<<q<<"\n";
			i-=q,u-=q;
			in-=min(i,me);
			assert(in>=0);
			resi+=in;
		}
		else {
			// cout<<"segundo if\n";
			resi+=u; e-=u; // g with e
			u=0;
			ll q=min(e/2,z),od=e&1; z-=q;
			resi+=2*q;
			if(z>0){
				// cout<<"pingo\n"<<od<<" od\n";
				if(od)z--;
				ll i=I,q=min(i,z);
				ll in=q; i-=q; u+=q;
				if(od&&i>0)i--,resi++;
				in-=min(i,u);
				assert(in>=0);
				resi+=in;
			}
		}
		// cout<<d<<" "<<U<<" "<<Z<<": "<<resi<<" "<<sol<<"\n";
		// sol-=7;
		// cout<<prob<<" prob\n";
		assert(resi<=2*n);
		sum=add(sum,prob);
		res=add(res,mul(prob,resi));
	}
	// cout<<sum<<" sum\n";
	cout<<res<<"\n";
}