#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	int n; cin>>n;
	ii pos[n];
	fore(i,0,n) pos[i]={-1,-1};
	fore(i,0,2*n){
		int x; cin>>x;
		x--;
		if(pos[x].fst==-1)pos[x].fst=i;
		else pos[x].snd=i;
	}
	fore(i,0,n) if(pos[i].fst>pos[i].snd) swap(pos[i].fst,pos[i].snd);
	ll a=0,b=0,rta=0;
	fore(i,0,n){
		rta+=abs(a-pos[i].fst);
		rta+=abs(b-pos[i].snd);
		a=pos[i].fst;
		b=pos[i].snd;
	}
	cout<<rta<<"\n";
	return 0;
}