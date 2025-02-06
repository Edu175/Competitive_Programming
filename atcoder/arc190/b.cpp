#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int MOD=998244353,MAXF=1e7+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(int i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
int nCr(int n, int k){ //must call factos before
	// assert(n>=0);
	if(k==0)return 1;
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
int main(){FIN;
	factos();
	int n,a,b; cin>>n>>a>>b;
	int q; cin>>q;
	vector<ii>par(4);
	vv curs(4);
	auto actu=[&](ll w, ll n, ll k){
		ll dl=k,dr=n;
		auto &l=par[w].fst;
		auto &r=par[w].snd;
		auto &cur=curs[w];
		while(l>dl){
			cur=sub(cur,nCr(r,--l));
		}
		while(r<dr){
			cur=add(cur,cur);
			cur=sub(cur,nCr(r,l-1));
			(r++);
		}
		while(l<dl){
			cur=add(cur,nCr(r,l++));
		}
		while(r>dr){
			(--r);
			cur=add(cur,nCr(r,l-1));
			cur=mul(cur,(MOD+1)/2);
		}
	};
	while(q--){
		int k; cin>>k;
		int mov=n-k;
		int x1=a-k,x2=a-1;
		int y1=b-k,y2=b-1;
		if(k==1){
			cout<<mul(nCr(mov,x2),nCr(mov,y2))<<"\n";
			continue;
		}
		// swap(x1,x2);
		// swap(y1,y2);
		ll cur=0;
		cur=sub(cur,mul(nCr(mov,x1),nCr(mov,y1)));
		cur=sub(cur,mul(nCr(mov,x1),nCr(mov,y2)));
		cur=sub(cur,mul(nCr(mov,x2),nCr(mov,y1)));
		cur=sub(cur,mul(nCr(mov,x2),nCr(mov,y2)));
		
		actu(0,mov,x2+1);
		actu(1,mov,x1);
		
		actu(2,mov,y2+1);
		actu(3,mov,y1);

		int now=0;
		// cout<<x1<<" "<<x2<<" xs\n";
		// cout<<y1<<" "<<y2<<" ys\n";
		// cout<<sub(0,cur)<<" -cur\n";
		ll sum=sub(curs[0],curs[1]);
		// cout<<ans[dep[0]]<<" "<<ans[dep[1]]<<" dep0 dep1\n";
		// cout<<sum<<" sum1\n";
		now=add(now,mul(add(nCr(mov,y2),nCr(mov,y1)),sum));
		// cout<<now<<" now1\n";
		sum=sub(curs[2],curs[3]);
		// cout<<sum<<" sum2\n";
		now=add(now,mul(add(nCr(mov,x2),nCr(mov,x1)),sum));
		// cout<<now<<" now1+now2\n";	
		cur=add(cur,mul(2,now));
		cur=mul(cur,fpow(4,k-2));
		cout<<cur<<"\n";
	}
	return 0;
}
