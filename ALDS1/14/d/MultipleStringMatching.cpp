#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class SuffixArray{
    string s;
    vector<int> sa, rev;
public:
    SuffixArray(const string &str) : s(str) {
        int n = s.size();
        s.push_back('$');
        sa.resize(n+1);
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(),
            [&](int a,int b){
                if(s[a] == s[b]){
                    return a > b;
                }
                return s[a] < s[b];
            });
        vector<int> c(n+1), r(n+1), cnt(n+1);
        for(int i = 0; i <= n; i++){
            r[i] = s[i];
        }
        for(int len = 1; len <= n; len *= 2){
            for(int i = 0; i <= n; ++i){
                c[sa[i]] = i;
                if(i > 0 && r[sa[i-1]] ==r[sa[i]] 
                    && sa[i-1] + len <= n 
                    && r[sa[i-1]+len/2] == r[sa[i]+len/2]){
                    
                    c[sa[i]]=c[sa[i-1]];
                }
            }
            iota(cnt.begin(), cnt.end(), 0);
            copy(sa.begin(), sa.end(), r.begin());
            for(int i = 0; i <= n; ++i){
                int s1 = r[i] - len;
                if(s1 >= 0){
                    sa[cnt[c[s1]]++]=s1;
                }
            }
            c.swap(r);
        }
        rev.resize(n+1);
        for(int i = 0; i <= n; ++i){
            rev[sa[i]] = i;
        }
    }

    int operator[](int i) const { return sa[i]; }

    bool lt_substr(string &t,int si,int ti){
        int sn = s.size();
        int tn = t.size();
        while(si < sn && ti < tn){
            if(s[si] < t[ti]){
                return 1;
            }
            if(s[si]>t[ti]){
                return 0;
            }
            si++; ti++;
        }
        return si == sn && ti < tn;
    }

    int lower_bound(string& t){
        int l = 0;
        int r = s.size();
        while(l+1 < r){
            int m = (l + r) >> 1;
            if(lt_substr(t, sa[m], 0)){
                l = m;
            }
            else{
                r = m;
            }
        }
        return r;
    }

    int upper_bound(string& t){
        t.back()++;
        int res = lower_bound(t);
        t.back()--;
        return res;
    }

    int count(string& T){
        return upper_bound(T) - lower_bound(T);
    }
};


int main(){
    
    string t;
    int q;
    cin >> t >> q;
    
    SuffixArray sa(t);
    for(int i = 0; i < q; ++i){
        string p;
        cin >> p;
        if(sa.count(p) > 0){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}