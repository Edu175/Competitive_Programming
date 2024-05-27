#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll n,h; cin>>n>>h;
	vector<ii>a(n);
	vector<ll>p(n);
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	sort(ALL(a));
	fore(i,0,n)p[a[i].snd]=i;
	vector<ll>pr,id(n),viv;
	fore(i,0,n){
		if(!i||a[i-1].fst<a[i].fst-h)pr.pb(1),viv.pb(1);
		else viv.back()++;
		id[i]=SZ(pr)-1;
	}
	imp(viv);
	vector<ll>is(n);
	ll res=1,q=SZ(pr);
	ll last=0;
	fore(i,0,n){
		ll x=p[i],k=id[x];
		ll ul=pr[k];
		if(!x||a[x-1].fst<a[x].fst-h)pr[k]=mul(pr[k],fpow(2,MOD-2));
		else if(is[x-1])pr[k]=mul(pr[k],mul(3,fpow(4,MOD-2)));
		if(x==n-1||a[x].fst+h<a[x+1].fst)pr[k]=mul(pr[k],fpow(2,MOD-2));
		else if(is[x+1])pr[k]=mul(pr[k],mul(3,fpow(4,MOD-2)));
		viv[k]--;
		is[x]=1;
		if(viv[k]==0)pr[k]=0;
		cout<<i<<": ";;for(auto i:pr)cout<<sub(1,i)<<" ";;cout<<"\n";
		if(ul!=pr[k]){
			if(ul!=1)res=mul(res,fpow(sub(1,ul),MOD-2));
			else q--;
			res=mul(res,sub(1,pr[k]));
			cout<<"changed\n";
		}
		cout<<ul<<" --> "<<pr[k]<<"\n";
		cout<<viv[k]<<"\n";
		cout<<last<<" -> "<<res<<"\n";
		ll resi=sub(res,last);
		if(q)cout<<"0 ",last=0;
		else cout<<mul(resi,fpow(2,n))<<" ",last=res;
		cout<<"\n\n";
	}
	cout<<"\n";
	return 0;
}
