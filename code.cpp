// https://leetcode.com/problems/implement-trie-prefix-tree/

#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define rsrtl(v) sort(v.begin(), v.end(), greater<ll>())
#define fi(i, a, b) for (int i = a; i < b; i++)
#define fll(i, a, b) for (ll i = a; i < b; i++)
#define srt(v) sort(v.begin(), v.end())
#define pb push_back
#define g(v, i, j) get<i>(v[j])
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(),(x).end()
#define ll long long
ll md = 1000000007;
#define theartofwar                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define F first
#define S second
#define sz(v) v.size()
using namespace std;
#define dbg(x) cerr << #x << " = " << x << endl;
template <typename T>
T pw(T a, T b){
    T c = 1, m = a;
    while (b){
        if (b & 1) c = (c * m);
        m = (m * m), b /= 2;
    }
    return c;
}
template <typename T>
T ceel(T a, T b){
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
template <typename T>
T my_log(T n, T b){
    T i = 1, ans = 0;
    while (1){
        if (i > n){
            ans--;
            break;
        }
        if (i == n) break;
        i *= b, ans++;
    }
    return ans;
}
template <typename T>
T gcd(T a, T b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll pwmd(ll a, ll b){
    ll c = 1, m = a;
    while (b){
        if (b & 1) c = (c * m) % md;
        m = (m * m) % md;
        b /= 2;
    }
    return c;
}
ll modinv(ll n){
    return pwmd(n, md - 2);
}
ll inverse(ll i){
    if (i == 1)
        return 1;
    return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b){
    return (a.second < b.second);
}


class TrieNode{
public:
    bool isend;
    TrieNode *child[26];
    TrieNode(){
        isend = false;
        for (int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

class Trie {   
public:
    TrieNode *root = new TrieNode();
    Trie() {
        
    }
    // insert word into the Trie
    void insert(string word) {
        int len = word.length();
        TrieNode *temp = root;
        for (int i = 0; i < len; i++){
            if (!temp -> child[word[i] - 'a']){
                temp -> child[word[i] - 'a'] = new TrieNode();
            }
            temp = temp -> child[word[i] - 'a'];
        }
        temp -> isend = true;
    }
    // tells if word is in Trie
    bool search(string word) {
        int len = word.length();

        TrieNode *temp = root;
        for (int i = 0; i < len; i++){
            temp = temp -> child[word[i] - 'a'];
            if (!temp) return false;
        }
        return temp -> isend;
    }
    // tells if prefix is a prefix of some string word
    bool startsWith(string prefix) {
        int len = prefix.length();

        TrieNode *temp = root;
        for (int i = 0; i < len; i++){
            temp = temp -> child[prefix[i] - 'a'];
            if (!temp) return false;
        }
        return true;
    }
};

int main()
{
    theartofwar;
    Trie *tree = new Trie();
    string s1 = "ankit";
    string s2 = "vivek";
    tree -> insert(s1);
    tree -> insert(s2);
    if (tree -> startsWith("anki")) cout << "Working";
}
