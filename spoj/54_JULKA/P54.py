#!/usr/bin/env python
# @BEGIN_OF_SOURCE_CODE
# @SPOJ JULKA Python "Ad Hoc"

from sys import stdin

for i in xrange(10):
    s = int(stdin.readline().strip())
    d = int(stdin.readline().strip())
    n = (s-d)/2
    k = s-n
    print k
    print n
# @END_OF_SOURCE_CODE
