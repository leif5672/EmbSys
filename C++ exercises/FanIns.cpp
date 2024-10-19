#include <iostream>
#include <vector>
#include <algorithm>  // für std::find

//predef
void sucheFanIns(std::vector<int>);
void sucheFanIns2(int);
void sucheFanOuts(int);

//glob vars
std::vector<int> fanIns;
std::vector<int> fanOuts;

//        nodes                   0, 1, 2, ..., 10   
std::vector<std::vector<int>> G {{4, 8, 5}, {9, 10}, {3, 1}, {9, 5}, {}, {4, 6}, {}, {3, 1, 8}, {9, 6}, {10, 6}, {}}; 

int main (){
    int knoten = 9;

    //sucheFanIns(G[knoten]);
    sucheFanIns2(knoten);
    sucheFanOuts(knoten);
        
    // FanIns ausgeben
    std::cout << "FanIns von Knoten " << knoten << " " << std::endl;
    for (int fan : fanIns) {
        std::cout << fan << " ";
    }
    
    // FanOuts ausgeben
    std::cout << "\nFanOuts von Knoten " << knoten << " " << std::endl;
    for (int fan : fanOuts) {
        std::cout << fan << " ";
    }
    return 0;
}

void sucheFanOuts (int suchknoten){
    int knotenNr = 0;
    for (std::vector<int> gKnoten : G){
        if (std::find(gKnoten.begin(), gKnoten.end(), suchknoten) != gKnoten.end()){                
                if (std::find(fanOuts.begin(), fanOuts.end(), knotenNr) == fanOuts.end()){
                    fanOuts.push_back(knotenNr);
                    sucheFanOuts(knotenNr);
                }
        }
        knotenNr++;
    }
}

void sucheFanIns2 (int suchknoten){
    for (int gefundenerKnoten : G[suchknoten]){
        if (std::find(fanIns.begin(), fanIns.end(), gefundenerKnoten) == fanIns.end()){
            fanIns.push_back(gefundenerKnoten);
            sucheFanIns2(gefundenerKnoten);
        }
    }
}

void sucheFanIns (std::vector<int> suchknoten){
    // int i = 0;
    // do
        // gefundenerKnoten = Suchknoten[i]
        
        // Wenn der gefundene Knoten nicht in FanIns  ist,
            // füge den gefundenen Knoten hinzu
            // wenn der Suchknoten  nicht leer ist
               //suche(gefundenerKnoten)
        
    // while nicht an der letzten stelle des Suchknotens i != Suchknoten.end ; i++ )  gehe eine stelle des Suchn´knotens weiter suche(gefundenerKnoten = Suchknoten[i+1])
        // break

    int suchknotenstelle = 0;
    
    do {
        int gefundenerKnoten = suchknoten[suchknotenstelle];
        
        if (std::find(fanIns.begin(), fanIns.end(), gefundenerKnoten) == fanIns.end()){ // wenn der gefundene knoten nicht in fanIns ist
            fanIns.push_back(gefundenerKnoten); // füge ihn hinzu
            if (!G[gefundenerKnoten].empty()) //wenn der gefundene knoten nicht leer ist
                sucheFanIns(G[gefundenerKnoten]); // hier passiert die REKURSION
        }
        
        suchknotenstelle++;
    } while (suchknotenstelle < suchknoten.size());
}