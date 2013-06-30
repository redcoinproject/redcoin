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
            (  1, uint256("0x11b82349e53d49a5b5ef6262c262564e7663d8cfd912b0040b33683f623022f2"))
            ( 11, uint256("0xc8fc42e967eebdeafcabbd9050a545617f8685d53f2ebcd8f0fa5002b7e62a86"))
            ( 59, uint256("0xcdde8a3e42fa8888df2db8bf6673b29f5e2ae29951275d452686c47acb51cb66"))
            (104, uint256("0x206fe8cc678598456a11041fac65c8e096d9e26c887e391977fdad41e7add208"))
			;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        // return hash == i->second;
		return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        // return mapCheckpoints.rbegin()->first;
		return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                // return t->second;
				return NULL;
        }
        return NULL;
    }
}
