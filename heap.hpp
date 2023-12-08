#ifndef __HEAP_H
#define __HEAP_H
#include <iostream>
#include <vector>
#include <functional>

template<typename T, typename Compare = std::less<T>> class heap
{
   public:
    heap() {
        mem = new std::vector<T>();
    }

    heap(std::vector<T> &elems) {
        if(!elems.empty()) {
            mem = elems;
            for(int i = (mem.size() / 2) + 2; i >= 0; --i) {
                make_heap_great_again(i);
            }
        }
    }

    ~heap() {
    }

    void push (const T &elem) {
        if(Compare{}(mem.back(), elem)) {
            mem.push_back(elem);
            int i = mem.size() - 1;
            while(i != 0 && Compare{}(mem[i / 2], mem[i])) {
                auto tmp = mem[i / 2];
                mem[i / 2] = mem[i];
                mem[i] = tmp;
                i = i / 2;
            }
        } else {
            mem.push_back(elem);
        }
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

    void print (void) {
        for(const auto &n : mem) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

   private:
    void make_heap_great_again (size_t index) {
        size_t left = (index * 2) + 1;
        size_t right = (index * 2) + 2;
        size_t max = index;

        if(left < mem.size() && Compare{}(mem[index], mem[left])) {
            max = left;
        }

        if(right < mem.size() && Compare{}(mem[max], mem[right])) {
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