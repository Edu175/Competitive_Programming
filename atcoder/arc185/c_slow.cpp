#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
const ll MAXN=4<<20;
typedef ll tf;
typedef vector<tf> poly;
const tf MOD=2305843009255636993,RT=5;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(__int128 a, __int128 b){return a*b%MOD;}
ll fpow(ll a, ll b){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
#define pm fpow
// NTT

struct CD {
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){return CD(mul(a.x,b.x));}
CD operator+(const CD& a, const CD& b){return CD(add(a.x,b.x));}
CD operator-(const CD& a, const CD& b){return CD(sub(a.x,b.x));}
vector<tf> rts(MAXN+9,-1);
CD root(int n, bool inv){
	tf r=rts[n]<0?rts[n]=pm(RT,(MOD-1)/n):rts[n];
	return CD(inv?pm(r,MOD-2):r);
}

CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		// double z=2*pi/m*(inv?-1:1); // FFT
		// CD wi=CD(cos(z),sin(z)); // FFT
		CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	// if(inv)fore(i,0,n)a[i]/=n; // FFT
	if(inv){ // NTT
		CD z(pm(n,MOD-2)); // pm: modular exponentiation
		fore(i,0,n)a[i]=a[i]*z;
	}
}
poly multiply(poly& p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	// fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	fore(i,0,n)res.pb(cp1[i].x); // NTT
	return res;
}
poly pote(poly &p, ll e){ // solo e=2 y e=3
	int n=SZ(p)*e+3;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0;
	fore(i,0,SZ(p))cp1[i]=p[i];
	dft(cp1,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp1[i]*(e==3?cp1[i]:CD(1));
	dft(cp1,m,true);
	poly res;
	fore(i,0,n)res.pb(cp1[i].x);
	return res;
}
const ll MAXV=1e6+5;
bool good(vv a, ll k, ll e){
	vv c(MAXV);
	for(auto i:a)c[i]++;
	fore(i,0,MAXV)c[i]=min(c[i],3ll);
	ll ban=k%3==0&&k/3<MAXV?c[k/3]:0;
	if(e==2)ban=k%2==0&&k/2<MAXV?c[k/2]:0;
	else {
		fore(i,0,MAXV){
			ll j=k-2*i;
			if(j!=i&&j>=0&&j<MAXV)ban=add(ban,mul(3,mul(c[i],c[j])));
		}
	}
	auto d=pote(c,e);
	ll res=sub(d[k],ban);
	return res>0;
}

int main(){FIN;
	ll n,k; cin>>n>>k; ll _k=k;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	if(!good(a,k,3)){
		cout<<"-1\n";
		return 0;
	}
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		vv b;
		fore(i,0,m+1)b.pb(a[i]);
		if(good(b,k,3))r=m-1;
		else l=m+1;
	}
	ll e=l;
	k-=a[l];
	l=0,r=e-1;
	while(l<=r){
		ll m=(l+r)/2;
		vv b;
		fore(i,m,e)b.pb(a[i]);
		if(good(b,k,2))l=m+1;
		else r=m-1;
	}
	ll s=r;
	k-=a[s];
	ll m=-1;
	fore(i,s+1,e)if(a[i]==k)m=i;
	cout<<s+1<<" "<<m+1<<" "<<e+1<<"\n";
	// cout<<endl;
	assert(_k==a[s]+a[m]+a[e]);
	return 0;
}
