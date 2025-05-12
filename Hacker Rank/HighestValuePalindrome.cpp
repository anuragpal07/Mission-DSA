#include <bits/stdc++.h>
using namespace std;

#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

typedef long long ll;
const int MOD = 1000000007;

template<class T> inline T tmin(T a, T b) { return (a < b) ? a : b; }
template<class T> inline T tmax(T a, T b) { return (a > b) ? a : b; }
template<class T> inline void amax(T &a, T b) { if (b > a) a = b; }
template<class T> inline void amin(T &a, T b) { if (b < a) a = b; }
template<class T> inline T tabs(T a) { return (a > 0) ? a : -a; }
template<class T> T gcd(T a, T b) { while (b != 0) { T c = a; a = b; b = c % b; } return a; }

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
	int n, k;
	string s;

	cin >> n >> k >> s;
	int hn = n >> 1;
	int diff = 0;
	REPU(i, 0, hn) {
		if (s[i] != s[n - 1 - i]) diff++;
	}
	if (diff > k) {
		puts("-1"); return 0;
	}
	int rem = k;
	REPU(i, 0, hn + 1) {
		if (rem <= 0) break;
		if (s[i] != s[n - 1 - i]) {
			diff--;
			if (s[i] == '9' || s[n - 1 - i] == '9') {
				s[i] = s[n - 1 - i] = '9';
				rem--;
			}
			else if (rem - 2 >= diff) {
				s[i] = s[n - 1 - i] = '9';
				rem -= 2;
			}
			else {
				if (s[i] > s[n - 1 - i]) s[n - 1 - i] = s[i];
				else s[i] = s[n - 1 - i];
				rem--;
			}
		}
		else if (i != n - i - 1 && s[i] < '9' && rem - 2 >= diff) {
			s[i] = s[n - 1 - i] = '9';
			rem -= 2;
		}
		else if (i == n - i - 1 && s[i] < '9' && rem - 1 >= diff) {
			s[i] = '9';
			rem--;
		}
	}
	printf("%s\n", s.c_str());
	
	return 0;
}