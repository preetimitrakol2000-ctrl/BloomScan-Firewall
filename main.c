#include <stdio.h>
#include "bloom.h"

int main() {
    printf("🛡️ Initializing BloomScan-Firewall Threat Filter Bitfields...\n\n");

    BloomFilter* IP_blacklist = create_filter(1024);

    // Seed malicious threat vectors into the filter's bits
    register_threat(IP_blacklist, "185.220.101.5");
    register_threat(IP_blacklist, "45.132.22.11");

    printf("📡 Scanning Incoming Traffic Stream Request ID: [45.132.22.11]...\n");
    if (check_threat(IP_blacklist, "45.132.22.11")) {
        printf("🛑 PACKET DROPPED: Address flagged as blacklisted Malicious Threat!\n");
    } else {
        printf("✅ PACKET PASSED: Source node structural check clear.\n");
    }

    free_filter(IP_blacklist);
    return 0;
}
