#include <cstring>
#include <iostream>
#include <climits>
using namespace std;

#define I INT_MAX;


void primsMST(int Adjmat[6][6], int selected[6],int V){
    int E=0;  // number of Egdes
     int p=0;  //  row number
     int q=0;  //  column number

    while (E < V - 1) {

    int min = I;
    p = 0;
    q = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && Adjmat[i][j]) { 
            if (min > Adjmat[i][j]) {
              min = Adjmat[i][j];
              p = i;
              q = j;
            }
          }
        }
      }
    }
    cout << p << " - " << q << " -->  " << Adjmat[p][q];
    cout << endl;
    selected[q] = true;
    E++;
}
}
int main() {
  int start_vetex = 3;

  int Adjmat[6][6] = {
  {0, 3, 0, 0, 0, 1},
  {3, 0, 2, 1, 10, 0},
  {0, 2, 0, 3, 0, 5},
  {0, 1, 3, 0, 5, 0},
  {0, 10, 0, 5, 0, 4},
  {1, 0, 5, 0, 4, 0}};

  // Array to track the selected vertex.
  int selected[6];
  for (int i=0; i<6; i++){
    selected[i] = false;
  }

  selected[start_vetex] = true;

  // print for edge and weight
  cout << "Egdes"
     << " --> "
     << "Weight";
  cout << endl;
  
  
    primsMST(Adjmat,selected,6);

  return 0;
}
