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
const ll MAXV=1e7+5;

int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nloglog(n))
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}

const ll ans=121313;

int main(){FIN;
	init_sieve();
	vector<ll>primes;
	fore(i,2,MAXV)if(cr[i]==-1)primes.pb(i);
	for(auto p:primes){
		//cout<<p<<"\n";
		string s=to_string(p);
		vector<ll> pos[10];
		fore(i,0,SZ(s))pos[s[i]-'0'].pb(i);
		fore(d,0,3){
			fore(mk,1,1ll<<SZ(pos[d])){
				ll cnt=0;
				//cout<<mk<<": ";
				fore(di,0,10){
					string si=s;
					for(auto i:pos[d])si[i]='0'+di;
					if(si[0]=='0')continue;
					if(cr[stoll(si)]==-1)cnt++;
				}
				if(cnt>=8){
					fore(di,0,10){
						string si=s;
						for(auto i:pos[d])si[i]='0'+di;
						if(si[0]=='0')continue;
						if(cr[stoll(si)]==-1)cout<<si<<"\n";
					}
					exit(0);
				}
				//cout<<"\n";
			}
		}
	}
	cout<<"ninguno\n";
	return 0;
}

