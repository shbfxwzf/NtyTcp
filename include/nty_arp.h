


#ifndef __NTY_ARP_H__
#define __NTY_ARP_H__

#include "nty_header.h"

#define MAX_ARPENTRY	256

typedef struct _nty_arp_entry {
	uint32_t ip;
	int8_t prefix;
	uint32_t ip_mask;
	uint32_t ip_masked;
	unsigned char haddr[ETH_ALEN];
} nty_arp_entry;

typedef struct _nty_arp_table {
	nty_arp_entry *entry;
	int entries;
} nty_arp_table;

unsigned char *GetDestinationHWaddr(uint32_t dip);
int GetOutputInterface(uint32_t daddr);

int nty_arp_register_entry(uint32_t ip, const unsigned char *haddr);
int nty_arp_process(nty_nic_context *ctx, unsigned char *stream);
int nty_arp_init_table(void);

int str2mac(char *mac, char *str);


#endif



