#include "iostream"
#include "string"
#include "vector"

using namespace std;

void decode(string word, string *alphabet) {
  if (!word.compare(".-")) *alphabet += "A";
  if (!word.compare("-...")) *alphabet += "B";
  if (!word.compare("-.-.")) *alphabet += "C";
  if (!word.compare("-..")) *alphabet += "D";
  if (!word.compare(".")) *alphabet += "E";
  if (!word.compare("..-.")) *alphabet += "F";
  if (!word.compare("--.")) *alphabet += "G";
  if (!word.compare("....")) *alphabet += "H";
  if (!word.compare("..")) *alphabet += "I";
  if (!word.compare(".---")) *alphabet += "J";
  if (!word.compare("-.-")) *alphabet += "K";
  if (!word.compare(".-..")) *alphabet += "L";
  if (!word.compare("--")) *alphabet += "M";
  if (!word.compare("-.")) *alphabet += "N";
  if (!word.compare("---")) *alphabet += "O";
  if (!word.compare(".--.")) *alphabet += "P";
  if (!word.compare("--.-")) *alphabet += "Q";
  if (!word.compare(".-.")) *alphabet += "R";
  if (!word.compare("...")) *alphabet += "S";
  if (!word.compare("-")) *alphabet += "T";
  if (!word.compare("..-")) *alphabet += "U";
  if (!word.compare("...-")) *alphabet += "V";
  if (!word.compare(".--")) *alphabet += "W";
  if (!word.compare("-..-")) *alphabet += "X";
  if (!word.compare("-.--")) *alphabet += "Y";
  if (!word.compare("--..")) *alphabet += "Z";
  if (!word.compare(".----")) *alphabet += "1";
  if (!word.compare("..---")) *alphabet += "2";
  if (!word.compare("...--")) *alphabet += "3";
  if (!word.compare("....-")) *alphabet += "4";
  if (!word.compare(".....")) *alphabet += "5";
  if (!word.compare("-....")) *alphabet += "6";
  if (!word.compare("--...")) *alphabet += "7";
  if (!word.compare("---..")) *alphabet += "8";
  if (!word.compare("----.")) *alphabet += "9";
  if (!word.compare("-----")) *alphabet += "0";
  if (!word.compare(".-.-.-")) *alphabet += ".";
  if (!word.compare("--..--")) *alphabet += ",";
  if (!word.compare("..--..")) *alphabet += "?";
  if (!word.compare(".----.")) *alphabet += "'";
  if (!word.compare("-.-.--")) *alphabet += "!";
  if (!word.compare("-..-.")) *alphabet += "/";
  if (!word.compare("-.--.")) *alphabet += "(";
  if (!word.compare("-.--.-")) *alphabet += ")";
  if (!word.compare(".-...")) *alphabet += "&";
  if (!word.compare("---...")) *alphabet += ":";
  if (!word.compare("-.-.-.")) *alphabet += ";";
  if (!word.compare("-...-")) *alphabet += "=";
  if (!word.compare(".-.-.")) *alphabet += "+";
  if (!word.compare("-....-")) *alphabet += "-";
  if (!word.compare("..--.-")) *alphabet += "_";
  if (!word.compare(".-..-.")) *alphabet += "\"";
  if (!word.compare(".--.-.")) *alphabet += "@";
}

void conversion(vector<string> &letters, int count, string *alphabet) {
  int len = 0;
  string word, letter;
  for (int i = 0; i < count; i++) {
    word = letters[i];
    if(i == count - 1) {
      word.pop_back(); // da skine znak za kraj u poslednjem slovu
    }
    if(!word.compare(" ")) {
      *alphabet += " ";
      word = "";
    }
    else {
      decode(word, &*alphabet);
      word = "";
    }
  }
}


int main() {
  int n, msg_len = 0, count = 0;
  string message, letter, alphabet;
  vector<string> word;
  vector<string> sentence;
  //cout << "Enter number of messages" << endl;    //skinuto zbog UVa
  cin >> n;
  if (n > 1 || n < 10) {
    for (int i = 0; i < n; i++) {
      //cout << "Enter message: " << endl;      //skinuto zbog UVa
      if ( i == 0) {
        cin.ignore();  // da bi ignorovao return na kraju inace preskoci prvi getline()., ostane mu bafer;
      }
      getline(cin, message);
      msg_len = message.length();
      if (msg_len <= 2000) {
        for (int i = 0; i <= msg_len; i++) {
          if (message[i] != ' ') {
           letter += message[i];
          }
          if (message[i] == ' ' || i == msg_len) { // i == msg_len ide da bi push_back odradio i za poslednje slovo
          word.push_back(letter);
          letter = "";
          count++;
          }
          if (message[i] == ' ' && message[i + 1] == ' ') {
          word.push_back(" ");
          count++;
          }
        }
      conversion(word, count, &alphabet);
      sentence.push_back(alphabet);
      alphabet = "";
      word.clear();
      count = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << "Message #" << i + 1 << endl;
      if (i == n - 1) cout << sentence[i] << endl;
      else cout << sentence[i] << "\n"<< endl;
    }
  }
return 0;
}
