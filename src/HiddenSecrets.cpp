#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "===============================================" << endl;
   cout << "   CppCon 2020 - Lecture by Nicolai Jossutis   " << endl;
   cout << "      The Hidden Secrets of Move Semantics     " << endl;
   cout << "                    Examples                   " << endl;
   cout << "===============================================" << endl;
   cout << endl;
}


class Cont {
   std::vector<std::string> vals;
public:
   Cont() = default;

   void insert(const std::string & v) {
       vals.push_back( v );
   }

   void print() const {
       std::cout << "Cont: \n";
       for ( const auto & v : vals ) {
           std::cout << "> " << v << '\n';
       }
   }
};


int main(int argc, char *argv[]) {
   printHeader();

   Cont txt;

   std::string str{"hello"};
   std::cout << str << '\n';
   txt.insert( str );
   txt.print();

   return 0;
}
