#include <iostream>
#include <vector>
#include <chrono>

void print_vector(const std::vector<int>& data){
    for(int i : data){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/* Sorting data in ascending order */
void bubble_sort(std::vector<int>& data){
    for (int i = 0; i < data.size() - 1; i++){
        for (int j = 0; j < data.size() - i - 1; j++){
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}



int main(void){
    int n = 0;
    do {
        std::cout << "Input array size(positive number): ";
        std::cin >> n;
    } while(n < 1);

    /* Reading array */
    std::vector<int> data(n);
    for(int i = 0; i < n; ++i){
        std::cin >> data[i];
    }

    std::cout << "Original data: ";
    print_vector(data);

    std::vector <int> data2 = data ;


    auto start = std::chrono::high_resolution_clock::now();
    bubble_sort(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "Data after sorting: ";
    print_vector(data);

    std::cout << "Time taken: " << duration.count() << "ns" << std::endl;

    return 0;
}
