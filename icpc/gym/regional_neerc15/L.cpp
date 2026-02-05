#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef __int128 xl;
const ll maxn=1e5+5,INF=2e18;
ll N,w;
ll h[maxn],p1[maxn],p2[maxn],sp[maxn];
vv qu[maxn];
typedef ii nd;
nd oper(nd a, nd b){
	return {max(a.fst,b.fst),min(a.snd,b.snd)};
}
const nd NEUT={-1,maxn};

void act(nd &a, nd v){
	if(v.fst!=-1) a.fst=v.fst;
	if(v.snd!=-1) a.snd=v.snd;
}

struct STree{
	nd t[2*maxn+5];
	STree() {
		fore(i,0,2*maxn+5) t[i]=NEUT;
	}
	void upd(int p, nd v){
		for(p+=w,act(t[p],v);p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	nd query(int l, int r){
		nd izq=NEUT, der=NEUT;
		for(l+=w,r+=w; l<r; l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
STree st;

void BB(ll &l,ll &r,const ll &i){
	ll m=(l+r)>>1;
	if(m==h[i]){l++; return;}
	//segmentree
	
	ll it=lower_bound(p1,p1+w,m-i)-p1;
	ll j1=st.query(it,w).fst;
	
	it=lower_bound(p2,p2+w,m+i)-p2;
	ll j2=min(st.query(it,w).snd,w);
	if(j2==w || j1==-1) {
		// cout<<i<<"i "<<m<<"m "<<j1<<"j1 "<<j2<<"j2 "<<sp[j2]-sp[j1+1]<<"sum \n";
		r=m-1; return;
	}
	xl c=xl(m)*m;
	c-=( xl(m-(i-j1)) * (m-(i-j1)+1) + xl(m-(j2-i)) * (m-(j2-i)+1))>>1;
	// cout<<i<<"i "<<m<<"m "<<j1<<"j1 "<<j2<<"j2 "<<sp[j2]-sp[j1+1]<<"sum "<<ll(c)<<"tr\n";
	c-=sp[j2]-sp[j1+1];
	
	if(c<=N) l=m+1;

	else r=m-1;

}

int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("landscape.in","r",stdin);     freopen("landscape.out","w",stdout);
	#endif
	cin>>w>>N;
	fore(i,0,w){
		cin>>h[i];
		sp[i+1]=sp[i]+h[i];
		p1[i]=h[i]-i;
		p2[i]=h[i]+i;
	}
	sort(p1,p1+w);sort(p2,p2+w);
	
	fore(i,0,w) qu[i].pb(maxn);
	for(ll i=w-1; i>=0; i--){
		ll it=lower_bound(p2,p2+w,h[i]+i)-p2;
		qu[it].pb(i);
	}
	fore(i,0,w) st.upd(i,nd({-1,qu[i].back()}));
	ll rta=0;
	fore(i,0,w){
		ll l=h[i], r=INF;
		ll it=lower_bound(p2,p2+w,h[i]+i)-p2;
		qu[it].pop_back();
		st.upd(it,nd({-1,qu[it].back()}));
		
		while(l<=r){
			BB(l,r,i);
		}
		rta=max(rta,r);
		
		
		it=lower_bound(p1,p1+w,h[i]-i)-p1;
		st.upd(it,nd({i,-1}));
	}
	cout<<rta<<"\n";	
	return 0;
}

// 8 4
// 3
// 4
// 2
// 1
// 3
// 3
// 2
// 4
// 0i 1000000000000000001m -1j1 8j2 22sum 
// 0i 500000000000000001m -1j1 8j2 22sum 
// 0i 250000000000000001m -1j1 8j2 22sum 
// 0i 125000000000000001m -1j1 8j2 22sum 
// 0i 62500000000000001m -1j1 8j2 22sum 
// 0i 31250000000000001m -1j1 8j2 22sum 
// 0i 15625000000000001m -1j1 8j2 22sum 
// 0i 7812500000000001m -1j1 8j2 22sum 
// 0i 3906250000000001m -1j1 8j2 22sum 
// 0i 1953125000000001m -1j1 8j2 22sum 
// 0i 976562500000001m -1j1 8j2 22sum 
// 0i 488281250000001m -1j1 8j2 22sum 
// 0i 244140625000001m -1j1 8j2 22sum 
// 0i 122070312500001m -1j1 8j2 22sum 
// 0i 61035156250001m -1j1 8j2 22sum 
// 0i 30517578125001m -1j1 8j2 22sum 
// 0i 15258789062501m -1j1 8j2 22sum 
// 0i 7629394531251m -1j1 8j2 22sum 
// 0i 3814697265626m -1j1 8j2 22sum 
// 0i 1907348632814m -1j1 8j2 22sum 
// 0i 953674316408m -1j1 8j2 22sum 
// 0i 476837158205m -1j1 8j2 22sum 
// 0i 238418579103m -1j1 8j2 22sum 
// 0i 119209289552m -1j1 8j2 22sum 
// 0i 59604644777m -1j1 8j2 22sum 
// 0i 29802322389m -1j1 8j2 22sum 
// 0i 14901161195m -1j1 8j2 22sum 
// 0i 7450580598m -1j1 8j2 22sum 
// 0i 3725290300m -1j1 8j2 22sum 
// 0i 1862645151m -1j1 8j2 22sum 
// 0i 931322576m -1j1 8j2 22sum 
// 0i 465661289m -1j1 8j2 22sum 
// 0i 232830645m -1j1 8j2 22sum 
// 0i 116415323m -1j1 8j2 22sum 
// 0i 58207662m -1j1 8j2 22sum 
// 0i 29103832m -1j1 8j2 22sum 
// 0i 14551917m -1j1 8j2 22sum 
// 0i 7275959m -1j1 8j2 22sum 
// 0i 3637980m -1j1 8j2 22sum 
// 0i 1818991m -1j1 8j2 22sum 
// 0i 909496m -1j1 8j2 22sum 
// 0i 454749m -1j1 8j2 22sum 
// 0i 227375m -1j1 8j2 22sum 
// 0i 113688m -1j1 8j2 22sum 
// 0i 56845m -1j1 8j2 22sum 
// 0i 28423m -1j1 8j2 22sum 
// 0i 14212m -1j1 8j2 22sum 
// 0i 7107m -1j1 8j2 22sum 
// 0i 3554m -1j1 8j2 22sum 
// 0i 1778m -1j1 8j2 22sum 
// 0i 890m -1j1 8j2 22sum 
// 0i 446m -1j1 8j2 22sum 
// 0i 224m -1j1 8j2 22sum 
// 0i 113m -1j1 8j2 22sum 
// 0i 57m -1j1 8j2 22sum 
// 0i 29m -1j1 8j2 22sum 
// 0i 15m -1j1 8j2 22sum 
// 0i 8m -1j1 8j2 22sum 
// 0i 5m -1j1 8j2 22sum 
// 0i 4m -1j1 8j2 22sum 
// 1i 1000000000000000002m -1j1 8j2 22sum 
// 1i 500000000000000002m -1j1 8j2 22sum 
// 1i 250000000000000002m -1j1 8j2 22sum 
// 1i 125000000000000002m -1j1 8j2 22sum 
// 1i 62500000000000002m -1j1 8j2 22sum 
// 1i 31250000000000002m -1j1 8j2 22sum 
// 1i 15625000000000002m -1j1 8j2 22sum 
// 1i 7812500000000002m -1j1 8j2 22sum 
// 1i 3906250000000002m -1j1 8j2 22sum 
// 1i 1953125000000002m -1j1 8j2 22sum 
// 1i 976562500000002m -1j1 8j2 22sum 
// 1i 488281250000002m -1j1 8j2 22sum 
// 1i 244140625000002m -1j1 8j2 22sum 
// 1i 122070312500002m -1j1 8j2 22sum 
// 1i 61035156250002m -1j1 8j2 22sum 
// 1i 30517578125002m -1j1 8j2 22sum 
// 1i 15258789062502m -1j1 8j2 22sum 
// 1i 7629394531252m -1j1 8j2 22sum 
// 1i 3814697265627m -1j1 8j2 22sum 
// 1i 1907348632815m -1j1 8j2 22sum 
// 1i 953674316409m -1j1 8j2 22sum 
// 1i 476837158206m -1j1 8j2 22sum 
// 1i 238418579104m -1j1 8j2 22sum 
// 1i 119209289553m -1j1 8j2 22sum 
// 1i 59604644778m -1j1 8j2 22sum 
// 1i 29802322390m -1j1 8j2 22sum 
// 1i 14901161196m -1j1 8j2 22sum 
// 1i 7450580599m -1j1 8j2 22sum 
// 1i 3725290301m -1j1 8j2 22sum 
// 1i 1862645152m -1j1 8j2 22sum 
// 1i 931322577m -1j1 8j2 22sum 
// 1i 465661290m -1j1 8j2 22sum 
// 1i 232830646m -1j1 8j2 22sum 
// 1i 116415324m -1j1 8j2 22sum 
// 1i 58207663m -1j1 8j2 22sum 
// 1i 29103833m -1j1 8j2 22sum 
// 1i 14551918m -1j1 8j2 22sum 
// 1i 7275960m -1j1 8j2 22sum 
// 1i 3637981m -1j1 8j2 22sum 
// 1i 1818992m -1j1 8j2 22sum 
// 1i 909497m -1j1 8j2 22sum 
// 1i 454750m -1j1 8j2 22sum 
// 1i 227376m -1j1 8j2 22sum 
// 1i 113689m -1j1 8j2 22sum 
// 1i 56846m -1j1 8j2 22sum 
// 1i 28424m -1j1 8j2 22sum 
// 1i 14213m -1j1 8j2 22sum 
// 1i 7108m -1j1 8j2 22sum 
// 1i 3555m -1j1 8j2 22sum 
// 1i 1779m -1j1 8j2 22sum 
// 1i 891m -1j1 8j2 22sum 
// 1i 447m -1j1 8j2 22sum 
// 1i 225m -1j1 8j2 22sum 
// 1i 114m -1j1 8j2 22sum 
// 1i 58m -1j1 8j2 22sum 
// 1i 30m -1j1 8j2 22sum 
// 1i 16m -1j1 8j2 22sum 
// 1i 9m -1j1 8j2 22sum 
// 1i 6m -1j1 8j2 22sum 
// 1i 5m -1j1 8j2 22sum 
// 2i 1000000000000000001m -1j1 8j2 22sum 
// 2i 500000000000000001m -1j1 8j2 22sum 
// 2i 250000000000000001m -1j1 8j2 22sum 
// 2i 125000000000000001m -1j1 8j2 22sum 
// 2i 62500000000000001m -1j1 8j2 22sum 
// 2i 31250000000000001m -1j1 8j2 22sum 
// 2i 15625000000000001m -1j1 8j2 22sum 
// 2i 7812500000000001m -1j1 8j2 22sum 
// 2i 3906250000000001m -1j1 8j2 22sum 
// 2i 1953125000000001m -1j1 8j2 22sum 
// 2i 976562500000001m -1j1 8j2 22sum 
// 2i 488281250000001m -1j1 8j2 22sum 
// 2i 244140625000001m -1j1 8j2 22sum 
// 2i 122070312500001m -1j1 8j2 22sum 
// 2i 61035156250001m -1j1 8j2 22sum 
// 2i 30517578125001m -1j1 8j2 22sum 
// 2i 15258789062501m -1j1 8j2 22sum 
// 2i 7629394531251m -1j1 8j2 22sum 
// 2i 3814697265626m -1j1 8j2 22sum 
// 2i 1907348632813m -1j1 8j2 22sum 
// 2i 953674316407m -1j1 8j2 22sum 
// 2i 476837158204m -1j1 8j2 22sum 
// 2i 238418579102m -1j1 8j2 22sum 
// 2i 119209289551m -1j1 8j2 22sum 
// 2i 59604644776m -1j1 8j2 22sum 
// 2i 29802322388m -1j1 8j2 22sum 
// 2i 14901161194m -1j1 8j2 22sum 
// 2i 7450580597m -1j1 8j2 22sum 
// 2i 3725290299m -1j1 8j2 22sum 
// 2i 1862645150m -1j1 8j2 22sum 
// 2i 931322575m -1j1 8j2 22sum 
// 2i 465661288m -1j1 8j2 22sum 
// 2i 232830644m -1j1 8j2 22sum 
// 2i 116415322m -1j1 8j2 22sum 
// 2i 58207661m -1j1 8j2 22sum 
// 2i 29103831m -1j1 8j2 22sum 
// 2i 14551916m -1j1 8j2 22sum 
// 2i 7275958m -1j1 8j2 22sum 
// 2i 3637979m -1j1 8j2 22sum 
// 2i 1818990m -1j1 8j2 22sum 
// 2i 909495m -1j1 8j2 22sum 
// 2i 454748m -1j1 8j2 22sum 
// 2i 227374m -1j1 8j2 22sum 
// 2i 113687m -1j1 8j2 22sum 
// 2i 56844m -1j1 8j2 22sum 
// 2i 28422m -1j1 8j2 22sum 
// 2i 14211m -1j1 8j2 22sum 
// 2i 7106m -1j1 8j2 22sum 
// 2i 3553m -1j1 8j2 22sum 
// 2i 1777m -1j1 8j2 22sum 
// 2i 889m -1j1 8j2 22sum 
// 2i 445m -1j1 8j2 22sum 
// 2i 223m -1j1 8j2 22sum 
// 2i 112m -1j1 8j2 22sum 
// 2i 56m -1j1 8j2 22sum 
// 2i 28m -1j1 8j2 22sum 
// 2i 14m -1j1 8j2 22sum 
// 2i 7m -1j1 8j2 22sum 
// 2i 4m 1j1 8j2 15sum 
// 2i 3m 1j1 8j2 15sum 
// 3i 1000000000000000000m -1j1 8j2 22sum 
// 3i 500000000000000000m -1j1 8j2 22sum 
// 3i 250000000000000000m -1j1 8j2 22sum 
// 3i 125000000000000000m -1j1 8j2 22sum 
// 3i 62500000000000000m -1j1 8j2 22sum 
// 3i 31250000000000000m -1j1 8j2 22sum 
// 3i 15625000000000000m -1j1 8j2 22sum 
// 3i 7812500000000000m -1j1 8j2 22sum 
// 3i 3906250000000000m -1j1 8j2 22sum 
// 3i 1953125000000000m -1j1 8j2 22sum 
// 3i 976562500000000m -1j1 8j2 22sum 
// 3i 488281250000000m -1j1 8j2 22sum 
// 3i 244140625000000m -1j1 8j2 22sum 
// 3i 122070312500000m -1j1 8j2 22sum 
// 3i 61035156250000m -1j1 8j2 22sum 
// 3i 30517578125000m -1j1 8j2 22sum 
// 3i 15258789062500m -1j1 8j2 22sum 
// 3i 7629394531250m -1j1 8j2 22sum 
// 3i 3814697265625m -1j1 8j2 22sum 
// 3i 1907348632812m -1j1 8j2 22sum 
// 3i 953674316406m -1j1 8j2 22sum 
// 3i 476837158203m -1j1 8j2 22sum 
// 3i 238418579101m -1j1 8j2 22sum 
// 3i 119209289550m -1j1 8j2 22sum 
// 3i 59604644775m -1j1 8j2 22sum 
// 3i 29802322387m -1j1 8j2 22sum 
// 3i 14901161193m -1j1 8j2 22sum 
// 3i 7450580596m -1j1 8j2 22sum 
// 3i 3725290298m -1j1 8j2 22sum 
// 3i 1862645149m -1j1 8j2 22sum 
// 3i 931322574m -1j1 8j2 22sum 
// 3i 465661287m -1j1 8j2 22sum 
// 3i 232830643m -1j1 8j2 22sum 
// 3i 116415321m -1j1 8j2 22sum 
// 3i 58207660m -1j1 8j2 22sum 
// 3i 29103830m -1j1 8j2 22sum 
// 3i 14551915m -1j1 8j2 22sum 
// 3i 7275957m -1j1 8j2 22sum 
// 3i 3637978m -1j1 8j2 22sum 
// 3i 1818989m -1j1 8j2 22sum 
// 3i 909494m -1j1 8j2 22sum 
// 3i 454747m -1j1 8j2 22sum 
// 3i 227373m -1j1 8j2 22sum 
// 3i 113686m -1j1 8j2 22sum 
// 3i 56843m -1j1 8j2 22sum 
// 3i 28421m -1j1 8j2 22sum 
// 3i 14210m -1j1 8j2 22sum 
// 3i 7105m -1j1 8j2 22sum 
// 3i 3552m -1j1 8j2 22sum 
// 3i 1776m -1j1 8j2 22sum 
// 3i 888m -1j1 8j2 22sum 
// 3i 444m -1j1 8j2 22sum 
// 3i 222m -1j1 8j2 22sum 
// 3i 111m -1j1 8j2 22sum 
// 3i 55m -1j1 8j2 22sum 
// 3i 27m -1j1 8j2 22sum 
// 3i 13m -1j1 8j2 22sum 
// 3i 6m 1j1 8j2 15sum 
// 3i 3m 2j1 8j2 13sum 
// 3i 2m 2j1 8j2 13sum 
// 4i 1000000000000000001m -1j1 8j2 22sum 
// 4i 500000000000000001m -1j1 8j2 22sum 
// 4i 250000000000000001m -1j1 8j2 22sum 
// 4i 125000000000000001m -1j1 8j2 22sum 
// 4i 62500000000000001m -1j1 8j2 22sum 
// 4i 31250000000000001m -1j1 8j2 22sum 
// 4i 15625000000000001m -1j1 8j2 22sum 
// 4i 7812500000000001m -1j1 8j2 22sum 
// 4i 3906250000000001m -1j1 8j2 22sum 
// 4i 1953125000000001m -1j1 8j2 22sum 
// 4i 976562500000001m -1j1 8j2 22sum 
// 4i 488281250000001m -1j1 8j2 22sum 
// 4i 244140625000001m -1j1 8j2 22sum 
// 4i 122070312500001m -1j1 8j2 22sum 
// 4i 61035156250001m -1j1 8j2 22sum 
// 4i 30517578125001m -1j1 8j2 22sum 
// 4i 15258789062501m -1j1 8j2 22sum 
// 4i 7629394531251m -1j1 8j2 22sum 
// 4i 3814697265626m -1j1 8j2 22sum 
// 4i 1907348632814m -1j1 8j2 22sum 
// 4i 953674316408m -1j1 8j2 22sum 
// 4i 476837158205m -1j1 8j2 22sum 
// 4i 238418579103m -1j1 8j2 22sum 
// 4i 119209289552m -1j1 8j2 22sum 
// 4i 59604644777m -1j1 8j2 22sum 
// 4i 29802322389m -1j1 8j2 22sum 
// 4i 14901161195m -1j1 8j2 22sum 
// 4i 7450580598m -1j1 8j2 22sum 
// 4i 3725290300m -1j1 8j2 22sum 
// 4i 1862645151m -1j1 8j2 22sum 
// 4i 931322576m -1j1 8j2 22sum 
// 4i 465661289m -1j1 8j2 22sum 
// 4i 232830645m -1j1 8j2 22sum 
// 4i 116415323m -1j1 8j2 22sum 
// 4i 58207662m -1j1 8j2 22sum 
// 4i 29103832m -1j1 8j2 22sum 
// 4i 14551917m -1j1 8j2 22sum 
// 4i 7275959m -1j1 8j2 22sum 
// 4i 3637980m -1j1 8j2 22sum 
// 4i 1818991m -1j1 8j2 22sum 
// 4i 909496m -1j1 8j2 22sum 
// 4i 454749m -1j1 8j2 22sum 
// 4i 227375m -1j1 8j2 22sum 
// 4i 113688m -1j1 8j2 22sum 
// 4i 56845m -1j1 8j2 22sum 
// 4i 28423m -1j1 8j2 22sum 
// 4i 14212m -1j1 8j2 22sum 
// 4i 7107m -1j1 8j2 22sum 
// 4i 3554m -1j1 8j2 22sum 
// 4i 1778m -1j1 8j2 22sum 
// 4i 890m -1j1 8j2 22sum 
// 4i 446m -1j1 8j2 22sum 
// 4i 224m -1j1 8j2 22sum 
// 4i 113m -1j1 8j2 22sum 
// 4i 57m -1j1 8j2 22sum 
// 4i 29m -1j1 8j2 22sum 
// 4i 15m -1j1 8j2 22sum 
// 4i 8m -1j1 8j2 22sum 
// 4i 5m 1j1 8j2 15sum 
// 4i 4m 2j1 8j2 13sum 
// 5i 1000000000000000001m -1j1 8j2 22sum 
// 5i 500000000000000001m -1j1 8j2 22sum 
// 5i 250000000000000001m -1j1 8j2 22sum 
// 5i 125000000000000001m -1j1 8j2 22sum 
// 5i 62500000000000001m -1j1 8j2 22sum 
// 5i 31250000000000001m -1j1 8j2 22sum 
// 5i 15625000000000001m -1j1 8j2 22sum 
// 5i 7812500000000001m -1j1 8j2 22sum 
// 5i 3906250000000001m -1j1 8j2 22sum 
// 5i 1953125000000001m -1j1 8j2 22sum 
// 5i 976562500000001m -1j1 8j2 22sum 
// 5i 488281250000001m -1j1 8j2 22sum 
// 5i 244140625000001m -1j1 8j2 22sum 
// 5i 122070312500001m -1j1 8j2 22sum 
// 5i 61035156250001m -1j1 8j2 22sum 
// 5i 30517578125001m -1j1 8j2 22sum 
// 5i 15258789062501m -1j1 8j2 22sum 
// 5i 7629394531251m -1j1 8j2 22sum 
// 5i 3814697265626m -1j1 8j2 22sum 
// 5i 1907348632814m -1j1 8j2 22sum 
// 5i 953674316408m -1j1 8j2 22sum 
// 5i 476837158205m -1j1 8j2 22sum 
// 5i 238418579103m -1j1 8j2 22sum 
// 5i 119209289552m -1j1 8j2 22sum 
// 5i 59604644777m -1j1 8j2 22sum 
// 5i 29802322389m -1j1 8j2 22sum 
// 5i 14901161195m -1j1 8j2 22sum 
// 5i 7450580598m -1j1 8j2 22sum 
// 5i 3725290300m -1j1 8j2 22sum 
// 5i 1862645151m -1j1 8j2 22sum 
// 5i 931322576m -1j1 8j2 22sum 
// 5i 465661289m -1j1 8j2 22sum 
// 5i 232830645m -1j1 8j2 22sum 
// 5i 116415323m -1j1 8j2 22sum 
// 5i 58207662m -1j1 8j2 22sum 
// 5i 29103832m -1j1 8j2 22sum 
// 5i 14551917m -1j1 8j2 22sum 
// 5i 7275959m -1j1 8j2 22sum 
// 5i 3637980m -1j1 8j2 22sum 
// 5i 1818991m -1j1 8j2 22sum 
// 5i 909496m -1j1 8j2 22sum 
// 5i 454749m -1j1 8j2 22sum 
// 5i 227375m -1j1 8j2 22sum 
// 5i 113688m -1j1 8j2 22sum 
// 5i 56845m -1j1 8j2 22sum 
// 5i 28423m -1j1 8j2 22sum 
// 5i 14212m -1j1 8j2 22sum 
// 5i 7107m -1j1 8j2 22sum 
// 5i 3554m -1j1 8j2 22sum 
// 5i 1778m -1j1 8j2 22sum 
// 5i 890m -1j1 8j2 22sum 
// 5i 446m -1j1 8j2 22sum 
// 5i 224m -1j1 8j2 22sum 
// 5i 113m -1j1 8j2 22sum 
// 5i 57m -1j1 8j2 22sum 
// 5i 29m -1j1 8j2 22sum 
// 5i 15m -1j1 8j2 22sum 
// 5i 8m 1j1 8j2 15sum 
// 5i 5m 2j1 8j2 13sum 
// 5i 4m 4j1 8j2 9sum 
// 6i 1000000000000000001m -1j1 8j2 22sum 
// 6i 500000000000000001m -1j1 8j2 22sum 
// 6i 250000000000000001m -1j1 8j2 22sum 
// 6i 125000000000000001m -1j1 8j2 22sum 
// 6i 62500000000000001m -1j1 8j2 22sum 
// 6i 31250000000000001m -1j1 8j2 22sum 
// 6i 15625000000000001m -1j1 8j2 22sum 
// 6i 7812500000000001m -1j1 8j2 22sum 
// 6i 3906250000000001m -1j1 8j2 22sum 
// 6i 1953125000000001m -1j1 8j2 22sum 
// 6i 976562500000001m -1j1 8j2 22sum 
// 6i 488281250000001m -1j1 8j2 22sum 
// 6i 244140625000001m -1j1 8j2 22sum 
// 6i 122070312500001m -1j1 8j2 22sum 
// 6i 61035156250001m -1j1 8j2 22sum 
// 6i 30517578125001m -1j1 8j2 22sum 
// 6i 15258789062501m -1j1 8j2 22sum 
// 6i 7629394531251m -1j1 8j2 22sum 
// 6i 3814697265626m -1j1 8j2 22sum 
// 6i 1907348632813m -1j1 8j2 22sum 
// 6i 953674316407m -1j1 8j2 22sum 
// 6i 476837158204m -1j1 8j2 22sum 
// 6i 238418579102m -1j1 8j2 22sum 
// 6i 119209289551m -1j1 8j2 22sum 
// 6i 59604644776m -1j1 8j2 22sum 
// 6i 29802322388m -1j1 8j2 22sum 
// 6i 14901161194m -1j1 8j2 22sum 
// 6i 7450580597m -1j1 8j2 22sum 
// 6i 3725290299m -1j1 8j2 22sum 
// 6i 1862645150m -1j1 8j2 22sum 
// 6i 931322575m -1j1 8j2 22sum 
// 6i 465661288m -1j1 8j2 22sum 
// 6i 232830644m -1j1 8j2 22sum 
// 6i 116415322m -1j1 8j2 22sum 
// 6i 58207661m -1j1 8j2 22sum 
// 6i 29103831m -1j1 8j2 22sum 
// 6i 14551916m -1j1 8j2 22sum 
// 6i 7275958m -1j1 8j2 22sum 
// 6i 3637979m -1j1 8j2 22sum 
// 6i 1818990m -1j1 8j2 22sum 
// 6i 909495m -1j1 8j2 22sum 
// 6i 454748m -1j1 8j2 22sum 
// 6i 227374m -1j1 8j2 22sum 
// 6i 113687m -1j1 8j2 22sum 
// 6i 56844m -1j1 8j2 22sum 
// 6i 28422m -1j1 8j2 22sum 
// 6i 14211m -1j1 8j2 22sum 
// 6i 7106m -1j1 8j2 22sum 
// 6i 3553m -1j1 8j2 22sum 
// 6i 1777m -1j1 8j2 22sum 
// 6i 889m -1j1 8j2 22sum 
// 6i 445m -1j1 8j2 22sum 
// 6i 223m -1j1 8j2 22sum 
// 6i 112m -1j1 8j2 22sum 
// 6i 56m -1j1 8j2 22sum 
// 6i 28m -1j1 8j2 22sum 
// 6i 14m -1j1 8j2 22sum 
// 6i 7m 1j1 8j2 15sum 
// 6i 4m 5j1 8j2 6sum 
// 6i 3m 5j1 8j2 6sum 
// 7i 1000000000000000002m -1j1 8j2 22sum 
// 7i 500000000000000002m -1j1 8j2 22sum 
// 7i 250000000000000002m -1j1 8j2 22sum 
// 7i 125000000000000002m -1j1 8j2 22sum 
// 7i 62500000000000002m -1j1 8j2 22sum 
// 7i 31250000000000002m -1j1 8j2 22sum 
// 7i 15625000000000002m -1j1 8j2 22sum 
// 7i 7812500000000002m -1j1 8j2 22sum 
// 7i 3906250000000002m -1j1 8j2 22sum 
// 7i 1953125000000002m -1j1 8j2 22sum 
// 7i 976562500000002m -1j1 8j2 22sum 
// 7i 488281250000002m -1j1 8j2 22sum 
// 7i 244140625000002m -1j1 8j2 22sum 
// 7i 122070312500002m -1j1 8j2 22sum 
// 7i 61035156250002m -1j1 8j2 22sum 
// 7i 30517578125002m -1j1 8j2 22sum 
// 7i 15258789062502m -1j1 8j2 22sum 
// 7i 7629394531252m -1j1 8j2 22sum 
// 7i 3814697265627m -1j1 8j2 22sum 
// 7i 1907348632815m -1j1 8j2 22sum 
// 7i 953674316409m -1j1 8j2 22sum 
// 7i 476837158206m -1j1 8j2 22sum 
// 7i 238418579104m -1j1 8j2 22sum 
// 7i 119209289553m -1j1 8j2 22sum 
// 7i 59604644778m -1j1 8j2 22sum 
// 7i 29802322390m -1j1 8j2 22sum 
// 7i 14901161196m -1j1 8j2 22sum 
// 7i 7450580599m -1j1 8j2 22sum 
// 7i 3725290301m -1j1 8j2 22sum 
// 7i 1862645152m -1j1 8j2 22sum 
// 7i 931322577m -1j1 8j2 22sum 
// 7i 465661290m -1j1 8j2 22sum 
// 7i 232830646m -1j1 8j2 22sum 
// 7i 116415324m -1j1 8j2 22sum 
// 7i 58207663m -1j1 8j2 22sum 
// 7i 29103833m -1j1 8j2 22sum 
// 7i 14551918m -1j1 8j2 22sum 
// 7i 7275960m -1j1 8j2 22sum 
// 7i 3637981m -1j1 8j2 22sum 
// 7i 1818992m -1j1 8j2 22sum 
// 7i 909497m -1j1 8j2 22sum 
// 7i 454750m -1j1 8j2 22sum 
// 7i 227376m -1j1 8j2 22sum 
// 7i 113689m -1j1 8j2 22sum 
// 7i 56846m -1j1 8j2 22sum 
// 7i 28424m -1j1 8j2 22sum 
// 7i 14213m -1j1 8j2 22sum 
// 7i 7108m -1j1 8j2 22sum 
// 7i 3555m -1j1 8j2 22sum 
// 7i 1779m -1j1 8j2 22sum 
// 7i 891m -1j1 8j2 22sum 
// 7i 447m -1j1 8j2 22sum 
// 7i 225m -1j1 8j2 22sum 
// 7i 114m -1j1 8j2 22sum 
// 7i 58m -1j1 8j2 22sum 
// 7i 30m -1j1 8j2 22sum 
// 7i 16m -1j1 8j2 22sum 
// 7i 9m 1j1 8j2 15sum 
// 7i 6m 4j1 8j2 9sum 
// 7i 5m 5j1 8j2 6sum 
// 4
