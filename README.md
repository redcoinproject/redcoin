Redcoin - a decendent of Litecoin that combines the great features from Luckycoin (random blocks) and Florincoin (transaction message). Like Litecoin it uses scrypt as a proof of work scheme.

	- 1 minute block time
	- Difficulty retargets every 20 blocks (or 20 mins)
	- Total coins will be around 329 millions
	- 6 confirmations for transaction
	- 50 confirmations for minted blocks
	- Low fees.
	- Normal blocks are 50-150 coins per block, randomly.
	- Every 500 blocks there is a super block with 500-1000 coins.
	- Starting block 25000, there will be a super block of 5000-10000 coins on average every 20,000 blocks.

	- First 600 blocks after the launch are normal blocks.
	- Next 2 weeks time (20,160 blocks), the payout will be tripled (3x).
	- The following 4 weeks time (40,320 blocks), the payout will be doubled (2x).
	- After it, the payout will return to normal.
	- During 2x, 3x period, the superblocks will be multiplied by the same factor. So you may get a 20,000 coin block!

	- The prize will be halved every 3 years.

	- The default ports are 11631(Connect) and 11632 (RPC).

The official website is: www.RedCoin.pw


Development process
===================

Developers work in their own trees, then submit pull requests when
they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a
good thing.  Developers should expect to rework and resubmit patches
if they don't match the project's coding conventions (see coding.txt)
or are controversial.

The master branch is regularly built and tested, but is not guaranteed
to be completely stable. Tags are regularly created to indicate new
official, stable release versions of Litecoin.

Feature branches are created when there are major new features being
worked on by several people.

From time to time a pull request will become outdated. If this occurs, and
the pull is no longer automatically mergeable; a comment on the pull will
be used to issue a warning of closure. The pull will be closed 15 days
after the warning if action is not taken by the author. Pull requests closed
in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after
15 days from their last activity. Issues closed in this manner will be 
labeled 'stale'. 
