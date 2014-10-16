#!/usr/bin/python
# Copyright (C) 2011  Pavel Simo
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
import sys
import collections


if __name__ == '__main__':
   A   = [231552,234756,596873,648219,726312,981237,988331,1277361,1283379]
   ans = [0,0,0,0,0,0,0,0,0]
   freq = {}
   for line in sys.stdin:
      n = int(line)
      freq[n] = freq.get(n, 0) + 1
   for x in freq:
      for i in xrange(0, len(A)):
         if x <= A[i]:
            f1 = freq.get(x, 0)
            f2 = freq.get(A[i] - x, 0)
            if f1 > 0 and f2 > 0:
               if x == A[i] - x and f1 >= 2:
                  ans[i] = 1
               elif f1 >= 1 and f2 >= 1:
                  ans[i] = 1
   for i in ans:
      print i,
