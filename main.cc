#include <iostream>
#include <sstream>
using namespace std;

// Test harness for IntSet functions. You may assume that all commands entered are valid.
// Valid commands: n <ind>,  p <ind>, & <ind1> <ind2>,
//                 | <ind1> <ind2>, = <ind1> <ind2>,
//                 s <ind1> <ind2>, c <ind1> <elem>,
//                 a <ind1> <elem>, r <ind1> <elem>,
//                 q/EOF
// Silently ignores invalid commands. Doesn't check that 0 <= index < MAX_INT_SETS.
// Do not test invalid commands!

int main() { 
  
  char c;

    while ( cin >> c ) {
        int lhs, rhs;
 
        if ( c == 'q' ) break;
        
        switch(c) {
          case 'n':
            // Create new IntSet at index lhs after destroying the old.
            // Read in integers to add to it until hitting non-int using operator>>.

          case 'p':
            // Print IntSet at lhs.

          case '&':
            // Print intersection of lhs and rhs.


          case '|':
            // Print union of lhs and rhs.


          case '=':
            // Print true if lhs == rhs, false otherwise.

          case 's':
            // Print true if rhs is subset of lhs, false otherwise.


          case 'c':
            // Print true if lhs contains element rhs, false otherwise.


          case 'a':
            // Add elem rhs to set lhs


          case 'r':
            // Remove elem rhs from set lhs

            
        } // switch
    } // while
} // main
