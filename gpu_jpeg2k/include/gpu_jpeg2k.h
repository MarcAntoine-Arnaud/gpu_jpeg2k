/* 
Copyright 2009-2013 Poznan Supercomputing and Networking Center

Authors:
Milosz Ciznicki miloszc@man.poznan.pl

GPU JPEG2K is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GPU JPEG2K is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with GPU JPEG2K. If not, see <http://www.gnu.org/licenses/>.
*/
/*
 * gpu_jpeg2k.h
 *
 *  Created on: Feb 2, 2012
 *      Author: miloszc
 */

#include <stdint.h>
#include "memory.h"

#ifndef GPU_JPEG2K_H_
#define GPU_JPEG2K_H_

#ifdef __cplusplus
extern "C" {
#endif

#define UNSIGNED 0U
#define SIGNED 1U

#define DWT_53 0
#define DWT_97 1

typedef struct {
	/** Image width */
	uint16_t img_w;
	/** Image height */
	uint16_t img_h;
	/** Tile width. Default img_w */
	uint16_t tile_w;
	/** Tile height. Default img_h */
	uint16_t tile_h;
	/** Number of image channels/components */
	uint16_t num_comp;
	/** Image bit depth. XXX: Should be separate for every component */
	uint16_t depth;
	/** Image data sign. UNSIGNED or SIGNED*/
	uint8_t sign;
	/** Type of wavelet transform: lossless DWT_53, lossy DWT_97. */
	uint8_t wavelet_type;
	/** Number of decomposition levels. Range: 1-5*/
	uint8_t num_dlvls;
	/** Nominal exponent value for code-block width */
	uint8_t cblk_exp_w;
	/** Nominal exponent value for code-block height */
	uint8_t cblk_exp_h;
	/** Transform image to YUV */
	uint8_t use_mct;
	/** Target image size in bytes. Default 0 */
	uint32_t target_size;

	mem_mg_t *mem_mg;
} Config;

typedef struct {
	size_t length;
	void *data;
} Chunk;

void encode(void **img_data, Config *config, Chunk **blocks, Chunk **order);
void decode(Chunk *img_data, Config *config, Chunk **blocks, Chunk **order);

#ifdef __cplusplus
}
#endif

#endif /* GPU_JPEG2K_H_ */
