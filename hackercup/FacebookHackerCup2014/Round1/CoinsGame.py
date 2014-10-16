#!/usr/bin/python
from sys import stdin

def main():
   TC = int(stdin.readline().strip())
   for tc in xrange(1, TC+1):
      line = stdin.readline().strip().split()
      njars, ncoins, ntarget = int(line[0]), int(line[1]), int(line[2])
      
      res = 0
      if njars > ncoins:
         miss = (njars - ncoins) 
         res = miss + ntarget
      else:
         bucket_sz = ncoins / njars
         bucket_rem = ncoins % njars
         
         if bucket_rem == 0:
            res = ntarget
         else:            
            if ncoins/njars >= ntarget:
               res = ntarget
            else:
               mi = 1000000000000000
               for j in xrange(njars, 0, -1):
                  a = ntarget / j
                  rem = ntarget % j
                  nempty = njars - j
                  if rem >= 1:
                     nempty = max(0, nempty - 1)
                  #print (a, rem, nempty)
                  mi = min(mi, ntarget + rem + nempty)
               res = mi

      print 'Case #%s: %s' % (tc, res)

if __name__ == '__main__':
   main()
