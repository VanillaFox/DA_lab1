#pragma once
#include "pair.h"
#include "vector.h"
#include <cinttypes>
#include <iostream>
namespace NSort {
	using TKey = std::uint16_t;
	void CountingSort(NVector::TVector<NPair::TPair<TKey>>& elem) {
		int max = 0, min = elem[0].Key;
		for (long long i = 0; i < elem.Size(); ++i) {
			if (elem[i].Key > max) {
				max = elem[i].Key;
			}
			else if (elem[i].Key < min) {
				min = elem[i].Key;
			}
		}

		NVector::TVector<NPair::TPair<TKey>> res(elem.Size());
		int differ = max - min + 1;

		long long* count = new long long[differ] {0};
		for (long long i = 0; i < elem.Size(); ++i) {
			++count[elem[i].Key - min];
		}

		for (long long i = 0; i < differ - 1; ++i) {
			count[i + 1] += count[i];
		}

		for (long long i = elem.Size() - 1; i > -1; --i) {
			res[count[elem[i].Key - min] - 1] = elem[i];
			--count[elem[i].Key - min];
		}

		for (long long i = 0; i < elem.Size(); ++i) {
			elem[i] = res[i];
		}
		delete[] count;
	}
}