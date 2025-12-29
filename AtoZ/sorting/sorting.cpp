#include <bits/stdc++.h>
using namespace std;

// SORTING-I

// 1. Selection Sort - O(n²)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// 2. Bubble Sort - O(n²)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Optimization
    }
}

// 3. Insertion Sort - O(n²)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// SORTING-II

// 4. Merge Sort - O(n log n)
void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> temp;
    int left = l, right = mid + 1;

    while (left <= mid && right <= r) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= r) temp.push_back(arr[right++]);

    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

// 5. Recursive Bubble Sort - O(n²)
void recursiveBubbleSort(vector<int>& arr, int n) {
    if (n == 1) return;

    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    if (!swapped) return;
    recursiveBubbleSort(arr, n - 1);
}

void recursiveBubbleSort(vector<int>& arr) {
    recursiveBubbleSort(arr, arr.size());
}

// 6. Recursive Insertion Sort - O(n²)
void recursiveInsertionSort(vector<int>& arr, int n) {
    if (n <= 1) return;

    recursiveInsertionSort(arr, n - 1);

    int key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

void recursiveInsertionSort(vector<int>& arr) {
    recursiveInsertionSort(arr, arr.size());
}

// 7. Quick Sort - O(n log n) average, O(n²) worst
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// BONUS: Other useful sorting techniques

// Heap Sort - O(n log n)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Counting Sort - O(n + k) where k is range
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0), output(arr.size());

    for (int num : arr) count[num - minVal]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    arr = output;
}

// Utility functions
void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

vector<int> copyArray(const vector<int>& arr) {
    return arr;
}

int main() {
    vector<int> original = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    printArray(original, "");
    cout << "\n";

    cout << "=== SORTING-I ===\n\n";

    vector<int> arr = copyArray(original);
    selectionSort(arr);
    printArray(arr, "Selection Sort");

    arr = copyArray(original);
    bubbleSort(arr);
    printArray(arr, "Bubble Sort");

    arr = copyArray(original);
    insertionSort(arr);
    printArray(arr, "Insertion Sort");

    cout << "\n=== SORTING-II ===\n\n";

    arr = copyArray(original);
    mergeSort(arr);
    printArray(arr, "Merge Sort");

    arr = copyArray(original);
    recursiveBubbleSort(arr);
    printArray(arr, "Recursive Bubble Sort");

    arr = copyArray(original);
    recursiveInsertionSort(arr);
    printArray(arr, "Recursive Insertion Sort");

    arr = copyArray(original);
    quickSort(arr);
    printArray(arr, "Quick Sort");

    cout << "\n=== BONUS SORTS ===\n\n";

    arr = copyArray(original);
    heapSort(arr);
    printArray(arr, "Heap Sort");

    arr = copyArray(original);
    countingSort(arr);
    printArray(arr, "Counting Sort");

    cout << "\n=== TIME COMPLEXITIES ===\n";
    cout << "Selection Sort: O(n²)\n";
    cout << "Bubble Sort: O(n²)\n";
    cout << "Insertion Sort: O(n²)\n";
    cout << "Merge Sort: O(n log n)\n";
    cout << "Quick Sort: O(n log n) avg, O(n²) worst\n";
    cout << "Heap Sort: O(n log n)\n";
    cout << "Counting Sort: O(n + k)\n";

    return 0;
}
