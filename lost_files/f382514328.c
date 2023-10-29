#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) (x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef int ll;

using namespace std;

void duplilong(vector<string> &palabras, int k, vector<int> & longitudes){
    ll n=SZ(palabras);
    fore(i,0,k)longitudes[i]=SZ(palabras[i]);
    fore(i,n-k,n)palabras[i]+=palabr