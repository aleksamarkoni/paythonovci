using namespace std;

void main_menu() {
  cout << " _________________________________" << endl;
  cout << " |     DOBRODOSLI U KVIZ C++     |" << endl;
  cout << " | Izaberite oblast:             |" << endl;
  cout << " | 1) Fundamental variable types |" << endl;
  cout << " | 2) Void                       |" << endl;
  cout << " | 3) Variable sizes             |" << endl;
  cout << " | 4) Integers                   |" << endl;
  cout << " | 5) Floating point numbers     |" << endl;
  cout << " | 6) Boolean values             |" << endl;
  cout << " | 7) Exit                       |" << endl;
  cout << " |_______________________________|" << endl;
}

int Povezivanje::izbor(Povezivanje& povezivanje) {
int izbor;
cin >> izbor;
  switch(izbor) {
    case 1:
    //TODO ukloniti parametar iz metode
    //TODO promeniti da ovo budu relativne putanje
    // myfile = "../pitanja/CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt"
    myfile = "/home/dusan/gits/paythonovci/pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/21_fundamental_variable_types.txt";
    break;
    case 2:
    povezivanje.myfile = "/home/dusan/gits/paythonovci/pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/22_void.txt";
    break;
    case 3:
    povezivanje.myfile = "/home/dusan/gits/paythonovci/pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/23_variable_sizes.txt";
    break;
    case 4:
    povezivanje.myfile = "/home/dusan/gits/paythonovci/pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/24_integers.txt";
    break;
    case 5:
    povezivanje.myfile = "/home/dusan/gits/paythonovci/pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/25_floating_point_numbers.txt";
    break;
    case 6:
    povezivanje.myfile = "/home/dusan/gits/paythonovci/pitalice/"
    "CHAPTER2_Variables_and_Fundamental_Data_Types/26_boolean_values.txt";
    break;
    case 7:
    //return 0;
    break;
  }
}
