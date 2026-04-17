#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

set<ll> s;

ll checkmax(ll k){
    ll num = 0;
    if(SZ(s) % 2 == 0){
        ll raiz = sqrtl(k) - 3;
        while(raiz < 0 || raiz * raiz != k){
            if(raiz * raiz > k) return 0;
            raiz++;
        }
        if(!s.count(raiz)) num = raiz;
    }
    for(auto x:s){
        if(k%x != 0) return 0;
        ll aux = k/x;
        if(!s.count(aux) && num>0) return 0;
        if(!s.count(aux)) num = aux;
    }
    return num;
}

int main(){
    JET
    ll n; cin>>n;
    fore(i,0,n){
        ll x; cin>>x;
        s.insert(x);
    }
    if(n == 1 && *s.begin() == 1){
        cout<<"*\n";
        return 0;
    }
    if(checkmax(*s.rbegin())){
        cout<<*s.rbegin()<<" "<<checkmax(*s.rbegin())<<"\n";
        return 0;
    }
    s.erase(1);
    cout<<*s.begin() * *s.rbegin()<<" "<<*s.begin() * *s.rbegin()<<"\n";
    return 0;
}