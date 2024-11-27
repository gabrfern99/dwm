/* See LICENSE file for copyright and license details. */

/* appearance */
static unsigned int borderpx  = 1;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray = 1;     /* 0 means no systray */
static unsigned int gappih    = 20;       /* horiz inner gap between windows */
static unsigned int gappiv    = 10;       /* vert inner gap between windows */
static unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */
#define ICONSIZE 16   /* icon size */
#define ICONSPACING 5 /* space between icon and title */
static const char buttonbar[]       = "";
static char *fonts[]          = { "JetBrains Mono:size=10:antialias=true:autohint=true", "NotoColorEmoji:pixelsize=14:antialias=true:autohint=true","FontAwesome:pixelsize=14:antialias=true:autohint=true", "siji:pixelsize=21:antialias=true:autohint=true", };
static char normbgcolor[]           = "#1a1a1a"; /* "#222222"; */
static char normbordercolor[]       = "#1a1a1a"; /* "#444444"; */
static char normfgcolor[]           = "#d7d7d7"; /* "#bbbbbb"; */
static char selfgcolor[]            = "#d7d7d7"; /* "#eeeeee"; */
static char selbordercolor[]        = "#ffffff"; /* "#ae00ff"; */
static char selbgcolor[]            = "#8f3d3d"; /*"#ae00ff"; */

static char back[]   = "#1C1E27";
static char fore[]   = "#CACACC";
static char border[] = "#CACACC";
static char col0[]   = "#6C6F93";
static char col1[]   = "#E4436F";
static char col2[]   = "#24E39D";
static char col3[]   = "#EDA685";
static char col4[]   = "#00A5AF";
static char col5[]   = "#B367CF";
static char col6[]   = "#00A5AF";
static char col7[]   = "#CACACC";
static char col8[]   = "#9b9fc9";
static char col9[]   = "#E4436F";
static char col10[]  = "#24E39D";
static char col11[]  = "#EDA685";
static char col12[]  = "#00A5AF";
static char col13[]  = "#B367CF";
static char col14[]  = "#00A5AF";
static char col15[]  = "#CACACC";
static char col16[]  = "#2B3833";

/* Here is the color array. Check the 'color.h' file to see the names' */
static char *colors[][3]      = {
	/*               fg         bg         border           code */
	[SchemeNorm]     = { fore,      "#121212",      border   }, // \x0b
	[SchemeSel]      = { fore,      back,      back   }, // \x0c
	[SchemeStatus]   = { fore,      "#121212",      NULL }, // \x0d
	[SchemeTagsSel]  = { back,      fore,   border }, // \x0e
	[SchemeTagsNorm] = { fore,      back,   border }, // \x0f
	[SchemeInfoSel]  = { normbgcolor,      fore,      border }, // \x10
	[SchemeInfoNorm] = { normbgcolor,      fore,      border }, // \x11
};

static const Block blocks[] = {
       /* fg     command                               interval        signal */
       { "#e6e6e6", "musicctl",                        0,             11},
       { "#f05c7e", "pacpackages",                        1,             8},
       { "#f05caf", "srvstatus",                        60,             20},
       { "#47b7e5", "memory",                        5,             2},
       { "#f84545", "cpu",                        10,             3},
       { "#dd5a1d", "echo $(cpubars)",                        1,             4},
       { "#5cdaf0", "mailbox",                        180,             5},
       //{ "#ff6600", "donations",         3600,                15},
       { "#2fbe48", "nettraf",                        1,             6},
       { "#d9e547", "volume",                        0,             10},
       { "#47e5ac", "clock",                         60,           9},
       
};

/* inverse the order of the blocks, comment to disable */
#define INVERSED       0
/* delimeter between blocks commands. NULL character ('\0') means no delimeter. */
static char delimiter[] = " ";
/* max number of character that one block command can output */
#define CMDLENGTH      90


typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = { "st", "-n", "spterm", "-g", "150x30", "-e","tmux", "new-session", "-A", "-s", "spterm", NULL };
const char *spcmd2[] = { "st", "-n", "spcalc", "-g", "50x20", "-e", "qalculate-gtk", NULL };
const char *spcmd3[] = { "virt-manager", NULL };
const char *spcmd4[] = { "java", "-jar", "~/.local/bin/burploader.jar", NULL };
const char *spcmd5[] = { "st", "-n", "spncmpcpp", "-f" "monospace:size=11", "-g", "120x20", "-e", "ncmpcpp", NULL };
const char *spcmd6[] = { "wireshark", NULL };
const char *spcmd7[] = { "dolphin", NULL };
const char *spcmd8[] = { "st", "-n", "spneo", "-g", "150x30", "-e", "neomutt", NULL };
const char *spcmd9[] = { "telegram-desktop", NULL };
const char *spcmd10[] = { "obsidian", NULL };
const char *spcmd11[] = { "zapzap", NULL }; // whatsapp
const char *spcmd12[] = { "crow", NULL };
const char *spcmd13[] = { "st", "-n", "splf", "-g", "150x30", "-e","lfub" };
const char *spcmd14[] = { "keepassxc", NULL };
const char *spcmd15[] = { "soundcloud-nativefier", NULL };
const char *spcmd16[] = { "st", "-n", "spncmpcpp", "-g", "150x30", "-e", "ncmpcpp", NULL };

static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",    spcmd2},
	{"spvirtman", spcmd3},
	{"spburp", spcmd4},
	{"spncmpcpp", spcmd5},
	{"spwire", spcmd6},
	{"spthunar", spcmd7},
	{"spneo", spcmd8},
	{"sptel", spcmd9},
	{"spobsidian", spcmd10},
	{"spzap", spcmd11},
	{"spcrow", spcmd12},
	{"splf", spcmd13},
	{"spkeepassxc", spcmd14},
	{"spsoundcloud", spcmd15},
	{"spncmpcpp", spcmd16},
};


/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "🐧" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   isterminal noswallow monitor */
	{ "St",       NULL,       NULL,       0,            0,           1,         0,        -1 },
	{ NULL,       "St",       NULL,       0,            0,           1,         0,        -1 },
	{ "mpv", NULL, NULL, 0, 1, 0, 0, -1 },
	{ NULL,      "spterm",    NULL,		    SPTAG(0),     1,           1,         0,        -1 },
	{ NULL,      "spcalc",    NULL,		    SPTAG(1),     1,           1,         0,        -1 },
	{ NULL,      "burp-StartBurp",    NULL,		    SPTAG(3),     1,           1,         0,        -1 },
	{ NULL,      "spncmpcpp",    NULL,		    SPTAG(4),     1,           1,         0,        -1 },
	{ NULL,      "wireshark",    NULL,		    SPTAG(5),     1,           1,         0,        -1 },
	{ NULL,      "dolphin",    NULL,		    SPTAG(6),     1,           1,         0,        -1 },
	{ NULL,      "spneo",    NULL,		    SPTAG(7),     1,           1,         0,        -1 },
	{ NULL,      "obsidian",    NULL,		    SPTAG(9),     1,           1,         0,        -1 },
	{ NULL,      "zapzap",    NULL,		    SPTAG(10),     1,           1,         0,        -1 },
	{ NULL,      "crow",    NULL,		    SPTAG(11),     1,           1,         0,        -1 },
	{ NULL,      "splf",    NULL,		    SPTAG(12),     1,           1,         0,        -1 },
	{ NULL,      "keepassxc", NULL,		    SPTAG(13),     1,           1,         0,        -1 },
	{ NULL,      "soundcloud-nativefier-914611",    NULL, SPTAG(14),     1,           1,         0,        -1 },
	{ NULL,      "spncmpcpp",    NULL,       SPTAG(15),     1,           1,         0,        -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",	tile },			/* Default: Master on lefnt, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */

	{ "[@]",	spiral },		/* Fibonacci spiral */
	{ "[\\]",	dwindle },		/* Decreasing in size right and leftward */

	{ "H[]",	deck },			/* Master on left, slaves in monocle-like mode on right */
	{ "[M]",	monocle },		/* All windows on top of eachother */

	{ "|M|",	centeredmaster },		/* Master in middle, slaves on sides */
	{ ">M>",	centeredfloatingmaster },	/* Same but master floats */

	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	/* { MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, */
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_q,     ACTION##stack, {.i = 0 } }, \ */
	/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "st", "-e", "tmux", "new-session", "-A", "-s", "main", NULL };

ResourcePref resources[] = {
		{ "color0",		STRING,	&normbordercolor },
		{ "color8",		STRING,	&selbordercolor },
		{ "color0",		STRING,	&normbgcolor },
		{ "color4",		STRING,	&normfgcolor },
		{ "color0",		STRING,	&selfgcolor },
		{ "color4",		STRING,	&selbgcolor },
		{ "borderpx",		INTEGER, &borderpx },
		{ "snap",		INTEGER, &snap },
		{ "showbar",		INTEGER, &showbar },
		{ "topbar",		INTEGER, &topbar },
		{ "nmaster",		INTEGER, &nmaster },
		{ "resizehints",	INTEGER, &resizehints },
		{ "mfact",		FLOAT,	&mfact },
		{ "gappih",		INTEGER, &gappih },
		{ "gappiv",		INTEGER, &gappiv },
		{ "gappoh",		INTEGER, &gappoh },
		{ "gappov",		INTEGER, &gappov },
		{ "swallowfloating",	INTEGER, &swallowfloating },
		{ "smartgaps",		INTEGER, &smartgaps },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	/* { MODKEY|ShiftMask,		XK_Escape,	spawn,	SHCMD("") }, */
	{ MODKEY,			XK_u,	spawn,	SHCMD("dmenuunicode") },
	/* { MODKEY|ShiftMask,		XK_grave,	togglescratch,	SHCMD("") }, */
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(			XK_9,		8)
	{ MODKEY,			XK_0,		view,		{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,		tag,		{.ui = ~0 } },
	{ MODKEY,           XK_grave,      setscratch,             {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },
	{ MODKEY,			XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwm)") },
	{ MODKEY|ShiftMask,		XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwm)") },
	{ MODKEY,			XK_equal,	spawn,		SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwm)") },
	{ MODKEY|ShiftMask,		XK_equal,	spawn,		SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwm)") },
	{ MODKEY,			XK_BackSpace,	spawn,		SHCMD("sysact") },
	/* { MODKEY|ShiftMask,		XK_BackSpace,	spawn,		SHCMD("") }, */

	{ MODKEY,			XK_Tab,		view,		{0} },
	/* { MODKEY|ShiftMask,		XK_Tab,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_q,		killclient,	{0} },
	/* { MODKEY|ShiftMask,XK_q, togglescratch, {.ui = 11 } }, */
	{ MODKEY,			XK_w,		spawn,		SHCMD("$BROWSER") },
	{ MODKEY|ShiftMask,		XK_w,		togglescratch,		{.ui = 5 } },
	{ MODKEY,			XK_e,		togglescratch,		{.ui = 7 } },
	{ MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD("tutorialvids") },
	{ MODKEY,			XK_r,		togglescratch,		{.ui = 3 } },
	{ MODKEY|ShiftMask,		XK_r, togglescratch, {.ui = 12 } },
	{ MODKEY,			XK_t,		setlayout,	{.v = &layouts[0]} },
	{ MODKEY|ShiftMask, XK_t, togglescratch, {.ui = 14 } },
	/* { MODKEY|Shiftmask,			XK_y,		setlayout,	{.v = &layouts[2]} }, */
	/* { MODKEY, XK_y, togglescratch, {.ui = 13 } }, */
	{ MODKEY, XK_k, togglescratch, {.ui = 13 } },
	/*{ MODKEY,			XK_u,		setlayout,	{.v = &layouts[4]} }, */
	{ MODKEY|ShiftMask,		XK_u,		setlayout,	{.v = &layouts[5]} },
	{ MODKEY,			XK_i,		setlayout,	{.v = &layouts[6]} },
	{ MODKEY|ShiftMask,		XK_i,		setlayout,	{.v = &layouts[1]} },
	{ MODKEY,			XK_o, togglescratch, {.ui = 9} },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,     {.i = -1 } },
	{ MODKEY,			XK_p,			spawn,		SHCMD("playerctl -p mpd play-pause;") },
	{ MODKEY|ShiftMask,		XK_p,			spawn,		SHCMD("playerctl -p spotify play-pause; kill -45 $(pidof dwm)") },
	{ MODKEY,			XK_bracketleft,		spawn,		SHCMD("playerctl -p mpd position 10-") },
	{ MODKEY|ShiftMask,		XK_bracketleft,		spawn,		SHCMD("playerctl -p spotify position 10-; kill -45 $(pidof dwm)") },
	{ MODKEY,			XK_bracketright,	spawn,		SHCMD("playerctl -p mpd position 10+") },
	{ MODKEY|ShiftMask,		XK_bracketright,	spawn,		SHCMD("playerctl -p spotify position 10+; kill -45 $(pidof dwm)") },
	{ MODKEY,			XK_backslash,		view,		{0} },
	/* { MODKEY|ShiftMask,		XK_backslash,		spawn,		SHCMD("") }, */
	/* { MODKEY,			XK_a, togglescratch, {.ui = 10} }, */
	/* { MODKEY|ShiftMask,		XK_a,		spawn,		SHCMD("") }, */
	{ MODKEY, XK_s, togglescratch, {.ui = 11 } },
	{ MODKEY|ShiftMask, XK_s, spawn,  SHCMD("pdfselect") },
	{ MODKEY,			XK_d,		spawn,          SHCMD("j4-dmenu-allbin") },
	{ MODKEY|ShiftMask,		XK_d,		togglegaps,	{0} },
	{ MODKEY,			XK_f,		togglefullscr,	{0} },
	{ MODKEY|ShiftMask,		XK_f,		setlayout,	{.v = &layouts[8]} },
	/* { MODKEY,			XK_g, togglescratch, {.ui = 12 } }, */
	{ MODKEY|ShiftMask, XK_g, togglescratch,  {.ui = 8 } },
	/* { MODKEY|ShiftMask,		XK_g,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_h,		setmfact,	{.f = -0.05} },
	/* J and K are automatically bound above in STACKEYS */
	{ MODKEY,			XK_l,		setmfact,	{.f = +0.05} },
	{ MODKEY,			XK_semicolon,	shiftview,	{ .i = 1 } },
	/* { MODKEY|ShiftMask,		XK_semicolon,	shiftview,	SHCMD("") }, */
	{ MODKEY,			XK_apostrophe,	togglescratch,		{.ui = 1 } },
	/*{ MODKEY|ShiftMask,		XK_apostrophe,	spawn,		SHCMD("") }, */
	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },
	{ MODKEY|ShiftMask,		XK_Return,	togglescratch,	{.ui = 0 } },

	{ MODKEY,			XK_z,		togglescratch,	{.ui = 12 } },
	{ MODKEY|ShiftMask,		XK_z,		incrgaps,	{.i = -1 } },
	/* { MODKEY,			XK_x,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_x, togglescratch, {.ui = 10} },
	{ MODKEY|ShiftMask,		XK_x, incrgaps, {.i = +1 } },
	{ MODKEY,			XK_c,		spawn,		SHCMD("st -e bc -l") },
	/* { MODKEY|ShiftMask,		XK_c,		togglescratch, {.ui = 9 } }, */
	{ MODKEY,			XK_v,		spawn,		SHCMD("virt-manager") },
	/* { MODKEY|ShiftMask,		XK_v, togglescratch, {.ui = 2 } }, */
	{ MODKEY,			XK_b,		togglebar,	{0} },
	{ MODKEY|ShiftMask,		XK_b, togglescratch, {.ui = 6} },
	{ MODKEY,			XK_n,		spawn,		SHCMD("manpdf 2> /dev/null") },
	{ MODKEY|ShiftMask,		XK_n, togglescratch,		{.ui = 4 } },
	{ MODKEY,			XK_m,		togglescratch,		{.ui = 15} },
	{ MODKEY|ShiftMask,		XK_m,		spawn,		SHCMD("pamixer -t") },
	{ MODKEY,			XK_comma,	spawn,		SHCMD("playerctl -p mpd previous") },
	{ MODKEY|ShiftMask,		XK_comma,	spawn,		SHCMD("playerctl -p spotify previous; kill -45 $(pidof dwm)") },
	{ MODKEY,			XK_period,	spawn,		SHCMD("playerctl -p mpd next") },
	{ MODKEY|ShiftMask,		XK_period,	spawn,		SHCMD("playerctl -p spotify next; kill -45 $(pidof dwm)") },
	{ MODKEY,			XK_Left,	focusmon,	{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_Left,	tagmon,		{.i = -1 } },
	{ MODKEY,			XK_Right,	focusmon,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Right,	tagmon,		{.i = +1 } },

	{ MODKEY,			XK_Page_Up,	shiftview,	{ .i = -1 } },
	{ MODKEY,			XK_Page_Down,	shiftview,	{ .i = 1 } },
	{ MODKEY,			XK_Insert,	spawn,		SHCMD("notify-send \"📋 Clipboard contents:\" \"$(xclip -o -selection clipboard)\"") },

	{ MODKEY,			XK_F1,		spawn,		SHCMD("groff -mom /usr/local/share/dwm/larbs.mom -Tpdf | zathura -") },
	{ MODKEY,			XK_F2,		quit,		{1} },
	{ MODKEY,			XK_F3,		spawn,		SHCMD("displayselect") },
	/* { MODKEY,			XK_F4,		spawn,		SHCMD("") }, */
	/* { MODKEY,			XK_F5,		xrdb,		{.v = NULL } }, */
	{ MODKEY,			XK_F6,		spawn,		SHCMD("torwrap") },
	{ MODKEY,			XK_F7,		spawn,		SHCMD("td-toggle") },
	{ MODKEY,			XK_F8,		spawn,		SHCMD("mailsync") },
	{ MODKEY,			XK_F9,		spawn,		SHCMD("dmenumount") },
	{ MODKEY,			XK_F10,		spawn,		SHCMD("dmenuumount") },
	/* { MODKEY,			XK_F11,		spawn,		SHCMD("") }, */
	/* { MODKEY,			XK_F12,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_space,	zoom,		{0} },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,	{0} },
	/* { 0,				XK_Print,	spawn,		SHCMD("sleep 0.4; scrot -s /tmp/screenshot-$(date +%F_%T).png -e 'xclip -selection c -t image/png < $f'") }, */
	{ 0,				XK_Print,	spawn,		SHCMD("flameshot gui") },
	{ ShiftMask,			XK_Print,	spawn,		SHCMD("maimpick") },
	{ MODKEY,			XK_Print,	spawn,		SHCMD("dmenurecord") },
	{ MODKEY|ShiftMask,		XK_Print,	spawn,		SHCMD("scrot /tmp/screenshot-$(date +%F_%T).png -e 'xclip -selection c -t image/png < $f'") },
	{ MODKEY,			XK_Delete,	spawn,		SHCMD("dmenurecord kill") },
	{ MODKEY,			XK_Scroll_Lock,	spawn,		SHCMD("killall screenkey || screenkey &") },

	{ 0, XF86XK_AudioMute,		spawn,		SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioPrev,		spawn,		SHCMD("mpc -h $MAINIPAD prev") },
	{ 0, XF86XK_AudioNext,		spawn,		SHCMD("mpc -h $MAINIPAD next") },
	{ 0, XF86XK_AudioPause,		spawn,		SHCMD("mpc -h $MAINIPAD pause") },
	{ 0, XF86XK_AudioPlay,		spawn,		SHCMD("mpc -h $MAINIPAD play") },
	{ 0, XF86XK_AudioStop,		spawn,		SHCMD("mpc -h $MAINIPAD stop") },
	{ 0, XF86XK_AudioRewind,	spawn,		SHCMD("mpc -h $MAINIPAD seek -10") },
	{ 0, XF86XK_AudioForward,	spawn,		SHCMD("mpc -h $MAINIPAD Mseek +10") },
	{ 0, XF86XK_AudioMedia,		spawn,		SHCMD("st -e ncmpcpp") },
	{ 0, XF86XK_PowerOff,		spawn,		SHCMD("[ \"$(printf \"No\\nYes\" | dmenu -i -nb darkred -sb red -sf white -nf gray -p \"Shutdown computer?\")\" = Yes ] && sudo -A shutdown -h now") },
	{ 0, XF86XK_Calculator,		spawn,		SHCMD("st -e bc -l") },
	{ 0, XF86XK_Sleep,		spawn,		SHCMD("sudo -A zzz") },
	{ 0, XF86XK_WWW,		spawn,		SHCMD("$BROWSER") },
	{ 0, XF86XK_DOS,		spawn,		SHCMD("st") },
	{ 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{ 0, XF86XK_TaskPane,		spawn,		SHCMD("st -e htop") },
	{ 0, XF86XK_Mail,		spawn,		SHCMD("st -e neomutt") },
	{ 0, XF86XK_MyComputer,		spawn,		SHCMD("st -e lf /") },
	/* { 0, XF86XK_Battery,		spawn,		SHCMD("") }, */
	{ 0, XF86XK_Launch1,		spawn,		SHCMD("xset dpms force off") },
	{ 0, XF86XK_TouchpadToggle,	spawn,		SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOff,	spawn,		SHCMD("synclient TouchpadOff=1") },
	{ 0, XF86XK_TouchpadOn,		spawn,		SHCMD("synclient TouchpadOff=0") },
	{ 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("xbacklight -inc 15") },
	{ 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("xbacklight -dec 15") },

	/* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} }, */
	/* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } }, */
	/* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
	/* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
	/* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
	/* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */


};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	/*{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} }, */
	{ ClkButton,            0,              Button1,        spawn,          SHCMD("jgmenu_run") },
	{ ClkRootWin,           0,              Button3,        spawn,          SHCMD("rofi.sh") },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sendstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sendstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sendstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sendstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sendstatusbar,   {.i = 5} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
};
