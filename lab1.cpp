#include <iostream>
#include "vector.h"
#include "sort.h"
#include "pair.h"

using TData = NPair::TPair<NSort::TKey>;
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    NVector::TVector<TData> vec;
    NSort::TKey key;
    char value[65];

    while (std::cin >> key) {
        std::cin >> value;
        vec.PushBack(TData(key, value));
    }

    NSort::CountingSort(vec);
    for (long long i = 0; i < vec.Size(); ++i) {
        std::cout << vec[i].Key << '\t' << vec[i].Str << std::endl;
    }
    return 0;
}