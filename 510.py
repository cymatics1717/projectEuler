from gmpy2 import *

bmax = mpz(10**9)
nmax = mpz(bmax**0.25)

global s
s = mpz(0)

def jisuan(n):
  global s
  m = mpz(1)
  n = mpz(n)
  while m <= n:
    if gcd(m,n) == 1:
      k = bmax//(n**2 * (m+n)**2)
      s = s + k*(k+1)//2 * ((m**2+n**2)*(m+n)**2+m**2 * n**2)
    m = m+1

list(map(jisuan, range(1, nmax+1)))

print('result:',s)
