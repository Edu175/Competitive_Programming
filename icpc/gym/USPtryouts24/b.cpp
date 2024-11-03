#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef ll tf;
typedef vector<tf> poly;
const tf MOD=998244353, RT=998244350,MAXN=1<<19;


ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll pm(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b),e>>=1;
	}
	return res;
}

ll addmod(ll a, ll b){return add(a,b);}
ll submod(ll a, ll b){return sub(a,b);}
ll mulmod(ll a, ll b){return mul(a,b);}
struct CD{
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a,const CD& b){return CD(mulmod(a.x,b.x));}
CD operator+(const CD& a,const CD& b){return CD(addmod(a.x,b.x));}
CD operator-(const CD& a,const CD& b){return CD(submod(a.x,b.x));}
vector<tf> rts(MAXN+9,-1);
CD root(int n,bool inv){
	tf r=rts[n]<0?rts[n]=pm(RT,(MOD-1)/n):rts[n];
	return CD(inv?pm(r,MOD-2):r);
}
CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a,int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		CD wi=root(m,inv);
	for(int j=0;j<n;j+=m){
		CD w(1);
		for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
			CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
		}
	}
	}
	if(inv){
		CD z(pm(n,MOD-2));
		fore(i,0,n)a[i]=a[i]*z;
	}
	
}

poly multiply(poly& p1, poly& p2){
	int n=SZ(p1)+SZ(p2)+1;
	int m=1,cnt=0;
	while(m<=n) m+=m,cnt++;
	
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,SZ(p1))cp1[i]=p1[i];
	fore(i,0,SZ(p2))cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	fore(i,0,n)res.pb(cp1[i].x);
	return res;
}

poly fpow(poly b, ll e, ll n){
	poly res={1};
	while(e){
		if(e&1)res=multiply(res,b);
		res.resize(n);
		b=multiply(b,b); e>>=1;
		b.resize(n);
		
	}
	return res;
}
const ll MAXF=MAXN;
ll fc[MAXF],fci[MAXF];

ll nCr(ll n, ll k){
	return mul(fc[n],mul(fci[k],fci[n-k]));
}

int main(){
	JET
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=pm(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
	
	
	ll t; cin>>t;
	while(t--){
		ll n,m,h; cin>>n>>m>>h;
		vector<ll>p(h+1);
		fore(i,1,h+1)p[i]=1;
		p=fpow(p,m+1,n+5);
		ll res=p[n+1];
		res=mul(res,pm(nCr(n,m),MOD-2));
		res=sub(1,res);
		cout<<res<<"\n";
	}
	return 0;
}