// constructing vectors
#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  // constructors used in the same order as described above:
  vector<int> first;
  cout << "Velicina niza " << first.size() << endl;
  cout << "Kapacitet niza " << first.capacity() << endl;
  
  first.push_back(10);
  first.push_back(20);
  first.push_back(10);
  
  cout << "Velicina niza " << first.size() << endl;
  cout << "Kapacitet niza " << first.capacity() << endl;
  
  first.push_back(20);
  first.push_back(10);
  first.push_back(20);
  first.push_back(20);
  first.push_back(2323);
  first.push_back(232);
  
  for (int i = 0; i < first.size(); i++) {
	cout << first[i] << endl;
  }
  
  
  cout << "Velicina niza " << first.size() << endl;
  cout << "Kapacitet niza " << first.capacity() << endl;
  
  cout << first.front() << endl;
  cout << first.back() << endl;

  return 0;
}