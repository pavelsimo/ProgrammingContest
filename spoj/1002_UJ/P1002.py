#!/usr/bin/env python
# @BEGIN_OF_SOURCE_CODE
# @SPOJ UJ Python "Math, Combinatorics"

from sys import stdin

while True:
   p = stdin.readline().split()
   N  = int(p[0])
   CD = int(p[1])
   if N==0 and CD==0:
      break;
   print N**CD
# @END_OF_SOURCE_CODE
