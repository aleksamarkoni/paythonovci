#include <iostream>
using namespace std;


bool buyMore() {
  cout << "Do you want to buy anything else?, please enter [Y]es or [N]o." << endl;
  char buyElse=reader.readChar("YyNn");
  buyElse = toupper(buyElse);
  if(buyElse == 'Y')
    return true;
  return false;
}


int main() {

  int payment = 10; //the total money you have
  int priceBeer = 2; //the unit price for each items
  int priceSoda = 3;
  int priceWine = 5;
  int priceGum = 1;
  int priceMilk = 6;

  int amountBeer = 10;
  int amountSoda = 10;
  int amountWine = 10;
  int amountGum = 50;
  int amountMilk = 30;

  int payBeer = 0;
  int paySoda = 0;
  int payWine = 0;
  int payGum = 0;
  int payMilk = 0;

  bool isQuit = false;
  bool haveMoney = false;
  while (!isQuit && !haveMoney) {
    menu();

  char selectBuyer = reader.readChar("BbSsWwGgMmCc");
  selectBuyer = toupper(selectBuyer);
  if( selectBuyer == 'B' )
    cout << "Now you select beer." << endl;
  if( selectBuyer == 'S' )
    cout << "Now you select Soda" << endl;
  if( selectBuyer == 'W' )
    cout << "Now you select Wine." << endl;
  if( selectBuyer == 'G' )
    cout << "Now you select Gum." << endl;
  if( selectBuyer == 'M' )
    cout << "Now you select Milk." << endl;
  if( selectBuyer == 'C' )
    cout << "You select check out. Your balance is zero.\n" ;

  switch (selectBuyer) {
    case 'B': {
      cout << "How many bottoles of beer do you need?\n" ;
      int buyBeer = reader.readInt(1,10);
      cout << "Now you select " << buyBeer << "." << "\n" << "You spend " << buyBeer*priceBeer << " Dollars on Beer." << endl;
      payBeer = payBeer + buyBeer * priceBeer;
      payment = payment - buyBeer * priceBeer;
      amountBeer = amountBeer - buyBeer;
      cout << "Now your balance is left " << payment << " Dollar. " << endl;
      if(payment <0) {
        isQuit = true;
        break;
      }
      cout << "The beer of bottle is " << amountBeer << endl;
      }
    case 'S': {
      cout << "you select soda now. Please input the numbers of Soda." ;
      int buySoda = reader.readInt(1,10);
      cout << "Now you select " << buySoda << "." << "\n" << "You spend " << buySoda * priceSoda << " Dollars on Soda." << endl;
      paySoda = paySoda + buySoda * priceSoda;
      payment = payment - paySoda;
      amountSoda = amountSoda - buySoda;
      cout << "Now your balance is left " << payment << " Dollar. "<< endl;
      cout << "The soda of bottle is " << amountSoda << endl;
    }
    case 'W': {
      cout << "you select beer now. Please input the numbers of Wine.";
      int buyWine = reader.readInt(1,10);
      cout << "Now you select "<< buyWine << "." << "\n" <<"You spend " << buyWine*priceWine << " Dollars on Wine."<< endl;
      payWine = payWine + buyWine * priceWine;
      payment = payment - payWine;
      cout << "Now your balance is left " << payment << " Dollar. "<< endl;
      break;
    }
    case 'G': {
      cout << "you select beer now. Please input the numbers of Gum.";
      int buyGum = reader.readInt(1,10);
      cout << "Now you select " << buyGum << "." << "\n" << "You spend " << buyGum * priceGum << " Dollars on Gum." << endl;
      payGum = payGum + buyGum * priceGum;
      payment = payment - payGum;
      cout << "Now your balance is left " << payment << " Dollar. "<< endl;
      break;
    }
    case 'M': {
      cout << "you select beer now. Please input the numbers of Milk";
      int buyMilk = reader.readInt(1,10);
      cout << "Now you select " << buyMilk << "." << "\n" << "You spend " << buyMilk * priceMilk << " Dollars on Milk." << endl;
      payMilk = payMilk + buyMilk * priceMilk;
      payment = payment - payMilk;
      cout << "Now your balance is left " << payment << " Dollar. "<< endl;
      break;
    }
  }
  if(buyMore() == true ) { //user choose yes and buy else.
    isQuit = false;// not quit and shopping again.
  }
  else {
    isQuit = true;
    continue;
  }
}

  int totalPay = 0;
  int totalOwn = payBeer + paySoda + payWine + payGum + payMilk;

  cout <<"Your totalOwn "<< totalOwn << endl;
  if(totalOwn>payment)
    isQuit=false;

    else if (totalOwn != 0) {
      cout << "Now you total own " << totalOwn << endl;
      cout << "Please enter your payment:" ;

    do {
      int totalPay = reader.readInt();
      if(totalPay > totalOwn) {
        cout << "Thanks for your shopping here. please keep your change. $" << totalPay-totalOwn << " ." << endl;
        break;
      }
      else if (totalPay < totalOwn)
      cout << "Sorry, you still own us" << totalOwn - totalPay << "Dollars. " << ", please enter your moeny again." << endl;
        else
        {
          cout << "Thanks for your shopping in my store. \n" ;
          break;
        }
      }while(totalPay != totalOwn);
    }
    return 0;
}
