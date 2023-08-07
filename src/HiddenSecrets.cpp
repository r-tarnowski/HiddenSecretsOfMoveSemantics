#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "===============================================" << endl;
   cout << "   CppCon 2020 - Lecture by Nicolai Josuttis   " << endl;
   cout << "      The Hidden Secrets of Move Semantics     " << endl;
   cout << "                    Examples                   " << endl;
   cout << "===============================================" << endl;
   cout << endl;
}

void mem( const std::string & txt ) {
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

/*
    std::string * pRetVal = new std::string{ pVal };
    std::cout << "get: ";
    mem( * pRetVal );
    return (* pRetVal);
*/
}

std::string getString( const char * pVal ) {

   std::string retVal { pVal };
   std::cout << "getString: ";
   mem( retVal );
   return std::move(retVal);
}

class Cont {
   std::vector<std::string> vals;
public:
   Cont() {
       vals.reserve( 10 );
   }

   void insert(const std::string & v) {
       std::cout << "insert(const std::string & v) called" << std::endl;
       vals.push_back( v );
   }

   void insert( std::string && v ) {
       std::cout << "insert( std::string && v ) called" << std::endl;
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

   Cont txt;

   std::string str = "hello";
   mem( str );
   txt.insert( str );
   txt.print();

   txt.insert( getConstString( "const_string" ) );
   txt.print();

   txt.insert( getString( "non_const_string_1" ) );
   txt.print();

   txt.insert( getString( "non_const_string_2" ) );
   txt.print();

/*
   std::string fromGet = getString( "string2" );
   mem( fromGet );

   txt.insert( std::move( fromGet ) );
   txt.print();
*/
   //mem( str );

   //mem( getString() );


   return 0;
}
