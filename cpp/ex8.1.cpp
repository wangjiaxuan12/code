#include <iostream>

template<typename T, int size>
void array_stats(T (&arr)[size])
{
    T max = arr[0];
    T min = arr[0];
    T sum = arr[0];
    for(int i=1; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
        sum += arr[i];
    }
    std::cout << "Max value: " << max << std::endl;
    std::cout << "Min value: " << min << std::endl;
    std::cout << "Average value: " << sum/static_cast<T>(size) << std::endl;
}

int main()
{
    int int_arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    double double_arr[] = {1.2, 2.3, 3.4, 4.5, 5.6};
    
    std::cout << "Int array stats: " << std::endl;
    array_stats(int_arr);
    std::cout << "Double array stats: " << std::endl;
    array_stats(double_arr);
    
    return 0;
}
