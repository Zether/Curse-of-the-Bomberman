/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/
#ifndef BITMACROS_H
#define BITMACROS_H

#define SETBIT(var,bit)         ((var) |= (1 << (bit)))
#define CLRBIT(var,bit)         ((var) &= (~ (1 << (bit))))
#define CHCKBIT(var,bit)        ((var) &  (1 << (bit)))

#endif