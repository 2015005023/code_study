#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n);  // 오름차순으로 정렬
    
    int max_result = 0;
    
    // next_permutation을 사용하여 순열을 탐색
    do {
        int total = 0;
        for (int i = 0; i < n - 1; i++) {
            total += abs(a[i] - a[i + 1]);
        }
        max_result = max(max_result, total);  // total이 더 크면 갱신
    } while (next_permutation(a, a + n));  // 다음 순열로 이동
    
    cout << max_result << endl;
    
    return 0;
}
