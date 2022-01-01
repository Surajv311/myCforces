#include "bits/stdc++.h"
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define foru(i , a , b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define ford(i , a , b) for(ll i = (ll)(a) ; i >= (ll)(b) ; i--)
#define ain(a , n) for(int i = 0 ; i < (int)n ; i++) cin >> a[i]
#define aout(a , n) for(int i = 0 ; i < (int)n ; i++) cout << a[i] << " "; cend
#define M 1000000007ll
#define mp make_pair
#define Random_Generator(name) mt19937 name(chrono::steady_clock::now().time_since_epoch().count());
#define cend cout << "\n"
#define all(x) x.begin() , x.end()
#define aout2(a , n , m) for(ll i = 0 ; i < n ; i++){for(ll j = 0 ; j < m ; j++){cout << a[i][j] << " ";} cout << endl;}
#define ain2(a , n , m) for(ll i = 0 ; i < n ; i++){for(ll j = 0 ; j < m ; j++){cin >> a[i][j];}}
#define ff first
#define ss second
#define sz(a) ((long long)(a).size())
#define mset(a , b) memset(a , b , sizeof(a))
#define pb push_back
#define endn '\n'
#define google cout << "Case #" << test_num << ": "
#ifdef PARTH
#define dbg(a) cerr << #a << ": "; _print(a); cerr << endl;
#else
#define dbg(a) // No more TLEs
#endif

using namespace std;
using namespace std::chrono;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vch;
typedef vector <string> vs;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef pair <ll , ll> pll;
typedef vector <pair <ll , ll>> vpll;
typedef vector <pair <int, int>> vpi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
//void _print(ordered_set &v){cerr<<"[ ";for(int i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*----------------------------- # --- MATH ALGORITHMS --- # -----------------------------*/

template <class T> T gcd(T a , T b) { while (a != 0) {T temp = a; a = b % a; b = temp;} return b;}
template <class T> T egcd(T a , T b , T &x , T &y) {T gcd , xt , yt; if (a == 0) {gcd = b; x = 0 , y = 1;} else {gcd = egcd(b % a , a , xt , yt); x = yt - (b / a) * xt; y = xt;} return gcd;}
template <class T> T expo(T base , T exp , T mod) {T res = 1; base = base % mod; while (exp > 0) {if (exp & 1)res = (res * base) % mod; exp = exp >> 1; base = (base * base) % mod;} return res;}
template <class T> T modinv(T a , T mod) {T x , y; egcd<T>(a , mod , x , y); while (x < 0) x += mod; while (x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T a , T mod) {return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b) {return a > b;}
template <class T> ll maxpower(T a , T b) {ll ans = 0; while (a > 0 && a % b == 0) {ans++; a /= b;} return ans;}
template <class T> T mceil(T a, T b) {if (a % b == 0) return a / b; else return a / b + 1;}
template <class T> T lcm(T a, T b) {return (a * b) / gcd<T>(a, b);}
const ll infl = 1e18; const int inf = 1e9 + 5;

/*----------------------------- # --- MAIN CODE --- # -----------------------------*/

vector<int> intime;
vector<int> outtime;
vector<int> level;
vector<vector<int>> up;
vector<vector<int>> adj;
vector<ll> fact;

ll ncr(ll n, ll r) {
	if (n < r) {
		return 0;
	}
	return (fact[n] * modinv<ll>((fact[n - r] * fact[r]) % M, M)) % M;
}

const int l = 8; // Initialise l with ceil(log(n)) where n is the number of vertices
int Time = -1;
void dfs(int s, int p, int lev) {
	Time++;
	intime[s] = Time;
	up[s][0] = p;
	level[s] = lev;
	for (int i = 1; i <= l; i++) {
		up[s][i] = up[up[s][i - 1]][i - 1];
	}
	for (int u : adj[s]) {
		if (u != p) {
			dfs(u, s, lev + 1);
		}
	}
	Time++;
	outtime[s] = Time;
}
inline bool is_ancestor(int u, int v) {
	return intime[u] <= intime[v] and outtime[u] >= outtime[v];
}
inline int lca(int u, int v) {
	if (is_ancestor(u, v)) {
		return u;
	}
	if (is_ancestor(v, u)) {
		return v;
	}
	for (int i = l; i >= 0; i--) {
		if (!is_ancestor(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}


void test_case(int test_num) {
	int n;
	cin >> n;
	adj = vector<vector<int>>(n);
	intime = vector<int>(n);
	outtime = vector<int>(n);
	level = vector<int>(n);
	fact = vector<ll>(n + 5);
	fact[0] = 1;
	vector<vector<ll>> dp(205, vector<ll>(205));
	for (int i = 0; i < 205; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < 205; i++) {
		for (int j = 1; j < 205; j++) {
			dp[i][j] = (((dp[i - 1][j] + dp[i][j - 1]) % M) * modinv<ll>(2, M)) % M;
		}
	}
	for (int i = 1; i < n + 5; i++) {
		fact[i] = (i * fact[i - 1]) % M;
	}


	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dbg(adj)
	ll tot_ans = 0;
	ll total = (n * (n - 1)) / 2;
	ll total_inv = modinv<ll>(total, M);
	for (int root = 0; root < n; root++) {
		up = vector<vector<int>>(n, vector<int>(l + 1));
		Time = -1;
		intime = vector<int>(n);
		outtime = vector<int>(n);
		level = vector<int>(n);
		dfs(root, root, 0);
		ll ans = 0;
		dbg(level)
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int u = j, v = i;
				int LCA = lca(u, v);
				ll dist_u = level[u] - level[LCA];
				ll dist_v = level[v] - level[LCA];
				ll total_dist = dist_u + dist_v;
				// dbg(total_dist)
				if (dist_v != 0) {
					ll prob = dp[dist_u][dist_v];
					ans = (ans + prob) % M;
				}
			}
		}
		ans = (ans * modinv<ll>(n, M)) % M;
		tot_ans = (tot_ans + ans) % M;
		dbg(tot_ans)
	}
	cout << tot_ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifdef PARTH
	FILE* inp = freopen("input.txt", "r", stdin);
	FILE* err = freopen("error.txt", "w", stderr);
	FILE* out = freopen("output.txt", "w", stdout);
#endif
	int _;
	_ = 1;
	// cin >> _;
	auto start = high_resolution_clock::now();
	cout << setprecision(15);
	for (int t = 1; t <= _; t++) {
		test_case(t);
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
#ifdef PARTH
	cerr << "Time: " << duration.count() / 1000.0 << endl;
#endif
	return 0;
}