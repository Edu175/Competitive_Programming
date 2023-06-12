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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n;
		string s; cin>>s; n=SZ(s);
		ll a[n];
		fore(i,0,n)a[i]=s[i]-'A';
		vector<ll>d={1,10,100,1000,10000};
		ll sig[n+1][5];
		vector<ll>val(n+1);
		fore(i,0,5)sig[n][i]=1;
		val[n]=0;
		for(ll i=n-1;i>=0;i--){
			val[i]=val[i+1];
			ll s=1; fore(j,a[i]+1,5)s=min(s,sig[i+1][j]);
			val[i]+=d[a[i]]*s;
			fore(j,0,5)sig[i][j]=sig[i+1][j];
			sig[i][a[i]]=-1;
		}
		/*imp(a);
		fore(i,0,n+1){
			cout<<i<<": "; imp(sig[i]); cout<<val[i]<<"\n";
		}*/
		vector<ll>c(5);
		ll res=val[0];
		ll sum=0;
		fore(i,0,n){
			//cout<<i<<":\n";
			fore(j,0,5){
				ll resi=sum+val[i+1];
				ll s=1; fore(k,j+1,5)s=min(s,sig[i+1][k]);
				resi+=d[j]*s;
				ll sigi[5];
				fore(k,0,5)sigi[k]=sig[i+1][k];
				sigi[j]=-1;
				s=1;
				//cout<<"\t"<<j<<":\n";imp(c);imp(sigi);
				//cout<<sum<<" + "<<val[i+1];
				for(ll k=4;k>=0;k--){
					resi+=c[k]*d[k]*s,
					//cout<<" + "<<c[k]*d[k]*s;
					s=min(s,sigi[k]);
				}
				res=max(res,resi);
				//cout<<" = "<<resi<<"\n";
			}
			c[a[i]]++;
			fore(k,0,a[i])sum+=-c[k]*d[k],c[k]=0;
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
