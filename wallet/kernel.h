// Copyright (c) 2012-2013 The PPCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef PPCOIN_KERNEL_H
#define PPCOIN_KERNEL_H

#include "transaction.h"
#include <cstdint>

class CBlock;
class CBlockIndex;

// MODIFIER_INTERVAL_RATIO:
// ratio of group interval length between the last group and the first group
static const int MODIFIER_INTERVAL_RATIO = 3;

// Compute the hash modifier for proof-of-stake
bool ComputeNextStakeModifier(const ITxDB& txdb, const CBlockIndex* const pindexPrev,
                              uint64_t& nStakeModifier, bool& fGeneratedStakeModifier);

// Check whether stake kernel meets hash target
// Sets hashProofOfStake on success return
bool CheckStakeKernelHash(const ITxDB& txdb, unsigned int nBits, const CBlock& blockFrom,
                          const uint256& blockFromHash, unsigned int nTxPrevOffset,
                          const CTransaction& txPrev, const COutPoint& prevout, unsigned int nTimeTx,
                          uint256& hashProofOfStake, uint256& targetProofOfStake,
                          bool fPrintProofOfStake = false);

// Check kernel hash target and coinstake signature
// Sets hashProofOfStake on success return
bool CheckProofOfStake(const ITxDB& txdb, const CTransaction& tx, unsigned int nBits,
                       uint256& hashProofOfStake, uint256& targetProofOfStake);

// Check whether the coinstake timestamp meets protocol
bool CheckCoinStakeTimestamp(int64_t nTimeBlock, int64_t nTimeTx);

// Get stake modifier checksum
unsigned int GetStakeModifierChecksum(const CBlockIndex* pindex, const ITxDB& txdb);

// Check stake modifier hard checkpoints
bool CheckStakeModifierCheckpoints(int nHeight, unsigned int nStakeModifierChecksum);

// Get time weight using supplied timestamps
int64_t GetWeight(const ITxDB& txdb, int64_t nIntervalBeginning, int64_t nIntervalEnd);

#endif // PPCOIN_KERNEL_H
