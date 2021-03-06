/* gui.h
 *
 * Copyright (C) 2010 dking <dking024@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licens e as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __GUI_H__
#define __GUI_H__

#include "ds2_types.h"
#include "fs_api.h"
#include "gcheat.h"

#define UP_SCREEN_UPDATE_METHOD   0
#define DOWN_SCREEN_UPDATE_METHOD 2

// For general option text
#define OPTION_TEXT_X             10
#define OPTION_TEXT_SX            236

// For option rows
#define GUI_ROW1_Y                36
#define GUI_ROW_SY                19
// The following offset is added to the row's Y coordinate to provide
// the Y coordinate for its text.
#define TEXT_OFFSET_Y             2
// The following offset is added to the row's Y coordinate to provide
// the Y coordinate for its ICON_SUBSELA (sub-screen selection type A).
#define SUBSELA_OFFSET_Y          -2
#define SUBSELA_X                 ((NDS_SCREEN_WIDTH - ICON_SUBSELA.x) / 2)

// For message boxes
#define MESSAGE_BOX_TEXT_X        ((NDS_SCREEN_WIDTH - ICON_MSG.x) / 2 + 3)
#define MESSAGE_BOX_TEXT_SX       (ICON_MSG.x - 6)
// Y is brought down by the "window title" that's part of ICON_MSG
#define MESSAGE_BOX_TEXT_Y        ((NDS_SCREEN_HEIGHT - ICON_MSG.y) / 2 + 24)

// For cheats [ NUM. DESC . . . . . +/- ]
#define CHEAT_NUMBER_X            10
#define CHEAT_DESC_X              34
#define CHEAT_DESC_SX             197
#define CHEAT_ACTIVE_X            241

// For the file selector
#define FILE_SELECTOR_ICON_X      10
#define FILE_SELECTOR_ICON_Y      (TEXT_OFFSET_Y - 1)
#define FILE_SELECTOR_NAME_X      32
#define FILE_SELECTOR_NAME_SX     214

// Back button
#define BACK_BUTTON_X             229
#define BACK_BUTTON_Y             10
// Title icon
#define TITLE_ICON_X              12
#define TITLE_ICON_Y              9

#define MAX_GAMEPAD_MAP 16

#ifdef __cplusplus
extern "C" {
#endif

//
struct _EMU_CONFIG
{
  u32 language;
  char rom_file[256];
  char rom_path[256];
  char latest_file[5][512];
  u32 HotkeyReturnToMenu;
  u32 HotkeyTemporaryFastForward;
  u32 HotkeyToggleSound;
  u32 HotkeyQuickLoadState;
  u32 HotkeyQuickSaveState;
  u32 HotkeyToggleFullScreen;
  u32 Reserved[58];
};

struct _GAME_CONFIG
{
	u32 clock_speed_number;
	u32  Reserved0;
	u32 frameskip_value;
	u32 graphic;
	u32 enable_audio;
	u32 Reserved1;
	u32 backward;
	u32 backward_time;
	u32 HotkeyReturnToMenu;
	u32 HotkeyTemporaryFastForward;
	u32 HotkeyToggleSound;
	u32 SoundSync;
	/*
	 * PreviouslyUsed_20130206_1 was for a second meaning of
	 * frameskip_value that is now dropped.
	 * THIS VALUE IS NOT GUARANTEED TO BE RESERVED AND SET TO 0.
	 */
	u32 PreviouslyUsed_20130206_1;
	/*
	 * PreviouslyUsed_20130206_2 was for a second meaning of
	 * clock_speed_number that is now dropped.
	 * THIS VALUE IS NOT GUARANTEED TO BE RESERVED AND SET TO 0.
	 */
	u32 PreviouslyUsed_20130206_2;
	u32 RetroSound;
	u32 HotkeyQuickLoadState;
	u32 HotkeyQuickSaveState;
	u32 HotkeyToggleFullScreen;
	u32  Reserved2[38];
};

typedef enum
{
  CURSOR_NONE = 0,
  CURSOR_UP,
  CURSOR_DOWN,
  CURSOR_LEFT,
  CURSOR_RIGHT,
  CURSOR_SELECT,
  CURSOR_BACK,
  CURSOR_EXIT,
  CURSOR_RTRIGGER,
  CURSOR_LTRIGGER,
  CURSOR_KEY_SELECT,
  CURSOR_TOUCH
} gui_action_type;

typedef enum
{
  BUTTON_ID_A   = 0x01,
  BUTTON_ID_B   = 0x02,
  BUTTON_ID_SELECT  = 0x04,
  BUTTON_ID_START   = 0x08,
  BUTTON_ID_RIGHT   = 0x10,
  BUTTON_ID_LEFT    = 0x20,
  BUTTON_ID_UP      = 0x40,
  BUTTON_ID_DOWN    = 0x80,
  BUTTON_ID_R       = 0x100,
  BUTTON_ID_L       = 0x200,
  BUTTON_ID_X       = 0x400,
  BUTTON_ID_Y       = 0x800,
  BUTTON_ID_TOUCH   = 0x1000,
  BUTTON_ID_LID     = 0x2000,
  BUTTON_ID_FA      = 0x4000,
  BUTTON_ID_FB      = 0x8000,
  BUTTON_ID_NONE    = 0
} input_buttons_id_type;

extern char main_path[MAX_PATH];
extern char rom_path[MAX_PATH];

extern u32 game_enable_audio;
extern u32 game_fast_forward;
extern u32 temporary_fast_forward;

/******************************************************************************
 ******************************************************************************/
extern char g_default_rom_dir[MAX_PATH];
extern char DEFAULT_RTS_DIR[MAX_PATH];
extern char DEFAULT_CFG_DIR[MAX_PATH];
extern char DEFAULT_SS_DIR[MAX_PATH];
extern char DEFAULT_CHEAT_DIR[MAX_PATH];

typedef struct _EMU_CONFIG		EMU_CONFIG;
typedef struct _GAME_CONFIG		GAME_CONFIG;

extern EMU_CONFIG	emu_config;
extern GAME_CONFIG	game_config;

/******************************************************************************
 ******************************************************************************/
extern void gui_init(u32 lang_id);
extern u32 menu(u16 *original_screen, bool8 FirstInvocation);
extern void LowFrequencyCPU();
extern void HighFrequencyCPU();
extern void GameFrequencyCPU();

extern void QuickSaveState();
extern void QuickLoadState();
extern void ToggleFullScreen();

extern int load_language_msg(char *filename, u32 language);

#ifdef __cplusplus
}
#endif

#endif //__GUI_H__
