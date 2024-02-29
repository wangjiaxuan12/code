#include <iostream>
#include <algorithm>

template<typename T>
class ArrayOps {
private:
    T* array;
    int size;

public:
    ArrayOps(T arr[], int n) {
        array = arr;
        size = n;
    }

    int search(T key) {
        for (int i = 0; i < size; i++) {
            if (array[i] == key) {
                return i;
            }
        }
        return -1;
    }

    void sort() {
        std::sort(array, array + size);
    }

    int interpolationSearch(T key) {
        int low = 0;
        int high = size - 1;
        while (low <= high && key >= array[low] && key <= array[high]) {
            int pos = low + (key - array[low]) * (high - low) / (array[high] - array[low]);
            if (array[pos] == key) {
                return pos;
            }
            if (array[pos] < key) {
                low = pos + 1;
            }
            else {
                high = pos - 1;
            }
        }
        return -1;
    }
};

int main() {

    int arr1[] = {3, 6, 1, 8, 2, 9, 4, 7, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ArrayOps<int> intOps(arr1, n1);

    std::cout << "Original int array: ";
    for (int i = 0; i < n1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    intOps.sort();
    std::cout << "Sorted int array: ";
    for (int i = 0; i < n1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    int key1 = 6;
    int pos1 = intOps.search(key1);
    if (pos1 == -1) {
        std::cout << key1 << " is not found." << std::endl;
    }
    else {
        std::cout << key1 << " is found at index " << pos1 << "." << std::endl;
    }

    key1 = 10;
    pos1 = intOps.interpolationSearch(key1);
    if (pos1 == -1) {
        std::cout << key1 << " is not found." << std::endl;
    }
    else {
        std::cout << key1 << " is found at index " << pos1 << "." << std::endl;
    }

    std::cout << std::endl;

    double arr2[] = {3.4, 6.2, 1.8, 8.1, 2.5, 9.9, 4.3, 7.6, 5.7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ArrayOps<double> doubleOps(arr2, n2);

    std::cout << "Original double array: ";
    for (int i = 0; i < n2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    doubleOps.sort();
    std::cout << "Sorted double array: ";
    for (int i = 0; i < n2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    double key2 = 6.2;
    int pos2 = doubleOps.search(key2);
    if (pos2 == -1) {
        std::cout << key2 << " is not found." << std::endl;
    }
    else {
        std::cout << key2 << " is found at index " << pos2 << "." << std::endl;
    }

    key2 = 10.0;
    pos2 = doubleOps.interpolationSearch(key2);
    if (pos2 == -1) {
        std::cout << key2 << " is not found." << std::endl;
    }
    else {
        std::cout << key2 << " is found at index " << pos2 << "." << std::endl;
    }

    return 0;
}

