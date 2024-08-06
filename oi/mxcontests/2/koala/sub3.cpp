#include "koala.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,mxcont=b;i<mxcont;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jfhg:v)cout<<jfhg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int minValue(int N, int W) {
    return N+W;
}

int maxValue(int N, int W) {
    return N+W;
}
ll i=0,j=1;
int greaterValue(int n, int w) {
    ll res=-1;
    auto qan=[&](ll x)->int{
        cout<<"qan "<<x<<"\n";
        vector<ll>B(n),R(n);
        B[i]=B[j]=x;
        playRound(B.data(),R.data());
        imp(B); imp(R);
        vector<ll>s(n);
        fore(i,0,n)s[i]=R[i]>B[i];
        imp(s);
        if(s[i]!=s[j])res=s[i]<s[j];
        return s[i]+s[j];
    };
    vector<vector<ll>>magic={{1, 2, 4, 8},{51, 52, 54, 58}};
    ll sub=w==200;
    ll l=0,r=SZ(magic[sub])-1;
    while(l<=r){
        ll m=(l+r)/2;
        if(qan(magic[sub][m])==2)l=m+1;
        else r=m-1;
    }
    return res;
}

void allValues(int N, int W, int *P) {
    
}
