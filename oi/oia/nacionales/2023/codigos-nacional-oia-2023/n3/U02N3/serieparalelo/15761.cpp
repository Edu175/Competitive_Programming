#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll N=50;
ll g[N][N];

int serieparalelo(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    g[0][1]=1;
    vector<ii>A={{0,1}};
    fore(i,0,SZ(e)){
    	e[i]--;
    	ll a=A[e[i]].fst,b=A[e[i]].snd;
    	if(t[i]==1){
    		A.pb({a,i});
    		A[e[i]]={i,b};
    	}
    	else {
    		A.pb({a,i});
    		A.pb({i,b});
    	}
    }
    ll n=SZ(e)+2;
    vector<ll>p;
    fore(i,0,n)p.pb(i);
    ll res=0;
    do{
    	vector<ll>ap(n);
    	fore(i,0,n)ap[p[i]]=i;
    	ll flag=1;
    	for(auto i:A){
    		if(flag=0)break;
    		if(ap[i.fst]>ap[i.snd])flag=0;
    	}
    	res+=flag;
    }
    while(next_permutation(ALL(p)));
    return res;
}
