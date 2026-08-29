#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv; 
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("O3,")
#define oper(a,b) (a)+(b)
#define NEUT 0

struct STree{
    vv t; ll n;
    STree(ll n):t(2*n+5,NEUT),n(n){}
    void upd(ll p, ll v){
        for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
    }
    ll __query(ll l, ll r){ // [,)
        ll res=NEUT;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)res=oper(res,t[l++]);
            if(r&1)res=oper(res,t[--r]);
        }
        return res;
    }
    ll query(ll l, ll r){ // [,)
        if(l>r)return __query(l,n)+__query(0,r);
        return __query(l,r);
    }
};

struct CustomBitset {
    ll n;
    ll size_count;
    vector<unsigned long long> words;
    
    CustomBitset(ll n) : n(n), size_count(0) {
        words.assign((n + 63) >> 6, 0ULL);
    }
    
    void insert(ll val) {
        if (!((*this)[val])) {
            words[val >> 6] |= (1ULL << (val & 63));
            size_count++;
        }
    }
    
    void erase(ll val) {
        if ((*this)[val]) {
            words[val >> 6] &= ~(1ULL << (val & 63));
            size_count--;
        }
    }
    
    bool operator[](ll val) const {
        return (words[val >> 6] >> (val & 63)) & 1ULL;
    }
    
    ll size() const { return size_count; }
    bool empty() const { return size_count == 0; }
    
    ll lower_bound(ll val) {
        if (size_count == 0) return -1;
        ll w_idx = val >> 6;
        ll bit_idx = val & 63;
        
        unsigned long long mask = (~0ULL) << bit_idx;
        unsigned long long current_word = words[w_idx] & mask;
        if (current_word != 0) {
            return (w_idx << 6) + __builtin_ctzll(current_word);
        }
        
        fore(i, w_idx + 1, SZ(words)) {
            if (words[i] != 0) {
                return (i << 6) + __builtin_ctzll(words[i]);
            }
        }
        
        fore(i, 0, w_idx + 1) {
            if (words[i] != 0) {
                return (i << 6) + __builtin_ctzll(words[i]);
            }
        }
        return -1;
    }
    
    ll prev_element(ll val) {
        if (size_count <= 1) return val;
        ll w_idx = val >> 6;
        ll bit_idx = val & 63;
        
        unsigned long long mask = bit_idx == 0 ? 0ULL : (~0ULL >> (64 - bit_idx));
        unsigned long long current_word = words[w_idx] & mask;
        if (current_word != 0) {
            return (w_idx << 6) + (63 - __builtin_clzll(current_word));
        }
        
        for (ll i = w_idx - 1; i >= 0; i--) {
            if (words[i] != 0) {
                return (i << 6) + (63 - __builtin_clzll(words[i]));
            }
        }
        
        for (ll i = SZ(words) - 1; i >= w_idx; i--) {
            if (words[i] != 0) {
                return (i << 6) + (63 - __builtin_clzll(words[i]));
            }
        }
        return val;
    }

    ll next_element(ll val) {
        if (size_count <= 1) return val;
        ll w_idx = val >> 6;
        ll bit_idx = val & 63;
        
        unsigned long long mask = bit_idx == 63 ? 0ULL : (~0ULL << (bit_idx + 1));
        unsigned long long current_word = words[w_idx] & mask;
        if (current_word != 0) {
            return (w_idx << 6) + __builtin_ctzll(current_word);
        }
        
        fore(i, w_idx + 1, SZ(words)) {
            if (words[i] != 0) {
                return (i << 6) + __builtin_ctzll(words[i]);
            }
        }
        
        fore(i, 0, w_idx + 1) {
            if (words[i] != 0) {
                return (i << 6) + __builtin_ctzll(words[i]);
            }
        }
        return val;
    }
};

int main(){
    JET
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vv a(n-3);
        fore(i,0,n-3)cin>>a[i],a[i]--;
        ll mis=0;
        vv bl(n);
        STree seg(n); // is alive
        fore(i,0,n)seg.upd(i,1);
        
        CustomBitset bar(n); // i -- i+1
        vv inb(n,1);
        fore(i,0,n)bar.insert(i);
        
        ll cad=n;
        ll tam=n;
        vv L(n),R(n);
        fore(i,0,n)L[i]=(i-1+n)%n,R[i]=(i+1)%n;
        
        auto cir=[&](){return bar.empty();};
        auto lin=[&](){return bar.size()==1;};
        
        auto lwb=[&](ll p){
            return bar.lower_bound(p);
        };
        auto pre=[&](ll item){
            return bar.prev_element(item);
        };
        auto nxt=[&](ll item){
            return bar.next_element(item);
        };
        
        auto val=[&](ll item)->ll {
            if(item == -1){
                assert(cir());
                return tam/2;
            }
            if(lin()){
                return (tam+1)/2;
            }
            ll z=seg.query(pre(item)+1, item+1);
            ll ret=(z+1)/2;
            return ret;
        };
        auto hay=[&](ll l, ll r)->bool { // [l,r)
            ll item = lwb(l);
            if(item == -1) return 0;
            if(l>r)return item>=l || item<r;
            return l<=item && item<r;
        };
        auto add=[&](ll b){ // bar b
            if(inb[b])return;
            inb[b]=1;
            bool era=cir();
            ll item = lwb(b);
            cad-=val(item);
            bar.insert(b);
            item = lwb(b);
            cad+=val(item);
            if(!era)cad+=val(nxt(item));
        };
        auto rem=[&](ll b){
            if(!inb[b])return;
            inb[b]=0;
            ll item = lwb(b);
            cad-=val(item);
            ll v=val(nxt(item));
            bar.erase(b);
            item = lwb(b);
            bool es=cir();
            if(!es)cad-=v;
            cad+=val(item);
        };
        auto block=[&](ll x){
            if(bl[x])return;
            add(x);
            add(L[x]);
            bl[x]=1; cad--;
        };
        auto sac=[&](ll x){ // already blocked
            assert(bl[x]);
            L[R[x]]=L[x];
            R[L[x]]=R[x];
            seg.upd(x,0);
            tam--;
            rem(L[x]);
            rem(x);
            if(!bl[L[x]]&&!bl[R[x]]){ // add edge
                rem(L[x]);
            }
            else {
                add(L[x]);
            }
        };
        fore(i,0,SZ(a)){
            ll x=a[i];
            ll l=L[x],r=R[x];
            if(!bl[x]){
                mis++;
                if(!hay(l,x))block(l);
                if(!hay(x,r))block(r);
                block(x);
            }
            sac(x);
            ll res=mis+cad;
            cout<<n-res<<" ";
        }
        cout<<"\n";
    }
    return 0;
}