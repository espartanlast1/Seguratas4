#include <iostream>
#include "vector"
#include "infoSegurata.h"

void seguratasPeligrososfunc(std::vector<InfoSegurata> &&seguratas, std::vector<InfoSegurata> &&seguratasPeligrosos, std::vector<InfoSegurata> &&seguratasNormales){
    if (seguratas.size() == 0){
        return;
    }
    InfoSegurata segurata1 = seguratas.at(seguratas.size()-1);
    seguratas.pop_back();
    if (segurata1.getEvaluacionCandidato() > 8){
        seguratasPeligrosos.push_back(segurata1);
    } else {
        seguratasNormales.push_back(segurata1);
    }
    seguratasPeligrososfunc(std::move(seguratas), std::move(seguratasPeligrosos), std::move(seguratasNormales));
}

int main() {
    std::vector<InfoSegurata> seguratas;
    std::vector<InfoSegurata> seguratasPeligrosos;
    std::vector<InfoSegurata> seguratasNormales;
    seguratas.push_back(InfoSegurata("Pablo", 6));
    seguratas.push_back(InfoSegurata("Pedro", 1));
    seguratas.push_back(InfoSegurata("Jorge", 10));
    seguratas.push_back(InfoSegurata("Miguel", 9));
    seguratas.push_back(InfoSegurata("Geronimo", 10));
    seguratas.push_back(InfoSegurata("Victor", 3));




    seguratasPeligrososfunc(std::move(seguratas), std::move(seguratasPeligrosos), std::move(seguratasNormales));

    std::cout << "Seguratas Peligrosos: " << endl;
    for (int i = 0; i < seguratasPeligrosos.size(); ++i) {
        std::cout << seguratasPeligrosos.at(i).mostrarSeguratas() << std::endl;
    }
    std::cout << std::endl << "Seguratas Normales: " << endl;
    for (int i = 0; i < seguratasNormales.size(); ++i) {
        std::cout << seguratasNormales.at(i).mostrarSeguratas() << std::endl;
    }
    return 0;
}
