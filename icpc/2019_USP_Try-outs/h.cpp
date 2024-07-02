#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

ll s[110][110];
ll cl[110];

int main(){
	JET
	int n,m; cin>>n>>m;
	mset(s,-1);
	mset(cl,-1);
	fore(i,0,n){
		int q; cin>>q;
		fore(j,0,q){
			int x,k; cin>>x>>k;
			s[i][x]=k;
		}
	}
	fore(i,0,n){
		ll best=1e12;
		fore(j,0,n){
			if(i==j) continue;
			ll aux=0;
			bool b=false;
			fore(q,0,m+1){
				if(s[i][q]!=-1 && s[j][q]!=-1){
					ll dist=abs(s[i][q]-s[j][q]);
					dist*=dist;
					aux+=dist;
					b=true;
				}
			}
			if(b && aux<best){
				cl[i]=j;
				best=aux;
			}
		}
	}
	fore(i,0,n){
		if(cl[i]==-1){
			cout<<-1<<"\n";
			continue;
		}
		ii rec ={-1,-1};
		fore(j,0,m+1){
			if(s[i][j]==-1 && s[cl[i]][j]!=-1 && s[cl[i]][j]>rec.snd){
				rec={j,s[cl[i]][j]};
			}
		}
		cout<<rec.fst<<"\n";
	}
}