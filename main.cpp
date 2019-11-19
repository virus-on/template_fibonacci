#include <iostream>
#include <type_traits>

template<ulong long number_of_iters>
struct fibonacci {
    static ulong long const val = (number_of_iters > 1 ? fibonacci<number_of_iters - 1>::val + fibonacci<number_of_iters - 2>::val : 1);
};

template<>
struct fibonacci<static_cast<ulong long>(0)> {
    static ulong long const val = 0;
};

template<>
struct fibonacci<static_cast<ulong long>(1)> {
    static ulong long const val = 1;
};

template<int number_of_iters>
struct loop {
    const void iterate()
    {
        loop<number_of_iters - 1> prev;
        prev.iterate();
        std::cout << fibonacci<number_of_iters - 1>::val << std::endl;
    }
};

template<>
struct loop<1>
{
    static void iterate()
    {
        std::cout << fibonacci<0>::val << std::endl;
    }
};

int main()
{
    loop<50> for_loop;
    for_loop.iterate();
    return 0;
}
