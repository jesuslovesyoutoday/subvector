#include <iostream>
#include "old_subvector.cpp"

int main()
{
    subvector vec;
    init(&vec);
    push_back(&vec, 1);   
    push_back(&vec, 2);   
    push_back(&vec, 3);   

    print_subvector(&vec);

    resize(&vec, 10);

    shrink_to_fit(&vec);

    std::cout << pop_back(&vec) << std::endl;
    std::cout << pop_back(&vec) << std::endl;
    std::cout << pop_back(&vec) << std::endl;

    clear(&vec);

    destructor(&vec);
    return 0;
}
