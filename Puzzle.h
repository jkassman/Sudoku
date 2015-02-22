#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <ctype.h> //for isalpha()

using namespace std;

template <typename T>
class Puzzle{
 public:
  Puzzle(string fileName = "suduko.txt", int size = 9);
  void display();
 private:
  int myBoardSize;
  vector< vector<T> > myBoard;
};

template <typename T>
Puzzle<T>::Puzzle(string fileName, int size)
{
  string rowString;
  ifstream boardFile (fileName.c_str());
  if (size > 0)
    {
      myBoardSize = size;
    }
  else
    {
      cout << "Invalid board size. Using default of 9." << endl;
      myBoardSize = 9;
    }
  cout << "Board is of size: " << myBoardSize << endl;
  if (boardFile.is_open())
    {
      for (int row = 0; row < myBoardSize; row++)
	{
	  getline(boardFile, rowString);
	  for (int col = 0; rowString[col] != '\n'; col++)
	    {
	      if (isalpha(rowString[col]))
		{
		  myBoard[row].push_back(rowString[col]);
		  cout << "(" << row << "," << col << ") " << rowString[col] << endl;
		}
	    }
	}
    }
  else
    {
      cout << "We have a problem. The file did not open." << endl;
    }
}

template <typename T>
void Puzzle<T>::display()
{
  for (int i = 0; i < myBoardSize; i++)
    {
      cout << "here!" << endl;
      for (int j = 0; j < myBoardSize; j++)
	{
	  cout << "here!" << j << endl;
	  cout << myBoard[i][j] << '|';
	}
      cout << endl;
    }
}
