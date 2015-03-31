/*
    This file is part of libcapwap.

    libcapwap is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libcapwap is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef __LWAPP_CISCO_H
#define __LWAPP_CISCO_H

#include <stdint.h>

#include "lwapp.h"

#define LW_VENDOR_CISCO				4232704


/* Vendor specific message elements LWAPP Cisco */

#define LW_CISCO_AP_USERNAME_PASSWORD		18

#define LW_CISCO_AC_IP_ADDR_WITH_INDEX		32
#define LW_CISCO_AP_LOGHOST_CONFIG		36

#define LW_CISCO_AP_SUBMODE			67

#define LW_CISCO_PATH_MTU			73

#define LW_CISCO_ADD_WLAN			128

#define LW_CISCO_MWAR_HASH_VALUE		134


/* function proto types */
extern int lw_put_cisco_path_mtu(uint8_t *dst, uint16_t max, uint16_t padding);

extern const char * lw_cisco_id_to_str(int elem_id);


/*
#define lw_addelem_cisco_path_mtu(dst,max,padding) \
	lw_put_elem_hdr(dst,LW_ELEM_VENDOR_SPECIFIC,lw_put_cisco_path_mtu(dst,max,padding))
*/

#endif