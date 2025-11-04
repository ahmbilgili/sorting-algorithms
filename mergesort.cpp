#include <iostream>
#include <string>
#include <algorithm>
#include "sort_utils.h"

std::vector<int> merge(std::vector<int> &L, std::vector<int> &R)
{

    int i = 0;
    int j = 0;
    std::vector<int> merged_vector;

    while (i != L.size() && j != R.size())
    {
        if (L[i] < R[j])
        {
            merged_vector.push_back(L[i]);
            i++;
        }
        else
        {
            merged_vector.push_back(R[j]);
            j++;
        }
    }
    // Left vector is exhausted, push back elements located in right vector to merged vector
    if (i == L.size())
    {
        for (int k = j; k < R.size(); k++)
        {
            merged_vector.push_back(R[k]);
        }
    }
    // Right vector is exhausted, push back elements located in left vector to merged vector
    else
    {
        for (int k = i; k < L.size(); k++)
        {
            merged_vector.push_back(L[k]);
        }
    }
    return merged_vector;
}

std::vector<int> mergesort(std::vector<int> &A, int l, int r)
{
    // Base case
    if (l == r)
    {
        std::vector<int> tempvec(1, A[l]);

        return tempvec;
    }

    int middle = (l+r)/2;
    std::vector<int> L = mergesort(A, l, middle);
    std::vector<int> R = mergesort(A, middle+1, r);

    return merge(L, R);
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

    // (size - 1) instead of (size) for param2 so that we get more "equal" splits
    // One might aswell give (size) for param2, however additional modifications must be made to the existing code

    std::vector<int> sorted_vec = mergesort(input_vec, 0, input_vec.size()-1);
    std::cout << "After sorting: ";
    print_vector(sorted_vec);
    std::cout << "\n";    
    return 0;
}