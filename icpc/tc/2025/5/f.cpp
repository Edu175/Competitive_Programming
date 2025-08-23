#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b); e>>=1;
	}
	return res;
}
ll dpg[15][15][15][15][15];
// c es cantidad de positivos
// b es bloques positivos
// g es dado que ya tengo al menos 30 elementos
// fg es si hay un 0 al final
ll g(ll s, ll v, ll b, ll u, ll c, ll fg){ // quedan
	if(s<0||v<0||b<0||c<0)return 0;
	auto &res=dpg[s][v][b][u][c];
	if(res!=-1)return res;
	if(s==0&&v==0){
		if(b||c)return res=0;
		if(fg){
			if(u==0)return res=1;
			// else dejo que lo ponga
		}
		else {
			return res=u!=0;
		}
	}
	res=0;
	fore(j,1,60){
		if(j>s)break;
		res=add(res,g(s-j,v-(j>u),b-(u==0),j,c-1,fg));
	}
	if(u){ // no voy a poner dos ceros seguidos
		// veo de poner un cero dado que el anterior es positivo
		res=add(res,g(s,v,b,0,c,fg));
	}
	// if(res)cerr<<"g "<<s<<" "<<v<<" "<<b<<" "<<u<<" "<<c<<" "<<fg<<": "<<res<<"\n";
	return res;
}

ll fci[50];

ll nCr(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	ll res=1;
	fore(i,0,k)res=mul(res,n-i);
	res=mul(res,fci[k]);
	return res;
}
ll ceb(ll c, ll b){
	return nCr(c+b-1,c-1);
}
ll n;
// const ll COT=5;
const ll COT=11;
ll dpf[35][15][15][15];
ll f(ll i, ll s, ll v, ll u){
	if(s<0||v<0)return 0;
	assert(i<25);
	auto &res=dpf[i][s][v][u];
	if(res!=-1)return res;
	if(s==0&&v==0)return res=1;
	if(i==n)return res=0;
	bool sepaso=i>=COT;
	res=0;
	if(sepaso){
		// los 0s los mando a g
		ll m=n-i-1;
		fore(b,0,s+1)fore(c,0,s+1)fore(fg,0,2){
			ll num=g(s,v,b,0,c,fg),coef=ceb(b+fg,m-c-(b-1)-fg);
			ll term=mul(coef,num);
			// if(num){
			// 	cerr<<"num "<<i<<" "<<s<<" "<<v<<" "<<u<<": "<<b<<" "<<c<<": "<<coef<<" "<<num<<"| "<<m-c+b<<","<<b<<"\n";
			// }
			res=add(res,term);
		}
	}
	fore(j,sepaso,i+1){
		if(j>s)break;
		res=add(res,f(i+1,s-j,v-(j>u),j));
	}
	return res;
}
int main(){
	JET
	mset(dpg,-1);
	mset(dpf,-1);
	ll acum=1;
	fore(i,0,50){
		if(i)acum=mul(acum,i);
		fci[i]=fpow(acum,MOD-2);
		// cout<<fci[i]<<"\n";
	}
	ll t; cin>>t;
	// vector<array<ll,4>>qs(t);
	// fore(i,0,t){
	// 	ll n,k,x; cin>>n>>k>>x;
	// 	qs[i]={n,k,x,i};
	// }
	// sort(ALL(qs));
	// vv ans(t);
	// for(auto [_n,k,x,idx]:qs){
	while(t--){
		ll k,x; cin>>n>>k>>x;
		if(1){
			fore(i,0,25)fore(j,0,k+1)fore(l,0,x+1)fore(m,0,i+1){
				dpf[i][j][l][m]=-1;
			}
			// mset(dpg,-1);
		}
		ll res=f(0,k,x,0);
		cout<<res<<"\n";
		// ans[idx]=res;
	}
	// fore(i,0,t)cout<<ans[i]<<"\n";
	return 0;
}