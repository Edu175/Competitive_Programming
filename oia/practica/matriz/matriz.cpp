#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, edu=b; i<edu; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),size_of(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;

using namespace std;

void procesaMatriz(vector<vector<int> > a, vector<long long> &resultadoEnArreglo, vector<vector<long long> > &resultadoEnMatriz){
    ll n=SZ(a), m=SZ(a[0]);
	ll sum=0,prod=1,maxi=-16515614,mini=65456465;
    for(auto v:a){
    	for(auto i:v){
    		sum+=i;
    		prod*=i;
    		maxi=max(maxi,ll(i));
    		mini=min(mini,ll(i));
    	}
    }
    resultadoEnMatriz={{sum,prod},{maxi,mini}};
    resultadoEnArreglo={sum,prod,maxi,mini};
}
