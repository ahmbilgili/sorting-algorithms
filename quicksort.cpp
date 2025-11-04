#include <iostream>
#include <vector>
#include <assert.h>
#include "sort_utils.h"

// chooses middle element in sublist as pivot
int partition_list_middle(std::vector<int> &A, int r, int q) 
{
    int pivot_index = (r+q)/2;
    // place pivot element to front
    int temp = A[r];
    A[r] = A[pivot_index];
    A[pivot_index] = temp;

    int i = r;
    int j = r + 1;
    int k = i;

    // Iteration
    while (j < q)
    {
        if (A[j] < A[r])
        {
            i = i+1; k = k+1;
            int loop_temp = A[i];
            A[i] = A[j];
            A[j] = loop_temp;
        }
        else if (A[j] == A[r])
        {
            k = k+1;
            int loop_temp = A[k];
            A[k] = A[j];
            A[j] = loop_temp;
        }
        j = j+1;
    }



    // swap pivot with A[i], placing pivot in its correct position.
    temp = A[i];
    A[i] = A[r];
    A[r] = temp;
    return i;
}

// chooses first element in sublist as pivot
int partition_list_firstelem(std::vector<int> &A, int r, int q) 
{
    int pivot_index = r;
    int pivot_elem = A[pivot_index];
    // cout << "pivot index: " << pivot_index << endl;

    int i = pivot_index;
    int j = pivot_index + 1;
    int k = i;

    // Iteration
    while (j < q)
    {
        if (A[j] < pivot_elem)
        {
            i = i+1; k = k+1;
            int loop_temp = A[i];
            A[i] = A[j];
            A[j] = loop_temp;
        }
        else if (A[j] == pivot_elem)
        {
            k = k+1;
            int loop_temp = A[k];
            A[k] = A[j];
            A[j] = loop_temp;
        }
        j = j+1;
    }

    // swap pivot with A[i], placing pivot in its correct position.
    int temp = A[i];
    A[i] = A[r];
    A[r] = temp;
    return i;
}

void quicksort_middle_partition(std::vector<int> &A, int r, int q)
{
    if (r < q)
    {
        int p = partition_list_middle(A, r, q);
        std::cout << "Result of partitioning: ";
        print_vector(A);
        quicksort_middle_partition(A, r, p-1);
        quicksort_middle_partition(A, p+1, q);
    }
}

void quicksort_firstelem_partition(std::vector<int> &A, int r, int q)
{
    if (r < q)
    {
        int p = partition_list_firstelem(A, r, q);
        std::cout << "Result of partitioning: ";
        print_vector(A);
        quicksort_firstelem_partition(A, r, p-1);
        quicksort_firstelem_partition(A, p+1, q);
    }
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cout << "No elements provided, please provide elements (leaving a single space in between each element)" 
            << "\n" << "Example: 1 3 5" << "\n";
        return 1;
    }

    std::vector<int> input_vec_1;
    std::vector<int> input_vec_2;

    for (int i = 1; i < argc; i++)
    {
        input_vec_1.push_back(std::stoi(argv[i]));
        input_vec_2.push_back(std::stoi(argv[i]));
    }

    // one can modify these two vector

    std::cout << "Before sorting: ";
    print_vector(input_vec_1);
    std::cout << "\n";

    quicksort_firstelem_partition(input_vec_1, 0, input_vec_1.size());
    std::cout << "After sorting (First element chosen as pivot): ";
    print_vector(input_vec_1);
    std::cout << "\n";

    std::cout << &input_vec_1 << " " << &input_vec_2 << "\n";

    quicksort_middle_partition(input_vec_2, 0, input_vec_2.size());
    std::cout << "After sorting (Middle element chosen as pivot): ";
    print_vector(input_vec_2);
    std::cout << "\n";
    return 0;
}