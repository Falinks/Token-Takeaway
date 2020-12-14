#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

//This is the basic multiplayer mode
int tokenTakeaway(int d,string name[2],int arr[10],int l){
  int a;

  for(int i=0; arr[0]>0 || arr[1]>0 || arr[2]>0 || arr[3]>0 || arr[4]>0 || arr[5]>0 || arr[6]>0 || arr[7]>0 || arr[8]>0 || arr[9]>0;i++){
    cout << endl;
    for(int i=0; i<l; ++i){
      cout << arr[i] << " ";
    }
    sleep(1);
    cout << endl << name[d-1] << ", please input which pile you would like to take away from." << endl;
    cin >> a;

    if(arr[a-1] != 0 && a<=l && a>0){
      int b;
      sleep(1);
      cout << "How many tokens would you like to take from pile " << a << "?" << endl;
      cin >> b;

      if(arr[a-1]-b >= 0){
        arr[a-1] -= b;
        if(d==1){
          d=2;
        }
        else{
          d=1;
        }
      }
      else{
        sleep(1);
        cout << endl << "ERROR, Please take away a smaller number so that the pile does not have less than zero tokens." << endl << endl;
      }
    }
    else{
      sleep(1);
      cout << endl << "ERROR: please select a valid pile (1, 2, or 3) that has at least one token in it." << endl << endl;
    }
  }
  sleep(1);
  cout << endl << name[d-1] << " wins!" << endl;

  return d;
}

//I know this is a really old game but I can't remember its name for the life of me.
void counterCountdown(){
  int a = 21;
  string name[] = {"Player 1", "Player 2"};
  int b;
  int d=0;
  for(int i=0; a>0; ++i){
    sleep(1);
    cout << endl << a << endl << name[d] << ", How many counters do you wish to take away(1, 2, or 3)" << endl;
    cin >> b;
    for(int i=0; b!=1 && b!=2 && b!=3; ++i){
      sleep(1);
      cout << endl << "INVALID NUMBER!" << endl << "Please input either 1, 2, or 3" << endl;
      cin >> b;
    }
    a-=b;
    if(d==0){
      d=1;
    }
    else{
      d=0;
    }
  }
  if(d==0){
    d=1;
  }
  else{
    d=0;
  }
  sleep(1);
  cout << endl << "0" << endl << endl << name[d] << " wins!";
  sleep(1);
  cout << endl << endl << "Press 1 to play again" << endl;
  cin >> a;
  if(a==1){
    sleep(1);
    counterCountdown();
  }
}

//This is used to find the variables a & e in tTVCPU. Yes I know I fricked up the name but I don't feel like fixing it.
int findAandB(int arr[3],int g){
  int a;
  int e;
  if(arr[0]==arr[1] || arr[0]==arr[2] || arr[1]==arr[2]){
    if(arr[0] == arr[1]){
      a=3;
    }
    if(arr[0] == arr[2]){
      a=2;
    }
    if(arr[1] == arr[2]){
      a=1;
    }
    e=2;
  }
  if(arr[0]==0 || arr[1]==0 || arr[2]==0){
    if(arr[0] > arr[1] && arr[0] > arr[2]){
      a=1;
      e=3;
    }
    if(arr[1] > arr[0] && arr[1] > arr[2]){
      a=2;
      e=4;
    }
    if(arr[2] > arr[0] && arr[2] > arr[1]){
      a=3;
      e=5;
    }
  }
  if((arr[0]==3||arr[1]==3||arr[2]==3)&&(arr[0]==4||arr[1]==4||arr[2]==4)&&(arr[0]==5||arr[1]==5||arr[2]==5)){
    if(arr[0]==3){
      a=1;
    }
    if(arr[1]==3){
      a=2;
    }
    if(arr[2]==3){
      a=3;
    }
      e=6;
    }
  if((arr[0]==1||arr[1]==1||arr[2]==1)&&(arr[0]==2||arr[1]==2||arr[2]==2)){
    if(arr[0]>2){
      a=1;
      e=8;
    }
    if(arr[1]>2){
      a=2;
      e=8;
    }
    if(arr[2]>2){
      a=3;
      e=8;
    }
  }
  if((arr[0]==1||arr[1]==1||arr[2]==1)&&(arr[0]==3||arr[1]==3||arr[2]==3)&&(arr[0]>3||arr[1]>3||arr[2]>3)){
    if(arr[0]>3){
      a=1;
      e=9;
    }
    if(arr[1]>3){
      a=2;
      e=9;
    }
    if(arr[2]>3){
      a=3;
      e=9;
    }
  }
  if((arr[0]==2||arr[1]==2||arr[2]==2)&&(arr[0]==3||arr[1]==3||arr[2]==3)&&(arr[0]>3||arr[1]>3||arr[2]>3)){
    if(arr[0]>3){
      a=1;
      e=10;
    }
    if(arr[1]>3){
      a=2;
      e=10;
    }
    if(arr[2]>3){
      a=3;
      e=10;
    }
  }
  if((arr[0]==0||arr[1]==0||arr[2]==0)&&(arr[0]==1||arr[1]==1||arr[2]==1)){
    if(arr[0]!=0&&arr[0]!=1){
      a=1;
    }
    if(arr[1]!=0&&arr[1]!=1){
      a=2;
    }
    if(arr[2]!=0&&arr[2]!=1){
      a=3;
    }
    e=7;
  }
  if((arr[0]==3||arr[1]==3||arr[2]==3)&&(arr[0]==4||arr[1]==4||arr[2]==4)&&(arr[0]==6||arr[1]==6||arr[2]==6)){
    if(arr[0]==3){
      a=1;
    }
    if(arr[1]==3){
      a=2;
    }
    if(arr[2]==3){
      a=3;
    }
    e=1;
  }
  if(arr[0]==1&&arr[1]==4&&arr[2]==6){
    a=3;
    e=1;
  }
  if(arr[0]==1&&arr[1]==5&&arr[2]==6){
    a=3;
    e=6;
  }
  if(arr[0]==2&&arr[1]==4&&arr[2]==5){
    a=1;
    e=1;
  }
  if(arr[0]==1&&arr[1]==1){
    if(arr[2]==0){
      a=1;
      e=1;
    }
    else{
    a=3;
    e=10;
    }
  }
  if(arr[2]==1&&arr[1]==1){
    if(arr[0]==0){
      a=2;
      e=1;
    }
    else{
    a=1;
    e=10;
    }
  }
  if(arr[0]==1&&arr[2]==1){
    if(arr[1]==0){
      a=1;
      e=1;
    }
    else{
      a=2;
      e=10;
    }
  }
  if(arr[0]==0&&arr[1]==0){
    a=3;
    e=10;
  }
  if(arr[0]==0&&arr[2]==0){
    a=2;
    e=10;
  }
  if(arr[1]==0&&arr[2]==0){
    a=1;
    e=10;
  }
  if(arr[0]==2&&arr[1]==5&&arr[2]==6){
    a=2;
    e=1;
  }
  if(g==1){
    return a;
  }
  else{
    return e;
  }
}

int level2findAandE(int arr[3], int b){
  int a=0;
  int e=0;
  if((arr[0]==0||arr[1]==0||arr[2]==0)&&(arr[0]==1||arr[1]==1||arr[2]==1)){
    if(arr[0]>1){
      a=1;
      e=1;
    }
    if(arr[1]>1){
      a=2;
      e=1;
    }
    if(arr[2]>1){
      a=3;
      e=1;
    }
    if((arr[0]==1&&arr[1]==1)||(arr[0]==1&&arr[2]==1)||(arr[2]==1&&arr[1]==1)){
      if(arr[0]==1){
        a=1;
        e=1;
      }
      if(arr[1]==1){
        a=2;
        e=1;
      }
    }
  }
  if(arr[0]==0&&arr[1]==0&&arr[2]>1){
    a=3;
    e=2;
  }
  if(arr[0]==0&&arr[2]==0&&arr[1]>1){
    a=2;
    e=2;
  }
  if(arr[2]==0&&arr[1]==0&&arr[0]>1){
    a=1;
    e=2;
  }
  if(b==1){
    return a;
  }
  else{
    return e;
  }
}

int level2FindB(int e, int a, int arr[3]){
  int b=0;

  if(e==1){
    b=arr[a-1];
  }
  if(e==2){
    b=arr[a-1]-1;
  }
  return b;
}

//This is used to find the variable b in tTVCPU
int findB(int e, int a, int b, int arr[3]){
  if(e==1){
    b=1;
  }
  if(e==2){
    b=arr[a-1];
  }
  if(e==3){
    b=arr[0]-(arr[1]+arr[2]);
  }
  if(e==4){
    b=arr[1]-(arr[0]+arr[2]);
  }
  if(e==5){
    b=arr[2]-(arr[0]+arr[1]);
  }
  if(e==6){
    b=2;
  }
  if(e==7){
    b=arr[0]+arr[1]+arr[2]-1;
  }
  if(e==8){
    b=arr[a-1]-3;
  }
  if(e==9){
    b=arr[a-1]-2;
  }
  if(e==10){
    b=arr[a-1]-1;
  }
  return b;
}

//This is the basic singleplayer mode against a computer that should be unbeatable. It stands for Token Takeaway Vs. CPU. I also added some easier difficulties that are very easy to beat. 
void tTVCPU(char h){
  int arr[] = {3, 5, 7};
  string name[] = {"CPU","Player"};
  int d=0;
  int a;
  int b;
  int c=1;
  int e;

  for(int i=0; arr[0]!=0 || arr[1]!=0 || arr[2]!=0;i++){
    cout << endl << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    sleep(1);
    cout << name[d] << ", please input which pile you would like to take away from." << endl;

    if(d==0){
      if(h=='1'){
        srand(time(0));
        a=1+(rand()%3);
        for(int i=0; arr[a-1]==0; ++i){
          a=1+(rand()%3);
        }
      }
      if(h=='2'){
        srand(time(0));
        a=level2findAandE(arr, 1);
        e=level2findAandE(arr, 2);
        if(a==0){
          a=1+(rand()%3);
          for(int i=0; arr[a-1]==0; ++i){
            a=1+(rand()%3);
          }
        }
      }
      if(h=='3'){
        if(c==1){
          a=3;
          e=1;
        }
        else{
          a=findAandB(arr, 1);
          e=findAandB(arr, 2);
        }
      }
      sleep(1);
      cout << a << endl;
    }
    else{
      cin >> a;
    }

    if(arr[a-1] != 0 && (a==1 || a==2 || a==3)){
      sleep(1);
      cout << "How many tokens would you like to take from  pile " << a << "?" << endl;

      if(d==0){
        if(h=='1'){
          srand(time(0));
          b=1+(rand()%arr[a-1]);
        }
        if(h=='2'){
          b=level2FindB(e,a,arr);
          if(b==0){
            srand(time(0));
            b=1+(rand()%arr[a-1]);
          }
        }
        if(h=='3'){
          b=findB(e, a, b, arr);
        }
        sleep(1);
        cout << b << endl;
        sleep(1);
      }
      else{
        cin >> b;
      }

      if(arr[a-1]-b >= 0 && b>0){
        arr[a-1] -= b;
        if(d==0){
          d=1;
          c++;
        }
        else{
          d=0;
          c++;
        }
      }
      else{
        sleep(1);
        cout << endl << "ERROR, Please take away a smaller number so that the pile does not have less than zero tokens. Also make sure you take away at least one token." << endl << endl;
      }
    }
    else{
      sleep(1);
      cout << endl << "ERROR: please select a valid pile (1, 2, or 3) that has at least one token in it." << endl << endl;
    }
  }
  cout << endl << arr[0] << " " << arr[1] << " " << arr[2] << endl;
  if(d==0){
    sleep(1);
    cout << endl << "The AI Wins";
  }  
  if(d==1){
    sleep(1);
    cout << endl << "You did it, you beat the CPU at level " << h;
  }
  sleep(1);
  cout << endl << endl << "Press 1 to play again" << endl;
  cin >> a;
  if(a==1){
    sleep(1);
    tTVCPU(h);
  }
}

string findCard(int a){
  string b;
  if(a<=4){
    b="A";
  }
  if(a>4&&a<=8){
    b="2";
  }
  if(a>8&&a<=12){
    b="3";
  }
  if(a>12&&a<=16){
    b="4";
  }
  if(a>16&&a<=20){
    b="5";
  }
  if(a>20&&a<=24){
    b="6";
  }
  if(a>24&&a<=28){
    b="7";
  }
  if(a>28&&a<=32){
    b="8";
  }
  if(a>32&&a<=36){
    b="9";
  }
  if(a>36&&a<=40){
    b="10";
  }
  if(a>40&&a<=44){
    b="J";
  }
  if(a>44&&a<=48){
    b="Q";
  }
  if(a>48&&a<=52){
    b="K";
  }
  return b;
}

//I could shorten this code down a bit, but I don't feel like it.
int calculate(string hand[10], int b){
  int a=0;
  int c=0;
  for(int i=0; i<b; ++i){
    if(hand[i]=="A"){
      a+=11;
      c++;
    }
    if(hand[i]=="2"){
      a+=2;
    }
    if(hand[i]=="3"){
      a+=3;
    }
    if(hand[i]=="4"){
      a+=4;
    }
    if(hand[i]=="5"){
      a+=5;
    }
    if(hand[i]=="6"){
      a+=6;
    }
    if(hand[i]=="7"){
      a+=7;
    }
    if(hand[i]=="8"){
      a+=8;
    }
    if(hand[i]=="9"){
      a+=9;
    }
    if(hand[i]=="10"){
      a+=10;
    }
    if(hand[i]=="J"){
      a+=10;
    }
    if(hand[i]=="Q"){
      a+=10;
    }
    if(hand[i]=="K"){
      a+=10;
    }
  }
  for(int i=0; c!=0; i++){
    if(a>21){
      a-=10;
    }
    c--;
  }
  return a;
}

//This is what would make the IT department block this code if it was a website for 'gambling'.
void blackjack(){
  srand(time(0));
  int a;
  int b = 2;
  int c = 0;
  int arr[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int e = 0;
  string hand[10];
  for(int i=0; i<2; ++i){
    a = 1 + (rand() % 52);
    for(int g=0; g!=1; g++){
      for(int h=0; h<e; ++h){
        if(a==arr[e]){
          g=0;
          a = 1 + (rand() % 52);
        }
      }
    }
    hand[i] = findCard(a);
    e++;
  }

  cout << endl << "Starting game of Blackjack" << endl;
  sleep(2);

  for(char i='0'; i!='2'; i=i){
    for(int f=0; f<=b; ++f){
      cout << hand[f] << " ";
    }
    sleep(1);
    cout << "= " << calculate(hand, b) << endl;
    if(calculate(hand,b)<=21){
      cout << endl << "Press 1 to hit" << endl << "Press 2 to stand" << endl;
      b++;
      cin >> i;
      for(int j=0; i!='1' && i!='2'; j=j){
        sleep(1);
        cout << endl << "Please input either '1' or '2'." << endl;
        cin >> i;
      }
      if(i=='1'){
        a = 1 + (rand() % 52);
        for(int g=0; g!=1; g++){
          for(int h=0; h<e; ++h){
            if(a==arr[e]){
              g=0;
              a = 1 + (rand() % 52);
            }
          }
        }
        hand[b-1] = findCard(a);
        e++;
      }
      if(i=='2'){
        sleep(1);
        cout << endl << "Your score is " << calculate(hand, b);
      }
    }
    else{
      sleep(1);
      cout << endl << "Dealer Wins";
      i='2';
      c=1;
    }
  }
  if(c!=1){
    string dealer[10];
    int d=2;
    for(int i=0; i<2; ++i){
      a = 1 + (rand() % 52);
      for(int g=0; g!=1; g++){
        for(int h=0; h<e; ++h){
          if(a==arr[e]){
            g=0;
            a = 1 + (rand() % 52);
          }
        }
      }
      dealer[i] = findCard(a);
      e++;
    } 
    sleep(1);
    cout << endl << endl << "Dealer's turn" << endl;
    for(int i=0; i!=1; i=i){
      sleep(1);
      for(int f=0; f<d; ++f){
        cout << dealer[f] << " ";
      }
      cout << "= " << calculate(dealer, d) << endl;
      d++;
      if(calculate(dealer,d)<17){
        sleep(1);
        cout << endl << "hit" << endl;
        a = 1 + (rand() % 52);
        for(int g=0; g!=1; g++){
          for(int h=0; h<e; ++h){
            if(a==arr[e]){
              g=0;
              a = 1 + (rand() % 52);
            }
          }
        }
        dealer[d-1] = findCard(a);
        e++;
      }
      else{
        sleep(1);
        cout << endl << "stand" << endl;
        i=1;
      }
    }
    if(calculate(dealer,d) > 21){
      sleep(1);
      cout << endl << "You Win";
    }
    else{
      if(calculate(dealer,d)!=calculate(hand, b)){
        if(calculate(dealer,d)<=calculate(hand, b)){
          sleep(1);
          cout << endl << "You Win";
        }
        else{
          sleep(1);
          cout << endl << "Dealer Wins";
        }
      }
      else{
        cout << endl << "Draw";
      }
    }
  }
  sleep(1);
  cout << endl << endl << "Press 1 to play again" << endl;
  cin >> a;
  if(a==1){
    blackjack();
  }
}

//Here is the crappy rulebook
void rulebook(){
  char a;
  cout << "Press 1 to read the Standard Game Rules" << endl << "Press 2 to read the Custom Game Rules" << endl << "Press 3 to read the Counter Countdown Rules" << endl << "Press 4 to read the Singleplayer Rules" << endl << "Press 5 to read the Blackjack Rules" << endl;
  cin >> a;
  if(a=='1'){
    cout << endl << "     There are 3 piles containing tokens, and the objective is to make your opponent take the last token." << endl << endl << "     First declare a number(1, 2, or 3) to select which pile you will take tokens away from. Then declare the number of tokes you wish to take away from that pile; the declared number must be greater than zero but no larger than the amount of tokens in the selected pile.";
  }
  if(a=='2'){
    cout << endl << "     Just like the Standard Game rules except beforehand, you select the amount of piles followed by the amount of tokens in each of those piles. You should be able to have as many tokens in a pile as you want although optimal play in a ginormous pile could take a long time.";
  }
  if(a=='3'){
    cout << endl << "     There is one pile containing 21 counter. The objective is to be the one who takes the last counter. on your turn, you must take either 1, 2, or 3 counters from the pile.";
  }
  if(a=='4'){
    cout << endl << "     Simply select the dificulty level for the CPU and there you go, you play according to the rules of the standard game. The CPU goes first every time. If you want to know the reason, then you better spend some time trying to over analyzing the game to find out the reason.";
  }
  if(a=='5'){
    cout << endl << "     The objective of Blackjack is to get your score higher than the dealer's score without going over 21. The game starts with you being dealt two cards. You can choose to either hit or stand" << endl << "     If you select hit, you will be given another card and that card will be added to your score. If you select stand, you will not get another card and it will now be the dealer's turn. If your score goes above 21, you automatically lose." << endl << "     During the dealer's turn, he will be given 2 cards and will get more until his score is at least 17. then your score and the dealer's score is compared and whomever has the highest score without going over 21 wins." << endl << "How points are scored:" << endl << "2-10: Their respective numbers" << endl << "A: 1 or 11, depending on whether or not 11 will make you go over 21." << endl << "K,Q,J: 10";
  }
}

//This is main, it is essentially the start screen
int main() {

  cout << "Press 1 to play the game" << endl << "Press 2 to read the rules" << endl;

  char a;
  int x = 0;
  int y = 0;
  int b = 1;
  char e;
  int l = 3;
  cin >> a;
  string name[2];

  for(int i=0; a != '1' && a != '2'; ++i){
    sleep(1);
    cout << endl << "INVALID DIFFICULTY LEVEL!" << endl << "Please input either 1 or 2" << endl;
    cin >> a;
  }
  sleep(1);

  if(a=='2'){
    rulebook();
    a=1;
  }

  if(a=='1'){
    char f;
    sleep(1);
    cout << endl << "Press 1 to play multiplayer, press 2 to play singleplayer" << endl;
    cin >> f;

    for(int i=0; f != '1' && f != '2' && f != '3'; ++i){
      sleep(1);
      cout << endl << "INVALID SELECTION!" << endl << "Please input either 1, 2, or 3" << endl;
      cin >> f;
    }

    if(f=='1'){
      char k;
      
      sleep(1);
      cout << endl << "Press 1 to play Standard Game" << endl << "Press 2 to play Custom Game" << endl << "Press 3 to play Bonus Games" << endl;
      cin >> k;

      for(int i=0; k != '1' && k != '2' && k != '3'; ++i){
        sleep(1);
        cout << endl << "INVALID DIFFICULTY LEVEL!" << endl << "Please input either 1, 2, or 3" << endl;
        cin >> k;
      }

      int arr[10];
      int mem[10] = {3,5,7,0,0,0,0,0,0,0};

      if(k=='2'){
        sleep(1);
        cout << endl << "Input the number of piles (max of 10):" << endl;
        cin >> l;
        for(int i=0; i<l; ++i){
          sleep(1);
          cout << endl << "Input the amount of tokens in pile " << i+1 << ":" << endl;
          cin >> arr[i];
          mem[i]=arr[i];
        }
        k=1;
      }

      if(k=='3'){
        char h;
        sleep(1);
        cout << endl << "Press 1 to play Counter Countdown" << endl << "Press 2 to play Blackjack" << endl;
        cin >> h;
        if(h=='1'){
          counterCountdown();
        }
        if(h=='2'){
          blackjack();
        }
      }

      if(k=='1'){
        sleep(1);
        cout << endl << "Player 1, please input your name (No spaces please)" << endl;
        cin >> name[0];
        sleep(1);
        cout << endl << "Player 2, please input your name (No spaces please)" << endl;
        cin >> name[1];

        int z;

        sleep(1);
        cout << endl << "Input the amount of games that a person has to win in order to be crowned victor:" << endl;
        cin >> z;

        for(int i=0; x < z && y < z; i++){
          for(int i=0; i<10; ++i){
            arr[i]=mem[i];
          }
          if(tokenTakeaway(b,name,arr, l)==1){
            x++;
            cout << endl << "   " << x << " - " << y << endl << endl;

            if(x!=z && y!=z){
              sleep(1);
              cout << name[1] << ", please press 1 to go first or press 2 to go second" << endl << endl;
              cin >> e;
              for(int i=0; e!='1' && e!='2'; ++i){
                sleep(1);
                cout << endl << "INVALID NUMBER!" << endl << "Please input either 1 or 2" << endl;
                cin >> e;
              }
              if(e=='1' || e=='2'){
                if(e=='1'){
                  b='2';
                }
                else{
                  b='1';
                }
              }
            }
          }
          else{
            y++;
            cout << endl << "   " << x << " - " << y << endl << endl;

            if(x!=z && y!=z){
              sleep(1);
              cout << name[0] << ", please press 1 to go first or press 2 to go second" << endl;
              cin >> e;
              for(int i=0; e!='1' && e!='2'; ++i){
                sleep(1);
                cout << endl << "INVALID NUMBER!" << endl << "Please input either 1 or 2" << endl;
                cin >> e;
              }
              if(e=='1' || e=='2'){
                if(e=='1'){
                  b=1;
                }
                else{
                  b=2;
                }
              }
            }
          }
        }
        if(x==z){
          sleep(1);
          cout << endl << name[0] << " IS THE CHAMPION" << endl;
        }
        else{
          sleep(1);
          cout << endl << name[1] << " IS THE CHAMPION" << endl;
        }
      }
    }

    if(f=='2'){
      char h;
      sleep(1);
      cout << endl << "Please input the difficulty level" << endl << "1 = level 1" << endl << "2 = level 2" << endl << "3 = level 3" << endl;
      cin >> h;

      for(int i=0; h!='1' && h!='2' && h!='3'; ++i){
        sleep(1);
        cout << endl << "INVALID NUMBER!" << endl << "Please input either 1, 2, or 3" << endl;
        cin >> h;
      }

      sleep(1);
      cout << endl << "Starting game against CPU, CPU will be going first" << endl << endl;

        tTVCPU(h);
    }
  }
  return 0;
}