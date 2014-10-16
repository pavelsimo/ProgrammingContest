#!/usr/bin/python
from sys import stdin

def solve(S, N):
   cnt, mult, csum, psum = 0, 0, 0, 0
   while True:
      mult = len(S) ** cnt
      csum += mult
      L, R = csum, csum + mult - 1
      for ch in S:
         if N >= L and N <= R:
            return (ch, cnt, psum + N - L)
         L = R + 1
         R = L + mult - 1
      cnt = cnt + 1
      psum = csum

def main():
   TC = int(stdin.readline().strip())
   for tc in xrange(1, TC+1):
      line = stdin.readline().strip().split()
      S, N = line[0], int(line[1])
      res, rem = "", N
      while True:
         ch, lvl, rem = solve(S, rem)
         res += ch
         if lvl == 0:
            break
      print 'Case #%s: %s' % (tc, res)

if __name__ == '__main__':
   main()
