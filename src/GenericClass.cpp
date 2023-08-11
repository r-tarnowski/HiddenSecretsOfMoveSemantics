#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "===============================================" << endl;
   cout << "   CppCon 2020 - Lecture by Nicolai Josuttis   " << endl;
   cout << "      The Hidden Secrets of Move Semantics     " << endl;
   cout << "            Examples - Generic Class           " << endl;
   cout << "===============================================" << endl;
   cout << endl;
}


void mem( const auto & txt ) {
   if ( ! txt.empty() ) {
      std::cout << std::hex << static_cast<const void *>( txt.data() ) << ": " << txt;
      //std::cout << std::endl << std::hex << static_cast<const void *>( & txt[0] ) << ": " << txt;
   }
   else {
      std::cout << "EMPTY STRING !!!";
   }
   std::cout << '\n';
}


const std::string getConstString( const char * pVal ) {

   std::string retVal { pVal };
   std::cout << "getConstString: ";
   mem( retVal );
   return retVal;
}



std::string getString( const char * pVal ) {

   std::string retVal { pVal };
   std::cout << "getString: ";
   mem( retVal );
   return std::move(retVal);
}




template<typename T>
class Cont {
   std::vector<T> vals;
public:
   void insert(const T & v) {
      std::cout << "insert(const T & v) called" << std::endl;
      vals.push_back( v );
   }

   void insert( T && v ) {
      std::cout << "insert( T && v ) called" << std::endl;
      vals.push_back( std::move( v ) );
   }

   void print() const {
      std::cout << "Cont: \n";
      for ( const auto & v : vals ) {
         std::cout << "> ";
         mem( v );
      }
   }
};

int main(int argc, char *argv[]) {
   printHeader();

   Cont<std::string> txt;
   txt.insert(getString("hello_from_getString") );
   txt.print();
/*
   std::string str_hello = "str_hello";
   mem( str_hello );
   txt.insert( str_hello );
   //txt.print();

   txt.insert( getConstString( "const_string" ) );
   //txt.print();

   txt.insert( getString( "non_const_string_1" ) );
   //txt.print();

   txt.insert( getString( "non_const_string_2" ) );
   //txt.print();

   mem( str_hello );
   txt.insert( std::move(str_hello) );

   std::string helloFromGetString = getString( "hello_from_getString" );
   mem( helloFromGetString );
   txt.insert( std::move(helloFromGetString) );

   str_hello = "str_hello_initialised_again";
   mem( str_hello );
   txt.insert( std::move(str_hello) );


   txt.print();
 */
   return 0;
}
