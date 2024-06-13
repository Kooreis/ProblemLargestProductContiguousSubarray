```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int maxSubarrayProduct(std::vector<int> arr) {
    int n = arr.size();
    int max_end = 1;
    int min_end = 1;
    int max_so_far = 0;
    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            max_end = max_end * arr[i];
            min_end = std::min(min_end * arr[i], 1);
            flag = 1;
        }
        else if (arr[i] == 0) {
            max_end = 1;
            min_end = 1;
        }
        else {
            int temp = max_end;
            max_end = std::max(min_end * arr[i], 1);
            min_end = temp * arr[i];
        }

        if (max_so_far < max_end)
            max_so_far = max_end;
    }

    if (flag == 0 && max_so_far == 0)
        return 0;
    return max_so_far;
}

int main() {
    std::vector<int> arr = {1, -2, -3, 0, 7, -8, -2};
    std::cout << "Maximum Sub array product is " << maxSubarrayProduct(arr);
    return 0;
}
```