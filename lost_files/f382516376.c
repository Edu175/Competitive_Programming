#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

/*struct player{
	ll 
};*/

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("carrera.in", ios::in);
	cout.open("carrera.out", ios::out);
	ll n,cf,cm,l; cin>>n>>cf>>cm>>l;
	ll fr[cf],mr[cm];
	fore(i,0,cf){
		ll b; cin>>fr[i]>>b;
	}
	fore(i,0,cm){
		ll b; cin>>mr[i]>>b;
	}
	ll cat[n];
	fore(i,0,n){
		ll e;char x; cin>>e>>x;
		if(x=='F')cat[i]=upper_bound(fr,fr+cf,e)-fr-1;
		else cat[i]=upper_bound(mr,mr+cm,e)-mr+cf-1;
	}
	ll c=cf+cm;
	vector<ll> res[c];
	fore(i,0,l){
		ll x; cin>>x; x--;
		vector<ll> &pod=res[cat[x]];
		if(SZ(pod)<3)pod.pb(x+1);
	}
	/*fore(i,0,n)cout<<cat[i]<<" ";
	cout<<"\n";*/
	fore(i,0,c){
		if(i<cf){
			cout<<i+1<<" ";
			fore(j,0,3){
				if(SZ(res[i])>j)cout<<res[i][j];
				else cout<<0;
				cout<<" ";
			}
			cout<<"\n";
		}
		else{
			cout<<i+1-cf<<" ";
			fore(j,0,3){
				if(SZ(res[i])>j)cout<<res[i][j];
				else cout<<0;
				cout<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
