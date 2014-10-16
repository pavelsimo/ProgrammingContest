#!/usr/bin/env python
# @BEGIN_OF_SOURCE_CODE
# @SPOJ MINCOUNT Python "Ad Hoc"

from sys import stdin

TC = int(stdin.readline().strip())

for i in xrange(0,TC):
    n = int(stdin.readline().strip())
    if n == 0 or n == 1:
        print 0
    else:
        print n*(n+1)/6
# @END_OF_SOURCE_CODE
