/* See LICENSE file for copyright and license details. */

/* appearance */
static unsigned int borderpx  = 0;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static unsigned int gappih    = 0;       /* horiz inner gap between windows */
 const unsigned int gappiv    = 0;       /* vert inner gap between windows */
static unsigned int gappoh    = 0;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov    = 0;       /* vert outer gap between windows and screen edge */
static int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */
static char *fonts[]          = { "monospace:size=9", "JoyPixels:pixelsize=9:antialias=true:autohint=true", "FontAwesome:pixelsize=9:antialias=true:autohint=true" };

static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#ae00ff";/* "#ffae00"  #005577 */
static char selbgcolor[]            = "#ae00ff";/* #005577 */

static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = { "st", "-n", "spterm", "-e","tmux", NULL };
const char *spcmd2[] = { "st", "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "qalculate-gtk", NULL };
const char *spcmd3[] = { "virt-manager", NULL };
const char *spcmd4[] = { "burpsuite", NULL };
const char *spcmd5[] = { "st", "-n", "spnewsboat", "-f" "monospace:size=11", "-g", "120x20", "-e", "newsboat", NULL };
const char *spcmd6[] = { "wireshark", NULL };
const char *spcmd7[] = { "thunar", NULL };
const char *spcmd8[] = { "st", "-n", "spneo", "-e", "neomutt", NULL };
const char *spcmd9[] = { "telegram-desktop", NULL };
const char *spcmd10[] = { "cherrytree", NULL };
const char *spcmd11[] = { "whatsapp-nativefier-dark", NULL };
const char *spcmd12[] = { "crow", NULL };
const char *spcmd13[] = { "rofi.sh", NULL };
const char *spcmd14[] = { "freetube-bin", NULL };
const char *spcmd15[] = { "soundcloud-nativefier", NULL };

static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",    spcmd2},
	{"spvirtman", spcmd3},
	{"spburp", spcmd4},
	{"spnewsboat", spcmd5},
	{"spthunar", spcmd6},
	{"spranger", spcmd7},
	{"spneo", spcmd8},
	{"sptel", spcmd9},
	{"spcherry", spcmd10},
	{"spzap", spcmd11},
	{"spcrow", spcmd12},
	{"sprofi", spcmd13},
	{"spfreetube", spcmd14},
	{"spsoundcloud", spcmd15},
};


/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   isterminal noswallow monitor */
	{ "St",       NULL,       NULL,       0,            0,           1,         0,        -1 },
	{ NULL,       "St",       NULL,       0,            0,           1,         0,        -1 },
	{ "qutebrowser", NULL, NULL, 1 << 1, 0, 0, -1 },
	{ "Virt-manager", NULL, NULL, 0, 1, 0, 0, -1 },
	{ "Steam", NULL, NULL, 1 << 3, 0, 0, 0, -1 },
	{ "mpv", NULL, NULL, 0, 1, 0, 0, -1 },
	{ NULL,      "spterm",    NULL,       	    SPTAG(0),     1,           1,         0,        -1 },
	{ NULL,      "spcalc",    NULL,       	    SPTAG(1),     1,           1,         0,        -1 },
	{ NULL,      "virt-manager",    NULL,       	    SPTAG(2),     1,           1,         0,        -1 },
	{ NULL,      "burp-StartBurp",    NULL,       	    SPTAG(3),     1,           1,         0,        -1 },
	{ NULL,      "spnewsboat",    NULL,       	    SPTAG(4),     1,           1,         0,        -1 },
	{ NULL,      "wireshark",    NULL,       	    SPTAG(5),     1,           1,         0,        -1 },
	{ "Thunar",      NULL,    NULL,       	    SPTAG(6),     1,           1,         0,        -1 },
	{ NULL,      "spneo",    NULL,       	    SPTAG(7),     1,           1,         0,        -1 },
	{ NULL,      "telegram-desktop",    NULL,       	    SPTAG(8),     1,           1,         0,        -1 },
	{ NULL,      "cherrytree",    NULL,       	    SPTAG(9),     1,           1,         0,        -1 },
	{ NULL,      "whatsapp-nativefier-d52542",    NULL,       	    SPTAG(10),     1,           1,         0,        -1 },
	{ NULL,      "crow",    NULL,       	    SPTAG(11),     1,           1,         0,        -1 },
	{ NULL,      "rofi",    NULL,       	    SPTAG(12),     1,           1,         0,        -1 },
	{ "FreeTube",      NULL,    NULL,       	    SPTAG(13),     1,           1,         0,        -1 },
	{ NULL,      "soundcloud-nativefier-914611",    NULL, SPTAG(14),     1,           1,         0,        -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
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
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_q,     ACTION##stack, {.i = 0 } }, \ */
	/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "st", "-e", "tmux", NULL };

ResourcePref resources[] = {
		{ "dwm.color0",		STRING,	&normbordercolor },
		{ "dwm.color8",		STRING,	&selbordercolor },
		{ "dwm.color0",		STRING,	&normbgcolor },
		{ "dwm.color4",		STRING,	&normfgcolor },
		{ "dwm.color0",		STRING,	&selfgcolor },
		{ "dwm.color4",		STRING,	&selbgcolor },
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
static Key keys[] = {
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
	{ MODKEY,			XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_minus,	spawn,		SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			XK_equal,	spawn,		SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		XK_equal,	spawn,		SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
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
	{ MODKEY,			XK_r,		togglescratch,		{.ui = 6 } },
	{ MODKEY|ShiftMask,		XK_r, togglescratch, {.ui = 12 } },
	{ MODKEY,			XK_t,		setlayout,	{.v = &layouts[0]} },
	{ MODKEY|ShiftMask, XK_t, togglescratch, {.ui = 11 } },
	{ MODKEY,			XK_y,		setlayout,	{.v = &layouts[2]} },
	{ MODKEY|ShiftMask,		XK_y, togglescratch, {.ui = 13 } },
	/*{ MODKEY,			XK_u,		setlayout,	{.v = &layouts[4]} }, */
	{ MODKEY|ShiftMask,		XK_u,		setlayout,	{.v = &layouts[5]} },
	{ MODKEY,			XK_i,		setlayout,	{.v = &layouts[6]} },
	{ MODKEY|ShiftMask,		XK_i,		setlayout,	{.v = &layouts[1]} },
	{ MODKEY,			XK_o,		incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,     {.i = -1 } },
	{ MODKEY,			XK_p,			spawn,		SHCMD("mpc -h $MAINIPAD toggle") },
	{ MODKEY|ShiftMask,		XK_p,			spawn,		SHCMD("mpc -h $MAINIPAD pause ; pauseallmpv") },
	{ MODKEY,			XK_bracketleft,		spawn,		SHCMD("mpc -h $MAINIPAD seek -10") },
	{ MODKEY|ShiftMask,		XK_bracketleft,		spawn,		SHCMD("mpc -h $MAINIPAD seek -120") },
	{ MODKEY,			XK_bracketright,	spawn,		SHCMD("mpc -h $MAINIPAD seek +10") },
	{ MODKEY|ShiftMask,		XK_bracketright,	spawn,		SHCMD("mpc -h $MAINIPAD seek +120") },
	{ MODKEY,			XK_backslash,		view,		{0} },
	/* { MODKEY|ShiftMask,		XK_backslash,		spawn,		SHCMD("") }, */

	{ MODKEY,			XK_a,		spawn,		SHCMD("st -e pulsemixer; kill -44 $(pidof dwmblocks)") },
	/* { MODKEY|ShiftMask,		XK_a,		spawn,		SHCMD("") }, */
	{ MODKEY, XK_s, togglescratch, {.ui = 14 } },
	{ MODKEY|ShiftMask, XK_s, spawn,  SHCMD("pdfselect") },
	{ MODKEY,			XK_d,		spawn,          SHCMD("dmenu_run") },
	{ MODKEY|ShiftMask,		XK_d,		togglegaps,	{0} },
	{ MODKEY,			XK_f,		togglefullscr,	{0} },
	{ MODKEY|ShiftMask,		XK_f,		setlayout,	{.v = &layouts[8]} },
	/* { MODKEY,			XK_g, togglescratch, {.ui = 12 } }, */
	{ MODKEY|ShiftMask, XK_g, togglescratch,  {.ui = 8 } },
	/* { MODKEY|ShiftMask,		XK_g,		spawn,		SHCMD("") }, */
	{ MODKEY,			XK_h,		setmfact,	{.f = -0.05} },
	/* J and K are automatically bound above in STACKEYS */
	{ MODKEY,			XK_l,		setmfact,      	{.f = +0.05} },
	{ MODKEY,			XK_semicolon,	shiftview,	{ .i = 1 } },
	/* { MODKEY|ShiftMask,		XK_semicolon,	shiftview,	SHCMD("") }, */
	{ MODKEY,			XK_apostrophe,	togglescratch,		{.ui = 1 } },
	/*{ MODKEY|ShiftMask,		XK_apostrophe,	spawn,		SHCMD("") }, */
	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },
	{ MODKEY|ShiftMask,		XK_Return,	togglescratch,	{.ui = 0 } },

	{ MODKEY,			XK_z,		incrgaps,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_z,		incrgaps,	{.i = -1 } },
	/* { MODKEY,			XK_x,		spawn,		SHCMD("") }, */
	{ MODKEY|ShiftMask,		XK_x, togglescratch, {.ui = 10 } },
	{ MODKEY,			XK_c,		spawn,		SHCMD("st -e bc -l") },
	{ MODKEY|ShiftMask,		XK_c,		togglescratch, {.ui = 9 } },
	{ MODKEY,			XK_v,		spawn,		SHCMD("virt-manager") },
	{ MODKEY|ShiftMask,		XK_v, togglescratch, {.ui = 2 } },
	{ MODKEY,			XK_b,		togglebar,	{0} },
	{ MODKEY|ShiftMask,		XK_b, togglescratch, {.ui = 3} },
	{ MODKEY,			XK_n,		spawn,		SHCMD("manpdf 2> /dev/null") },
	{ MODKEY|ShiftMask,		XK_n, togglescratch,		{.ui = 4 } },
	{ MODKEY,			XK_m,		spawn,		SHCMD("st -e ncmpcpp") },
	{ MODKEY|ShiftMask,		XK_m,		spawn,		SHCMD("pamixer -t") },
	{ MODKEY,			XK_comma,	spawn,		SHCMD("mpc -h $MAINIPAD prev") },
	{ MODKEY|ShiftMask,		XK_comma,	spawn,		SHCMD("mpc -h $MAINIPAD seek 0%") },
	{ MODKEY,			XK_period,	spawn,		SHCMD("mpc -h $MAINIPAD next") },
	{ MODKEY|ShiftMask,		XK_period,	spawn,		SHCMD("mpc -h $MAINIPAD repeat") },

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

	{ 0,				XK_Print,	spawn,		SHCMD("sleep 0.4; scrot -s /tmp/screenshot-$(date +%F_%T).png -e 'xclip -selection c -t image/png < $f'") },
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
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
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
