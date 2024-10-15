#pragma once
#include <definitions.hpp>
#include <vis.hpp>

namespace alg
{
    void bubbleSort(SDL_Renderer *renderer, std::vector<int> &arr)
    {
        int n = arr.size();
        bool swapped;
        std::vector<int> highlights;

        for (int i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
                highlights.push_back(j);
                highlights.push_back(i);

                vis::renderArray(renderer, arr, highlights);
                highlights.clear();
                SDL_Delay(20);
            }
            // no more swaps so we are done
            if (!swapped)
                break;
        }
    }

    // Partition function for quick sort
    int partition(SDL_Renderer *renderer, std::vector<int> &arr, int low, int high)
    {
        int pivot = arr[high]; // Pivot elem
        int i = low - 1;       // Index of smaller elem
        std::vector<int> highlights;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
                highlights.push_back(i);
                highlights.push_back(j);
                vis::renderArray(renderer, arr, highlights);
                highlights.clear();
                SDL_Delay(20);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        vis::renderArray(renderer, arr, highlights);
        SDL_Delay(50);
        return i + 1;
    }

    // Quick sort
    void quickSort(SDL_Renderer *renderer, std::vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(renderer, arr, low, high);
            // Recursively sort elements before and after partition
            quickSort(renderer, arr, low, pi - 1);
            quickSort(renderer, arr, pi + 1, high);
        }
    }

    // insertion sort
    void insertionSort(SDL_Renderer *renderer, std::vector<int> &arr, int left, int right)
    {
        for (int i = left + 1; i <= right; i++)
        {
            int temp = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;

            std::vector<int> highlights;
            highlights.push_back(left);
            highlights.push_back(right);
            vis::renderArray(renderer, arr, highlights);
            highlights.clear();
            SDL_Delay(20);
        }
    }

    // Merge sort
    void merge(SDL_Renderer *renderer, std::vector<int> &arr, int left, int mid, int right)
    {
        std::vector<int> highlights;
        highlights.push_back(left);
        highlights.push_back(right);

        int len1 = mid - left + 1, len2 = right - mid;
        std::vector<int> leftArr(len1), rightArr(len2);

        for (int i = 0; i < len1; i++)
            leftArr[i] = arr[left + i];
        for (int i = 0; i < len2; i++)
            rightArr[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;

        while (i < len1 && j < len2)
        {
            if (leftArr[i] <= rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
            k++;

            vis::renderArray(renderer, arr, highlights);
            SDL_Delay(20);
        }

        while (i < len1)
        {
            arr[k] = leftArr[i];
            i++;
            k++;
            vis::renderArray(renderer, arr, highlights);
            SDL_Delay(20);
        }

        while (j < len2)
        {
            arr[k] = rightArr[j];
            j++;
            k++;
            vis::renderArray(renderer, arr, highlights);
            highlights.clear();
            SDL_Delay(20);
        }
    }

    // Function to perform Tim Sort
    void timSort(SDL_Renderer *renderer, std::vector<int> &arr, int n)
    {
        // Sort each subarray of size RUN using insertion sort
        for (int i = 0; i < n; i += RUN)
        {
            insertionSort(renderer, arr, i, std::min((i + RUN - 1), (n - 1)));
        }

        // MergeSort sorted subarrays
        for (int size = RUN; size < n; size = 2 * size)
        {
            for (int left = 0; left < n; left += 2 * size)
            {
                int mid = std::min((left + size - 1), (n - 1));
                int right = std::min((left + 2 * size - 1), (n - 1));

                if (mid < right)
                {
                    merge(renderer, arr, left, mid, right);
                }
            }
        }
    }

    void sort(sort_alg sorting_algorithim, SDL_Renderer *renderer, std::vector<int> data)
    {
        switch (sorting_algorithim)
        {
        case sort_alg::quick:
            quickSort(renderer, data, 0, data.size() - 1);
            break;
        case sort_alg::bubble:
            bubbleSort(renderer, data);
            break;
        case sort_alg::tim:
            timSort(renderer, data, data.size());
            break;
        }
    }

}