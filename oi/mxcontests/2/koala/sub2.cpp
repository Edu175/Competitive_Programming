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

int minValue(int n, int w) {
    // TODO: Implement Subtask 1 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    int B[n],R[n];
    fore(i,0,n)B[i]=R[i]=0;
    B[0]=1;
    playRound(B,R);
    ll mn=-1;
    fore(i,0,n)if(B[i]>=R[i])mn=i;
    return mn;
}

int maxValue(int n, int w) {
    // TODO: Implement Subtask 2 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    vector<ll>ks={1,2,4,10};
    vector<ll>good(n,1);
    int B[n],R[n];
    fore(ro,0,SZ(ks)){
        fore(i,0,n)B[i]=R[i]=0;
        if(ro==3){
            vector<ll>idx;
            fore(i,0,n)if(good[i])idx.pb(i);
            good[rng()%SZ(idx)]=0;
        }
        fore(i,0,n)if(good[i])B[i]=ks[ro];
        playRound(B,R);
        fore(i,0,n)good[i]&=R[i]>B[i];
    }
    ll res=-1;
    fore(i,0,n)if(good[i])res=i;
    return res;
}

int greaterValue(int N, int W) {
    // TODO: Implement Subtask 3 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    return 0;
}

void allValues(int N, int W, int *P) {
    if (W == 2*N) {
        // TODO: Implement Subtask 4 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    } else {
        // TODO: Implement Subtask 5 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    }
}
