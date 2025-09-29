#include <iostream>

using namespace std;

int main() {
    const int LENGTH = 5;
    int arr[LENGTH] = {10, 20, 30, 40, 50};
    cout << &arr << endl;
    cout << &arr + 1 << endl;
    /*
     可以透過這神奇的方法，取得Array長度
     但不常使用，也不建議使用。
     除了可讀性較差外，如果是指標指向Array首個位址
     這個方法會失效。
     */
    cout << *(&arr + 1) - arr << endl;

    // 可透過Get Address得方式，並在迭代過程中修改內容.
    for (auto &num : arr) {
        cout << num << endl;
        num += 1;
    }

    for (auto &num : arr) {
        cout << num << endl;
    }
    if (true) {
    } else {
    }

    return 0;
}