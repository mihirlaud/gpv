/****************************************************************************
 *
 *   Copyright (c) 2012-2019 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file gpv_main.cpp
 * Debug tool for getting current local position and velocity of a drone
 *
 * @author Mihir Laud <mihirlaud@gmail.com>
 */

#include <string.h>
#include <px4_platform_common/log.h>
#include <uORB/topics/vehicle_local_position.h>

extern "C" __EXPORT int gpv_main(int argc, char *argv[]);

int gpv_main(int argc, char *argv[]) {
	struct vehicle_local_position_s pos;
	memset(&pos, 0, sizeof(pos));

	int pos_sub = orb_subscribe(ORB_ID(vehicle_local_position));

	orb_copy(ORB_ID(vehicle_local_position), pos_sub, &pos);

	PX4_INFO("Position:\tx: %.5f\ty: %.5f\tz: %.5f", (double)pos.x, (double)pos.y, (double)pos.z);
	PX4_INFO("Velocity:\tvx: %.5f\tvy: %.5f\tvz: %.5f", (double)pos.vx, (double)pos.vy, (double)pos.vz);

	return OK;
}
