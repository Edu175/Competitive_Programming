#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ifstream cin;   cin.open("mesadas.in", ios::in);
	ofstream cout; cout.open("mesadas.out", ios::out);
	ll n; cin>>n;
	ii a[n];
	fore(i,0,n){
		cin>>a[i].fst>>a[i].snd;
		if(a[i].fst<a[i].snd)swap(a[i].fst,a[i].snd);
	}
	//maxima anticadena
	sort(ALL(a)); reverse(ALL(a));
	
	
	return 0;
}
