#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define ford(i,a,b) for(int i=a,jet=b; i>=jet;i-=2)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef short int sint;
const ll MAXN=2e6+5;
bitset <MAXN> p, q;

void updp(int i){
	if(!p[i]) {
		if(p[i+1]){
			p[i+1]=0;
			p[i]=0;
			updp(i+2); return;
		}
		if(i&&p[i-1]){
			p[i]=0;
			p[i-1]=0;
			updp(i+1);
			return;
		}
		p[i]=1;
		return;
	}
	p[i]=0;
	updp(i+1);
	if(i>1) updp(i-2);
	if(i==1) updp(i-1);
	return;
}
void upds(int i){
	if(p[i]) {p[i]=0; return;}
//	p._Find_first(); primer prendido
//	p._Find_next(j); primer prendido despues de j, o MAXN si no hay
	ll j=p._Find_next(i);
	assert(j!=MAXN&&j>i);
	p[j]=0;
	ford(k,j-1,i) updp(k>i?k:(k?k-1:0));
}
void add(){
	fore(i,0,MAXN){
		//ll j=MAXN-1-i;
		if(q[i]) updp((int)i);
	}
}
void sub(){
	fore(i,0,MAXN){
		//ll j=MAXN-1-i;
		if(q[i]) upds((int)i);
	}
}
/*ll F[91];
void init(ll n, bool b){
	auto &d=(b?p:q);
	d.reset();
	ll j=90;
	while(n){
		if(F[j]<=n){
			n-=F[j];
			d[j]=1;
		}
		j--;
	}
}
*/
int main(){
	/*JET
	F[0]=1;
	F[1]=2;
	fore(i,2,91) F[i]=F[i-1]+F[i-2];
//	cout<<F[90]<<"\n";
// return 0;
	// ll n,m; cin>>n>>m;
	// if(n<m) swap(n,m);
	// init(n,1); init(m,0);
	*/
ll _; cin>>_; while(_--){
	ll n; cin>>n;
	fore(i,0,n){
		ll x; cin>>x; p[i]=x;
	}
	cin>>n;
	fore(i,0,n){
		ll x; cin>>x; q[i]=x;
	}
	p[MAXN/2]=1; q[MAXN/2]=0;
	sub();
	fore(i,0,n)cout<<p[i]<<" ";;cout<<"\n";
	//assert(0);
	/*return 0;
	// n+=m;
	// init(n,0);
	fore(i,0,MAXN) assert(p[i]==q[i]) ;;cout<<"Suma bien\n";
	//fore(i,0,MAXN) if(p[i]!=q[i])cout<<i<<" "<<p[i]<<" "<<q[i]<<"\n"; */
	}	
	return 0;
}