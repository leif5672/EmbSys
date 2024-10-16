#include <iostream>
#include <vector>
#include <algorithm>  // für std::find

//predef
void suche(std::vector<int>);

//glob vars
std::vector<int> fanIns;

 //        nodes                   0, 1, 2, ..., 10   
std::vector<std::vector<int>> G {{4, 8, 5}, {9, 10}, {3, 1}, {9, 5}, {}, {4, 6}, {}, {3, 1, 8}, {9, 6}, {10, 6}, {}}; 

int main ()
{

             
//std::vector<std::vector<int>>::iterator Knoten = 2;
int Knoten = 2;

std::vector<int> KnotenIns = G[Knoten];

suche(G[Knoten]);

for (int knoten : fanIns) {
    std::cout << knoten << " ";
}

return 0;
}

void suche (std::vector<int> suchknoten){
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
        suche(G[gefundenerKnoten]); // hier passiert die REKURSION
    }
    
    suchknotenstelle++;
} while (suchknotenstelle < suchknoten.size());

   
}