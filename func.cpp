#include "func.h"

/////////////////////////////////////////////////////////////
void header(){
// Displaying the Header
    // this function contains no parameter and prints the information about the department, student's name, euid and email

cout << "+-----------------------------------------------+"<<endl;
cout << "|                                               |" << endl;
cout << "|                Asim Timsina                   |" << endl;
cout << "|                                               |" << endl;
cout << "+-----------------------------------------------+ " << endl << endl ; 

}


/////////////////////////////////////////////////

void fileinclude(room ** area , int size){
//this function contains area (dynamic array ) and its size as parameter
// this function calls the file name from user, load the file and fill the dynamic array with the appropriate tiles
  char user[20];
  cout <<"Please enter the name of the room file: " ;
  cin >> user ;
  ifstream ifile; 
 ifile.open(user); 
  //ifile.open("room1.txt"); // FIXME_BEFORE_SUBMIT

  while (!(ifile.is_open())){ // if file is not found/ opened
    cout <<"File not found. " << endl;
    cout <<"Please re enter the name of the room file: " ;
    cin >> user;
    ifile.open(user);
  }
  string line; // string to store the line read from the file
  string piece;
  istringstream wait(line);
  char temp;
  int lineno =0;
  int column = 0;
  while(getline(ifile,line)){  // reading from the file
      wait.str(line);
      while(getline(wait,piece, ',')){
              temp = piece[0];
              // cout << temp << " "; 
              switch (temp)  // switch case to store all the tiles in the array
              {
                case 'X' : // if the tile is wall
                  area[lineno][column].type= wall ;
                  area[lineno][column].home = false; 
                  column ++;
                  break ;

                case 'A' :  // if the tile is avatar
                area[lineno][column].type= avatar ;
                area[lineno][column].home = false ;
                column ++;
                   break ;

                case 'H' :   // if the tile is Home
                area[lineno][column].type= home ;
                area[lineno][column].home = true;
                column ++; 
                  break ;

                case ' ':  // if the tile is space
                 area[lineno][column].type= space ;
                 area[lineno][column].home = false; 
                 column ++;
                  break ;

                  case 'B':  // if the tile is box
                 area[lineno][column].type= box ;
                 area[lineno][column].home = false; 
                 column ++;
                  break ;
              }
          }
        lineno ++;
        column = 0;
        wait.clear();
      }   
      
    cout << endl ;
  }

////////////////////////////////////////////////////

  void display(room ** area , int size){
// this function returns void with the parameter array and its size and prints the gameboard(array) when called

  for (int i=0; i < size ; i++){
    for (int j=0; j < size ; j++){
      cout << static_cast <char> (area[i][j].type) <<" " ;  // printing each tile
  }
  cout << endl;
}
}

////////////////////////////////////////////////////////////

bool move(room **area , int size , int xavatar , int yavatar ,int& moves){
// this function has parameters array, its size, the x and y coordinates of the avatar and the no of moves
// this function prompts the user to enter the direction and calls the appropiate function in order to move , quit , save, reload or reset the game
  
for (int i=0; i < 15 ; i++){ // tracing the location of x and y coordinate of avatar
    for (int j=0 ; j < 15 ; j++){
        if (area[i][j].type == avatar){
          xavatar = j;
          yavatar = i;
        }
    }
  }
//cout << xavatar <<" " << yavatar << endl;  // FIXME_BEFORE 

char userchoice ;

cout <<"Please enter direction to move: U for Up, D for Down, L for Left, R for Right, Q for Quit, S to save file to continue play later, X to reset the game :" ;
cin >> userchoice ; 
userchoice = toupper(userchoice);
//cout << userchoice << endl; //FIX_ME

 while ((userchoice != 'U')&& (userchoice != 'D')&& (userchoice != 'L')&& (userchoice != 'R')&& (userchoice != 'Q')&& (userchoice != 'S') && (userchoice != 'X') && (userchoice != 'Z')) {
    cout <<"Choice didn't match" << endl;
cout <<"Please re-enter direction to move: U for Up, D for Down, L for Left, R for Right, Q for Quit, S to save file to continue play later, X to reset the game or press Z to reload the saved game :" ;
cin >> userchoice ; 
userchoice = toupper(userchoice);
  }
cout << endl;
  
  
  if (userchoice =='Q'){  // if user wants to quit the game
    cout <<"You choose to quit the Game" << endl;
       return false; 
  }

  if (userchoice =='U'){  // if user wants to move up
    if(toupper(area, size, xavatar, yavatar)){
      moves++;
       display(area, size);
           return 1;
      }
    else{
      display(area, size);
      return 1;
      
    }
  
    }

    if (userchoice =='D'){  // if user wants to move down
    if(todown(area, size, xavatar, yavatar)){
      moves++;
      display(area, size);
      return 1;
      
    }
    else{
      display(area, size);
      return 1;
      
    }
  
    }

     if (userchoice =='L'){  // if user wants to move left
    if(toleft(area, size, xavatar, yavatar)){
      moves++;
       display(area, size);
       return 1;
      
    }
    else{
      display(area, size);
      return 1;
      
    }
  
    }

     if (userchoice =='R'){ // if user wants to move Right
    if(toright(area, size, xavatar, yavatar)){
      moves++;
       display(area, size);
      return 1;
      
    }
    else{
      display(area, size);
      return 1;
      
    }
  
    }

    if (userchoice =='S'){ // if user wants to save the game in new file
        savefile(area,size,moves);
         return 1;
      }

    if (userchoice =='X'){ // if user wants to reset the game
        fileinclude(area,size);
        display(area,size);
        cout <<"The game has been reset." << endl;
         return 1;
      }

      if (userchoice =='Z'){ // if user wants to reload the previously saved game
        reopen(area,size,moves);
        display(area,size);
        cout <<"The saved file has been load. Now you can continue the game. \n" ;
         return 1;
      }

    
return 0;
    }
    


///////////////////////////////////////////////////////////////////


bool toupper(room** area,int size,int xavatar,int yavatar){
    // this function has parameter array, its size, x and y coordinate of avatar
    // this function tries to move the avatar in up direction and returns true if avatar is able to move else return false

if((area[yavatar][xavatar].home == 1)&& (area[yavatar][xavatar].type == avatar)){
      area[yavatar][xavatar].type = home;  
      area[yavatar-1][xavatar].type = avatar;  
      return 1;
    }
      
      if((area[yavatar-1][xavatar].home == 1) && (area[yavatar-1][xavatar].type == box)) { // if box is present in the home location
          cout <<"Box stuck in the Home. Cannot move " << endl;
          return 0;
      }

      if(area[yavatar-1][xavatar].type == wall ){  //if the tile up the avatar is wall
      cout << "You strike on wall. Cannot move." << endl;
      return 0;
    }

      if(area[yavatar-1][xavatar].type == space){  // if the tile up the avatar is space
        area[yavatar][xavatar].type = space ;
        area[yavatar-1][xavatar].type = avatar ;
         return 1;
      }
     
     if(area[yavatar-1][xavatar].type == home){  // if the tile up the avatar is home
       area[yavatar][xavatar].type = space ;
        area[yavatar-1][xavatar].type = avatar ;
        return 1;
     }

     if(area[yavatar-1][xavatar].type == box){  // if the tile up the avatar is box
        if(area[yavatar-2][xavatar].type == box){
          cout <<"Cannot move two box" << endl;
          return 0;
        }
        if(area[yavatar-2][xavatar].type == space){  
          area[yavatar-2][xavatar].type = box;
          area[yavatar-1][xavatar].type = avatar;
          area[yavatar][xavatar].type = space;
          return 1;
        }
        if(area[yavatar-2][xavatar].type == wall){
          cout <<"Cannot Move. You are striking on the wall" << endl;
          return 0;
        }
        if(area[yavatar-2][xavatar].type == home){
          area[yavatar-2][xavatar].home = 1;
          area[yavatar-2][xavatar].type = box;
          area[yavatar-1][xavatar].type = avatar;
          area[yavatar][xavatar].type = space;
          return 1;
        }
     }
      
return 0;
}

//////////////////////////////////////////////////////////////

bool todown(room** area,int size,int xavatar,int yavatar){
  // this function has parameter array, its size, x and y coordinate of avatar
  // this function tries to move the avatar in down direction and returns true if avatar is able to move else return false

        if((area[yavatar][xavatar].home == 1)&& (area[yavatar][xavatar].type == avatar)){
      area[yavatar][xavatar].type = home;
      area[yavatar+1][xavatar].type = avatar;  
      return 1;
    }
  
      if((area[yavatar+1][xavatar].home == 1) && (area[yavatar+1][xavatar].type == box)) {// if box is present in the home location
          cout <<"Box stuck in the Home. Cannot move " << endl;
          return 0;
      }

      if(area[yavatar+1][xavatar].type == wall ){ //if the tile down the avatar is wall
      cout << "You strike on wall. Cannot move." << endl;
      return 0;
    }

      if(area[yavatar+1][xavatar].type == space){ //if the tile down the avatar is space
        area[yavatar][xavatar].type = space ;
        area[yavatar+1][xavatar].type = avatar ;
         return 1;
      }
     
     if(area[yavatar+1][xavatar].type == home){  //if the tile down the avatar is home
       area[yavatar][xavatar].type = space ;
        area[yavatar+1][xavatar].type = avatar ;
        return 1;
     }

     if(area[yavatar+1][xavatar].type == box){  //if the tile down the avatar is box
        if(area[yavatar+2][xavatar].type == box){
          cout <<"Cannot move two box" << endl;
          return 0;
        }
        if(area[yavatar+2][xavatar].type == space){
          area[yavatar+2][xavatar].type = box;
          area[yavatar+1][xavatar].type = avatar;
          area[yavatar][xavatar].type = space;
          return 1;
        }
        if(area[yavatar+2][xavatar].type == wall){
          cout <<"Cannot Move. You are striking on the wall" << endl;
          return 0;
        }
        if(area[yavatar+2][xavatar].type == home){
          area[yavatar+2][xavatar].home = 1;
          area[yavatar+2][xavatar].type = box;
          area[yavatar+1][xavatar].type = avatar;
          area[yavatar][xavatar].type = space;
          return 1;

        }
     }
return 0;
}
//////////////////////////////////////////////////////////////

bool toleft(room** area,int size,int xavatar,int yavatar){
  // this function has parameter array, its size, x and y coordinate of avatar
    // this function tries to move the avatar in left direction and returns true if avatar is able to move else return false

      if((area[yavatar][xavatar].home == 1)&& (area[yavatar][xavatar].type == avatar)){
      area[yavatar][xavatar].type = home;
      area[yavatar][xavatar-1].type = avatar;  
      return 1;
    }
 
      if((area[yavatar][xavatar-1].home == 1) && (area[yavatar][xavatar-1].type == box)) {// if box is present in the home location
          cout <<"Box stuck in the Home. Cannot move " << endl;
          return 0;
      }

      if(area[yavatar][xavatar-1].type == wall ){  //if the tile left the avatar is wall
      cout << "You strike on wall. Cannot move." << endl;
      return 0;
    }

      if(area[yavatar][xavatar-1].type == space){   //if the tile left the avatar is space
        area[yavatar][xavatar].type = space ;
        area[yavatar][xavatar-1].type = avatar ;
         return 1;
      }
     
     if(area[yavatar][xavatar-1].type == home){   //if the tile left the avatar is home
       area[yavatar][xavatar].type = space ;
        area[yavatar][xavatar-1].type = avatar ;
        return 1;
     }

     if(area[yavatar][xavatar-1].type == box){   //if the tile left the avatar is box
        if(area[yavatar][xavatar-2].type == box){
          cout <<"Cannot move two box" << endl;
          return 0;
        }
        if(area[yavatar][xavatar-2].type == space){
          area[yavatar][xavatar-2].type = box;
          area[yavatar][xavatar-1].type = avatar;
          area[yavatar][xavatar].type = space;
          return 1;
        }
        if(area[yavatar][xavatar-2].type == wall){
          cout <<"Cannot Move. You are striking on the wall" << endl;
          return 0;
        }
        if(area[yavatar][xavatar-2].type == home){
          area[yavatar][xavatar-2].home = 1;
          area[yavatar][xavatar-2].type = box;
          area[yavatar][xavatar-1].type = avatar;
          area[yavatar][xavatar].type = space;
          return 1;

        }
     }
return 0;
}
///////////////////////////////////////////////////////

bool toright(room** area,int size,int xavatar,int yavatar){
// this function has parameter array, its size, x and y coordinate of avatar
    // this function tries to move the avatar in right direction and returns true if avatar is able to move else return false

     if((area[yavatar][xavatar].home == 1)&& (area[yavatar][xavatar].type == avatar)){
      area[yavatar][xavatar].type = home;
      area[yavatar][xavatar+1].type = avatar;  
      return 1;
    }
 

      if((area[yavatar][xavatar+1].home == 1) && (area[yavatar][xavatar+1].type == box)) {// if box is present in the home location
          cout <<"Box stuck in the Home. Cannot move " << endl;
          return 0;
      }

      if(area[yavatar][xavatar+1].type == wall ){ //if the tile right the avatar is wall
      cout << "You strike on wall. Cannot move." << endl;
      return 0;
    }

      if(area[yavatar][xavatar+1].type == space){  //if the tile right the avatar is space
        area[yavatar][xavatar].type = space ;
        area[yavatar][xavatar+1].type = avatar ;
         return 1;
      }
     
     if(area[yavatar][xavatar+1].type == home){ //if the tile right the avatar is home
       area[yavatar][xavatar].type = space ;
        area[yavatar][xavatar+1].type = avatar ;
        return 1;
     }

     if(area[yavatar][xavatar+1].type == box){  //if the tile right the avatar is box
        if(area[yavatar][xavatar+2].type == box){
          cout <<"Cannot move two box" << endl;
          return 0;
        }
        if(area[yavatar][xavatar+2].type == space){ 
          area[yavatar][xavatar+2].type = box;
          area[yavatar][xavatar+1].type = avatar;
          area[yavatar][xavatar].type = space;
          return 1;
        }
        if(area[yavatar][xavatar+2].type == wall){
          cout <<"Cannot Move. You are striking on the wall" << endl;
          return 0;
        }
        if(area[yavatar][xavatar+2].type == home){
          area[yavatar][xavatar+2].home = 1;
          area[yavatar][xavatar+2].type = box;
          area[yavatar][xavatar+1].type = avatar;
          area[yavatar][xavatar].type = space;
          return 1;

        }
     }
return 0;
}
///////////////////////////////////////////////////////


bool gameover(room ** area , int size){
// this function returns bool and has parameter of array and its size
// this function returns true if home position is present in the game else return false

  bool temp = false; 
    for(int i= 0; i < size ; i++){
        for(int j= 0; j < size ; j++){
            if(area[i][j].type == home){ // returns true if home location is present else false
              temp =true;
            }
        }
    }

    if (temp){
      return 1;
    }
      else{
       return 0;
      }
return 0;
}
///////////////////////////////////////////////////
void savefile(room** area , int size,int moves){
// this is a void function with the parameter array its size and no of moves made by the user
// this function asks the user to enter a new file name and saves the progressed game in that file 

  char file[20];
    cout <<"Enter the file name where you want to save your progress: " ;
  cin >> file;
 ofstream out(file,ios::out);

  for(int i =0 ; i < size ; i++){
    for(int j =0 ; j < size ; j++){
      if (j!=14){
      out  << static_cast<char> (area[i][j].type) <<','; // writes every tiles to the file
      }
      else
      {
        out  << static_cast<char> (area[i][j].type) ;
      }
    }
    out << endl;
    
  }
  out << moves ; // writes the no of moves to the file

  cout << "Your progress is saved in the file named " <<file << endl;
  cout <<"You are exitting the game." << endl;
  out.close();
  exit(1);
}
////////////////////////////////////////////
void reopen(room ** area , int size,int& moves){
// this is a void function with the parameter array its size and no of moves made by the user
// this function asks the user to enter a new file name and reload the progressed game from that file

 char user[20];
  cout <<"Please enter the name of the room file: " ;
  cin >> user ;
  ifstream ifile; 
 ifile.open(user); 
  //ifile.open("room1.txt"); // FIXME_BEFORE_SUBMIT

  while (!(ifile.is_open())){
    cout <<"File not found. " << endl;
    cout <<"Please re enter the name of the room file: " ;
    cin >> user;
    ifile.open(user);
  }
  string line;
  string piece;
  istringstream wait(line);
  char temp;
  int lineno =0;
  int column = 0;
  for(int i =0; i < size; i++){
    getline(ifile,line) ;
      wait.str(line);
      while(getline(wait,piece, ',')){
              temp = piece[0];
              // cout << temp << " "; 
              switch (temp)
              {
                case 'X' :
                  area[lineno][column].type= wall ;
                  area[lineno][column].home = false; 
                  column ++;
                  break ;

                case 'A' :
                area[lineno][column].type= avatar ;
                area[lineno][column].home = false ;
                column ++;
                   break ;

                case 'H' :
                area[lineno][column].type= home ;
                area[lineno][column].home = true;
                column ++; 
                  break ;

                case ' ':
                 area[lineno][column].type= space ;
                 area[lineno][column].home = false; 
                 column ++;
                  break ;

                  case 'B':
                 area[lineno][column].type= box ;
                 area[lineno][column].home = false; 
                 column ++;
                  break ;
              }
          }
        lineno ++;
        column = 0;
        wait.clear();
      }   

      getline(ifile,line) ;
      moves = stoi(line);
      
    cout << endl ;
  }

