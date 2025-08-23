#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int MAXN = 1<<17;
typedef ll tf;
typedef vector<tf> poly;
const tf MOD=998244353, RT = 3;

ll addmod(ll a, ll b){
	a+=b;
	return a<MOD?a:a-MOD;
}
ll mulmod(LL a, LL b){return a*b%MOD;}
ll submod(ll a, ll b){
	a-=b;
	return a<0?a+MOD:a;
}

ll pm(ll b, int e){
	ll r=1;
	while(e){if(e&1) r=mulmod(r,b); b=mulmod(b,b); e>>=1;}
	return r;
}
// struct CD{
// 	double r,i;
// 	CD(double r =0 , double i =0):r(r),i(i){}
// 	double real()const{return r;}
// 	void operator/=(const int c){r/=c,i/=c;}	
// };
// CD operator*(const CD& a,const CD& b){
// 	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
// }
// CD operator+(const CD& a, const CD& b){
// 	return CD(a.r+b.r,a.i+b.i);
// }
// CD operator-(const CD& a, const CD& b){
// 	return CD(a.r-b.r,a.i-b.i);
// }
//concha de edu

struct CD{
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){
	return CD(mulmod(a.x,b.x));
}
CD operator+(const CD& a, const CD& b){
	return CD(addmod(a.x,b.x));
}
CD operator-(const CD& a, const CD& b){
	return CD(submod(a.x,b.x));
}
vector<tf> rts(MAXN+9,-1);
CD root(int n, bool inv){
	tf r = rts[n]<0 ? rts[n] = pm(RT, (MOD-1)/n) : rts[n];
	return CD(inv ? pm(r,MOD-2):r);
}
CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n) if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m = 2;m<=n;m*=2){
		// double z = 2*pi/m * (inv? -1 : 1);
		// CD wi = CD(cos(z),sin(z));
		CD wi = root(m,inv);
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k = j,k2 = j+m/2;k2<j+m;k++,k2++){
				CD u = a[k]; CD v = a[k2] * w;
				a[k] = u+v;
				a[k2] = u-v;
				w = w*wi;
			}
		}
	}
	if(inv){
		CD z(pm(n,MOD-2));
		fore(i,0,n) a[i] = a[i]*z;
	}
}
void multiply(poly& p1, poly& p2){
	int n = SZ(p1)+SZ(p2)+1;
	int m = 1,cnt = 0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){
		R[i]=0;
		fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);
	}
	fore(i,0,m) cp1[i] =0 , cp2[i] = 0;
	fore(i,0,SZ(p1)) cp1[i] = p1[i];
	fore(i,0,SZ(p2)) cp2[i] = p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i] = cp1[i] * cp2[i];
	dft(cp1,m,true);
	fore(i,0,SZ(p1)) p1[i]=cp1[i].x;
}
short mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN) if(mu[i]) for(int j=(i<<1); j<MAXN; j+=i) mu[j]-=mu[i];
}

int main(){
	JET
	ll n,m; 
	cin>>n>>m;
	ii lr[n];
	fore(i,0,n) cin>>lr[i].fst>>lr[i].second;
	mobius();
	ll rta=0;
	poly p= poly(m+1,0); 
	poly p1= poly(m+1,0); 
	fore(g,1,m+1)if(mu[g]){
		ll mm=m/g;
		p.resize(mm+1);
		p1.resize(mm+1);
		fore(i,1,mm+1) p[i]=0;
		p[0]=1;
		fore(i,0,n){
			fore(i,0,mm+1) p1[i]=0;
			fore(j,(lr[i].fst+g-1)/g,(lr[i].snd)/g +1) p1[j]=1;
			multiply(p,p1);
			p.resize(mm+1);
			p1.resize(mm+1);
		}
		fore(i,0,mm+1)rta=(mu[g]>0?addmod(rta,p[i]):submod(rta,p[i]));
	}
	cout<<rta<<"\n";
	return 0;
}