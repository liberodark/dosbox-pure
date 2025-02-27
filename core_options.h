/*
 *  Copyright (C) 2020-2021 Bernhard Schelling
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

static retro_core_option_v2_category option_cats[] =
{
	{ "Input",       "Input Options",       "Keyboard, mouse and joystick settings." },
	{ "Performance", "Performance Options", "Adjust the performance of the emulated CPU." },
	{ "Video",       "Video Options",       "Settings for the emulated graphics card and aspect ratio." },
	{ "System",      "System Options",      "Other system settings for RAM, CPU type and start menu behavior." },
	{ "Audio",       "Audio Options",       "MIDI, SoundBlaster and other audio settings." },
	{ NULL, NULL, NULL }
};

static retro_core_option_v2_definition option_defs[] =
{
	{
		"dosbox_pure_advanced",
		"Show Advanced Options", NULL,
		"Close and re-open the menu to refresh this options page.", NULL,
		NULL,
		{ { "false", "Off" }, { "true", "On" } },
		"false"
	},
	{
		"dosbox_pure_savestate",
		"Save States Support", NULL,
		"Make sure to test it in each game before using it. Complex late era DOS games might have problems." "\n"
		"Be aware that states saved with different video, CPU or memory settings are not loadable." "\n"
		"Rewind support comes at a high performance cost, setting it requires a full core restart." "\n"
		"Save states might not be compatible with new versions of this core." "\n\n", NULL, //end of top section
		NULL,
		{
			{ "on",       "Enable save states" },
			{ "rewind",   "Enable save states with rewind" },
			{ "disabled", "Disabled" },
		},
		"on"
	},

	// Input
	{
		"dosbox_pure_bind_unused",
		"Bind Unused Buttons", NULL,
		"Bind all unused controller buttons to keyboard keys.\nCan be remapped in the Controls section of the core settings.", NULL,
		"Input",
		{ { "true", "On" }, { "false", "Off" } },
		"true"
	},
	{
		"dosbox_pure_on_screen_keyboard",
		"Enable On Screen Keyboard", NULL,
		"Enable the On Screen Keyboard feature which can be activated with the L3 button on the controller.", NULL,
		"Input",
		{ { "true", "On" }, { "false", "Off" } },
		"true"
	},
	{
		"dosbox_pure_mouse_wheel",
		"Bind Mouse Wheel To Key", NULL,
		"Bind mouse wheel up and down to two keyboard keys to be able to use it in DOS games.", NULL,
		"Input",
		{
			{ "67/68", "Left-Bracket/Right-Bracket" },
			{ "72/71", "Comma/Period" },
			{ "79/82", "Page-Up/Page-Down" },
			{ "78/81", "Home/End" },
			{ "80/82", "Delete/Page-Down" },
			{ "64/65", "Minus/Equals" },
			{ "69/70", "Semicolon/Quote" },
			{ "99/100", "Numpad Minus/Plus" },
			{ "97/98", "Numpad Divide/Multiply" },
			{ "84/85", "Up/Down" },
			{ "83/86", "Left/Right" },
			{ "11/13", "Q/E" },
			{ "none", "Disable" },
		},
		"67/68"
	},
	{
		"dosbox_pure_mouse_speed_factor",
		"Mouse Sensitivity", NULL,
		"Sets the overall mouse cursor movement speed." "\n\n", NULL, //end of Input section
		"Input",
		{
			{ "0.2",  "20%" }, { "0.25",  "25%" }, { "0.3",  "30%" }, { "0.35",  "35%" }, { "0.4",  "40%" }, { "0.45",  "45%" },
			{ "0.5",  "50%" }, { "0.55",  "55%" }, { "0.6",  "60%" }, { "0.65",  "65%" }, { "0.7",  "70%" }, { "0.75",  "75%" },
			{ "0.8",  "80%" }, { "0.85",  "85%" }, { "0.9",  "90%" }, { "0.95",  "95%" }, { "1.0", "100%" }, { "1.1" , "110%" },
			{ "1.2", "120%" }, { "1.3" , "130%" }, { "1.4", "140%" }, { "1.5" , "150%" }, { "1.6", "160%" }, { "1.7" , "170%" },
			{ "1.8", "180%" }, { "1.9" , "190%" }, { "2.0", "200%" }, { "2.2" , "220%" }, { "2.4", "240%" }, { "2.6" , "260%" },
			{ "2.8", "280%" }, { "3.0" , "300%" }, { "3.2", "320%" }, { "3.4" , "340%" }, { "3.6", "360%" }, { "3.8" , "380%" },
			{ "4.0", "400%" }, { "4.2" , "420%" }, { "4.4", "440%" }, { "4.6",  "460%" }, { "4.8", "480%" }, { "5.0",  "500%" },
		},
		"1.0"
	},
	{
		"dosbox_pure_mouse_speed_factor_x",
		"Advanced > Horizontal Mouse Sensitivity.", NULL,
		"Experiment with this value if the mouse is too fast/slow when moving left/right.", NULL,
		"Input",
		{
			{ "0.2",  "20%" }, { "0.25",  "25%" }, { "0.3",  "30%" }, { "0.35",  "35%" }, { "0.4",  "40%" }, { "0.45",  "45%" },
			{ "0.5",  "50%" }, { "0.55",  "55%" }, { "0.6",  "60%" }, { "0.65",  "65%" }, { "0.7",  "70%" }, { "0.75",  "75%" },
			{ "0.8",  "80%" }, { "0.85",  "85%" }, { "0.9",  "90%" }, { "0.95",  "95%" }, { "1.0", "100%" }, { "1.1" , "110%" },
			{ "1.2", "120%" }, { "1.3" , "130%" }, { "1.4", "140%" }, { "1.5" , "150%" }, { "1.6", "160%" }, { "1.7" , "170%" },
			{ "1.8", "180%" }, { "1.9" , "190%" }, { "2.0", "200%" }, { "2.2" , "220%" }, { "2.4", "240%" }, { "2.6" , "260%" },
			{ "2.8", "280%" }, { "3.0" , "300%" }, { "3.2", "320%" }, { "3.4" , "340%" }, { "3.6", "360%" }, { "3.8" , "380%" },
			{ "4.0", "400%" }, { "4.2" , "420%" }, { "4.4", "440%" }, { "4.6",  "460%" }, { "4.8", "480%" }, { "5.0",  "500%" },
		},
		"1.0"
	},
	{
		"dosbox_pure_mouse_input",
		"Advanced > Use Mouse Input", NULL,
		"You can disable input handling from a mouse or a touchscreen (emulated mouse through joypad will still work).", NULL,
		"Input",
		{ { "true", "On (default)" }, { "false", "Off" } },
		"true"
	},
	{
		"dosbox_pure_auto_mapping",
		"Advanced > Automatic Game Pad Mappings", NULL,
		"DOSBox Pure can automatically apply a gamepad control mapping scheme when it detects a game." "\n"
		"These button mappings are provided by the Keyb2Joypad Project (by Jemy Murphy and bigjim).", NULL,
		"Input",
		{ { "true", "On (default)" }, { "notify", "Enable with notification on game detection" }, { "false", "Off" } },
		"true"
	},
	{
		"dosbox_pure_keyboard_layout",
		"Advanced > Keyboard Layout", NULL,
		"Select the keyboard layout (will not change the On Screen Keyboard).", NULL,
		"Input",
		{
			{ "us",    "US (default)" },
			{ "uk",    "UK" },
			{ "be",    "Belgium" },
			{ "br",    "Brazil" },
			{ "hr",    "Croatia" },
			{ "cz243", "Czech Republic" },
			{ "dk",    "Denmark" },
			{ "su",    "Finland" },
			{ "fr",    "France" },
			{ "gr",    "Germany" },
			{ "gk",    "Greece" },
			{ "hu",    "Hungary" },
			{ "is161", "Iceland" },
			{ "it",    "Italy" },
			{ "nl",    "Netherlands" },
			{ "no",    "Norway" },
			{ "pl",    "Poland" },
			{ "po",    "Portugal" },
			{ "ru",    "Russia" },
			{ "sk",    "Slovakia" },
			{ "si",    "Slovenia" },
			{ "sp",    "Spain" },
			{ "sv",    "Sweden" },
			{ "sg",    "Switzerland (German)" },
			{ "sf",    "Switzerland (French)" },
			{ "tr",    "Turkey" },
		},
		"us"
	},
	{
		"dosbox_pure_joystick_analog_deadzone",
		"Advanced > Joystick Analog Deadzone", NULL,
		"Set the deadzone of the joystick analog sticks. May be used to eliminate drift caused by poorly calibrated joystick hardware.", NULL,
		"Input",
		{
			{ "0",  "0%" }, { "5",  "5%" }, { "10", "10%" }, { "15", "15%" }, { "20", "20%" }, { "25", "25%" }, { "30", "30%" }, { "35", "35%" }, { "40", "40%" },
		},
		"15"
	},
	{
		"dosbox_pure_joystick_timed",
		"Advanced > Enable Joystick Timed Intervals", NULL,
		"Enable timed intervals for joystick axes. Experiment with this option if your joystick drifts." "\n\n", NULL, //end of Input > Advanced section
		"Input",
		{ { "true", "On (default)" }, { "false", "Off" } },
		"true"
	},

	// Performance
	{
		"dosbox_pure_cycles",
		"Emulated Performance", NULL,
		"The raw performance that DOSBox will try to emulate." "\n\n", NULL, //end of Performance section
		"Performance",
		{
			{ "auto",    "AUTO - DOSBox will try to detect performance needs (default)" },
			{ "max",     "MAX - Emulate as many instructions as possible" },
			{ "315",     "8086/8088, 4.77 MHz from 1980 (315 cps)" },
			{ "1320",    "286, 6 MHz from 1982 (1320 cps)" },
			{ "2750",    "286, 12.5 MHz from 1985 (2750 cps)" },
			{ "4720",    "386, 20 MHz from 1987 (4720 cps)" },
			{ "7800",    "386DX, 33 MHz from 1989 (7800 cps)" },
			{ "13400",   "486DX, 33 MHz from 1990 (13400 cps)" },
			{ "26800",   "486DX2, 66 MHz from 1992 (26800 cps)" },
			{ "77000",   "Pentium, 100 MHz from 1995 (77000 cps)" },
			{ "200000",  "Pentium II, 300 MHz from 1997 (200000 cps)" },
			{ "500000",  "Pentium III, 600 MHz from 1999 (500000 cps)" },
			{ "1000000", "AMD Athlon, 1.2 GHz from 2000 (1000000 cps)" },
		},
		"auto"
	},
	{
		"dosbox_pure_cycles_scale",
		"Detailed > Performance Scale", NULL,
		"Fine tune the emulated performance for specific needs." "\n\n", NULL, //end of Performance > Detailed section
		"Performance",
		{
			{ "0.2",  "20%" }, { "0.25",  "25%" }, { "0.3",  "30%" }, { "0.35",  "35%" }, { "0.4",  "40%" }, { "0.45",  "45%" },
			{ "0.5",  "50%" }, { "0.55",  "55%" }, { "0.6",  "60%" }, { "0.65",  "65%" }, { "0.7",  "70%" }, { "0.75",  "75%" },
			{ "0.8",  "80%" }, { "0.85",  "85%" }, { "0.9",  "90%" }, { "0.95",  "95%" }, { "1.0", "100%" }, { "1.05", "105%" },
			{ "1.1", "110%" }, { "1.15", "115%" }, { "1.2", "120%" }, { "1.25", "125%" }, { "1.3", "130%" }, { "1.35", "135%" },
			{ "1.4", "140%" }, { "1.45", "145%" }, { "1.5", "150%" }, { "1.55", "155%" }, { "1.6", "160%" }, { "1.65", "165%" },
			{ "1.7", "170%" }, { "1.75", "175%" }, { "1.8", "180%" }, { "1.85", "185%" }, { "1.9", "190%" }, { "1.95", "195%" },
			{ "2.0", "200%" },
		},
		"1.0",
	},

	// Video
	{
		"dosbox_pure_machine",
		"Emulated Graphics Chip (restart required)", NULL,
		"The type of graphics chip that DOSBox will emulate.", NULL,
		"Video",
		{
			{ "svga",     "SVGA (Super Video Graphics Array) (default)" },
			{ "vga",      "VGA (Video Graphics Array)" },
			{ "ega",      "EGA (Enhanced Graphics Adapter" },
			{ "cga",      "CGA (Color Graphics Adapter)" },
			{ "tandy",    "Tandy (Tandy Graphics Adapter" },
			{ "hercules", "Hercules (Hercules Graphics Card)" },
			{ "pcjr",     "PCjr" },
		},
		"svga"
	},
	{
		"dosbox_pure_cga",
		"CGA Mode", NULL,
		"The CGA variation that is being emulated.", NULL,
		"Video",
		{
			{ "early_auto", "Early model, composite mode auto (default)" },
			{ "early_on",   "Early model, composite mode on" },
			{ "early_off",  "Early model, composite mode off" },
			{ "late_auto", "Late model, composite mode auto" },
			{ "late_on",   "Late model, composite mode on" },
			{ "late_off",  "Late model, composite mode off" },
		},
		"early_auto"
	},
	{
		"dosbox_pure_hercules",
		"Hercules Color Mode", NULL,
		"The color scheme for Hercules emulation.", NULL,
		"Video",
		{
			{ "white", "Black & white (default)" },
			{ "amber", "Black & amber" },
			{ "green", "Black & green" },
		},
		"white"
	},
	{
		"dosbox_pure_svga",
		"SVGA Mode (restart required)", NULL,
		"The SVGA variation that is being emulated. Try changing this if you encounter graphical glitches.", NULL,
		"Video",
		{
			{ "svga_s3",       "S3 Trio64 (default)" },
			{ "vesa_nolfb",    "S3 Trio64 no-line buffer hack (reduces flickering in some games)" },
			{ "vesa_oldvbe",   "S3 Trio64 VESA 1.3" },
			{ "svga_et3000",   "Tseng Labs ET3000" },
			{ "svga_et4000",   "Tseng Labs ET4000" },
			{ "svga_paradise", "Paradise PVGA1A" },
		},
		"s3"
	},
	{
		"dosbox_pure_aspect_correction",
		"Aspect Ratio Correction", NULL,
		"When enabled, the core's aspect ratio is set to what a CRT monitor would display." "\n\n", NULL, //end of Video section
		"Video",
		{ { "false", "Off (default)" }, { "true", "On" } },
		"false"
	},

	// System
	{
		"dosbox_pure_memory_size",
		"Memory Size (restart required)", NULL,
		"The amount of (high) memory that the emulated machine has. You can also disable extended memory (EMS/XMS)." "\n"
		"Using more than the default is not recommended, due to incompatibility with certain games and applications.", NULL,
		"System",
		{
			{ "none", "Disable extended memory (no EMS/XMS)" },
			{ "4",  "4 MB" },
			{ "8",  "8 MB" },
			{ "16", "16 MB (default)" },
			{ "24", "24 MB" },
			{ "32", "32 MB (unsafe)" },
			{ "48", "48 MB (unsafe)" },
			{ "64", "64 MB (unsafe)" },
			{ "96", "96 MB (unsafe)" },
			{ "128", "128 MB (unsafe)" },
			{ "224", "224 MB (unsafe)" },
		},
		"16"
	},
	{
		"dosbox_pure_cpu_type",
		"CPU Type (restart required)", NULL,
		"Emulated CPU type. Auto is the fastest choice." "\n"
			"Games that require specific CPU type selection:" "\n"
			"386 (prefetch): X-Men: Madness in The Murderworld, Terminator 1, Contra, Fifa International Soccer 1994" "\n"
			"486 (slow): Betrayal in Antara" "\n"
			"Pentium (slow): Fifa International Soccer 1994, Windows 95/Windows 3.x games" "\n\n", NULL, //end of System section
		"System",
		{
			{ "auto", "Auto - Mixed feature set with maximum performance and compatibility" },
			{ "386", "386 - 386 instruction with fast memory access" },
			{ "386_slow", "386 (slow) - 386 instruction set with memory privilege checks" },
			{ "386_prefetch", "386 (prefetch) - With prefetch queue emulation (only on 'auto' and 'normal' core)" },
			{ "486_slow", "486 (slow) - 486 instruction set with memory privilege checks" },
			{ "pentium_slow", "Pentium (slow) - 586 instruction set with memory privilege checks" },
		},
		"auto"
	},
	{
		"dosbox_pure_cpu_core",
		"Advanced > CPU Core (restart required)", NULL,
		"Emulation method (DOSBox CPU core) used.", NULL,
		"System",
		{
			#if defined(C_DYNAMIC_X86)
			{ "auto", "Auto - Real-mode games use normal, protected-mode games use dynamic" },
			{ "dynamic", "Dynamic - Dynamic recompilation (fast, using dynamic_x86 implementation)" },
			#elif defined(C_DYNREC)
			{ "auto", "Auto - Real-mode games use normal, protected-mode games use dynamic" },
			{ "dynamic", "Dynamic - Dynamic recompilation (fast, using dynrec implementation)" },
			#endif
			{ "normal", "Normal (interpreter)" },
			{ "simple", "Simple (interpreter optimized for old real-mode games)" },
		},
		#if defined(C_DYNAMIC_X86) || defined(C_DYNREC)
		"auto"
		#else
		"normal"
		#endif
	},
	{
		"dosbox_pure_menu_time",
		"Advanced > Start Menu", NULL,
		"Set the behavior of the start menu before and after launching a game." "\n"
		"You can also force it to open by holding shift or L2/R2 when selecting 'Restart'." "\n\n", NULL, //end of System > Advanced section
		"System",
		{
#ifndef STATIC_LINKING
			{ "5", "Show at start, shut down core 5 seconds after auto started game exit" },
			{ "3", "Show at start, shut down core 3 seconds after auto started game exit" },
			{ "0", "Show at start, shut down core immediately after auto started game exit" },
#else
			{ "5", "Show at start, show again after game exit (default)" },
#endif
			{ "-1", "Always show menu on startup and after game exit, ignore auto start setting" },
		},
		"5"
	},

	// Audio
	{
		"dosbox_pure_audiorate",
		"Audio Sample Rate (restart required)", NULL,
		"This should match the frontend audio output rate (Hz) setting.", NULL,
		"Audio",
		{
			{ "48000", NULL },
			{ "44100", NULL },
			#ifdef _3DS
			{ "32730", NULL },
			#endif
			{ "32000", NULL },
			{ "22050", NULL },
			{ "16000", NULL },
			{ "11025", NULL },
			{  "8000", NULL },
			{ "49716", NULL }, //for perfect OPL emulation
		},
		DBP_DEFAULT_SAMPLERATE_STRING
	},
	{
		"dosbox_pure_sblaster_conf",
		"SoundBlaster Settings", NULL,
		"Set the address, interrupt, low 8-bit and high 16-bit DMA.", NULL,
		"Audio",
		{
			// Some common (and less common) port, irq, low and high dma settings (based on a very scientific web search)
			{ "A220 I7 D1 H5",  "Port 0x220, IRQ 7, 8-Bit DMA 1, 16-bit DMA 5"  },
			{ "A220 I5 D1 H5",  "Port 0x220, IRQ 5, 8-Bit DMA 1, 16-bit DMA 5"  },
			{ "A240 I7 D1 H5",  "Port 0x240, IRQ 7, 8-Bit DMA 1, 16-bit DMA 5"  },
			{ "A240 I7 D3 H7",  "Port 0x240, IRQ 7, 8-Bit DMA 3, 16-bit DMA 7"  },
			{ "A240 I2 D3 H7",  "Port 0x240, IRQ 2, 8-Bit DMA 3, 16-bit DMA 7"  },
			{ "A240 I5 D3 H5",  "Port 0x240, IRQ 5, 8-Bit DMA 3, 16-bit DMA 5"  },
			{ "A240 I5 D1 H5",  "Port 0x240, IRQ 5, 8-Bit DMA 1, 16-bit DMA 5"  },
			{ "A240 I10 D3 H7", "Port 0x240, IRQ 10, 8-Bit DMA 3, 16-bit DMA 7" },
			{ "A280 I10 D0 H6", "Port 0x280, IRQ 10, 8-Bit DMA 0, 16-bit DMA 6" },
			{ "A210 I5 D1 H5",  "Port 0x210, IRQ 5, 8-Bit DMA 1, 16-bit DMA 5"  },
		},
		"A220 I7 D1 H5"
	},
	{
		"dosbox_pure_midi",
		"MIDI Output", NULL,
		"Select the .SF2 SoundFont file, .ROM file or interface used for MIDI output." "\n"
		"To add SoundFonts or ROM files, copy them into the 'system' directory of the frontend." "\n"
		"To use the frontend MIDI driver, make sure it's set up correctly." "\n\n", NULL, //end of Audio section
		"Audio",
		{
			// dynamically filled in retro_init
		},
		"none"
	},
	{
		"dosbox_pure_sblaster_type",
		"Advanced > SoundBlaster Type", NULL,
		"Type of emulated SoundBlaster card.", NULL,
		"Audio",
		{
			{ "sb16", "SoundBlaster 16 (default)" },
			{ "sbpro2", "SoundBlaster Pro 2" },
			{ "sbpro1", "SoundBlaster Pro" },
			{ "sb2", "SoundBlaster 2.0" },
			{ "sb1", "SoundBlaster 1.0" },
			{ "gb", "GameBlaster" },
			{ "none", "none" },
		},
		"sb16"
	},
	{
		"dosbox_pure_sblaster_adlib_mode",
		"Advanced > SoundBlaster Adlib/FM Mode", NULL,
		"The SoundBlaster emulated FM synth mode. All modes are Adlib compatible except CMS.", NULL,
		"Audio",
		{
			{ "auto",     "Auto (select based on the SoundBlaster type) (default)" },
			{ "cms",      "CMS (Creative Music System / GameBlaster)" },
			{ "opl2",     "OPL-2 (AdLib / OPL-2 / Yamaha 3812)" },
			{ "dualopl2", "Dual OPL-2 (Dual OPL-2 used by SoundBlaster Pro 1.0 for stereo sound)" },
			{ "opl3",     "OPL-3 (AdLib / OPL-3 / Yamaha YMF262)" },
			{ "opl3gold", "OPL-3 Gold (AdLib Gold / OPL-3 / Yamaha YMF262)" },
			{ "none",     "Disabled" },
		},
		"auto"
	},
	{
		"dosbox_pure_sblaster_adlib_emu",
		"Advanced > SoundBlaster Adlib Provider", NULL,
		"Provider for the Adlib emulation. Default has good quality and low performance requirements.", NULL,
		"Audio",
		{
			{ "default", "Default" },
			{ "nuked", "High quality Nuked OPL3" },
		},
		"default"
	},
	{
		"dosbox_pure_gus",
		"Advanced > Enable Gravis Ultrasound (restart required)", NULL,
		"Enable Gravis Ultrasound emulation. Settings are fixed at port 0x240, IRQ 5, DMA 3." "\n"
		"If the ULTRADIR variable needs to be different than the default 'C:\\ULTRASND' you need to issue 'SET ULTRADIR=...' in the command line or in a batch file." "\n\n", NULL, //end of Audio > Advanced section
		"Audio",
		{ { "false", "Off (default)" }, { "true", "On" } },
		"false"
	},

	{ NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL }
};
