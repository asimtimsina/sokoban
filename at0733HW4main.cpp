#include "at0733HW4func.h"


int main (){

int size = 15;   // size of the dynamic array
int moves = 0;  // to count the no of moves made by user
int xavatar , yavatar ; // coordinates of avatar
  room** area = new room*[15]; // making dynamic array
   
  for(int i = 0 ; i < size ; i++){
    area[i] = new room[size];
  }

  header(); // printing the header
  fileinclude(area ,size); // including the game file and filling in the dynamic array
  cout <<"Welcome to Mr. Mover! " << endl;
cout << "The goal is to push each of the boxes (represented by B's) into a home location (represented by H's). Mr. Mover is represented by an A, and you can move Up(U), Down(D), Left(L), and Right(R).Once a box is in a home location, it cannot be moved again so be careful about how your push the boxes. Good luck!" << endl;
  display(area, size);
  /////
 bool over= true;  // bool to check whether game is over
  
  do{
    over = gameover(area, size);
    if(over){ 
  if(!move (area, size, xavatar, yavatar, moves)){ // if user hit quit the move function returns false and the game ends wih the message
      cout <<"You Quit the game" << endl;
      exit(1);
  }
    }
    else{  // after all box are in home location the gameover becomes true
      cout <<"You won the game in " << moves <<" moves." << endl;
    }
  } while (over) ;
 
  /////
  return 0;
}










