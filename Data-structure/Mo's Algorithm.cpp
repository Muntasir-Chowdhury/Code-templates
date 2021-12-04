#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 1e6 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

ll mp[Max];

int BLOCK_SIZE;
ll cnt;

int ar[Max];
ll ans[Max];

struct Node {
	ll l, r, id;

	Node() {};

	Node(int l_, int r_, int id_) {
		l = l_;
		r = r_;
		id = id_;
	}

	bool operator<(const Node &b) const {
		if(l / BLOCK_SIZE < b.l / BLOCK_SIZE) {
			return 1;
		}
		if(l / BLOCK_SIZE > b.l / BLOCK_SIZE) {
			return 0;
		}
		return ((l / BLOCK_SIZE) & 1) ? r < b.r : r > b.r;
	}
} qr[Max];

int tog[Max];

void add(int x) {
	cnt -= mp[x] * mp[x] * x;
	mp[x]++;
	cnt += mp[x] * mp[x] * x;
}

void del(int x) {
	cnt -= mp[x] * mp[x] * x;
	mp[x]--;
	cnt += mp[x] * mp[x] * x;
}

int main() {
#ifdef Mr_Emrul
	freopen("inputf.in", "r", stdin);
#endif ///Mr_Emrul

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int n, m, l, r;
	scanf("%d %d", &n, &m);
	BLOCK_SIZE = 1000;

	for(int i = 1; i <= n; i++) {
		scanf("%d", &ar[i]);
	}

	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &l, &r);
		qr[i] = Node(l, r, i);
	}

	sort(qr + 1, qr + m + 1);

	ll L = 1, R = 0;

	for(int i = 1; i <= m; i++) {
		ll l = qr[i].l;
		ll r = qr[i].r;

		while(R < r) {
			R++;
			add(ar[R]);
		}

		while(R > r) {
			del(ar[R]);
			R--;
		}

		while(L < l) {
			del(ar[L]);
			L++;
		}

		while(L > l) {
			L--;
			add(ar[L]);
		}

		ans[ qr[i].id ] = cnt;
	}

	for(int i = 1; i <= m; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}
