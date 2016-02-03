#include <iostream>
#include "Text.h"
#include <sstream>
#include "Globals.h"

int wrap (std::string* text)
{
    char c = 0;
    unsigned int width = 78;
    unsigned int n = 0;
    unsigned int i = 0;
    unsigned int r = 0;
    unsigned int rStart[M_ROW];
    
    for (i = 0; i < M_ROW; i++) {
        rStart[i] = 0;
    }
    
    for (i = 0; i < text->length(); ++i) {
        if ((*text)[i] == '\n') {
            r++;
            rStart[r] = i;
        }
        else if ((i - rStart[r]) > width) {
            for (n = i; n > rStart[r]; --n) {
                c = (*text)[n];
                if (isspace(c)) {
                    (*text)[n] = '\n';
                    r++;
                    rStart[r] = n;
                }
            }
        }
    }
    return r + 1;
}

void screen (const std::string text)
{
    int r = 0;
    std::string prompt = text;
    
    r = wrap(&prompt);
    std::cout << prompt << std::endl;
    flush(r);
}

void flush (int n)
{
    std::cout << std::string(SCR_HEIGHT - n,'\n');
}

int getInt (int N)
{
    std::string input = "";
    std::string thang = "";
    int numb = 0;
    
    std::cout << "Please enter a number: ";
    getline(std::cin, input);
    std::stringstream myStream(input);
    
    if (myStream >> numb) {
        if (numb > N) {
            return FAIL;
        }
        else if (numb < 1) {
            return FAIL;
        }
        else {
            return numb;
        }
    }
    else {
        return FAIL;
    }
}
