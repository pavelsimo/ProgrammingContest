#!/usr/bin/env python
# @BEGIN_OF_SOURCE_CODE
# @SPOJ CHAIR Python "Math, Combinatorics"

import math
from sys import stdin

def fact(n):
   if n < 0:
      return 0
   if n == 0:
      return 1
   res = 1
   while n > 0:
      res = res * n
      n = n - 1
   return res

MOD = 1000000003
n = input()
k = input() 
if k == 1:
   print 1
elif k > n-1:
   print 0
else:
   x = fact(n-1)
   y = fact(n-k)*fact(k)
   print (x-y)%MOD
# @END_OF_SOURCE_CODE
