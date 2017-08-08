#pragma once
/*
 * This file provides the system inet.h to the socket interface
 *
 */
#include <sys/types.h>
#include <netinet/in.h>

/** 255.255.255.255 */
#define INADDR_NONE         ((uint32_t)0xffffffffUL)
/** 127.0.0.1 */
#define INADDR_LOOPBACK     ((uint32_t)0x7f000001UL)
/** 0.0.0.0 */
#define INADDR_ANY          ((uint32_t)0x00000000UL)
/** 255.255.255.255 */
#define INADDR_BROADCAST    ((uint32_t)0xffffffffUL)

/* Definitions of the bits in an Internet address integer.

   On subnets, host and network parts are found according to
   the subnet mask, not these masks.  */
#define IN_CLASSA(a)        IP_CLASSA(a)
#define IN_CLASSA_NET       IP_CLASSA_NET
#define IN_CLASSA_NSHIFT    IP_CLASSA_NSHIFT
#define IN_CLASSA_HOST      IP_CLASSA_HOST
#define IN_CLASSA_MAX       IP_CLASSA_MAX

#define IN_CLASSB(b)        IP_CLASSB(b)
#define IN_CLASSB_NET       IP_CLASSB_NET
#define IN_CLASSB_NSHIFT    IP_CLASSB_NSHIFT
#define IN_CLASSB_HOST      IP_CLASSB_HOST
#define IN_CLASSB_MAX       IP_CLASSB_MAX

#define IN_CLASSC(c)        IP_CLASSC(c)
#define IN_CLASSC_NET       IP_CLASSC_NET
#define IN_CLASSC_NSHIFT    IP_CLASSC_NSHIFT
#define IN_CLASSC_HOST      IP_CLASSC_HOST
#define IN_CLASSC_MAX       IP_CLASSC_MAX

#define IN_CLASSD(d)        IP_CLASSD(d)
#define IN_CLASSD_NET       IP_CLASSD_NET     /* These ones aren't really */
#define IN_CLASSD_NSHIFT    IP_CLASSD_NSHIFT  /*   net and host fields, but */
#define IN_CLASSD_HOST      IP_CLASSD_HOST    /*   routing needn't know. */
#define IN_CLASSD_MAX       IP_CLASSD_MAX

#define IN_MULTICAST(a)     IP_MULTICAST(a)

#define IN_EXPERIMENTAL(a)  IP_EXPERIMENTAL(a)
#define IN_BADCLASS(a)      IP_BADCLASS(a)

#define IN_LOOPBACKNET      IP_LOOPBACKNET

#define inet_addr_from_ipaddr(target_inaddr, source_ipaddr)\
  ((target_inaddr)->s_addr = ip4_addr_get_u32(source_ipaddr))
#define inet_addr_to_ipaddr(target_ipaddr, source_inaddr)\
  (ip4_addr_set_u32(target_ipaddr, (source_inaddr)->s_addr))
/* ATTENTION: the next define only works because both s_addr and ip_addr_t are an u32_t effectively! */
#define inet_addr_to_ipaddr_p(target_ipaddr_p, source_inaddr)\
  ((target_ipaddr_p) = (ip_addr_t*)&((source_inaddr)->s_addr))

/* directly map this to the lwip internal functions */
//#define inet_addr(cp)         ipaddr_addr(cp)
//#define inet_aton(cp, addr)   ipaddr_aton(cp, (ip_addr_t*)addr)
//#define inet_ntoa(addr)       ipaddr_ntoa((ip_addr_t*)&(addr))
//#define inet_ntoa_r(addr, buf, buflen) ipaddr_ntoa_r((ip_addr_t*)&(addr), buf, buflen)

/*
 * The following functions are provided in usr/src/libsocket/socketlib.c
 */
uint16_t htons(uint16_t hostshort);
uint16_t ntohs(uint16_t netshort);
uint32_t htonl(uint32_t hostlong);
uint32_t ntohl(uint32_t netlong);
uint32_t inet_addr(const char *cp);
int inet_aton(const char *cp, struct in_addr *addr);
char *inet_ntoa(struct in_addr addr);

