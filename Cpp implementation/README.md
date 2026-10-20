Why this structure?
Component	Responsibility
CacheConfig	Cache size, associativity, block size and timing parameters
CacheLine	Data block, tag, valid bit and dirty bit
CacheSet	Stores cache lines belonging to one set
ReplacementPolicy	Defines the interface for LRU and potentially other policies
Memory	Models backing memory and memory-access latency
Cache	Coordinates lookup, allocation, eviction and write-back
CacheStats	Tracks hits, misses, write-backs and latency statistics
Simulator	Coordinates requests and models cycle-level behavior
Trace	Loads and represents synthetic memory-access traces


The rtl/ directory is reserved for your later SystemVerilog implementation. Keeping it in the same repository makes cross-validation easier.