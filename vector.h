#pragma once

namespace NVector {
    const long long D_SIZE = 2;
    template<typename T>
    class TVector {
    public:
        explicit TVector(long long size = 0) :Len(size) {
            if (Len == 0) {
                SizeArr = D_SIZE;
            }
            else {
                SizeArr = Len * D_SIZE;
            }
            MyArray = new T[SizeArr];
        }

        T& operator[](long long i) {
            return MyArray[i];
        }

        ~TVector() {
            delete[] MyArray;
        }

        TVector& operator=(const TVector& other) {
            delete[] MyArray;
            MyArray = new T[other.Size()];
            for (int i = 0; i < other.Size(); i++) {
                MyArray[i] = other[i];
            }
            return *this;
        }

        void PushBack(T elem) {
            if (Len == (SizeArr - 1)) {
                SizeArr *= D_SIZE;
                T* n_arr = new T[SizeArr];
                for (long long i = 0; i < Len; i++) {
                    n_arr[i] = MyArray[i];
                }
                delete[] MyArray;
                MyArray = n_arr;
            }
            MyArray[Len] = elem;
            Len++;
        }
        T* Begin() const {
            return MyArray;
        }

        T* End() const {
            if (MyArray) {
                return MyArray + Len;
            }
            return nullptr;
        }
        long long Size() {
            return Len;
        }

    private:
        T* MyArray;
        long long Len, SizeArr;
    };
}