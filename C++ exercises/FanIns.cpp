#include <iostream>
#include <vector>
#include <algorithm>  // für std::find

//predef
void sucheFanIns(std::vector<int>);
void sucheFanOuts(int);

//glob vars
std::vector<int> fanIns;
std::vector<int> fanOuts;

 //        nodes                   0, 1, 2, ..., 10   
std::vector<std::vector<int>> G {{4, 8, 5}, {9, 10}, {3, 1}, {9, 5}, {}, {4, 6}, {}, {3, 1, 8}, {9, 6}, {10, 6}, {}}; 

int main ()
{

             
//std::vector<std::vector<int>>::iterator Knoten = 2;
int Knoten = 6;

std::vector<int> KnotenIns = G[Knoten];

//sucheFanIns(G[Knoten]);

sucheFanOuts(Knoten);

for (int knoten : fanIns) {
    std::cout << knoten << " ";
}
for (int knoten : fanOuts) {
    std::cout << knoten << " ";
}
return 0;
}

void sucheFanOuts (int suchknoten){

    int knotenNr = 0;
    for (std::vector<int> gKnoten : G){

        if (std::find(gKnoten.begin(), gKnoten.end(), suchknoten) != gKnoten.end()){                
            
          //  for (int gefundenerKnoten : gKnoten){
                
                if (std::find(fanOuts.begin(), fanOuts.end(), knotenNr) == fanOuts.end()){
                    fanOuts.push_back(knotenNr);
                    sucheFanOuts(knotenNr);
                }
           // }
        }
        knotenNr++;
    }
    

}

void sucheFanIns2 (int suchknoten){
    
    for (int gefundenerKnoten : G[suchknoten]){
        if (std::find(fanOuts.begin(), fanOuts.end(), gefundenerKnoten) == fanOuts.end()){
            fanOuts.push_back(gefundenerKnoten);
            sucheFanOuts(gefundenerKnoten);
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