#include <vector>
#include <iostream>

/*
    Written for integer vectors. One can introduce a struct vector as an argument instead
*/
void print_vector(const std::vector<int>& A)
{
    for (int i = 0; i < A.size(); i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}

bool vectorEquals(const std::vector<int> &vec1, const std::vector<int> &vec2)
{
    if (vec1.size() == vec2.size())
    {
        for (int i = 0; i < vec1.size(); i++)
        {
            if (vec1[i] != vec2[i])
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}