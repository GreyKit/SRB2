// SONIC ROBO BLAST 2
//-----------------------------------------------------------------------------
// Copyright (C) 1993-1996 by id Software, Inc.
// Copyright (C) 1998-2000 by DooM Legacy Team.
// Copyright (C) 1999-2020 by Sonic Team Junior.
//
// This program is free software distributed under the
// terms of the GNU General Public License, version 2.
// See the 'LICENSE' file for more details.
//-----------------------------------------------------------------------------
/// \file  r_state.h
/// \brief Refresh/render internal state variables (global)

#ifndef __R_STATE__
#define __R_STATE__

// Need data structure definitions.
#include "d_player.h"
#include "r_data.h"

#ifdef __GNUG__
#pragma interface
#endif

//
// Refresh internal data structures, for rendering.
//

// needed for pre rendering (fracs)
typedef struct
{
	fixed_t width;
	fixed_t offset;
	fixed_t topoffset;
	fixed_t height;
} sprcache_t;

extern sprcache_t *spritecachedinfo;

extern lighttable_t *colormaps;
extern lighttable_t *fadecolormap;

// Boom colormaps.
extern extracolormap_t *extra_colormaps;

// for global animation
extern INT32 *texturetranslation;

// Sprites
extern size_t numspritelumps, max_spritelumps;

//
// Lookup tables for map data.
//
extern size_t numsprites;
extern spritedef_t *sprites;

extern size_t numvertexes;
extern vertex_t *vertexes;

extern size_t numsegs;
extern seg_t *segs;

extern size_t numsectors;
extern sector_t *sectors;
extern sector_t *spawnsectors;

extern size_t numsubsectors;
extern subsector_t *subsectors;

extern size_t numnodes;
extern node_t *nodes;

extern size_t numlines;
extern line_t *lines;
extern line_t *spawnlines;

extern size_t numsides;
extern side_t *sides;
extern side_t *spawnsides;

//
// POV data.
//
extern fixed_t viewx, viewy, viewz;
extern angle_t viewangle, aimingangle;
extern sector_t *viewsector;
extern player_t *viewplayer;
extern mobj_t *r_viewmobj;

extern consvar_t cv_allowmlook;
extern consvar_t cv_maxportals;

extern angle_t clipangle;
extern angle_t doubleclipangle;

extern INT32 viewangletox[FINEANGLES/2];
extern angle_t xtoviewangle[MAXVIDWIDTH+1];

// Wall rendering
typedef struct
{
	INT32 x, stopx;
	angle_t centerangle;
	fixed_t offset;
	fixed_t offset2; // for splats
	fixed_t scale, scalestep;
	fixed_t midtexturemid, toptexturemid, bottomtexturemid;
#ifdef ESLOPE
	fixed_t toptextureslide, midtextureslide, bottomtextureslide; // Defines how to adjust Y offsets along the wall for slopes
	fixed_t midtextureback, midtexturebackslide; // Values for masked midtexture height calculation
#endif
	fixed_t distance;
	angle_t normalangle;
	angle_t angle1; // angle to line origin

	// for masked segs and thick sides
	INT32 texnum;
	void (*colfunc_2s) (column_t *);

	// masked segs
	INT32 maskedrepeat;

	// thick sides
	ffloor_t *pfloor;
	fixed_t offsetvalue;

#ifdef ESLOPE
	// Render FOF sides kinda like normal sides, with the frac and step and everything
	// NOTE: INT64 instead of fixed_t because overflow concerns
	INT64 top_frac, top_step, bottom_frac, bottom_step;
	boolean ffloorslopeskew;
	fixed_t ffloortextureslide;
	fixed_t left_top, left_bottom; // needed here for slope skewing
#endif
} renderwall_t;
extern renderwall_t rw;

#endif
