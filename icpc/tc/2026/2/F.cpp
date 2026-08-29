#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e6+3;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b); e>>=1;
	}
	return res;
}
ll inv(ll a){return fpow(a,MOD-2);}
ll ask(ll x){
	cout<<"? "<<x<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}
void red(vv &a){
	while(SZ(a)>1&&!a.back())a.pop_back();
}
vv multiply(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
	red(c);
	return c;
}
vv add(vv a, vv b){
	vv c(max(SZ(a),SZ(b)));
	fore(i,0,SZ(a))c[i]=add(c[i],a[i]);
	fore(i,0,SZ(b))c[i]=add(c[i],b[i]);
	red(c);
	return c;
}
ll eval(vv a, ll x){
	reverse(ALL(a));
	ll res=0;
	for(auto c:a)res=add(mul(res,x),c);
	return res;
}
int main(){
	JET
	ll n=12;
	vv f(n);
	fore(i,0,n)f[i]=ask(i);
	// cerr<<"f "; show(f)
	vv pol={0};
	fore(i,0,n){
		vv cur={1};
		fore(j,0,n)if(i!=j)cur=multiply(cur,{sub(0,j),1});
		ll coef=inv(eval(cur,i));
		coef=mul(coef,f[i]);
		for(auto &i:cur)i=mul(i,coef);
		pol=add(pol,cur);
		// cerr<<i<<": "; show(cur)
	}
	// cerr<<"pol: ";;show(pol)
	fore(x,0,MOD){
		if(!eval(pol,x)){
			cout<<"! "<<x<<endl;
			return 0;
		}
	}
	cout<<"! -1"<<endl;
	return 0;
}
