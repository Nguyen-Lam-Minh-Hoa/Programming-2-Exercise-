#include <iostream>
using namespace std;

//function prototype
void merge(int array[], int left, int mid, int right);
void merge_sort(int array[], int left, int right);
void print_array(int array[], int size);

int main() {
    // install the array with the elements
    int array[] = {12, 67, 99, 7, 2, 58};
    int size = sizeof(array) / sizeof(array[0]);

    //print the original array
    cout<< "The original array is: \n";
    //call the function
    print_array(array, size);

    //call merge soft
    merge_sort(array, 0, size - 1);

    //print the sorted array
    cout << "Sorted array is: \n";
    //call the function
    print_array(array, size);

    return 0;    
}

//function to merge two subarray of the array
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create left_array = array[left ... mid], right_array = array[mid+1 ... right]
    int left_array[n1];
    int right_array[n2];

    for(int i = 0; i < n1; i++) {
        left_array[i] = array[left + i];
    }
    for(int i = 0; i < n2; i++) {
        right_array[i] = array[mid + 1 + i];
    }
    //maintain the current index of subarray
    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    // element place in the corect position
    while (i < n1 && j < n2) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        }
        else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = left_array[i];
        i++;
        k++;       
    }
    while (j < n2) {
        array[k] = right_array[j];
        j++;
        k++;
    }
}
// merge soft function
void merge_sort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        //call the fuction
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
//function to print the array
void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout<<endl;
}