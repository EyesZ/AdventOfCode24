#include <bits/stdc++.h>
using namespace std;

long long checksum_chunk(const std::vector<int> &zzz) {
	std::unordered_map<int, int> m1, m2;
	int j = 0, l = 0;
	for (int i = 0; i < zzz.size(); i++) {
		int k = 0;
        if (i % 2 == 1 ) {
            k = -(i / 2 + 1);   // this 
        } else {
            k = i / 2;          // that
        }

		if (i % 2 == 0) {
			j = k;
		}

		m1[k]  = zzz[i];
		m2[k] = l;
		l += zzz[i];
	}

	while (j > 0) {
		for (int i = 1; i <= j; i++) {
            // if this is smaller than that, then continue
			if (m1[-i] < m1[j]) {
				continue;
			}
            // remove the that from this
            // and replace pos of this with that
            // and add that to this
			m1[-i] -= m1[j];
			m2[j] = m2[-i];
			m2[-i] += m1[j];

			break;
		}

		j--;
	}

	long long sum = 0;
	for (const auto &[n, p] : m2) {
		if (n < 0) {
			continue;
		}

		for (int i = 0; i < m1[n]; i++) {
			sum += n * (p + i);
		}
	}

	return sum;
}

int main() {
    string line;
    getline(cin, line);

    vector<int> zzz;
    for (char c : line) {
        zzz.push_back(c-'0');
    }

    long long sum = 0;
    sum = checksum_chunk(zzz);
    cout << sum << endl;
    return 0;
}