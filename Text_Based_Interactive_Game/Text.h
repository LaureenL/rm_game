#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <string>
#include <ctype.h>

const unsigned int M_ROW = 20;
const int SCR_HEIGHT = 24;
int wrap (std::string*);
void screen (const std::string);
void flush (int);
int getInt (int);


#endif // TEXT_H_INCLUDED