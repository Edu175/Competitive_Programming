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
const ll MOD=1e9+7,MAXF=1e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
vv operator*(vv a, vv &b){
    fore(i,0,SZ(a))a[i]=mul(a[i],b[i]);
    return a;
}
vv multiply(vv a, vv b){
    vv c(SZ(a)+SZ(b)-1);
    fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
    return c;
}
vv eval(vv pol){
	ll n=SZ(pol);
	vv p(n);
    fore(i,0,n){
        ll pot=1;
        fore(j,0,n){
            p[i]=add(p[i],mul(pol[j],pot));
            pot=mul(pot,i);
        }
    }
	return p;
}
// vv interpolate(vv p){
// 	ll n=SZ(p);
// 	vv a()
// }
int main(){FIN;
    factos();
	ll n; cin>>n;
    vv F(n+1);
    fore(m,1,n+1){
        ll pot=fpow(m,m-1),inv=fpow(m,MOD-2);
        fore(k,1,m+1){
            pot=mul(pot,inv);
            F[m]=add(F[m],mul(pot,fci[m-k]));
        }
    }
    fore(i,0,n+1)cout<<mul(F[i],fc[i])<<" ";;cout<<"\n";
    vv p(n+1);
    fore(i,0,n+1){
        ll pot=1;
        fore(j,0,n+1){
            p[i]=add(p[i],mul(F[j],pot));
            pot=mul(pot,i);
        }
    }
    auto cur=p;
    auto pol=F;
    fore(k,1,n+1){
		cout<<"\n";
		cout<<k<<":\n";
		cout<<"pol: ";imp(pol)
		cout<<"eval: ";imp(eval(pol))
		cout<<"cur: ";imp(cur)
        ll coef=0;
        fore(i,0,n+1){
            coef=((n+i)&1?sub:add)(coef,mul(nCr(n,i),cur[i]));
        }
        cout<<coef<<"\n";
        cout<<mul(pol[n],fc[n])<<"\n";
		cout<<"antes\n";
        // coef=mul(coef,fci[n]);
        coef=mul(coef,fci[k]);
        cout<<coef<<"\n";
        cout<<mul(pol[n],mul(fc[n],fci[k]))<<"\n";
		cout<<"despues\n";
        cur=cur*p;
        pol=multiply(pol,F);
		// pol.resize(n+1);
    }
	return 0;
}