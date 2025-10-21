#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll h[7][7];
ll dp[7][7][7][7][7][7][7];
vector<vv> finales; // 0011110
ll f(vv a, ll p){
	// imp(a);
	// cout<<endl;
	ll &res=dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];
	if(res!=-1)return res;
	for(auto v:finales){
		ll flag=1;
		fore(j,0,SZ(v))flag&=v[j]<=a[j];
		if(flag)return res=1<<(p^1);
	}
	res=0;
	fore(j,0,7)if(a[j]<6&&h[a[j]][j]==p){
		vv ai=a;
		ai[j]++;
		res|=f(ai,p^1);
	}
	return res;
}

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}

int main(){FIN;
	ll ljgfjfdg; cin>>ljgfjfdg;
	fore(ldjg,0,ljgfjfdg){
		cout<<"Case #"<<ldjg+1<<": ";
		mset(dp,-1);
		for(ll i=6-1;i>=0;i--)fore(j,0,7){
			char c; cin>>c;
			h[i][j]=c=='F';
		}
		// finales
		finales.clear();
		vector<ii> dir={{1,0},{0,1},{1,1},{-1,1}};
		fore(i,0,6)fore(j,0,7){
			for(auto d:dir){
				vector<ii>c;
				ll mk=0;
				for(ii p={i,j};p.fst>=0&&p.fst<6&&p.snd>=0&&p.snd<7&&SZ(c)<4;p=p+d){
					c.pb(p);
					mk|=1<<h[p.fst][p.snd];
				}
				if(mk!=3&&SZ(c)==4){
					vv row(7,0);
					for(auto [i,j]:c)row[j]=max(row[j],i+1);
					finales.pb(row);
					// imp(row);
				}
			}
		}
		
		// finales
		vv a(7);
		ll mk=f(a,0);
		if(mk==0)cout<<"0\n";
		if(mk==1)cout<<"C\n";
		if(mk==2)cout<<"F\n";
		if(mk==3)cout<<"?\n";
	}
	return 0;
}
