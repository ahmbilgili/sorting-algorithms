#include <iostream>
#include <vector>
#include "sort_utils.h"

void insertion_sort(std::vector<int> &A, int l, int r)
{
    for (int j = 1; j < r; j++)
    {
        int key = A[j];
        int i = j-1;

        while (i > -1 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
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
    std::vector<int> input_vec;

    for (int i = 1; i < argc; i++)
    {
        input_vec.push_back(std::stoi(argv[i]));
    }

    std::cout << "\nBefore sorting: ";
    print_vector(input_vec);
    std::cout << "\n";

    insertion_sort(input_vec, 0, input_vec.size());

    std::cout << "\nAfter sorting: ";
    print_vector(input_vec);
    std::cout << "\n";
}