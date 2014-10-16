#!/usr/bin/python
# @BEGIN_OF_SOURCE_CODE
# @SPOJ BISHOPS C++ "Simple Math"
from sys import stdin

while True:
   line = stdin.readline()
   if line == '':
      break;
   n = int(line)
   if n == 1:
      print 1
   else:
      print 2*n-2
# @END_OF_SOURCE_CODE

