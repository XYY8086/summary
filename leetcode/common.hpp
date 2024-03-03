#include <iostream>

template<typename T>
void PrintSeries(const T& input, char sep=','){
    for(const auto& itr : input){
        std::cout << itr << sep;
    }
    std::cout << std::endl;
}

template<typename T>
void PrintComplexSeries(const T& input, char sep=','){
    for(const auto& itr : input){
        PrintSeries<decltype(itr)>(itr, sep);
    }
    std::cout << std::endl;
}

template<typename T>
void PrintPairs(const T& input, char sep=','){
    for(const auto& itr : input){
        std::cout << itr.first << sep << PrintSeries<decltype(itr.second)>(itr.second, sep);
    }
    std::cout << std::endl;
}