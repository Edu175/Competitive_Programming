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
 
ll jere = 1;
void caso(){cout<<"Case #"<<jere++<<": ";}

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a, ll b, ll m) {
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}
ll expmod(ll b, ll e, ll m){
	if(!e)return 1;
	ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
	if(n==a)return true;
	ll s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	fore(_,0,s-1){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(ll n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
	return true;
}
// optimized version: replace rho and fact with the following:
const int MAXP=1e6+1; // sieve size
int sv[MAXP]; // sieve
ll add(ll a, ll b, ll m){return (a+=b)<m?a:a-m;}
ll rho(ll n){
	static ll s[MAXP];
	while(1){
		ll x=rand()%n,y=x,c=rand()%n;
		ll *px=s,*py=s,v=0,p=1;
		while(1){
			*py++=y=add(mulmod(y,y,n),c,n);
			*py++=y=add(mulmod(y,y,n),c,n);
			if((x=*px++)==y)break;
			ll t=p;
			p=mulmod(p,abs(y-x),n);
			if(!p)return gcd(t,n);
			if(++v==26){
				if((p=gcd(p,n))>1&&p<n)return p;
				v=0;
			}
		}
		if(v&&(p=gcd(p,n))>1&&p<n)return p;
	}
}
void init_sv(){
	fore(i,2,MAXP)if(!sv[i])for(ll j=i;j<MAXP;j+=i)sv[j]=i;
}
void fact(ll n, map<ll,int>& f){ // call init_sv first!!!
	for(auto&& p:f){
		while(n%p.fst==0){
			p.snd++;
			n/=p.fst;
		}
	}
	if(n<MAXP)while(n>1)f[sv[n]]++,n/=sv[n];
	else if(rabin(n))f[n]++;
	else {ll q=rho(n);fact(q,f);fact(n/q,f);}
}


void div_rec(vector<pair<ll,vv>>& r, vector<ii>& f, int k, ll c, vector<ll>ve){
	if(k==SZ(f)){
        r.pb({c,ve});
        return;
    }
	fore(i,0,f[k].snd+1){
        div_rec(r,f,k+1,c,ve),c*=f[k].fst,ve[k]++;
    }
}
vector<pair<ll,vv>> divisors(vector<ii> f){
	vector<pair<ll,vv>> r; // returns divisors given factorization
    vector<ll> ve(SZ(f),0);
	div_rec(r,f,0,1,ve);
	return r;
}

const int mod = 1e9+7;
ll exp(ll x, ll b){
    if(b == 0) return 1;
    ll k = exp(x,b/2);
    k=(k*k)%mod;
    if(b&1) k=(k*x)%mod;
    return k;
}


int add(int a, int b){a+=b;if(a>=mod)a-=mod;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=mod;return a;}
int mul(ll a, ll b){return a*b%mod;}
const int MAXF = 100;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=exp(fc[MAXF-1],mod-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}




int main(){
    JET
    ll t; cin>>t;
    factos();
    while(t--){
        ll n,a,b; cin>>n>>a>>b;
        init_sv();
        map<ll,int> f;
        vector<ii> v;
        fact(b,f);
        for(auto [p,cnt] : f) v.pb({p,cnt});
        ll tot = 0;
        for(auto [p,cnt] : v) tot+=cnt;
        vector<pair<ll,vv>> divs = divisors(v);
        ll rta = 0;
        // cout<<"tot es "<<tot<<"\n";
        ll cyb[100], ar[100], aux = n;
        cyb[0] = 1, ar[0] = 1;
		aux%=mod;
        fore(i,1,100){
            ar[i] = (ar[i-1] * aux++);
            // cout<<"ar "<<i<<" es "<<ar[i]<<" pq antes era "<<ar[i-1]<<endl;
            ar[i] = ar[i] %mod;
            cyb[i] = ar[i] * fci[i];
            cyb[i] %= mod;
            // cout<<"cyb "<<i<<" "<<cyb[i]<<endl;
        }
        for(auto [d,ve] : divs){
            if(d <= a){
                // cout<<"entrando a "<<d<<endl;
                ll loc = 1;
                fore(i,0,SZ(f)){
                    assert(ve[i]<100 && i<SZ(ve));
                    loc = (loc* cyb[ve[i]]) %mod;
                    loc = (loc * cyb[v[i].snd - ve[i]])%mod;
                    // cout<<"veo el primo "<<i<<" hay en total "<<v[i].snd<<" y este tiene "<<ve[i]<<endl;
                }
                rta += loc;
                rta%=mod;
            }
            // else cout<<d<<" no entra\n";
        }
        caso();
        cout<<rta<<"\n";
    }
    return 0;
}
