// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Redcoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (    1, uint256("0x232f1f219a4a2e8a84b6e03827a829fb9aac1ecd2d6863e440a425be9d97d9cd"))
            (   75, uint256("0x12668ad9a9e1385bdbcc5f5da60150c364c9dc78359afbc02f25f1a2fd45b4fe"))
            (  250, uint256("0x334f13876f225bc4343179caf87b387ea62855697c8292051666aac6c8494deb"))
            (  948, uint256("0xe00df8e44f9eb1634390e73300781ed4bb99a38ba09ff09181361bd50f1bcd15"))
            (15088, uint256("0xf67cdc603ff0f5594f204cb6f4fedf65ca2904d6681cd26fb54002a4b36b7643"))
            (17399, uint256("0x7fd1fb3dfbf15b6c2e557e0860e64752b8bf093667dca0d939f661de31b81c3a"))
			;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
		// return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
		// return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
				// return NULL;
        }
        return NULL;
    }
}
