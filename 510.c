#include<gmp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int cnt, char** v) {
    if (cnt > 1) {

        mpz_t max, pmax, qmax, p, q, max_tmp, ans, gcd, tmp, a, b, c, k;
        mpz_inits(max, pmax, qmax, '\0');
        mpz_inits(p, q, max_tmp, '\0');
        mpz_inits(ans, gcd, tmp, '\0');
        mpz_inits(a, b, c, k, '\0');

        mpz_set_str(max, v[1], 10);
        mpz_root(qmax, max, 4);
        mpz_fdiv_q_ui(max_tmp, max, 4);
        mpz_root(pmax, max_tmp, 4);

        mpz_set_str(p, "1", 10);
        while (mpz_cmp(p, pmax) <= 0)
        {
            mpz_set(q, p);
            while (mpz_cmp(q, qmax) <= 0) {
                mpz_gcd(gcd, p, q);
                if (mpz_cmp_ui(gcd, 1) == 0) {
                    // int g = mpz_get_ui(gcd);
                    // if(g==1){
                    // uint64_t k=max/q/q/(p+q)/(p+q);
                    // uint64_t a=p*p*(p+q)*(p+q);
                    // uint64_t b=q*q*(p+q)*(p+q);
                    // uint64_t c=p*p*q*q;
                    mpz_set_str(tmp, "0", 10);
                    mpz_set_str(max_tmp, "0", 10);
                    //mpz_set_str(k,"1",10);
                    mpz_set_str(a, "1", 10);
                    mpz_set_str(b, "1", 10);
                    mpz_set_str(c, "1", 10);
                    mpz_add(max_tmp, p, q);

                    mpz_fdiv_q(k, max, q);
                    mpz_fdiv_q(k, k, q);
                    mpz_fdiv_q(k, k, max_tmp);
                    mpz_fdiv_q(k, k, max_tmp);

                    mpz_mul(a, p, p);
                    mpz_mul(a, a, max_tmp);
                    mpz_mul(a, a, max_tmp);

                    mpz_mul(b, q, q);
                    mpz_mul(b, b, max_tmp);
                    mpz_mul(b, b, max_tmp);

                    mpz_mul(c, p, p);
                    mpz_mul(c, c, q);
                    mpz_mul(c, c, q);

                    mpz_add(tmp, tmp, a);
                    mpz_add(tmp, tmp, b);
                    mpz_add(tmp, tmp, c);
                    mpz_mul(tmp, tmp, k);
                    mpz_add_ui(k, k, 1);
                    mpz_mul(tmp, tmp, k);
                    mpz_fdiv_q_ui(tmp, tmp, 2);
                    mpz_add(ans, ans, tmp);
                    // }
                }
                mpz_add_ui(q, q, 1);
            }
            mpz_add_ui(p, p, 1);
        }
        gmp_printf("%Zd\n", ans);
        mpz_clears(max, pmax, qmax, '\0');
        mpz_clears(p, q, max_tmp,'\0');
        mpz_clears(ans, gcd, tmp, '\0');
        mpz_clears(a, b, c, k, '\0');
        
    }

}
