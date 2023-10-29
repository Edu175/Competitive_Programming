#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;

ll dp

int vial(int K, int C, string &tipo, vector<int> &cuantos, vector<int> &pos, string &queHay) {
    ll tengo[30];
    fore(i,0,SZ(tipo)){
    	tengo[tipo[i]-'A']+=cuantos[i];
    }
    map<ll,char>colocar;
    vector<pair<ll,ll>>a;
    vector<ll> oc[30];
    fore(i,0,2*n){
    	if(queHay[i]>='a'){
    		a.pb({pos[i],queHay[i]});
    		oc[queHay[i]-'a'].pb(pos[i]);
    	}
    	else colocar[pos[i]]=queHay[i];
    }
    fore(i,0,30)sort(ALL(oc[i]));
    sort(ALL(a));
    
    ll res=0;
    fore(i,0,SZ(a)){
    	if(i)res+=(a[i].fst-a[i-1].fst)*C;
    	
    }
}
