#include <iostream>
#include "vector"

void seguratasPeligrososfunc(std::vector<int> &&seguratas, std::vector<int> &&seguratasPeligrosos, std::vector<int> &&seguratasNormales){
    if (seguratas.size() == 0){
        return;
    }
    int segurata1 = seguratas.at(seguratas.size()-1);
    seguratas.pop_back();
    if (segurata1 > 8){
        seguratasPeligrosos.push_back(segurata1);
    } else {
        seguratasNormales.push_back(segurata1);
    }
    seguratasPeligrososfunc(std::move(seguratas), std::move(seguratasPeligrosos), std::move(seguratasNormales));
}

int main() {
    std::vector<int> seguratas;
    std::vector<int> seguratasPeligrosos;
    std::vector<int> seguratasNormales;
    seguratas.push_back(4);
    seguratas.push_back(1);
    seguratas.push_back(26);
    seguratas.push_back(10);
    seguratas.push_back(8);
    seguratas.push_back(9);
    seguratas.push_back(6);




    seguratasPeligrososfunc(std::move(seguratas), std::move(seguratasPeligrosos), std::move(seguratasNormales));

    for (int i = 0; i < seguratasPeligrosos.size(); ++i) {
        std::cout << seguratasPeligrosos.at(i) << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < seguratasNormales.size(); ++i) {
        std::cout << seguratasNormales.at(i) << std::endl;
    }
    return 0;
}
