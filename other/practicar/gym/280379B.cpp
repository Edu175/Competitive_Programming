#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

// Inverse: O(n*log(n))
const int MAXN=1<<20;
typedef int tf;
typedef vector<tf> poly;
const tf MOD=998244353,RT=5;
struct CD {
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
int addm(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int subm(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mulm(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mulm(r,a); b>>=1; a=mulm(a,a);}
	return r;
}
int inv(int a){return fpow(a,MOD-2);}
CD operator*(const CD& a, const CD& b){return CD(mulm(a.x,b.x));}
CD operator+(const CD& a, const CD& b){return CD(addm(a.x,b.x));}
CD operator-(const CD& a, const CD& b){return CD(subm(a.x,b.x));}
vector<tf> rts(MAXN+9,-1);
CD root(int n, bool inv){
	tf r=rts[n]<0?rts[n]=fpow(RT,(MOD-1)/n):rts[n];
	return CD(inv?fpow(r,MOD-2):r);
}
CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
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
		CD z(fpow(n,MOD-2));
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
	fore(i,0,n)res.pb(cp1[i].x);
	return res;
}

poly add(poly &a, poly &b){
	int n=SZ(a),m=SZ(b);
	poly ans(max(n,m));
	fore(i,0,max(n,m)) ans[i]=addm(i<SZ(a)?a[i]:0, i<SZ(b)?b[i]:0);
	while(SZ(ans)>1&&!ans.back())ans.pop_back();
	return ans;
}

// p % (x^n)
poly takemod(poly &p, int n){
	poly res=p;
	res.resize(min(SZ(res),n));
	while(SZ(res)>1&&res.back()==0) res.pop_back();
	return res;
}

// first d terms of 1/p
poly invert(poly &p, int d){
	assert(p[0]);
	poly res={inv(p[0])};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly pre(p.begin(), p.begin()+min(SZ(p),sz));
		poly cur=multiply(res,pre);
		fore(i,0,SZ(cur)) cur[i]=subm(0,cur[i]);
		cur[0]=addm(cur[0],2);
		res=multiply(res,cur);
		res=takemod(res,sz);
	}
	res.resize(d);
	return res;
}

poly operator*(tf c, poly p){
	for(auto &i:p)i=mulm(i,c);
	return p;
}
const ll MAXF=MAXN;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mulm(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mulm(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mulm(mulm(fc[n],fci[k]),fci[n-k]);
}
int main(){FIN;
	factos();
	ll n,k; cin>>n>>k;
	ll d=n+1;
	poly f(d);
	fore(i,1,d)if(i%k==0)f[i]=1;
	fore(i,0,d)f[i]=mulm(f[i],fci[i]);
	auto tmp=multiply(f,f);
 	tmp=(MOD-1)*takemod(tmp,d);
	assert(!tmp[0]); tmp[0]++;
	
	tmp=invert(tmp,d);
	auto num=(MOD-1)*f;
	assert(!num[0]); num[0]++;
	
	auto ans=multiply(num,tmp);
	ans.resize(d);
	
	if((n/k)&1)for(auto &i:ans)i=subm(0,i);
	
	fore(i,0,d)ans[i]=mulm(ans[i],fc[i]);
	if(n%k==0){
		cout<<ans[n]<<"\n";
	}
	else {
		ll r=n%k,res=0;
		for(ll z=r;z<=n;z+=k){
			ll resi=mulm(nCr(n,z),ans[n-z]);
			res=addm(res,resi);
			// res=(1?addm:subm)(res,resi);
			// cout<<z<<": "<<sig<<" "<<resi<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}