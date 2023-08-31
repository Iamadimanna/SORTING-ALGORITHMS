#include <iostream>
#include <vector>

// Function to print the current state of the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        std::cout << "Step " << i + 1 << ": ";
        printArray(arr);
    }
    std::cout << "Bubble Sort: In each pass, adjacent elements are compared and swapped if they are in the wrong order." << std::endl;
}

// Selection Sort
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
        std::cout << "Step " << i + 1 << ": ";
        printArray(arr);
    }
    std::cout << "Selection Sort: In each pass, the minimum element is selected and swapped with the current element." << std::endl;
}

// Insertion Sort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        std::cout << "Step " << i << ": ";
        printArray(arr);
    }
    std::cout << "Insertion Sort: In each pass, an element is picked and inserted into its correct position in the sorted subarray." << std::endl;
}

// Merge Sort
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
        std::cout << "Step: ";
        printArray(arr);
    }
    std::cout << "Merge Sort: The array is recursively divided into two halves, sorted individually, and then merged together." << std::endl;
}

// Quick Sort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        std::cout << "Pivot: " << arr[pi] << std::endl;
        std::cout << "Step: ";
        printArray(arr);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    std::cout << "Quick Sort: The array is divided into smaller subarrays based on a pivot element, and each subarray is sorted recursively." << std::endl;
}

// Heap Sort
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        std::cout << "Step " << n - i << ": ";
        printArray(arr);
    }
    std::cout << "Heap Sort: The array is transformed into a max-heap, and the largest element is repeatedly extracted and placed at the end." << std::endl;
}

// Radix Sort
int getMax(const std::vector<int>& arr) {
    int max = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr) {
    int max = getMax(arr);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
        std::cout << "Step: ";
        printArray(arr);
    }
    std::cout << "Radix Sort: The array is sorted based on each digit from least significant to most significant using counting sort." << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "\nBubble Sort:\n";
    bubbleSort(arr);

    std::cout << "\nSelection Sort:\n";
    selectionSort(arr);

    std::cout << "\nInsertion Sort:\n";
    insertionSort(arr);

    std::cout << "\nMerge Sort:\n";
    mergeSort(arr, 0, n - 1);

    std::cout << "\nQuick Sort:\n";
    quickSort(arr, 0, n - 1);

    std::cout << "\nHeap Sort:\n";
    heapSort(arr);

    std::cout << "\nRadix Sort:\n";
    radixSort(arr);

    return 0;
}
