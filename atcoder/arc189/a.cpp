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
const ll MOD=998244353,MAXN=1<<21;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int pm(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=1e6;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=pm(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
// typedef ll tf;
// typedef vector<tf> poly;
// const tf RT=5;

// struct CD {
// 	tf x;
// 	CD(tf x):x(x){}
// 	CD(){}
// };
// CD operator*(const CD& a, const CD& b){return CD(mul(a.x,b.x));}
// CD operator+(const CD& a, const CD& b){return CD(add(a.x,b.x));}
// CD operator-(const CD& a, const CD& b){return CD(sub(a.x,b.x));}
// vector<tf> rts(MAXN+9,-1);
// CD root(int n, bool inv){
// 	tf r=rts[n]<0?rts[n]=pm(RT,(MOD-1)/n):rts[n];
// 	return CD(inv?pm(r,MOD-2):r);
// }

// CD cp1[MAXN+9],cp2[MAXN+9];
// int R[MAXN+9];
// void dft(CD* a, int n, bool inv){
// 	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
// 	for(int m=2;m<=n;m*=2){
// 		// double z=2*pi/m*(inv?-1:1); // FFT
// 		// CD wi=CD(cos(z),sin(z)); // FFT
// 		CD wi=root(m,inv); // NTT
// 		for(int j=0;j<n;j+=m){
// 			CD w(1);
// 			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
// 				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
// 			}
// 		}
// 	}
// 	// if(inv)fore(i,0,n)a[i]/=n; // FFT
// 	if(inv){ // NTT
// 		CD z(pm(n,MOD-2)); // pm: modular exponentiation
// 		fore(i,0,n)a[i]=a[i]*z;
// 	}
// }
// poly multiply(poly& p1, poly& p2){
// 	int n=p1.size()+p2.size()+1;
// 	int m=1,cnt=0;
// 	while(m<=n)m+=m,cnt++;
// 	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
// 	fore(i,0,m)cp1[i]=0,cp2[i]=0;
// 	fore(i,0,p1.size())cp1[i]=p1[i];
// 	fore(i,0,p2.size())cp2[i]=p2[i];
// 	dft(cp1,m,false);dft(cp2,m,false);
// 	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
// 	dft(cp1,m,true);
// 	poly res;
// 	n-=2;
// 	// fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
// 	fore(i,0,n)res.pb(cp1[i].x); // NTT
// 	return res;
// }
// poly merge(poly a, poly b){
// 	fore(i,0,SZ(a))a[i]=mul(a[i],fci[i]);
// 	fore(i,0,SZ(b))b[i]=mul(b[i],fci[i]);
// 	auto c=multiply(a,b);
// 	fore(i,0,SZ(c))c[i]=mul(c[i],fc[i]);
// 	return c;
// }

int main(){FIN;
	factos();
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	if(!a[0]){
		cout<<"0\n";
		return 0;
	}
	vv dfc(n+1,1);
	fore(i,2,n+1)dfc[i]=mul(dfc[i-2],i-2);
	vv b;
	ll q=0,flag=1;
	fore(i,0,n){
		q++;
		if(i==n-1||a[i]!=a[i+1])b.pb(q),flag&=q&1,q=0;
	}
	if(!flag){
		cout<<"0\n";
		return 0;
	}
	// cout<<"pingo\n";
	ll res=1,ops=0;
	for(auto i:b){
		res=mul(res,dfc[i]);
		ll op=i/2;
		res=mul(res,nCr(ops+op,op));
		ops+=op;
	}
	cout<<res<<"\n";
	return 0;
}
