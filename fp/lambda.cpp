#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

//lambda functions are anonymous function

void ForEach(const std::vector<int> &values, const std::function<void(int)>& func)
{
    for(const auto &val: values)
    {
        func(val);
    }
}

int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5};
    auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
    std::cout<< *it<< std::endl;

    int a = 5;
    auto lambda = [=](int value) { std::cout<< a << std::endl;};

    ForEach(values, lambda);
    return 0;
}
