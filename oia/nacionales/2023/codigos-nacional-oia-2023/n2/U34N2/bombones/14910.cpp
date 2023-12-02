#include <bits/stdc++.h>

using namespace std;
#define fst first
#define snd second
#define pb push_back
#define forn(i,a,b) for(int i = a; i < b; i++)
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset(a,v,sizeof(a))
typedef long long ll;

/*struct STree{
	vector<ll> st; ll n;
	
	STree(ll n): st(4*n+5),n(n) {}
	
	void upd(ll k, ll l, ll r, ll p , ll v){
		if(l+1==r){st[k]=v; return;}
		if()
	}
};*/

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    /*vector<ll> ms;
    forn(i,0,SZ(x)) ms.pb((ll)x[i]);
    ll l = 0; ll r = (ll)1e14;
    sort(ALL(ms));
    reverse(ALL(ms));
    vector<ll> aux = ms;
    ll cant = 0;
   	forn(i,0,SZ(ms)){
   		if(i+K-1<=SZ(ms)-1){
   			forn(j,1,K){
   				aux[i+j]-=aux[i];
			}	
   			cant+=aux[i];
   			aux[i]=0;
   		}
   	}
   /* while(l<=r){
   		ll m = (l+r)/2;
   		vector<ll> aux = ms;
   		ll cant = 0;
   		forn(i,0,SZ(ms)){
   			if(i+K-1<=SZ(ms)-1){
   				forn(j,1,K){
   					aux[i+j]-=aux[i];
	   			}
   		
   			cant+=aux[i];
   			aux[i]=0;
   			}
   		}
   		cout<<
   		if(cant<m) r = m-1;
   		else l = m+1;
   	}*/
   	//cout<<l<<" "<<r<<'\n';
/*   	cout<<cant<<'\n';*/

	multiset<ll> ms;
    forn(i,0,SZ(x)) ms.insert((ll)x[i]);
    bool pueda = 1;
    ll cant = 0;
    while(pueda){
    	auto it = ms.end()--;
    	forn(i,0,K) it--;
    	if(*it==0){ pueda = false; continue;}
    	cant+=*it;
    	ll rest = *it;
    	forn(i,0,K){
    		ll aux = *it;
    		ms.erase(it);
    		ms.insert(aux-rest);
    		it++;
    	}
    }
    //cout<<cant<<'\n';
    return (ll)cant;
}
