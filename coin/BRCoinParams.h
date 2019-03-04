//
//  BRCoinParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
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

#ifndef BRCoinParams_h
#define BRCoinParams_h

#include "BRChainParams.h"
#include "BRPeer.h"
#include "BRInt.h"

#define NPOW_TARGET_TIMESPAN (24*60*60)        // Biblepay 1 day
#define NPOW_TARGEY_SPACING (7*60)
#define BBP_BLOCK_DIFFICULTY_INTERVAL (NPOW_TARGET_TIMESPAN/NPOW_TARGEY_SPACING)

static const char *BRCoinDNSSeeds[] = {
"seeds.blocknode.tech"
    , NULL
};

static const char *BRCoinTestNetDNSSeeds[] = {
    "testnet-seed.blocknodedot.io", "test.dnsseed.masternode.io", NULL
};

static const BRCheckPoint BRCoinTestNetCheckpoints[] = {
    {       1, uint256("18b37b60b422ea27d57ceea9dd794b5f74c561565ecc03e85a22ecdf74cbb33a"), 1511964848, 0x1d00ffff }       // timestamp and target bits probably not ok... just taking info directly from BBP chainparams.cpp
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRCoinCheckpoints[] = {
    {       0, uint256("00000c392c066ec40b4138a3642ac7c7c3a0b157be45553ea1adcce4196c968d"), 1525032500, 0x1e0ffff0 }
};

static int BRCoinVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{

    return 1;
}

static int BRCoinTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRCoinParams = {
    BRCoinDNSSeeds,
    37001,                // standardPort
    0xd3701cb1,          // magicNumber
    0, // services
    BRCoinVerifyDifficulty,
    BRCoinCheckpoints,
    sizeof(BRCoinCheckpoints)/sizeof(*BRCoinCheckpoints),
};

static const BRChainParams BRCoinTestNetParams = {
    BRCoinTestNetDNSSeeds,
    46005,               // standardPort
    0x5e18c3d4,          // magicNumber
    0, // services
    BRCoinTestNetVerifyDifficulty,
    BRCoinTestNetCheckpoints,
    sizeof(BRCoinTestNetCheckpoints)/sizeof(*BRCoinTestNetCheckpoints)
};

#endif // BRChainParams_h
