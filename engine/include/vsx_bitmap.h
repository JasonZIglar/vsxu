/**
* Project: VSXu Engine: Realtime modular visual programming engine.
*
* This file is part of Vovoid VSXu Engine.
*
* @author Jonatan Wallmander, Robert Wenzel, Vovoid Media Technologies AB Copyright (C) 2003-2013
* @see The GNU Lesser General Public License (LGPL)
*
* VSXu Engine is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*
* You should have received a copy of the GNU Lesser General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef VSX_BITMAP_H
#define VSX_BITMAP_H

#include <stdint.h>

// everyone that wants to mess with this must make a copy of their own.
// because threads are working on it it has to be like this.
// also, if the timestamp and it's valid it's ok to read from it, otherwise
// it's not.

typedef uint32_t vsx_bitmap_32bt;

class vsx_bitmap {
public:
  // channels - 3 for RGB, 4 for RGBA
  int channels;

  enum channel_storage_type_t
  {
    byte_storage = 0,
    float_storage = 1
  } storage_format;

  unsigned long width;
  unsigned long height;

  // either vsx_bitmap_32bt* or float*
  void *data;

  // while this is false, don't upload it as a texture or read it, use your old copy
  bool valid;

  // increased with 1 every time it's modified so others can now and react.
  int timestamp;

  // data has been flipped vertically
  bool flipped_vertically;
  
  vsx_bitmap()
    :
      channels(4),
      storage_format(byte_storage),
      width(0),
      height(0),
      data(0x0),
      valid(false),
      timestamp(0),
      flipped_vertically(false)
  {
  }
};

#endif
