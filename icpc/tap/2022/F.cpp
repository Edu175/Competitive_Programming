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

int main(){FIN;
	ll n,m; cin>>n>>m;
	string a[n];
	fore(i,0,n)cin>>a[i];
	pair<ll,ll>b[n];
	ll pow27[13]; pow27[0]=1; fore(i,1,13)pow27[i]=27*pow27[i-1];
	fore(i,0,n){
		b[i].fst=0;
		fore(j,0,m){
			if(a[i][j]!='*'){
				b[i].fst+=(a[i][j]-'a'+1)*pow27[j];
			}
			else b[i].snd=j;
		}
	}
	ll res=0;
	string ans;
	fore(i,0,n){
		ll q=0; vector<ll>c(30,0);
		//cout<<i<<":\n";
		fore(j,i,n){
			if(b[i].snd==b[j].snd){q+=(b[i].fst==b[j].fst);continue;}
			ll d=b[i].fst-(a[i][b[j].snd]-'a'+1)*pow27[b[j].snd];
			ll e=b[j].fst-(a[j][b[i].snd]-'a'+1)*pow27[b[i].snd];
			//cout<<"\t"<<j<<": "<<d<<" "<<e<<"\n";
			if(d==e)c[a[j][b[i].snd]-'a']++;
		}
		char h='a';
		ll resi=0;
		fore(j,0,30){
			//cout<<char('a'+j)<<" "<<c[j]<<" "<<resi<<"\n";
			if(c[j]>resi)h='a'+j,resi=c[j];
			
		}
		//cout<<resi<<" "<<q<<" "<<a[i]<<" "<<h<<"\n";
		resi+=q;
		string ansi=a[i];
		fore(j,0,m)if(ansi[j]=='*')ansi[j]=h;
		if(resi>res)res=resi,ans=ansi;
		else if(res==resi&&ansi<ans)ans=ansi;
	}
	cout<<ans<<" "<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

