/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 0;                      /* -b  option; if 0, dmenu appears at bottom */
#if ALPHA_PATCH
static int opacity = 1;                     /* -o  option; if 0, then alpha is disabled */
#endif // ALPHA_PATCH
#if CARET_WIDTH_PATCH
static int caret_width = 2;                 /* -cw option; set default caret width */
#endif // CARET_WIDTH_PATCH
#if FUZZYMATCH_PATCH
static int fuzzy = 1;                       /* -F  option; if 0, dmenu doesn't use fuzzy matching */
#endif // FUZZYMATCH_PATCH
#if INCREMENTAL_PATCH
static int incremental = 0;                 /* -r  option; if 1, outputs text each time a key is pressed */
#endif // INCREMENTAL_PATCH
#if INSTANT_PATCH
static int instant = 0;                     /* -n  option; if 1, selects matching item without the need to press enter */
#endif // INSTANT_PATCH
#if CENTER_PATCH
/* CONFIG: Centralizado e Largura */
static int center = 1;                      /* MUDADO PARA 1 (Centro) */
static int min_width = 600;                 /* MUDADO PARA 600 (Simular width=20 do fuzzel) */
#endif // CENTER_PATCH
#if BARPADDING_PATCH
static const int vertpad = 10;              /* vertical padding of bar */
static const int sidepad = 10;              /* horizontal padding of bar */
#endif // BARPADDING_PATCH
#if QUIET_PATCH
static int quiet = 0;                       /* -q  option; if 1, dmenu will not show any items if the search string is empty */
#endif // QUIET_PATCH
#if RESTRICT_RETURN_PATCH
static int restrict_return = 0;             /* -1 option; if 1, disables shift-return and ctrl-return */
#endif // RESTRICT_RETURN_PATCH
/* -fn option overrides fonts[0]; default X11 font or font set */
#if PANGO_PATCH
static char *font = "JetBrainsMono Nerd Font:size=12";
#else
#if XRESOURCES_PATCH
static char *fonts[] =
#else
static const char *fonts[] =
#endif // XRESOURCES_PATCH
{
	/* CONFIG: Fonte do Fuzzel */
	"JetBrainsMono Nerd Font:size=12"
};
#endif // PANGO_PATCH
#if MANAGED_PATCH
static char *prompt            = NULL;      /* -p  option; prompt to the left of input field */
#else
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
#endif // MANAGED_PATCH
#if DYNAMIC_OPTIONS_PATCH
static const char *dynamic     = NULL;      /* -dy option; dynamic command to run on input change */
#endif // DYNAMIC_OPTIONS_PATCH
#if SYMBOLS_PATCH
static const char *symbol_1 = "<";
static const char *symbol_2 = ">";
#endif // SYMBOLS_PATCH

#if ALPHA_PATCH
static const unsigned int baralpha = 0xff; 
static const unsigned int borderalpha = 0xff; /* Borda levemente transparente */
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	#if BORDER_PATCH
	[SchemeBorder] = { OPAQUE, OPAQUE, OPAQUE },
	#endif // BORDER_PATCH
	#if MORECOLOR_PATCH
	[SchemeMid] = { OPAQUE, baralpha, borderalpha },
	#endif // MORECOLOR_PATCH
	#if HIGHLIGHT_PATCH
	[SchemeSelHighlight] = { OPAQUE, baralpha, borderalpha },
	[SchemeNormHighlight] = { OPAQUE, baralpha, borderalpha },
	#endif // HIGHLIGHT_PATCH
	#if HIGHPRIORITY_PATCH
	[SchemeHp] = { OPAQUE, baralpha, borderalpha },
	#endif // HIGHPRIORITY_PATCH
	#if EMOJI_HIGHLIGHT_PATCH
	[SchemeHover] = { OPAQUE, baralpha, borderalpha },
	[SchemeGreen] = { OPAQUE, baralpha, borderalpha },
	[SchemeRed] = { OPAQUE, baralpha, borderalpha },
	[SchemeYellow] = { OPAQUE, baralpha, borderalpha },
	[SchemeBlue] = { OPAQUE, baralpha, borderalpha },
	[SchemePurple] = { OPAQUE, baralpha, borderalpha },
	#endif // EMOJI_HIGHLIGHT_PATCH
	#if VI_MODE_PATCH
	[SchemeCursor] = { OPAQUE, baralpha, borderalpha },
	#endif // VI_MODE_PATCH
	#if CARET_SCHEME_PATCH
	[SchemeCaret] = { OPAQUE, baralpha, borderalpha },
	#endif // CARET_SCHEME_PATCH
};
#endif // ALPHA_PATCH

static
#if !XRESOURCES_PATCH
const
#endif // XRESOURCES_PATCH
char *colors[][2] = {
	/*               fg         bg       */
	[SchemeNorm] = { "#93a1a1", "#0f0f0f" }, // Normal Text/Bg (base1 Solarized)
	[SchemeSel]  = { "#93a1a1", "#073642" }, // Selected Text/Bg (base02 sutil)
	[SchemeOut]  = { "#0f0f0f", "#2aa198" }, // Output (CIANO!)
	
	#if BORDER_PATCH
	[SchemeBorder] = { "#2aa198", "#2aa198" }, // Border ciano!
	#endif // BORDER_PATCH
	
	#if MORECOLOR_PATCH
	[SchemeMid]  = { "#93a1a1", "#073642" },
	#endif // MORECOLOR_PATCH
	
	#if HIGHLIGHT_PATCH
	/* Match Highlight Colors (CIANO DESTAQUE!) */
	[SchemeSelHighlight]  = { "#2aa198", "#073642" }, // ciano no selecionado
	[SchemeNormHighlight] = { "#268bd2", "#0f0f0f" }, // azul no normal
	#endif // HIGHLIGHT_PATCH
	
	#if HIGHPRIORITY_PATCH
	[SchemeHp]   = { "#fdf6e3", "#2aa198" }, // High priority: ciano!
	#endif // HIGHPRIORITY_PATCH
	
	#if EMOJI_HIGHLIGHT_PATCH
	[SchemeHover]  = { "#fdf6e3", "#073642" },
	[SchemeGreen]  = { "#0f0f0f", "#859900" }, // verde Solarized
	[SchemeRed]    = { "#0f0f0f", "#dc322f" }, // red Solarized
	[SchemeYellow] = { "#0f0f0f", "#b58900" }, // yellow Solarized
	[SchemeBlue]   = { "#0f0f0f", "#268bd2" }, // blue Solarized
	[SchemePurple] = { "#0f0f0f", "#d33682" }, // magenta Solarized
	#endif // EMOJI_HIGHLIGHT_PATCH
	
	#if VI_MODE_PATCH
	[SchemeCursor] = { "#0f0f0f", "#2aa198" }, // cursor ciano!
	#endif // VI_MODE_PATCH
	
	#if CARET_SCHEME_PATCH
	[SchemeCaret] = { "#93a1a1", "#073642" },
	#endif // CARET_SCHEME_PATCH
};
/* CONFIG: Número de linhas */
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 10; 

#if GRID_PATCH
/* -g option; if nonzero, dmenu uses a grid comprised of columns and lines */
static unsigned int columns    = 0;
#endif // GRID_PATCH

#if LINE_HEIGHT_PATCH
/* CONFIG: Altura da linha (Simulando padding vertical) */
static unsigned int lineheight = 28;         /* -h option; minimum height of a menu line */
static unsigned int min_lineheight = 8;
#endif // LINE_HEIGHT_PATCH

#if NAVHISTORY_PATCH
static unsigned int maxhist    = 15;
static int histnodup           = 1;	/* if 0, record repeated histories */
#endif // NAVHISTORY_PATCH

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
#if PIPEOUT_PATCH
static const char startpipe[] = "#";
#endif // PIPEOUT_PATCH
static const char worddelimiters[] = " ";

#if VI_MODE_PATCH
/*
 * -vi option; if nonzero, vi mode is always enabled and can be
 * accessed with the global_esc keysym + mod mask
 */
static unsigned int vi_mode = 1;
static unsigned int start_mode = 0;			/* mode to use when -vi is passed. 0 = insert mode, 1 = normal mode */
static Key global_esc = { XK_n, Mod1Mask };	/* escape key when vi mode is not enabled explicitly */
static Key quit_keys[] = {
	/* keysym	modifier */
	{ XK_q,		0 }
};
#endif // VI_MODE_PATCH

#if BORDER_PATCH
/* CONFIG: Largura da Borda */
static unsigned int border_width = 2;
#endif // BORDER_PATCH

#if PREFIXCOMPLETION_PATCH
/*
 * Use prefix matching by default; can be inverted with the -x flag.
 */
static int use_prefix = 1;
#endif // PREFIXCOMPLETION_PATCH
