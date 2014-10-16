/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11223  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*
Morse Code

A	.- 	J	.- - - 	S	... 	      1	.- - - - 	.	.-.-.- 	   :	- - -...
B	-... 	K	-.- 	   T	- 	         2	..- - - 	   ,	- -..- - 	;	-.-.-.
C	-.-. 	L	.-.. 	   U	..- 	      3	...- - 	   ?	..- -.. 	   =	-...-
D	-.. 	M	- - 	   V	...- 	      4	....- 	   '	.- - - -. 	+	.-.-.
E	. 	   N	-. 	   W	.- - 	      5	..... 	   !	-.-.- - 	   -	-....-
F	..-. 	O	- - - 	X	-..- 	      6	-.... 	   /	-..-. 	   _	..- -.-
G	- -. 	P	.- -. 	Y	-.- - 	   7	- -... 	   (	-.- -. 	   "	.-..-.
H	.... 	Q	- -.- 	Z	- -.. 	   8	- - -.. 	   )	-.- -.- 	   @	.- -.-.
I	.. 	R	.-. 	   0	- - - - - 	9	- - - -. 	&	.-... 		
*/

int main(int argc, char *argv[]) {
   
   map<string, char> code;
   code[".-"]   = 'A';
   code["-..."] = 'B';
   code["-.-."] = 'C';
   code["-.."]  = 'D';
   code["."]    = 'E';
   code["..-."] = 'F';
   code["--."] = 'G';
   code["...."] = 'H';
   code[".."]   = 'I';
   code[".---"]   = 'J';
   code["-.-"]   = 'K';
   code[".-.."]   = 'L';
   code["--"]   = 'M';
   code["-."]   = 'N';
   code["---"]   = 'O';
   code[".--."]   = 'P';
   code["--.-"]   = 'Q';
   code[".-."]   = 'R';
   code["..."]   = 'S';
   code["-"]   = 'T';
   code["..-"]   = 'U';
   code["...-"]   = 'V';
   code[".--"]   = 'W';
   code["-..-"]   = 'X';
   code["-.--"]   = 'Y';
   code["--.."]   = 'Z';
   code["-----"]   = '0';
   code[".----"]   = '1';
   code["..---"]   = '2';
   code["...--"]   = '3';
   code["....-"]   = '4';
   code["....."]   = '5';
   code["-...."]   = '6';
   code["--..."]   = '7';
   code["---.."]   = '8';
   code["----."]   = '9';
   code[".-.-.-"]   = '.';
   code["--..--"]   = ',';
   code["..--.."]   = '?';
   code[".----."]   = '\'';
   code["-.-.--"]   = '!';
   code["-..-."]   = '/';
   code["-.--."]   = '(';
   code["-.--.-"]   = ')';
   code[".-..."]   = '&';
   code["---..."]   = ':';
   code["-.-.-."]   = ';';
   code["-...-"]   = '=';
   code[".-.-."]   = '+';
   code["-....-"]   = '-';
   code["..--.-"]   = '_';
   code[".-..-."]   = '\"';
   code[".--.-."]   = '@';
   
   int TC,n;
   string word;
   scanf("%d\n",&TC);
   for(int tc=1; tc<=TC; ++tc) {
      if(tc!=1) printf("\n");
      printf("Message #%d\n",tc);
      int ch, prev;
      word="";
      while((ch=getchar()) != EOF) {
         if(ch=='\n') {
            if(code.count(word)>0) putchar(code[word]);
            word="";
            break;
         }
         if(ch=='.' || ch=='-') {
            word+=ch;
         } else if(ch==' ' && (prev=='.'||prev=='-')) {
            if(code.count(word)>0) putchar(code[word]);
            word="";
         } else if(ch==' ' && prev==' ') {
            putchar(' ');
            ch='\0';
         }
         prev=ch;
      }
      putchar('\n');
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */

