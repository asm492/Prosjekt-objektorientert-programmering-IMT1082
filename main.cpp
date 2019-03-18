
#include <iostream>
#include "conster.h"					//	Test
#include "functions.cpp"
int main(int argc, const char * argv[]) {
    char command;                //  Brukerens ›nske/valg.
    
    
    printMenu();                  //  Meny av brukerens valg.
    
    command = read();             //  Leser brukerens ›nske/valg.
    while (command != 'Q')  {
        switch(command)  {
            case 'K':        break;   //  Legg inn (om mulig) ny ansatt.
            case 'S':        break;   //  Endre data om partner.
            case 'O':        break;   //  Legg inn (om mulig) nytt barn.
            case 'A':        break;   //  Skriv alle data om en ansatt.
            default:  printMenu();      break;   //  Meny av brukerens valg.
        }
        command = read();           //  Leser brukerens ›nske/valg.
    }
    return 0;
}
