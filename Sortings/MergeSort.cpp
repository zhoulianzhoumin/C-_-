#include "MergeSort.hpp"
#include <algorithm>
#include<iostream>

void miv::sortings::merge_sort(int* const arr, const int arr_length) {
	
        if (arr_length <= 1) return;
        
        int* temp = new int[arr_length];
        
		if (temp) {
			for (int step = 1; step < arr_length; step *= 2) {
				for (int left = 0; left < arr_length; left += 2 * step) {
					int mid = std::min(left + step, arr_length);
					int right = std::min(left + 2 * step, arr_length);
                
					int i = left, j = mid, k = left;
					while (i < mid && j < right) {
						if (arr[i] <= arr[j]) temp[k++] = arr[i++];
						else temp[k++] = arr[j++];
					}
					while (i < mid) temp[k++] = arr[i++];
					while (j < right) temp[k++] = arr[j++];
                
					for (int p = left; p < right; ++p) {
						arr[p] = temp[p];
					}
				}
			}
			delete[] temp;	
		} else {
			std::cout << "Ошибка выделения памяти!";
		}
}



