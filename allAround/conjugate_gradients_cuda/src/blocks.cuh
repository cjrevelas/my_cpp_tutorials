#ifndef BLOCKS_H
#define BLOCKS_H

constexpr int getBlocks(const int& nbThreads, const int& systemSize) {
	return (systemSize + nbThreads - 1) / nbThreads;
}

#endif