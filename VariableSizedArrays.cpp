//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//int main()
//{
//	int n, q;
//	std::cin >> n >> q;
//	std::vector<int> a[n];
//
//
//}

//#include <iostream>
//#include <vector>
//
//int main() 
//{
//	int n;
//	int q;
//	std::cin >> n >> q;
//	std::vector<int> a[2];
//	for (int i = 0; i < n; ++i) {
//		int m;
//		std::cin >> m;
//		int o;
//		for (int j = 0; j < m; ++j) {
//			std::cin >> o;
//			a[i].push_back(o);
//		}
//	}
//
//	int r, s;
//	for (int k = 1; k <= q; ++k) {
//		std::cin >> r >> s;
//		std::cout << a[r][s] << std::endl;
//	}
//	return 0;
//}

#include <cstdio>

using namespace std;

int main() {
	int N, Q, k;
	int **data;
	scanf("%d %d", &N, &Q);
	data = new int*[N];
	for (int i = 0; i<N; i++) {
		scanf("%d", &k);
		data[i] = new int[k];
		for (int j = 0; j<k; j++) {
			scanf("%d", &data[i][j]);
		}
	}

	int a, b;
	for (int i = 0; i<Q; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", data[a][b]);
	}

	return 0;
}