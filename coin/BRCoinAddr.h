//
//  BRCoinAddr.h
//
//  Created by Aaron Voisine on 9/18/15.
//  Copyright (c) 2015 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRCoinAddr_h
#define BRCoinAddr_h

#include "BRCrypto.h"
#include "BRAddress.h"
#include <string.h>
#include <stddef.h>
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#if BITCOIN_TESTNET
#pragma message "testnet build"
#endif

typedef struct {
    char s[75];
} BRCoinAddr;

#define BR_ADDRESS_NONE ((BRCoinAddr) { "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"\
                                       "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" })

// writes the bitcoin address for a scriptPubKey to addr
// returns the number of bytes written, or addrLen needed if addr is NULL
size_t BRCoinAddrFromScriptPubKey(char *addr, size_t addrLen, const uint8_t *script, size_t scriptLen);

// writes the bitcoin address for a scriptSig to addr
// returns the number of bytes written, or addrLen needed if addr is NULL
size_t BRCoinAddrFromScriptSig(char *addr, size_t addrLen, const uint8_t *script, size_t scriptLen);

// writes the bitcoin address for a witness to addr
// returns the number of bytes written, or addrLen needed if addr is NULL
size_t BRCoinAddrFromWitness(char *addr, size_t addrLen, const uint8_t *witness, size_t witLen);

// writes the scriptPubKey for addr to script
// returns the number of bytes written, or scriptLen needed if script is NULL
size_t BRCoinAddrScriptPubKey(uint8_t *script, size_t scriptLen, const char *addr);

// returns true if addr is a valid bitcoin address
int BRCoinAddrIsValid(const char *addr);

// writes the 20 byte hash160 of addr to md20 and returns true on success
int BRCoinAddrHash160(void *md20, const char *addr);

// returns a hash value for addr suitable for use in a hashtable
inline static size_t BRCoinAddrHash(const void *addr)
{
    return BRMurmur3_32(addr, strlen((const char *)addr), 0);
}

// true if addr and otherAddr are equal
inline static int BRCoinAddrEq(const void *addr, const void *otherAddr)
{
    return (addr == otherAddr || strncmp((const char *)addr, (const char *)otherAddr, sizeof(BRCoinAddr)) == 0);
}

#ifdef __cplusplus
}
#endif

#endif // BRCoinAddr_h
