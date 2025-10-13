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

// fake, no se puede
// tengo un ^w despues de la suma
// que quiero intercambiar con la de c0+c1+c2=h
// que es la del fft, entonces no se puede meter adentro esa suma
// que es donde se estan multiplicando los coeficientes de los ci

const ll MOD=1e9+9;
const ll rt=884618610; // 3rd root of unity
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=1e6+5;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll inv(ll a){assert(a);return fpow(a,MOD-2);}

int main(){FIN;
	factos();
	ll h,w,k; cin>>h>>w>>k;
	// vv rts={1,rt,mul(rt,rt)};
	assert(fpow(rt,3)==1);
	vector<vector<vv>> coef(3,vector<vv>(3,vv(h+1))); // f,g,c
	fore(f,0,3)fore(g,0,3)fore(c,0,h+1){
		auto &res=coef[f][g][c];
		ll r=fpow(rt,g+f);
		ll sum=k+1;
		if(r!=1){
			ll num=sub(fpow(r,k+1),1);
			ll den=sub(r,1);
			sum=mul(num,inv(den));
		}
		sum=fpow(sum,c[g]);
	}
	res=mul(res,fc[h]);
	res=mul(res,inv(fpow(3,w+h)));
	cout<<res<<"\n";
	return 0;
}
