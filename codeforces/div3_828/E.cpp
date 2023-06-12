#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
vector<ll>divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
}
/*int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXN;j+=i)cr[j]=i;
}
map<int,int> fact(int n){  // must call init_cribe before
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}*/

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		ll idx[MAXN];mset(idx,0);
		ll idy[MAXN];mset(idy,0);
		divisores();
		fore(i,a+1,c+1){
			for(auto di:divs[i]){
				idx[di]=i;
			}
		}
		fore(i,b+1,d+1){
			for(auto di:divs[i]){
				idy[di]=i;
			}
		}
		//imp(xd);
		//imp(yd);
		ll r1=-1,r2=-1;
		/*for(ll i=1; i*i<=(a*b);i++){
			if((a*b)%i==0){
				
			}
		}*/
		fore(i,0,MAXN){
			if(idx[i]==0)continue;
			if(((a*b)/i)<MAXN&&idy[((a*b)/i)]){
				assert((idx[i]*idy[(a*b)/i])%(a*b)==0);
				if((idx[i]*idy[(a*b)/i])%(a*b)==0){
					r1=idx[i];
					r2=idy[(a*b)/i];
					break;
				}
			}
		}
		cout<<r1<<" "<<r2<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
