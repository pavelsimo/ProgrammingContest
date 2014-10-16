import sys

TC = int(sys.stdin.readline())
for tc in xrange(TC):
   S = sys.stdin.readline().strip().split(" ")
   r, t = int(S[0]), int(S[1])
   lo, hi = 1, t
   while hi - lo > 1:
      k = (lo + hi) / 2
      if k * (2*r + 2*k - 1) <= t:
         lo = k
      else:
         hi = k
   print "Case #%d: %d" % (tc, lo)
