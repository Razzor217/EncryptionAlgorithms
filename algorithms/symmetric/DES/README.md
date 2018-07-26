# Data Encryption Standard (DES)
This is an implementation of the *Data Encryption Standard* in `C`; it is based on the  
[specifications](https://csrc.nist.gov/csrc/media/publications/fips/46/3/archive/1999-10-25/documents/fips46-3.pdf "NIST/DES") of DES by [NIST](https://www.nist.gov).  

## Algorithm
DES is a block cipher which works on 64-bit message blocks and uses a 64-bit key.  
Let *M* be the 64b message block, *K* the 64b key. Encryption works as follows:
1. An initial permutation *IP* is applied to *M*.
2. *M* is then divided into two 32-bit blocks *L* and *R* such that *M = LR* holds 
(concatenation).
3. A key selection function determines 16 48-bit keys *K1, ..., K16* from the 64-bit 
key *K*.
4. Now, 16 *Feistel* rounds are applied to *L* and *R* as follows:
   1. A *Feistel*-function is applied to *R*:
      - *R* is expanded to 48 bits by doubling specific bits
      - XOR is then applied on the 48 bit result and the round-specific 48 bit key *Ki*
      - The result is fed into 8 selection functions which each select 4 bit output 
      from 6 bit input
      - The outputs are concatenated to build a 32 bit string and a final permutation 
      is applied
   2. XOR is then applied on the 32 bit output of the *Feistel* function and the 
   32 bit block *L*. Let *F'* be the result.
   3. New 32 bit input blocks for the *Feistel* function and XOR of the next round 
   are defined as *L' = R* and *R' = F'*.
5. After all rounds, the preoutput is defined as *L'16 = F'16* and *R'16 = R'15*.
6. The preoutput is concatenated to a 64 bit block and the inverse permutation to 
*IP*, *IP-1* is applied on the preoutput.
7. The permutated preoutput yields the 64 bit encrypted message block *C*.