#ifndef __HEAP_H
#define __HEAP_H
#include <iostream>
#include <vector>

template<typename T, typename Compare = std::less<T>> class heap
{
   public:
    heap() {
    }
    ~heap() {
    }
    void push (const T &elem) {
    }

    T pop (void) {
        T ret{ 0 };
        if(mem.size() != 0) {
            ret = mem[0];
            mem[0] = mem.back();
            mem.pop_back();
            make_heap_great_again(0);
        }
        return ret;
    }

   private:
    void make_heap_great_again (size_t index) {
        size_t left = index * 2;
        size_t right = (index * 2) + 1;
        size_t max = index;
        if(left < mem.size() && Compare(mem[index], mem[left])) {
            max = left;
        }
        if(right < mem.size() && Compare(mem[index], mem[right])) {
            max = right;
        }

        if(max != index) {
            auto tmp = mem[index];
            mem[index] = mem[max];
            mem[max] = tmp;
            make_heap_great_again(max);
        }
    }
    std::vector<T> mem;
};

#endif /* __HEAP_H */