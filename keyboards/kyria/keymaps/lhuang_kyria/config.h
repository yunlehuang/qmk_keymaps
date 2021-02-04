/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150
#endif

#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

#define MOUSEKEY_DELAY              0
#define MOUSEKEY_INTERVAL           2
#define MOUSEKEY_MAX_SPEED          3
#define MOUSEKEY_TIME_TO_MAX        60

#define MOUSEKEY_WHEEL_DELAY        0
#define MOUSEKEY_WHEEL_INTERVAL     250
#define MOUSEKEY_WHEEL_MAX_SPEED    10
#define MOUSEKEY_WHEEL_TIME_TO_MAX  100

#define COMBO_COUNT 3
#define COMBO_TERM 45

#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 2