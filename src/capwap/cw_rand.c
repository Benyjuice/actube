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

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "cw_util.h"
#include "log.h"

char *cw_rand_dev = "/dev/random";

int cw_rand_r(uint8_t * dst, int len)
{
	int rf;
	int l;

	rf = open(cw_rand_dev, O_RDONLY | O_NDELAY);
	if (rf < 0) {

		cw_log(LOG_ERR, "Can't open %s: %s", cw_rand_dev, strerror(errno));
		return 0;
	}


	l = read(rf, dst, len);
	close(rf);

	if ((l < 0) && (errno != EAGAIN)) {
		cw_log(LOG_ERR, "Cant read from %s: %s", cw_rand_dev, strerror(errno));
		return 0;
	}

	return l;
}



int cw_rand(uint8_t * dst, int len)
{
	static uint32_t rinit = 0;
	if (!rinit) {

		int l = cw_rand_r((uint8_t *) (&rinit), sizeof(uint32_t));
		if (l < sizeof(uint32_t)) {
			cw_log(LOG_WARNING,
			       "Can't read enough bytes from %s. Using time to init rand instead.",
			       cw_rand_dev);
			rinit = time(NULL);
		}

		srand(rinit);
	}
	int i;
	for (i = 0; i < len; i++) {
		dst[i] = rand();
	}
	return len;
}
