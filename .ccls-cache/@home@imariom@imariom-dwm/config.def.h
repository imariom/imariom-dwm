/* **************************
 *   |                   | *
 *   |   i m a r i o m   | *
 *   |                   | *
 * 
 * Mário Moiane (imariom)
 * http://www.youtube.com/c/imariom
 * http://www.github.com/imariom/imariom-dwm
 */

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx 	= 8;		/* gaps between windows */
static const unsigned int snap      = 25;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 11;		/* horizontal padding for statusbar */
static const int vertpadbar         = 11;		/* vertical padding for statusbar */

/* Default font will be JetBrains if installed
 * (sudo pacman -S ttf-jetbrains-mono-nerd ttf-nerd-fonts-symbols). */
static const char *fonts[] = {
    "JetBrains Mono Nerd Font:weight=bold:size=10:antialias=true"
};

static const char col_1[] = "#0a0f15"; /* background color of bar */
static const char col_2[] = "#282c34"; /* border color of unfocused windows */
static const char col_3[] = "#d1c1b0"; /* font color of the status bar */
static const char col_4[] = "#00ACD9"; /* border color of focused windows and tags */
static const char col_5[] = "#000000";

static const char *colors[][3] = {
	/*                   fg         bg         border   */
	[SchemeNorm]     = { col_3,     col_1,     col_2 },
	[SchemeSel]      = { col_3,     col_4,     col_4 },
    // I manually added the following schemes to change the color of the
    // middle of the status bar. dwm.c also has some changes made to.
    // This is a copy from colobar patch (that did fail on my dwm rice)
	[SchemeInfoSel]  = { col_3,     col_1,     col_5 }, /* infobar middle  selected {text,background,not used but cannot be empty} */
	[SchemeInfoNorm] = { col_3,     col_1,     col_5 }, /* infobar middle  unselected {text,background,not used but cannot be empty} */
};

/* tagging */
// static const char *tags[] = { " ", " ", " ", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { " ", " ", " ", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[] 	= { "alacritty", NULL };

static const char *rofi[] 			= { "rofi", "-show", "drun", "-show-emojis", NULL }; /* launches rofi */
static const char *braveBrowswer[] 	= { "brave", NULL }; /* launches Brave Browswer */
static const char *code[] 			= { "code", NULL }; /* launches visual studio code */
static const char *thunar[] 		= { "thunar", NULL }; /* launches thunar file manager */

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = rofi } },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = braveBrowswer } },
	{ MODKEY|ShiftMask,             XK_k,      spawn,          {.v = code } },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = thunar } },

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },

	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },

	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

	/* Switching between monitors */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	/* Restart or quit dwm */
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

