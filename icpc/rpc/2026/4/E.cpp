#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) for(auto pera:v) cout<<pera<<" ";;cout<<endl;
#define imp2(v) for(auto [sandia,melon]:v) cout<<sandia<<","<<melon<<" ";;cout<<endl;
#define inp(v) for(auto &uva:v) cin>>uva;
#define inp2(v) for(auto &[fresa,mora]:v) cin>>fresa>>mora;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef __int128 xl;
typedef long double ld;
typedef vector<vv> mtx;

const ll bigmod=(1ull<<62)-(18ull<<32)+1;
const ll mod=bigmod;
// const ll mod=998244353;
ll addm(ll a, ll b){a+=b; return a<mod?a:a-mod;}
ll subm(ll a, ll b){a-=b; return a<0?a+mod:a;}
ll mulm(xl a, xl b){return a*b%mod;}
ll fp(ll a,ll e){ll r=1; for(;e;e>>=1){if(e&1)r=mulm(r,a);; a=mulm(a,a);}return r;}
ll inv(ll a){return fp(a,mod-2);}

const ll LG=22;
typedef vector<ll> poly;
template<class u, class uu, u p, u root>
struct FFT{
    u r[1+(2<<LG)];
    constexpr u m(u a, u b){
        uu k = uu(a)*b;
        #define op(g) g*(g*p+2)
        k+= u(k) * (op(op(op(op(op(-p)))))) * uu(p);
        #undef op
        return u(k>>(8*sizeof(u)));
    }
    constexpr u red(u k, u a){return a-k*(a>=k);}
    FFT() {
        u k=r[2<<LG]=-p%p, b=root, e=p>>LG;
        for(;e;e/=2,b=m(b,b)) if(e&1) k=m(k,b);
        for(int i=(2<<LG)-1;i>=0;i--) r[i]=red(p,m(r[i+1],k)),i&(i-1)?0:k=m(k,k);
    }
    poly cv(const poly &as, const poly &bs, u *v){
        int c=max(SZ(as)+SZ(bs)-1,0ll), n=1;
        assert(c<=(1<<LG));
        u h=u(uu(-p)*-p%p),a=m(h,p/2+1),x,y;
        while(n<c) n*=2,h=red(p,m(h,a));
        fore(i,0,n){
            v[i]=i<SZ(as)?u(as[i]):0,
            v[i+n]=i<SZ(bs)?u(bs[i]):0;
        }
        for(auto s:{v,v+n}) for(int j=n; j>=2; j--) for(int k=j&-j;k/=2;)fore(i,j-k,j){
            x=s[i],y=s[i-k];
            s[i-k]=red(2*p,x+y);
            s[i]=m(2*p+y-x,r[3*k-j+i]);
        }
        fore(i,0,n) v[i]=m(v[i],v[i+n]);
        fore(j,2,n+1) for(int k=1; !(k&j); k*=2) fore(i,j-k,j){
            x=m(v[i],r[3*k+j-i]);
            y=red(2*p,v[i-k]);
            v[i-k]=x+y,v[i]=2*p+y-x;
        }
        fore(i,0,c) v[i]=red(p,m(v[i],h));
        return poly(v,v+c);
    }
};
poly sdfhskdjfhCUADRATICO(const poly &as,const poly &bs){
	vv c(SZ(as)+SZ(bs)-1);
	fore(i,0,SZ(as))fore(j,0,SZ(bs))c[i+j]=addm(c[i+j],mulm(as[i],bs[j]));
	return c;
}
poly conv_small(const poly &as,const poly &bs){
	static uint32_t v[2<<LG];
    static FFT<uint32_t,uint64_t, 998244353, 3> fft;
    return fft.cv(as,bs,v);
}
poly conv_big(const poly &as,const poly &bs){
	static uint64_t v[2<<LG];
	static FFT<uint64_t, __uint128_t, bigmod, 3> fft;
	return fft.cv(as,bs,v);
}
poly multiply(const poly &as,const poly &bs){
	return conv_big(as,bs);
}

poly add(poly &a, poly &b){
	int n=SZ(a),m=SZ(b);
	poly ans(max(n,m));
	fore(i,0,max(n,m)) ans[i]=addm(i<SZ(a)?a[i]:0, i<SZ(b)?b[i]:0);
    while(SZ(ans)>1&&ans.back()==0) ans.pop_back();
	return ans;
}

poly takemod(poly &p, int n){
    poly res=p;
    res.resize(min(SZ(res),ll(n)));
    while(SZ(res)>1&&res.back()==0) res.pop_back();
    return res;
}

poly invert(poly &p, int d){
    assert(p[0]);
    poly res={inv(p[0])};
    int sz=1;
    while(sz<d){
        sz*=2;
        poly pre(p.begin(),p.begin()+min(SZ(p),ll(sz)));
        poly cur=multiply(res,pre);
        fore(i,0,SZ(cur)) cur[i]=subm(0,cur[i]);
        cur[0]=addm(cur[0],2);
        res=multiply(res,cur);
        res=takemod(res,sz);
    }
    res.resize(d);
    return res;
}
void checkpolys(poly &a){
    for(auto &b:a) assert(!b);
}
poly divide(poly &a, poly &b){
    int m=SZ(a), n=SZ(b);
    if(m<n) {
        checkpolys(a);
        return {0};
    }
    poly ap=a; reverse(ALL(ap));
    poly bp=b; reverse(ALL(bp));
    bp=invert(bp,m-n+1);
    poly q=multiply(ap,bp);
    q.resize(SZ(q)+m-n-SZ(q)+1,0);
    reverse(ALL(q));
    poly bq=multiply(b,q);
    fore(i,0,SZ(bq)) bq[i]=subm(0,bq[i]);
    poly r=add(a,bq); 
    checkpolys(r);
    return q; 
}

const ll MAXN=2e5+5;
void reduce(vv &v){
	while(SZ(v)>1&&!v.back())v.pop_back();
}
int main(){
    JET
	vv a(MAXN),b=a,c=a;
	ll A,B,C; cin>>A>>B>>C;
	fore(i,0,A){ll x; cin>>x; a[x]++;}
	fore(i,0,B){ll x; cin>>x; b[x]++;}
	fore(i,0,C){ll x; cin>>x; c[x]++;}
	reduce(a);
	reduce(b);
	reduce(c);
    for(auto &i:a)i=mulm(i,inv(A));
    for(auto &i:b)i=mulm(i,inv(B));
    for(auto &i:c)i=mulm(i,inv(C));
	
	poly prod=multiply(a,b);
	poly d=divide(prod,c);
	vv nonz;
	for(auto i:d)if(i)nonz.pb(i);
	ll D=-1;
	fore(i,1,MAXN){
		bool good=1;
		ll sum=0;
		for(auto j:nonz){
			j=mulm(j,i);
			sum+=j;
			if(j>i||sum>i){good=0;break;}
		}
		good&=sum==i;
		if(good){
			D=i;
			break;
		}
	}
	assert(D!=-1);
	vv ans;
	assert(!d[0]);
	fore(i,0,SZ(d)){
		ll cur=mulm(D,d[i]);
		fore(_,0,cur)ans.pb(i);
	}
	assert(SZ(ans)==D);
	cout<<D<<"\n";
	fore(i,0,SZ(ans)){
		if(i)cout<<" ";
		cout<<ans[i];
	}
	cout<<"\n";
	return 0;
}