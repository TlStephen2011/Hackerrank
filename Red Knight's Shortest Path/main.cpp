#include <bits/stdc++.h>

using namespace std;

void displayVector(vector<string> s) {
  for (int i = 0; i < s.size(); i++) {
    cout << s[i] << " ";
  }
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
  //  Print the distance along with the sequence of moves.
  bool solved = false;
  while (!solved) {
    // checking preconditions
    if (abs(i_start - i_end) % 2 == 1) {
      cout << "Impossible" << endl;
      break;
    } else if (i_start == i_end && abs(j_start - j_end) % 2 == 1) {
      cout << "Impossible" << endl;
      break;
    } else if (j_start == j_end && abs(i_start - i_end) <= 2) {
      cout << "Impossible" << endl;
      break;
    }

    // solving part
    vector<string> movesUL;
    vector<string> movesUR;
    vector<string> movesR;
    vector<string> movesLR;
    vector<string> movesLL;
    vector<string> movesL;
    while (!(i_start == i_end && j_start == j_end)) {
      if (i_start == i_end) {
        if (j_start < j_end) {
          j_start += 2;
          movesR.push_back("R");
        } else {
          j_start -= 2;
          movesL.push_back("L");
        }
      } else if (i_start < i_end) {
        if (j_start == j_end) {
          i_start += 4;
          movesLR.push_back("LR");
          movesLL.push_back("LL");
        } else if (j_start < j_end) {
          i_start += 2;
          j_start += 1;
          movesLR.push_back("LR");
        } else {
          i_start += 2;
          j_start -= 1;
          movesLL.push_back("LL");
        }
      } else {
        if (j_start == j_end) {
          i_start -= 4;
          movesUL.push_back("UL");
          movesUR.push_back("UR");
        } else if (j_start < j_end) {
          i_start -= 2;
          j_start += 1;
          movesUR.push_back("UR");
        } else {
          i_start -= 2;
          j_start -= 1;
          movesUL.push_back("UL");
        }
      }
    }

    // printing moves
    int numMoves = movesUL.size() + movesUR.size() + movesR.size() +
                   movesLR.size() + movesLL.size() + movesL.size();
    cout << numMoves << endl;
    // for (int i = 0; i < numMoves; i++) {
    //   cout << moves[i] << " ";
    // }
    // cout << endl;
    displayVector(movesUL);
    displayVector(movesUR);
    displayVector(movesR);
    displayVector(movesLR);
    displayVector(movesLL);
    displayVector(movesL);

    solved = true;
  }
}

int main() {
  int n;
  cin >> n;
  int i_start;
  int j_start;
  int i_end;
  int j_end;
  cin >> i_start >> j_start >> i_end >> j_end;
  printShortestPath(n, i_start, j_start, i_end, j_end);
  return 0;
}
