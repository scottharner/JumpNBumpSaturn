#include <jo/jo.h>

#include "global.h"
//#include "resources.h"

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
int rabbits_tile_ind[JNB_MAX_PLAYERS][RABBIT_TILE_COUNT];


void load_rabbits() {
    // load Rabbits Sprites
    rabbit11_sprite_id = jo_sprite_add_tga_tileset(JO_ROOT_DIR, "RABBIT1.TGA", JO_COLOR_RGB(255, 0, 255), rabbit_tileset, RABBIT_TILE_COUNT);
    rabbits_tile_ind[0][0] = rabbit11_sprite_id;
	rabbit12_sprite_id = rabbit11_sprite_id + 1;
    rabbits_tile_ind[0][1] = rabbit12_sprite_id;
	rabbit13_sprite_id = rabbit11_sprite_id + 2;
    rabbits_tile_ind[0][2] = rabbit13_sprite_id;
	rabbit14_sprite_id = rabbit11_sprite_id + 3;
    rabbits_tile_ind[0][3] = rabbit14_sprite_id;
	rabbit15_sprite_id = rabbit11_sprite_id + 4;
    rabbits_tile_ind[0][4] = rabbit15_sprite_id;
	rabbit16_sprite_id = rabbit11_sprite_id + 5;
    rabbits_tile_ind[0][5] = rabbit16_sprite_id;
	rabbit17_sprite_id = rabbit11_sprite_id + 6;
    rabbits_tile_ind[0][6] = rabbit17_sprite_id;
	rabbit18_sprite_id = rabbit11_sprite_id + 7;
    rabbits_tile_ind[0][7] = rabbit18_sprite_id;
	rabbit19_sprite_id = rabbit11_sprite_id + 8;
    rabbits_tile_ind[0][8] = rabbit19_sprite_id;
	rabbit110_sprite_id = rabbit11_sprite_id + 9;
    rabbits_tile_ind[0][9] = rabbit110_sprite_id;
	rabbit111_sprite_id = rabbit11_sprite_id + 10;
    rabbits_tile_ind[0][10] = rabbit111_sprite_id;
	rabbit112_sprite_id = rabbit11_sprite_id + 11;
    rabbits_tile_ind[0][11] = rabbit112_sprite_id;
	rabbit113_sprite_id = rabbit11_sprite_id + 12;
    rabbits_tile_ind[0][12] = rabbit113_sprite_id;
	rabbit114_sprite_id = rabbit11_sprite_id + 13;
    rabbits_tile_ind[0][13] = rabbit114_sprite_id;
	rabbit115_sprite_id = rabbit11_sprite_id + 14;
    rabbits_tile_ind[0][14] = rabbit115_sprite_id;
	rabbit116_sprite_id = rabbit11_sprite_id + 15;
    rabbits_tile_ind[0][15] = rabbit116_sprite_id;
	rabbit117_sprite_id = rabbit11_sprite_id + 16;
    rabbits_tile_ind[0][16] = rabbit117_sprite_id;
	rabbit118_sprite_id = rabbit11_sprite_id + 17;
    rabbits_tile_ind[0][17] = rabbit118_sprite_id;
	rabbit21_sprite_id = jo_sprite_add_tga_tileset(JO_ROOT_DIR, "RABBIT2.TGA", JO_COLOR_RGB(255, 0, 255), rabbit_tileset, RABBIT_TILE_COUNT);
    rabbits_tile_ind[1][0] = rabbit21_sprite_id;
	rabbit22_sprite_id = rabbit21_sprite_id + 1;
    rabbits_tile_ind[1][1] = rabbit22_sprite_id;
	rabbit23_sprite_id = rabbit21_sprite_id + 2;
    rabbits_tile_ind[1][2] = rabbit23_sprite_id;
	rabbit24_sprite_id = rabbit21_sprite_id + 3;
    rabbits_tile_ind[1][3] = rabbit24_sprite_id;
	rabbit25_sprite_id = rabbit21_sprite_id + 4;
    rabbits_tile_ind[1][4] = rabbit25_sprite_id;
	rabbit26_sprite_id = rabbit21_sprite_id + 5;
    rabbits_tile_ind[1][5] = rabbit26_sprite_id;
	rabbit27_sprite_id = rabbit21_sprite_id + 6;
    rabbits_tile_ind[1][6] = rabbit27_sprite_id;
	rabbit28_sprite_id = rabbit21_sprite_id + 7;
    rabbits_tile_ind[1][7] = rabbit28_sprite_id;
	rabbit29_sprite_id = rabbit21_sprite_id + 8;
    rabbits_tile_ind[1][8] = rabbit29_sprite_id;
	rabbit210_sprite_id = rabbit21_sprite_id + 9;
    rabbits_tile_ind[1][9] = rabbit210_sprite_id;
	rabbit211_sprite_id = rabbit21_sprite_id + 10;
    rabbits_tile_ind[1][10] = rabbit211_sprite_id;
	rabbit212_sprite_id = rabbit21_sprite_id + 11;
    rabbits_tile_ind[1][11] = rabbit212_sprite_id;
	rabbit213_sprite_id = rabbit21_sprite_id + 12;
    rabbits_tile_ind[1][12] = rabbit213_sprite_id;
	rabbit214_sprite_id = rabbit21_sprite_id + 13;
    rabbits_tile_ind[1][13] = rabbit214_sprite_id;
	rabbit215_sprite_id = rabbit21_sprite_id + 14;
    rabbits_tile_ind[1][14] = rabbit215_sprite_id;
	rabbit216_sprite_id = rabbit21_sprite_id + 15;
    rabbits_tile_ind[1][15] = rabbit216_sprite_id;
	rabbit217_sprite_id = rabbit21_sprite_id + 16;
    rabbits_tile_ind[1][16] = rabbit217_sprite_id;
	rabbit218_sprite_id = rabbit21_sprite_id + 17;
    rabbits_tile_ind[1][17] = rabbit218_sprite_id;
	rabbit31_sprite_id = jo_sprite_add_tga_tileset(JO_ROOT_DIR, "RABBIT3.TGA", JO_COLOR_RGB(255, 0, 255), rabbit_tileset, RABBIT_TILE_COUNT);
    rabbits_tile_ind[2][0] = rabbit31_sprite_id;
	rabbit32_sprite_id = rabbit31_sprite_id + 1;
    rabbits_tile_ind[2][1] = rabbit32_sprite_id;
	rabbit33_sprite_id = rabbit31_sprite_id + 2;
    rabbits_tile_ind[2][2] = rabbit33_sprite_id;
	rabbit34_sprite_id = rabbit31_sprite_id + 3;
    rabbits_tile_ind[2][3] = rabbit34_sprite_id;
	rabbit35_sprite_id = rabbit31_sprite_id + 4;
    rabbits_tile_ind[2][4] = rabbit35_sprite_id;
	rabbit36_sprite_id = rabbit31_sprite_id + 5;
    rabbits_tile_ind[2][5] = rabbit36_sprite_id;
	rabbit37_sprite_id = rabbit31_sprite_id + 6;
    rabbits_tile_ind[2][6] = rabbit37_sprite_id;
	rabbit38_sprite_id = rabbit31_sprite_id + 7;
    rabbits_tile_ind[2][7] = rabbit38_sprite_id;
	rabbit39_sprite_id = rabbit31_sprite_id + 8;
    rabbits_tile_ind[2][8] = rabbit39_sprite_id;
	rabbit310_sprite_id = rabbit31_sprite_id + 9;
    rabbits_tile_ind[2][9] = rabbit310_sprite_id;
	rabbit311_sprite_id = rabbit31_sprite_id + 10;
    rabbits_tile_ind[2][10] = rabbit311_sprite_id;
	rabbit312_sprite_id = rabbit31_sprite_id + 11;
    rabbits_tile_ind[2][11] = rabbit312_sprite_id;
	rabbit313_sprite_id = rabbit31_sprite_id + 12;
    rabbits_tile_ind[2][12] = rabbit313_sprite_id;
	rabbit314_sprite_id = rabbit31_sprite_id + 13;
    rabbits_tile_ind[2][13] = rabbit314_sprite_id;
	rabbit315_sprite_id = rabbit31_sprite_id + 14;
    rabbits_tile_ind[2][14] = rabbit315_sprite_id;
	rabbit316_sprite_id = rabbit31_sprite_id + 15;
    rabbits_tile_ind[2][15] = rabbit316_sprite_id;
	rabbit317_sprite_id = rabbit31_sprite_id + 16;
    rabbits_tile_ind[2][16] = rabbit317_sprite_id;
	rabbit318_sprite_id = rabbit31_sprite_id + 17;
    rabbits_tile_ind[2][17] = rabbit318_sprite_id;
	rabbit41_sprite_id = jo_sprite_add_tga_tileset(JO_ROOT_DIR, "RABBIT4.TGA", JO_COLOR_RGB(255, 0, 255), rabbit_tileset, RABBIT_TILE_COUNT);
    rabbits_tile_ind[3][0] = rabbit41_sprite_id;
	rabbit42_sprite_id = rabbit41_sprite_id + 1;
    rabbits_tile_ind[3][1] = rabbit42_sprite_id;
	rabbit43_sprite_id = rabbit41_sprite_id + 2;
    rabbits_tile_ind[3][2] = rabbit43_sprite_id;
	rabbit44_sprite_id = rabbit41_sprite_id + 3;
    rabbits_tile_ind[3][3] = rabbit44_sprite_id;
	rabbit45_sprite_id = rabbit41_sprite_id + 4;
    rabbits_tile_ind[3][4] = rabbit45_sprite_id;
	rabbit46_sprite_id = rabbit41_sprite_id + 5;
    rabbits_tile_ind[3][5] = rabbit46_sprite_id;
	rabbit47_sprite_id = rabbit41_sprite_id + 6;
    rabbits_tile_ind[3][6] = rabbit47_sprite_id;
	rabbit48_sprite_id = rabbit41_sprite_id + 7;
    rabbits_tile_ind[3][7] = rabbit48_sprite_id;
	rabbit49_sprite_id = rabbit41_sprite_id + 8;
    rabbits_tile_ind[3][8] = rabbit49_sprite_id;
	rabbit410_sprite_id = rabbit41_sprite_id + 9;
    rabbits_tile_ind[3][9] = rabbit410_sprite_id;
	rabbit411_sprite_id = rabbit41_sprite_id + 10;
    rabbits_tile_ind[3][10] = rabbit411_sprite_id;
	rabbit412_sprite_id = rabbit41_sprite_id + 11;
    rabbits_tile_ind[3][11] = rabbit412_sprite_id;
	rabbit413_sprite_id = rabbit41_sprite_id + 12;
    rabbits_tile_ind[3][12] = rabbit413_sprite_id;
	rabbit414_sprite_id = rabbit41_sprite_id + 13;
    rabbits_tile_ind[3][13] = rabbit414_sprite_id;
	rabbit415_sprite_id = rabbit41_sprite_id + 14;
    rabbits_tile_ind[3][14] = rabbit415_sprite_id;
	rabbit416_sprite_id = rabbit41_sprite_id + 15;
    rabbits_tile_ind[3][15] = rabbit416_sprite_id;
	rabbit417_sprite_id = rabbit41_sprite_id + 16;
    rabbits_tile_ind[3][16] = rabbit417_sprite_id;
	rabbit418_sprite_id = rabbit41_sprite_id + 17;
    rabbits_tile_ind[3][17] = rabbit418_sprite_id;

    // memcpy(&palette[32], rabbits_palette1.data, 16 * 2);
    // memcpy(&palette[48], rabbits_palette2.data, 16 * 2);

    // for(u16 c1 = 0; c1 < 18; c1++) {
    //     rabbits_tile_ind[0][c1] = VDPTilesFilled;
        // const AnimationFrame* animationFrame = rabbit1_sprite.animations[0]->frames[c1];
        // const u32* tiles   = animationFrame->tileset->tiles;
        // const u16  numTile = animationFrame->tileset->numTile;
        // VDP_loadTileData(tiles, VDPTilesFilled, numTile, DMA);
        // VDPTilesFilled += numTile;
    // }

    // for(u16 c1 = 0; c1 < 18; c1++) {
    //     rabbits_tile_ind[1][c1] = VDPTilesFilled;
    //     const AnimationFrame* animationFrame = rabbit2_sprite.animations[0]->frames[c1];
    //     const u32* tiles   = animationFrame->tileset->tiles;
    //     const u16  numTile = animationFrame->tileset->numTile;
    //     VDP_loadTileData(tiles, VDPTilesFilled, numTile, DMA);
    //     VDPTilesFilled += numTile;
    // }

    // for(u16 c1 = 0; c1 < 18; c1++) {
    //     rabbits_tile_ind[2][c1] = VDPTilesFilled;
    //     const AnimationFrame* animationFrame = rabbit3_sprite.animations[0]->frames[c1];
    //     const u32* tiles   = animationFrame->tileset->tiles;
    //     const u16  numTile = animationFrame->tileset->numTile;
    //     VDP_loadTileData(tiles, VDPTilesFilled, numTile, DMA);
    //     VDPTilesFilled += numTile;
    // }

    // for(u16 c1 = 0; c1 < 18; c1++) {
    //     rabbits_tile_ind[3][c1] = VDPTilesFilled;
    //     const AnimationFrame* animationFrame = rabbit4_sprite.animations[0]->frames[c1];
    //     const u32* tiles   = animationFrame->tileset->tiles;
    //     const u16  numTile = animationFrame->tileset->numTile;
    //     VDP_loadTileData(tiles, VDPTilesFilled, numTile, DMA);
    //     VDPTilesFilled += numTile;
    // }
}

static struct {
    short x, y;
} rabbit_hs[18] = {
    { -2, -1 },
    { -2,  0 },
    { -2,  2 },
    { -3,  2 },
    { -3, -2 },
    { -1,  1 },
    {  0,  0 },
    {  1,  0 },
    { -1, -3 },
    { -1, -1 },
    {  0,  0 },
    {  0,  2 },
    {  0,  2 },
    {  1, -2 },
    {  0,  1 },
    {  0,  0 },
    {  0,  0 },
    {  2, -3 }
};

void update_rabbits_sprites(bool force_all) {
    int c1 = JNB_MAX_PLAYERS;
    while(c1--) {
        if(player[c1].enabled || force_all) {

            unsigned short image_ind = player[c1].image;
            short x = ((player[c1].x >> 16) * JO_TV_WIDTH / JNB_WIDTH) - rabbit_hs[image_ind].x;
            short y = ((player[c1].y >> 16) * JO_TV_HEIGHT / JNB_HEIGHT) - rabbit_hs[image_ind].y;

            jo_sprite_draw3D2(rabbits_tile_ind[c1][image_ind], x, y, RABBIT_ZINDEX);
        //     vdpSprite->y = y + 0x80 ;
        //     vdpSprite->x = x + 0x80;
        //     vdpSprite->size = SPRITE_SIZE(2, 2);
        //     vdpSprite->link = vdpSpriteInd++;
        //     vdpSprite->attribut = TILE_ATTR_FULL(PAL2 + (c1 >> 1), FALSE, FALSE, FALSE, rabbits_tile_ind[c1][image_ind]);
        //     vdpSprite++;
        }
    }
}
