# BloomScan-Firewall

An implementation of a space-efficient Bloom Filter probabilistic data structure in C99. This project functions as an edge-router firewall system, querying incoming IP values against a highly compressed bit-vector array to drop blacklisted nodes instantly.

## ⚡ Algorithmic Metrics
* **Time Complexity Lookups:** $O(K)$ space-time bounds (where $K$ represents hash iterations).
* **Memory Constraints:** Compressed tracking inside a 1D unsigned char bitfield.
