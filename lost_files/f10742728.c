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

//'A'<'a';

int vial(int K, int C, string &tipo, vector<int> &cuantos, vector<int> &pos, string &queHay) {
    map<ll,ll>colocar;
    map<ll,ll>hay;
    vector<pair<ll,ll>>km;
    fore(i,0,SZ(queHay)){
    	if(queHay[i]>='a')hay[pos[i]]=1;
    	else colocar[pos[i]]=1;
    	km.pb({pos[i],queHay[i]>='a'});
    }
    ll s=0,res=0;
    sort(ALL(km));
    for(auto i:km){
    	res+=C*(i.fst-s);
    	if(i.snd&&!hay[i.fst])res+=K;
    	if(i.fst&&!colocar[i.fst])res+=K;
    	s=i.fst;
    }
	return res;    
}
