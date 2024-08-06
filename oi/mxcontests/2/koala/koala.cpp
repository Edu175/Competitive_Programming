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
ll n,w;
vector<ll>per;
void init(ll N, ll W, ll doit=1){
    n=N,w=W;
    per=vector<ll>(n);
    iota(ALL(per),0);
    if(doit)shuffle(ALL(per),rng);
}
void play_round(int *B, int *R){
    vector<ll>b(n),r(n);
    fore(i,0,n)b[i]=B[per[i]];
    playRound(b.data(),r.data());
    fore(i,0,n)R[per[i]]=r[i];
}

int minValue(int N, int W) {
    init(N,W);
    int B[n],R[n];
    fore(i,0,n)B[i]=R[i]=0;
    B[0]=1;
    play_round(B,R);
    ll mn=-1;
    fore(i,0,n)if(B[i]>=R[i])mn=i;
    return mn;
}
ll fn(ll n){return n*(n+1)/2;}
vector<ll> alice(vector<ll>&b){
	vector<vector<ll>>dp(n+1,vector<ll>(w+1));
	for(ll i=n-1;i>=0;i--)fore(u,0,w+1){
		ll &res=dp[i][u];
		res=dp[i+1][u];
		if(u+b[i]+1<=w)res=max(res,i+1+dp[i+1][u+b[i]+1]);
	}
	ll u=0;
	vector<ll>r(n);
	fore(i,0,n){
		ll q=0;
		if(u+b[i]+1<=w&&dp[i][u]==i+1+dp[i+1][u+b[i]+1])q=b[i]+1;
		r[i]=q;
		u+=q;
	}
	return r;
}
ll old=-1,val=-1;
void new_t(vector<ll>&t, vector<ll>B, vector<ll>R){
    vector<vector<ll>>h(n,vector<ll>(2));
    fore(i,0,n)h[t[i]][R[i]>B[i]]=1;
    ll cnt=0;
    fore(i,0,n)fore(j,0,2)if(h[i][j])h[i][j]=cnt++;
    fore(i,0,n)t[i]=h[t[i]][R[i]>B[i]];
}
vector<ll>b,t,best;
ll value(vector<ll>r){
    auto t_=t;
    new_t(t_,b,r);
    return *max_element(ALL(t_));
}
ll s;
// map<vector<ll>,vector<ll>>dp;
ll increasing=1;
void f(){
    // if(!SZ(b)&&dp.count(t)){best=dp[t];return;}
	if(SZ(b)==n){
		ll vali=value(alice(b));
		if(val==-1||vali>val)best=b,val=vali;//,dp[t]=best; // maximize value
		return;
	}
	ll i=SZ(b);
	auto go=[&](ll v){
        if(val>old)return;
		s+=v; b.pb(v);
		if(s<=w)f();
		s-=v; b.pop_back();
	};
	if(i&&t[i]==t[i-1])go(b.back());
	else fore(v,increasing&&SZ(b)?b.back():0,w-s+1)go(v);
}
bool compare(ll i, ll j){
    ll res=-1;
    auto qan=[&](ll x)->int{
        // cout<<"qan "<<x<<"\n";
        vector<ll>B(n),R(n);
        B[i]=B[j]=x;
        play_round(B.data(),R.data());
        // imp(B); imp(R);
        vector<ll>s(n);
        fore(i,0,n)s[i]=R[i]>B[i];
        // imp(s);
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
int greaterValue(int N, int W) {
    init(N,W,0);
    return compare(0,1);
}
void msort(vector<ll>&a){
    if(SZ(a)<=1)return;
    ll n=SZ(a),m=n/2;
    vector<ll>l,r;
    fore(i,0,m)l.pb(a[i]);
    fore(i,m,n)r.pb(a[i]);
    msort(l); msort(r);
    a.clear();
    reverse(ALL(l)); reverse(ALL(r));
    while(SZ(l)||SZ(r)){
        ll ele=0;
        if(!SZ(l))ele=1;
        else if(!SZ(r))ele=0;
        else ele=!compare(l.back(),r.back());
        if(ele)a.pb(r.back()),r.pop_back();
        else a.pb(l.back()),l.pop_back();
    }
}
vector<ll>ty;
ll cnt=0;
void strat(){
	if(val==n)return;
	old=val;
    val=-1;
    if(cnt>=33){
        vector<ll>ans;
        // cout<<"strat "<<cnt<<": "; imp(t); imp(ty);
        fore(v,0,50){
            vector<ll>a;
            fore(i,0,n)if(ty[i]==v)a.pb(i);
            // cout<<"subarray "<<v<<": "; imp(a);
            msort(a);
            for(auto i:a)ans.pb(i);
            
        }
        fore(i,0,n)ty[ans[i]]=i;
        return;
    }
	f();
    vector<ll>ks(n);
    fore(i,0,n)ks[t[i]]=best[i];
    vector<ll>B(n),R(n);
    fore(i,0,n)B[i]=ks[ty[i]];
    play_round(B.data(),R.data());
    // for(auto i:b)cout<<i<<""
    // imp(B); imp(R);
    new_t(ty,B,R);
	auto r=alice(best);
    new_t(t,best,r);
    // imp(best) imp(r); cout<<"\n";
    cnt++;
    strat();
}

int maxValue(int N, int W) {
    init(N,W);
    /*t=ty=vector<ll>(n);
    strat();
    ll mx=0;
    fore(i,0,n)if(ty[i]>ty[mx])mx=i;
    return mx;*/
    return 0;
}

void allValues(int N, int W, int *P) {
    init(N,W);
    t=ty=vector<ll>(n);
    old=1,val=-1;
    strat();
    fore(i,0,n)P[i]=ty[per[i]]+1;
    // if (W == 2*N) {
        
    // } else {
        
    // }
}
