/* -*- Mode: C++; c-basic-offset: 2; tab-width: 2; indent-tabs-mode: nil -*-
 * 
 * Quadra, an action puzzle game
 * Copyright (C) 1998-2000  Ludus Design
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _HEADER_INPUT
#define _HEADER_INPUT

#include <stdint.h>

#include "SDL.h"

#include "types.h"

#define PRESSED 1
#define RELEASED 2
#define MAXKEY 32

class Input {
public:
  struct {
    uint8_t button[4];
    int quel;
    int wheel;
  } mouse;
  int key_pending;
  struct {
    bool special;
    char c;
    SDL_Keycode sym;
    Uint16 mod;
  } key_buf[MAXKEY];
  uint8_t keys[SDL_NUM_SCANCODES];
  bool pause;
  SDL_Keysym last_keysym;
  static Input* New(bool dumb=false);
  virtual ~Input() { };
  void clear_key();
  void clear_last_keysym();
  virtual void check() = 0;
  virtual void deraw() = 0;
  virtual void reraw() = 0;
protected:
  Input();
};

extern Input* input;

#endif
