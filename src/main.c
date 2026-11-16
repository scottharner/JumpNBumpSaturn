/*
** Jo Sega Saturn Engine
** Copyright (c) 2012-2017, Johannes Fetz (johannesfetz@gmail.com)
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the Johannes Fetz nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Johannes Fetz BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <jo/jo.h>
#include "main.h"

// #include <genesis.h>
// #include <libres.h>
// #include "resources.h"

// #include "bank.h"
// #include "global.h"
#include "menu.h"
// #include "game.h"
// #include "rabbits.h"
// #include "objects.h"
// #include "sfx.h"

// #define GAME_STATE_BOOT 0
// #define GAME_STATE_MENU 1
// #define GAME_STATE_GAME 2
// #define GAME_STATE_END  3
#define MAX_ACTION_CYCLES 10000
#define TITLE_TRACKID 3
#define GAME_TRACKID 2
static int action_counter;
static mode current_game_mode;
static int title_sprite_id;
static int rabbit11_sprite_id;
static int rabbit12_sprite_id;
static int rabbit13_sprite_id;
static int rabbit14_sprite_id;
static int rabbit15_sprite_id;
static int rabbit16_sprite_id;
static int rabbit17_sprite_id;
static int rabbit18_sprite_id;
static int rabbit19_sprite_id;
static int rabbit110_sprite_id;
static int rabbit111_sprite_id;
static int rabbit112_sprite_id;
static int rabbit113_sprite_id;
static int rabbit114_sprite_id;
static int rabbit115_sprite_id;
static int rabbit116_sprite_id;
static int rabbit117_sprite_id;
static int rabbit118_sprite_id;
static int rabbit21_sprite_id;
static int rabbit22_sprite_id;
static int rabbit23_sprite_id;
static int rabbit24_sprite_id;
static int rabbit25_sprite_id;
static int rabbit26_sprite_id;
static int rabbit27_sprite_id;
static int rabbit28_sprite_id;
static int rabbit29_sprite_id;
static int rabbit210_sprite_id;
static int rabbit211_sprite_id;
static int rabbit212_sprite_id;
static int rabbit213_sprite_id;
static int rabbit214_sprite_id;
static int rabbit215_sprite_id;
static int rabbit216_sprite_id;
static int rabbit217_sprite_id;
static int rabbit218_sprite_id;
static int rabbit31_sprite_id;
static int rabbit32_sprite_id;
static int rabbit33_sprite_id;
static int rabbit34_sprite_id;
static int rabbit35_sprite_id;
static int rabbit36_sprite_id;
static int rabbit37_sprite_id;
static int rabbit38_sprite_id;
static int rabbit39_sprite_id;
static int rabbit310_sprite_id;
static int rabbit311_sprite_id;
static int rabbit312_sprite_id;
static int rabbit313_sprite_id;
static int rabbit314_sprite_id;
static int rabbit315_sprite_id;
static int rabbit316_sprite_id;
static int rabbit317_sprite_id;
static int rabbit318_sprite_id;
static int rabbit41_sprite_id;
static int rabbit42_sprite_id;
static int rabbit43_sprite_id;
static int rabbit44_sprite_id;
static int rabbit45_sprite_id;
static int rabbit46_sprite_id;
static int rabbit47_sprite_id;
static int rabbit48_sprite_id;
static int rabbit49_sprite_id;
static int rabbit410_sprite_id;
static int rabbit411_sprite_id;
static int rabbit412_sprite_id;
static int rabbit413_sprite_id;
static int rabbit414_sprite_id;
static int rabbit415_sprite_id;
static int rabbit416_sprite_id;
static int rabbit417_sprite_id;
static int rabbit418_sprite_id;

// static int game_state = GAME_STATE_BOOT;

// bool ai[JNB_MAX_PLAYERS];

// //Index of the last tile that has been placed, useful to avoid overlapping
// u16 VDPTilesFilled = TILE_USER_INDEX;
// u16 palette[64];
// player_anim_t player_anims[7];
// player_t player[JNB_MAX_PLAYERS];

// static u16 portMapping[4];


// // SAT pointer
// VDPSprite* vdpSprite;
// // VDP sprite index (for link field)
// u8 vdpSpriteInd;

// const u16 (*ban_map)[32];

static jo_tile     rabbit_tileset[] =
{
	{0, 0, 16, 16},
	{16, 0, 16, 16},
	{32, 0, 16, 16},
	{48, 0, 16, 16},
	{64, 0, 16, 16},
	{80, 0, 16, 16},
	{96, 0, 16, 16},
	{112, 0, 16, 16},
	{128, 0, 16, 16},
	{144, 0, 16, 16},
	{160, 0, 16, 16},
	{176, 0, 16, 16},
	{192, 0, 16, 16},
	{208, 0, 16, 16},
	{224, 0, 16, 16},
	{240, 0, 16, 16},
	{256, 0, 16, 16},
	{272, 0, 16, 16}
};

#define RABBIT_TILE_COUNT JO_TILE_COUNT(rabbit_tileset)

void reset_game()
{
	action_counter = 0;
	current_game_mode = MODE_TITLE;
	// load_game_mode = MODE_INTRO_GRAPHIC;
	// load_action = load_pregame_assets;
}

void init() 
{
	jo_core_init(JO_COLOR_Black);

	// // initialize sound
	// load_drv(ADX_MASTER_2304);

	// // initialize fonts - load just what's needed for loading screen
	// white_font = jo_font_load(NULL, "GAMEWHT.TGA", JO_COLOR_RGB(255,0,255),GAME_FONT_WIDTH, GAME_FONT_HEIGHT, 0, GAME_FONT_MAPPING);
	// white_font->z_index = TEXT_ZINDEX;

	// hisc = make_table();
	// reset_scores(hisc);
	// load_sound_config();
	// CDDA_SetVolume(music_vol);

	// load sprites
	title_sprite_id = jo_sprite_add_tga(JO_NULL, "TITLE.TGA", JO_COLOR_Black);
	rabbit11_sprite_id = jo_sprite_add_tga_tileset(JO_ROOT_DIR, "RABBIT1.TGA", JO_COLOR_RGB(255, 0, 255), rabbit_tileset, RABBIT_TILE_COUNT);
	rabbit12_sprite_id = rabbit11_sprite_id + 1;
	rabbit13_sprite_id = rabbit11_sprite_id + 2;
	rabbit14_sprite_id = rabbit11_sprite_id + 3;
	rabbit15_sprite_id = rabbit11_sprite_id + 4;
	rabbit16_sprite_id = rabbit11_sprite_id + 5;
	rabbit17_sprite_id = rabbit11_sprite_id + 6;
	rabbit18_sprite_id = rabbit11_sprite_id + 7;
	rabbit19_sprite_id = rabbit11_sprite_id + 8;
	rabbit110_sprite_id = rabbit11_sprite_id + 9;
	rabbit111_sprite_id = rabbit11_sprite_id + 10;
	rabbit112_sprite_id = rabbit11_sprite_id + 11;
	rabbit113_sprite_id = rabbit11_sprite_id + 12;
	rabbit114_sprite_id = rabbit11_sprite_id + 13;
	rabbit115_sprite_id = rabbit11_sprite_id + 14;
	rabbit116_sprite_id = rabbit11_sprite_id + 15;
	rabbit117_sprite_id = rabbit11_sprite_id + 16;
	rabbit118_sprite_id = rabbit11_sprite_id + 17;
	rabbit21_sprite_id = jo_sprite_add_tga_tileset(JO_ROOT_DIR, "RABBIT2.TGA", JO_COLOR_RGB(255, 0, 255), rabbit_tileset, RABBIT_TILE_COUNT);
	rabbit22_sprite_id = rabbit21_sprite_id + 1;
	rabbit23_sprite_id = rabbit21_sprite_id + 2;
	rabbit24_sprite_id = rabbit21_sprite_id + 3;
	rabbit25_sprite_id = rabbit21_sprite_id + 4;
	rabbit26_sprite_id = rabbit21_sprite_id + 5;
	rabbit27_sprite_id = rabbit21_sprite_id + 6;
	rabbit28_sprite_id = rabbit21_sprite_id + 7;
	rabbit29_sprite_id = rabbit21_sprite_id + 8;
	rabbit210_sprite_id = rabbit21_sprite_id + 9;
	rabbit211_sprite_id = rabbit21_sprite_id + 10;
	rabbit212_sprite_id = rabbit21_sprite_id + 11;
	rabbit213_sprite_id = rabbit21_sprite_id + 12;
	rabbit214_sprite_id = rabbit21_sprite_id + 13;
	rabbit215_sprite_id = rabbit21_sprite_id + 14;
	rabbit216_sprite_id = rabbit21_sprite_id + 15;
	rabbit217_sprite_id = rabbit21_sprite_id + 16;
	rabbit218_sprite_id = rabbit21_sprite_id + 17;
	rabbit31_sprite_id = jo_sprite_add_tga_tileset(JO_ROOT_DIR, "RABBIT3.TGA", JO_COLOR_RGB(255, 0, 255), rabbit_tileset, RABBIT_TILE_COUNT);
	rabbit32_sprite_id = rabbit31_sprite_id + 1;
	rabbit33_sprite_id = rabbit31_sprite_id + 2;
	rabbit34_sprite_id = rabbit31_sprite_id + 3;
	rabbit35_sprite_id = rabbit31_sprite_id + 4;
	rabbit36_sprite_id = rabbit31_sprite_id + 5;
	rabbit37_sprite_id = rabbit31_sprite_id + 6;
	rabbit38_sprite_id = rabbit31_sprite_id + 7;
	rabbit39_sprite_id = rabbit31_sprite_id + 8;
	rabbit310_sprite_id = rabbit31_sprite_id + 9;
	rabbit311_sprite_id = rabbit31_sprite_id + 10;
	rabbit312_sprite_id = rabbit31_sprite_id + 11;
	rabbit313_sprite_id = rabbit31_sprite_id + 12;
	rabbit314_sprite_id = rabbit31_sprite_id + 13;
	rabbit315_sprite_id = rabbit31_sprite_id + 14;
	rabbit316_sprite_id = rabbit31_sprite_id + 15;
	rabbit317_sprite_id = rabbit31_sprite_id + 16;
	rabbit318_sprite_id = rabbit31_sprite_id + 17;
	rabbit41_sprite_id = jo_sprite_add_tga_tileset(JO_ROOT_DIR, "RABBIT4.TGA", JO_COLOR_RGB(255, 0, 255), rabbit_tileset, RABBIT_TILE_COUNT);
	rabbit42_sprite_id = rabbit41_sprite_id + 1;
	rabbit43_sprite_id = rabbit41_sprite_id + 2;
	rabbit44_sprite_id = rabbit41_sprite_id + 3;
	rabbit45_sprite_id = rabbit41_sprite_id + 4;
	rabbit46_sprite_id = rabbit41_sprite_id + 5;
	rabbit47_sprite_id = rabbit41_sprite_id + 6;
	rabbit48_sprite_id = rabbit41_sprite_id + 7;
	rabbit49_sprite_id = rabbit41_sprite_id + 8;
	rabbit410_sprite_id = rabbit41_sprite_id + 9;
	rabbit411_sprite_id = rabbit41_sprite_id + 10;
	rabbit412_sprite_id = rabbit41_sprite_id + 11;
	rabbit413_sprite_id = rabbit41_sprite_id + 12;
	rabbit414_sprite_id = rabbit41_sprite_id + 13;
	rabbit415_sprite_id = rabbit41_sprite_id + 14;
	rabbit416_sprite_id = rabbit41_sprite_id + 15;
	rabbit417_sprite_id = rabbit41_sprite_id + 16;
	rabbit418_sprite_id = rabbit41_sprite_id + 17;

	reset_game();
}

// static void initProgram() {
//     int player_anim_data[] = {
//         1, 0, 0, 0x7fff, 0, 0, 0, 0, 0, 0,
//         4, 0, 0, 4, 1, 4, 2, 4, 3, 4,
//         1, 0, 4, 0x7fff, 0, 0, 0, 0, 0, 0,
//         4, 2, 5, 8, 6, 10, 7, 3, 6, 3,
//         1, 0, 6, 0x7fff, 0, 0, 0, 0, 0, 0,
//         2, 1, 5, 8, 4, 0x7fff, 0, 0, 0, 0,
//         1, 0, 8, 5, 0, 0, 0, 0, 0, 0
//     };

//     for (u32 c1 = 0; c1 < 7; c1++) {
//         player_anims[c1].num_frames = player_anim_data[c1 * 10];
//         player_anims[c1].restart_frame = player_anim_data[c1 * 10 + 1];
//         for (u32 c2 = 0; c2 < 4; c2++) {
//             player_anims[c1].frame[c2].image = player_anim_data[c1 * 10 + c2 * 2 + 2];
//             player_anims[c1].frame[c2].ticks = player_anim_data[c1 * 10 + c2 * 2 + 3];
//         }
//     }

//     for(u32 c1 = 0; c1 < JNB_MAX_PLAYERS; c1++)		// reset player values
//     {
//         ai[c1] = FALSE;
//     }

//     init_objects();
//     initKeyb();
// }

// static void handleInput();
// static void displayLogo();
// static void displaySgdkLogo();

// int main(bool resetType) {
//     //Soft resets don't clear RAM, this can bring some bugs so we hard reset every time we detect a soft reset
//     if (!resetType)
//         SYS_hardReset();

//     // initialization
//     VDP_setScreenWidth320();

//     if (JOY_getPortType(PORT_1) == PORT_TYPE_TEAMPLAYER) {
//         JOY_setSupport(PORT_1, JOY_SUPPORT_TEAMPLAYER);
//     }
//     if (JOY_getPortType(PORT_2) == PORT_TYPE_TEAMPLAYER) {
//         JOY_setSupport(PORT_2, JOY_SUPPORT_TEAMPLAYER);
//     }

//     if (JOY_getPortType(PORT_1) == PORT_TYPE_EA4WAYPLAY || JOY_getPortType(PORT_1) == PORT_TYPE_TEAMPLAYER) {
//         portMapping[0] = JOY_1;
//         portMapping[1] = JOY_3;
//         portMapping[2] = JOY_4;
//         portMapping[3] = JOY_5;        
//     } else if (JOY_getPortType(PORT_2) == PORT_TYPE_TEAMPLAYER) {
//         portMapping[0] = JOY_2;
//         portMapping[1] = JOY_6;
//         portMapping[2] = JOY_7;
//         portMapping[3] = JOY_8;        
//     } else {
//         portMapping[0] = JOY_1;
//         portMapping[1] = JOY_2;
//         portMapping[2] = JOY_7;
//         portMapping[3] = JOY_8;
//     }

//     // set all palette to black
//     PAL_setColors(0, (u16*) &palette_black[0], 64, DMA);
//     memcpy(&palette[0], &palette_black[0], 64 * 2);

//     // init SFX
//     SFX_init();

//     initProgram();

//     loadRabbits();
//     load_objects_sprites();

//     SYS_doVBlankProcess();

//     while(TRUE)
//     {
//         vdpSprite = vdpSpriteCache;
//         vdpSpriteInd = 1;

//         handleInput();

//         } else if (game_state == GAME_STATE_MENU) {
//             u16 ret = menuFrame();

//             if (ret == 1) {
//                 menuFrame();
//                 PAL_fadeOutAll(30, FALSE);
//                 unloadMenu();
//                 XGM_stopPlay();

//                 loadLevel();
//                 initLevel();
//                 PAL_fadeInAll(palette, 30, TRUE);

//                 // start music
//                 if (SYS_isNTSC()) {
//                     XGM_startPlay(bump_music_ntsc);
//                 } else {
//                     XGM_startPlay(bump_music_pal);
//                 }
//                 game_state = GAME_STATE_GAME;
//             }
//         } else if (game_state == GAME_STATE_GAME) {
//             u16 ret = gameFrame();

//             if (ret == 1) {
//                 u16 c1;

//                 for(c1 = 0; c1 < JNB_MAX_PLAYERS; c1++)
//                     if (player[c1].bumps >= JNB_END_SCORE)
//                         break;
                
//                 VDP_clearTileMapRect(BG_A, 5, 10, 25, 6);
//                 VDP_clearTileMapRect(BG_B, 5, 10, 25, 6);
                
//                 VDP_drawText("GAME OVER", 13, 11);
//                 char buf[20];
//                 sprintf(buf, "Player %d WIN!", c1 +1);
//                 VDP_drawText(buf, 11, 12);
//                 VDP_drawText("Press START to continue", 6, 14);

//                 game_state = GAME_STATE_END;
//             }
//         } else if (game_state == GAME_STATE_END) {
//             XGM_stopPlay();

//             // clear sprites
//             vdpSprite->y = 0;
//             vdpSprite->link = 0;
//             DMA_queueDmaFast(DMA_VRAM, vdpSpriteCache, VDP_SPRITE_TABLE, 1 * (sizeof(VDPSprite) / 2), 2);
            
//             JOY_waitPress(JOY_ALL, BUTTON_START);
//             PAL_fadeOutAll(30, FALSE);
//             unloadLevel();

//             game_state = GAME_STATE_BOOT;
//         }

//         // remove 1 to get number of hard sprite used
//         vdpSpriteInd--;
//         if (vdpSpriteInd > 0) {
//             // get back to last sprite
//             vdpSprite--;
//             // mark as end
//             vdpSprite->link = 0;
//             // send sprites to VRAM using DMA queue
//             DMA_queueDmaFast(DMA_VRAM, vdpSpriteCache, VDP_SPRITE_TABLE, vdpSpriteInd * (sizeof(VDPSprite) / 2), 2);
//         } else {
//             // set 1st sprite off screen and mark as end
//             vdpSprite->y = 0;
//             vdpSprite->link = 0;
//             // send sprites to VRAM using DMA queue
//             DMA_queueDmaFast(DMA_VRAM, vdpSpriteCache, VDP_SPRITE_TABLE, 1 * (sizeof(VDPSprite) / 2), 2);
//         }
        
//         // sync frame and do vblank process
//         SYS_doVBlankProcess();
//     }

//     return 0;
// }

// static void handleInput() {
//     if (!ai[0]) {
//         u16 value = JOY_readJoypad(portMapping[0]);
//         addkey(((KEY_PL1_JUMP) & 0x7fff) | ((value & BUTTON_A) ? 0x0 : 0x8000));
//         addkey(((KEY_PL1_LEFT) & 0x7fff) | ((value & BUTTON_LEFT) ? 0x0 : 0x8000));
//         addkey(((KEY_PL1_RIGHT) & 0x7fff) | ((value & BUTTON_RIGHT) ? 0x0 : 0x8000));
//     }
// #ifndef __DEMO__
//     if (!ai[1]) {
//         u16 value = JOY_readJoypad(portMapping[1]);
//         addkey(((KEY_PL1_JUMP + 0x10) & 0x7fff) | ((value & BUTTON_A) ? 0x0 : 0x8000));
//         addkey(((KEY_PL1_LEFT + 0x10) & 0x7fff) | ((value & BUTTON_LEFT) ? 0x0 : 0x8000));
//         addkey(((KEY_PL1_RIGHT + 0x10) & 0x7fff) | ((value & BUTTON_RIGHT) ? 0x0 : 0x8000));
//     }
//     if (!ai[2]) {
//         u16 value = JOY_readJoypad(portMapping[2]);
//         addkey(((KEY_PL1_JUMP + 0x20) & 0x7fff) | ((value & BUTTON_A) ? 0x0 : 0x8000));
//         addkey(((KEY_PL1_LEFT + 0x20) & 0x7fff) | ((value & BUTTON_LEFT) ? 0x0 : 0x8000));
//         addkey(((KEY_PL1_RIGHT + 0x20) & 0x7fff) | ((value & BUTTON_RIGHT) ? 0x0 : 0x8000));
//     }
//     if (!ai[2]) {
//         u16 value = JOY_readJoypad(portMapping[3]);
//         addkey(((KEY_PL1_JUMP + 0x30) & 0x7fff) | ((value & BUTTON_A) ? 0x0 : 0x8000));
//         addkey(((KEY_PL1_LEFT + 0x30) & 0x7fff) | ((value & BUTTON_LEFT) ? 0x0 : 0x8000));
//         addkey(((KEY_PL1_RIGHT + 0x30) & 0x7fff) | ((value & BUTTON_RIGHT) ? 0x0 : 0x8000));
//     }
// #endif
// }

// static void displaySgdkLogo() {
//     VDP_clearPlane(BG_B, TRUE);

//     PAL_setColors(0, (u16*) palette_black, 64, DMA);
//     memcpy(&palette[0], sgdk_logo.palette->data, sgdk_logo.palette->length * 2);

//     VDP_drawBitmapEx(BG_B, &sgdk_logo, TILE_ATTR(PAL0, FALSE, FALSE, FALSE), 15, 9, FALSE);

//     PAL_fadeIn(0, 63, palette, 30, FALSE);
//     JOY_waitPressTime(JOY_ALL, BUTTON_ALL, 5000);
//     PAL_fadeOut(0, 63, 30, FALSE);

//     VDP_clearPlane(BG_B, TRUE);
// }

// static void displayLogo() {
//     VDP_clearPlane(BG_B, TRUE);

//     PAL_setColors(0, (u16*) palette_black, 64, DMA);
//     memcpy(&palette[0], image_logo.palette->data, 64 * 2);

//     VDP_loadTileSet(image_logo.tileset, VDPTilesFilled, DMA);
//     VDP_setTileMapEx(BG_B, image_logo.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, VDPTilesFilled), 11, 6, 0, 0, 18, 16, DMA);

//     PAL_fadeIn(0, 63, palette, 30, FALSE);
//     JOY_waitPressTime(JOY_ALL, BUTTON_ALL, 5000);
//     PAL_fadeOut(0, 63, 30, FALSE);

//     VDP_clearPlane(BG_B, TRUE);
// }

// u16 rnd(const u16 max) {
//     u32 op1 = random();
//     return modu(op1, max);
// }

void title() 
{
	if (action_counter <= 1)
	{
		init_menu();
//             PAL_fadeInAll(palette, 30, TRUE);
		jo_audio_stop_cd();
		jo_audio_play_cd_track(TITLE_TRACKID, TITLE_TRACKID, true);
	}

	load_menu(title_sprite_id);
    unsigned short result = menu_frame();
	(void)result; // avoid compiler warning until we use this
}

void update_game()
{
	if (action_counter == 0)
		jo_disable_all_screen_color_filter(); // need to clear at start of game loop for smoother transitions
	
	if (action_counter < MAX_ACTION_CYCLES)
		action_counter++;

	switch (current_game_mode)
	{
		// case MODE_INTRO_GRAPHIC:
		// 	intro_graphic();
		// 	break;

		// case MODE_INTRO_TEXT:
		// 	run_intro_text();
		// 	break;

		case MODE_TITLE:
			title();
			break;

		// case MODE_INSTRUCTIONS:
		// 	instructions();
		// 	break;

		// case MODE_CREDITS:
		// 	credits();
		// 	break;

		// case MODE_HIGH_SCORES:
		// 	high_scores();
		// 	break;

		// case MODE_HOF:
		// 	hof();
		// 	break;

		// case MODE_GAME:
		// 	play();
		// 	break;

		// case MODE_LOAD:
		// 	load();
		// 	break;

		default:
			jo_printf_with_color(0, 0, JO_COLOR_INDEX_White, "Hello world!");
			action_counter = 0; // always reset as we are not timing anything
			break;
	}
}

void jo_main(void) 
{
	init();
	// jo_core_add_vblank_callback(sdrv_vblank_rq);
    jo_core_add_callback(update_game);
	jo_core_run();
}

/*
** END OF FILE
*/