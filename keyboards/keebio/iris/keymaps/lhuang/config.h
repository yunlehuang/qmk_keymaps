/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C
#define EE_HANDS
#define TAPPING_TERM 175
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