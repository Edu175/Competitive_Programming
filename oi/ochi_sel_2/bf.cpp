#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=1e5+5;
ll L[MAXN],R[MAXN];
ll pri,ult,sz;
void go(ll &pos, ll &dir, ll v){
	//cout<<"go "<<pos<<" "<<dir<<"  "<<v<<endl;
	if(R[pri]==L[ult])return;
	while(v){
		if(pos==R[pri])dir=1;
		if(pos==L[ult])dir=-1;
		if(dir==1)pos=R[pos];
		else pos=L[pos];
		if(pos==R[pri])dir=1;
		if(pos==L[ult])dir=-1;
		v--;
	}
}
void erase(ll x){
	if(R[x]==-1)return;
	R[L[x]]=R[x];
	L[R[x]]=L[x];
	R[x]=L[x]=-1;
}
int main(){FIN;
	ll n,b[2]; cin>>n>>b[0]>>b[1];
	//assert(n>10&&b[0]>2&&b[1]>2);
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll c[2]={0,0};
	ii p[2]={{0,1},{n-1,-1}};
	pri=n+1,ult=n;
	R[pri]=0,L[0]=pri;
	L[ult]=n-1; R[n-1]=ult;
	fore(i,0,n){
		if(i)L[i]=i-1;
		if(i<n-1)R[i]=i+1;
	}
	ll men=0;
	sz=n;
	vector<ll>is(n,1);
	while(sz){
		//imp(st);
		ll ns=sz;
		fore(w,0,2){
			ll &pos=p[w].fst;
			ll &dir=p[w].snd;
			if(ns>1){
				ll mod=2*ns-2;
				ll v=(b[w]-men)%mod;
				go(pos,dir,v);
			}
			c[w]+=a[pos];
		}
		ll p0=p[0].fst,p1=p[1].fst;
		//cout<<"Mario "<<p[0].fst<<" "<<p[0].snd<<endl;
		//cout<<"Bowser "<<p[1].fst<<" "<<p[1].snd<<endl;
		fore(w,0,2)if(is[p[w].fst])ns--,is[p[w].fst]=0;
		//imp(is);
		//cout<<sz<<endl;
		fore(w,0,2)while(ns&&!is[p[w].fst]){
			go(p[w].fst,p[w].snd,1);
		}
		sz=ns;
		men=1;
		erase(p0);
		erase(p1);
		
		//cout<<endl;
	}
	cout<<c[0]<<" "<<c[1]<<"\n";
	if(c[0]>=c[1])cout<<"Mario\n";
	else cout<<"Bowser\n";
	return 0;
}
