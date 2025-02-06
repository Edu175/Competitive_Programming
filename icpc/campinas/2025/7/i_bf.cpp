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

ll rta=0;
ll k;
vv a;
void check(){
	bool b=false;
	fore(i,k,SZ(a)){
		b=false;
		for(ll j = i;j>=i-k;j--){
			if(a[i]>a[j]){
				b=true;
				break; 
			}
		}
		if(!b) return;	
	}
	// fore(i,0,SZ(a)){
	// 	cout<<a[i]<<" ";
	// }
	// cout<<"\n";
	rta++;
	return;
}

int main(){
	JET
	int n; cin>>n>>k;
	fore(i,1,n+1) a.pb(i);
	do{
		check();
	} while(next_permutation(ALL(a)));
	cout<<rta<<"\n";
}