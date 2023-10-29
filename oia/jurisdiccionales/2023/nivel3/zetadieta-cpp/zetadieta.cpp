#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ii> a={{27,105},{30,120},{1,9}};

long long zetadieta(int C, int P, int G) {
    vector<ll> c={C,P,G};
    ll res=0;
    fore(i,0,3){
    	res+=((c[i]+a[i].fst-1)/a[i].fst)*a[i].snd;
    }
    return res;
}
