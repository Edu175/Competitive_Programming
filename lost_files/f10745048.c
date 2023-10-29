#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXC=3004, MOD=1000000007;

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("input.txt", ios::in);
	cout.open("output.txt", ios::out);
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n; cin>>n;
		pair<ll,ll> a[n];
		vector<ll> ax(MAXC,0), ay(MAXC,0);
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
			ax[a[i].fst]++;
			ay[a[i].snd]++;
		}
		ll q; cin>>q;
		pair<ll,ll> b[q];
		vector<ll> bx(MAXC,0), by(MAXC,0);
		fore(i,0,q){
			cin>>b[i].fst>>b[i].snd;
			bx[b[i].fst]++;
			by[b[i].snd]++;
		}
		ll res=0;
		fore(i,0,MAXC){
			fore(j,0,MAXC){
				ll d=i-j;
				ll add=d*d;
				add*=bx[i];
				add%=MOD;
				add*=ax[j];
				add%=MOD;
				res+=add;
				res%=MOD;
			}
		}
		fore(i,0,MAXC){
			fore(j,0,MAXC){
				ll d=i-j;
				ll add=d*d;
				add*=by[i];
				add%=MOD;
				add*=ay[j];
				add%=MOD;
				res+=add;
				res%=MOD;
			}
		}
		pres;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
