#include <iostream>
#include <vector>
#include <chrono>

void print_vector(const std::vector<int>& data){
    for(int i : data){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void merge(int array[], int st, int m, int en){
//void merge_sort ( std::vector<int> & data2  ) {
//
//    if ( data2.size() == 0 )
//        return ;
    int k;
    int n1 = m - st + 1;
    int n2 = en - m;
    int array_1[n1], array_2[n2];
    for (int i = 0; i < n1; i++) array_1[i] = array[st + i];
    for (int j = 0; j < n2; j++) array_2[j] = array[m + j + 1];
    int l = 0;
    int r = 0;
    k = st;
    while (l < n1 && r < n2){
        if (array_1[l] <= array_1[r]){
            array[k] = array_1[l];
            l++;}
        else{
            array[k] = array_2[r];
            r++;
        }
        k++;
    }
    while (l < n1){
        array[k] = (array_1[l]);
        l ++;
        k++;

    }
    while (r < n2){
        array[k] = array_2[r];
        r ++;
        k ++;
    }
}

/* Sorting data in ascending order */
void merge_sort(int arr[], int st, int en){
    if (st < en){

        int m = st + (en - st)/2;
        merge_sort(arr, st, m);
        merge_sort(arr, m + 1, en);

        merge(arr, st, m, en);
    }
}

int main(){
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

    int sorted[10000] ;
    for (int i = 0 ; i < data.size() ; i ++ ) {
        sorted[i] = data[i] ;
    }
    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(sorted , 0, data.size()-1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "Data after sorting: ";
    for (int i =0 ; i<data.size() ; i++ )
        std:: cout << sorted[i] << " " ;
    std:: cout << std:: endl ;

    std::cout << "Time taken: " << duration.count() << "ns" << std::endl;

    return 0;
}

