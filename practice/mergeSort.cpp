#include <iostream>
#include <vector>
#include <random>

int randBetween(const int minVal, const int maxVal)
{
    static std::mt19937 prng(std::random_device{}());
    static std::uniform_int_distribution<int> dist(minVal, maxVal);
    return dist(prng);
}

std::vector<int> generateVec(int maxSize = 10000, int minVal = 0, int maxVal = 40000, bool fix = false)
{
    size_t n;
    if (fix)
    {
        n = maxSize;
    }
    else
    {
        n = randBetween(1, maxSize);
    }
    std::vector<int> data(n);
    for (int &num : data)
    {
        num = randBetween(minVal, maxVal);
    }
    return data;
}

using namespace std;

void merge(vector<int> &data, int start, int mid, int end)
{
    vector<int> left(data.begin() + start, data.begin() + mid + 1);
    vector<int> right(data.begin() + mid + 1, data.begin() + end + 1);
    int left_i = 0;
    int right_i = 0;
    int i = start;
    while (i <= end)
    {
        if (left_i < left.size() && right_i < right.size())
        {
            if (left[left_i] <= right[right_i])
            {
                data[i] = left[left_i++];
            }
            else
            {
                data[i] = right[right_i++];
            }
        }
        else
        {
            if (left_i < left.size())
            {
                data[i] = left[left_i++];
            }
            else
            {
                data[i] = right[right_i++];
            }
        }
        i++;
    }
    return;
}

void mergeSort(vector<int> &data, int i, int j)
{
    if (i == j)
    {
        return;
    }
    int mid = (i + j) / 2;
    mergeSort(data, i, mid);
    mergeSort(data, mid + 1, j);
    merge(data, i, mid, j);
}

vector<int> mergeSort(vector<int> data)
{
    mergeSort(data, 0, data.size() - 1);
    return data;
}

int main()
{
    vector<int> data = generateVec(100000, 0, 40000, true);
    vector<int> res;
    res = mergeSort(data);
    return 0;
}