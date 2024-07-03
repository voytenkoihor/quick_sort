#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// метод для обміну елементів масиву
void Swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

// метод повертає індекс опорного елементу
int Partition(vector<int>& array, int minIndex, int maxIndex) {
    int pivot = minIndex - 1;
    for (int i = minIndex; i < maxIndex; ++i) {
        if (array[i] < array[maxIndex]) {
            ++pivot;
            Swap(array[pivot], array[i]);
        }
    }

    ++pivot;
    Swap(array[pivot], array[maxIndex]);
    return pivot;
}

// швидке сортування
void QuickSort(vector<int>& array, int minIndex, int maxIndex) {
    if (minIndex >= maxIndex) {
        return;
    }

    int pivotIndex = Partition(array, minIndex, maxIndex);
    QuickSort(array, minIndex, pivotIndex - 1);
    QuickSort(array, pivotIndex + 1, maxIndex);
}

void QuickSort(vector<int>& array) {
    if (array.empty()) return;
    QuickSort(array, 0, array.size() - 1);
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << "N = ";
    int len;
    cin >> len;
    vector<int> a(len);
    for (int i = 0; i < len; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    QuickSort(a);

    cout << "Впорядкований масив: ";
    for (int i = 0; i < a.size(); ++i) {
        if (i != 0) cout << ", ";
        cout << a[i];
    }
    cout << endl;

    return 0;
}