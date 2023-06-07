// -*- mode: c++ -*-
// Snowkeep's Handsdown Gold Implementation
// Based on: Copyright 2016-2022 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 100's firmware
 */

// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for storing the keymap in EEPROM
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-FirmwareVersion.h"

#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-LEDEffect-BootGreeting.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include "Kaleidoscope-LEDEffect-Breathe.h"
#include "Kaleidoscope-LEDEffect-Chase.h"
#include "Kaleidoscope-LEDEffect-DigitalRain.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-LED-AlphaSquare.h"
#include "Kaleidoscope-LED-Palette-Theme.h"
#include "Kaleidoscope-Colormap.h"
#include "Kaleidoscope-IdleLEDs.h"
#include "Kaleidoscope-DefaultLEDModeConfig.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-HardwareTestMode.h"
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"
#include "Kaleidoscope-USB-Quirks.h"
#include "Kaleidoscope-LayerNames.h"

#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-CharShift.h"
#include "Kaleidoscope-Chord.h"

enum {
  MACRO_VERSION_INFO,
  MACRO_BRACES,
  MACRO_UPDIR,
  MACRO_SHBANG,
  MACRO_QU,
  MACRO_SH,
  MACRO_PH,
  MACRO_TH,
  MACRO_CH,
  MACRO_GH,
  MACRO_WH,
  MACRO_P4,
  MACRO_LBUP,
  MACRO_LBDN
};



enum {
  PRIMARY,
  SYM,
  NAV,
  FUNC,
};  // layers



// bunch of shift shortcuts
#define K_LCBR   Key_LeftCurlyBracket
#define K_RCBR   Key_RightCurlyBracket
#define K_Colon  LSHIFT(Key_Semicolon)
#define K_Pipe   LSHIFT(Key_Backslash)
#define K_Tild   LSHIFT(Key_Backtick)
#define K_LT     LSHIFT(Key_Comma)
#define K_Plus   LSHIFT(Key_Equals)
#define K_Unds   LSHIFT(Key_Minus)
#define K_GT     LSHIFT(Key_Period)
#define K_DQuot  LSHIFT(Key_Quote)
#define K_Ques   LSHIFT(Key_Slash)
#define K_Exlm   LSHIFT(Key_1)
#define K_At     LSHIFT(Key_2)
#define K_Hash   LSHIFT(Key_3)
#define K_Dolr   LSHIFT(Key_4)
#define K_Perc   LSHIFT(Key_5)
#define K_Circ   LSHIFT(Key_6)
#define K_Ampr   LSHIFT(Key_7)
#define K_Astr   LSHIFT(Key_8)
#define K_LParen LSHIFT(Key_9)
#define K_RParen LSHIFT(Key_0)


/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// clang-format off

KEYMAPS(

  // Edit this keymap to make a custom layout
  [PRIMARY] = KEYMAP_STACKED
  (Key_Backtick, Key_9, Key_3, Key_1, Key_5, Key_7, Key_LeftBracket,
   Key_Tab,      Key_J, Key_G, Key_M, Key_P, Key_V, CS(7),
   Key_Escape,   Key_R, Key_S, Key_N, Key_D, Key_B,
   Key_Delete,   Key_X, Key_F, Key_L, Key_C, Key_W, K_LCBR,
   Key_LeftShift, Key_Enter, Key_Spacebar, Key_Home,
   ShiftToLayer(NAV),

   Key_RightBracket, Key_6, Key_2, Key_0, Key_4, Key_8, Key_Backspace,
   CS(8),            CS(0), CS(1), CS(2), CS(3), CS(4), Key_Q,
                     CS(6), Key_A, Key_E, Key_I, Key_H, Key_Z,
   K_RCBR,           CS(5), Key_U, Key_O, Key_Y, Key_K, M(MACRO_BRACES),
   Key_End, Key_T, ___, ShiftToLayer(FUNC),
   ShiftToLayer(SYM)),

  [SYM] =  KEYMAP_STACKED
  (XXX,           Key_LEDEffectNext, ___,       ___,    ___,           ___,            Key_CapsLock,
   M(MACRO_LBUP), Key_Backtick,     K_LT,      K_GT,   K_DQuot,       Key_Period,     ___,
   M(MACRO_LBDN), K_Exlm,           Key_Minus, K_Plus, Key_Equals,    K_Hash,
   ___,           K_Circ,           Key_Slash, K_Astr, Key_Backslash, M(MACRO_UPDIR), ___,
   ___, ___, ___, ___,
   ___,

   M(MACRO_VERSION_INFO),  ___,    ___,     ___,             ___,              ___,    Key_Pause,
   ___,                    K_Ampr, K_Unds,  Key_LeftBracket, Key_RightBracket, K_Perc, XXX,
                           K_Pipe, K_Colon, K_LParen,        K_RParen,         K_Ques, XXX,
   ___,                    K_Tild, K_Dolr,  K_LCBR,          K_RCBR,           K_At,   XXX,
   ___, ___, ___, ___,
   ___),

  [NAV] =  KEYMAP_STACKED
  (K_Tild, K_Exlm, K_At,          K_Hash,        K_Dolr,         K_Perc,       Key_CapsLock,
   ___,    XXX,    Key_Home,      Key_UpArrow,   Key_End,        Key_PageUp,   XXX,
   ___,    XXX,    Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_PageDown,
   ___,    XXX,    XXX,           XXX,           XXX,            XXX,          XXX,
   ___, ___, ___, ___,
   ___,

   ___, K_Circ, K_Ampr, K_Astr, K_LParen, K_RParen,   ___,
   ___, XXX,    Key_7,  Key_8,  Key_9,    Key_Minus,  Key_RightBracket,
        XXX,    Key_4,  Key_5,  Key_6,    K_Plus,     ___,
   ___, XXX,    Key_1,  Key_2,  Key_3,    Key_Equals, ___,
   ___, XXX, Key_0, Key_Period,
   ___), 

  [FUNC] =  KEYMAP_STACKED
  (Key_F12, Key_F1, Key_F2,          Key_F3,                   Key_F4,               Key_F5, ___,
   XXX,     XXX,    Consumer_Rewind, Consumer_VolumeIncrement, Consumer_FastForward, XXX,    ___,
   XXX,     XXX,    Consumer_Play,   Consumer_VolumeDecrement, XXX,                  XXX,
   XXX,     XXX,    Consumer_Stop,   Consumer_Mute,            XXX,                  XXX,    ___,
   ___, ___, ___, ___,
   ___,

   ___, Key_F6, Key_F7, Key_F8, Key_F9,  Key_F10, Key_F11,
   ___, XXX,    Key_F7, Key_F8, Key_F9,  Key_F10, XXX,
        XXX,    Key_F4, Key_F5, Key_F6,  Key_F11, XXX,
   ___, XXX,    Key_F1, Key_F2, Key_F3,  Key_F12, XXX,
   ___, XXX, ___, ___,
   ___)
) // KEYMAPS(

/* Re-enable astyle's indent enforcement */
// clang-format on

namespace kaleidoscope {
  namespace plugin {

    class ModBlocker : public Plugin {
      public:
        EventHandlerResult onAddToReport(Key key) {
          if (active_ && key.isKeyboardShift())
            return EventHandlerResult::ABORT;
          return EventHandlerResult::OK;
        }

        void enable() {
          active_ = true;
        }
        void disable() {
          active_ = false;
        }

      private:
        bool active_{false};
    };
  }
}

kaleidoscope::plugin::ModBlocker ModBlocker;


static void versionInfoMacro(uint8_t key_state) {
  if (keyToggledOn(key_state)) {
    Macros.type(PSTR("Keyboardio Model 100 - Firmware version "));
    Macros.type(PSTR(KALEIDOSCOPE_FIRMWARE_VERSION));
  }
}



const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  switch (macro_id) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(event.state);
    break;

  case MACRO_BRACES:
    if (keyToggledOn(event.state)) {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftAlt)) {
        Macros.tap(K_LParen);
        Macros.tap(K_RParen);
      }
      else if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftControl)) {
        Macros.tap(K_LT);
        Macros.tap(K_GT);
      }
      else {
        // this handles shift too
        Macros.tap(Key_LeftBracket);
        Macros.tap(Key_RightBracket);
      }
      ModBlocker.enable();
      Macros.tap(Key_LeftArrow);
      ModBlocker.disable();
      return MACRO_NONE;
    }
    break;

  case MACRO_UPDIR:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("../"));
    }
    break;

  case MACRO_SHBANG:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("#!"));
    }
    break;

  case MACRO_QU:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("qu"));
    }
    break;

  case MACRO_SH:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("sh"));
    }
    break;

  case MACRO_PH:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("ph"));
    }
    break;

  case MACRO_TH:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("th"));
    }
    break;

  case MACRO_CH:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("ch"));
    }
    break;    
  
   case MACRO_GH:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("gh"));
    }
    break;

   case MACRO_WH:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("wh"));
    }
    break;

   case MACRO_P4:
    if (keyToggledOn(event.state)) {
      return Macros.type(PSTR("p4"));
    }
    break;

  case MACRO_LBDN:
    if (keyToggledOn(event.state)) {
      uint8_t brightness = LEDControl.getBrightness();
      if (brightness > 10)
        brightness -= 10;
      else
        brightness = 0;

      LEDControl.setBrightness(brightness);
    }
    break;

  case MACRO_LBUP:
    if (keyToggledOn(event.state)) {
      uint8_t brightness = LEDControl.getBrightness();
      if (brightness < 245)
        brightness += 10;
      else
        brightness = 255;

      LEDControl.setBrightness(brightness);
    }
    break;


  }
  return MACRO_NONE;
}



// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 100.


static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.enable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}


 /* These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE,
  // Enter test mode
  COMBO_ENTER_TEST_MODE
};

/** Wrappers, to be used by MagicCombo. **/

/**
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/**
 * Toggles between using the built-in keymap, and the EEPROM-stored one.
 */
static void toggleKeymapSource(uint8_t combo_index) {
  if (Layer.getKey == Layer.getKeyFromPROGMEM) {
    Layer.getKey = EEPROMKeymap.getKey;
  } else {
    Layer.getKey = Layer.getKeyFromPROGMEM;
  }
}

/**
 *  This enters the hardware test mode
 */
static void enterHardwareTestMode(uint8_t combo_index) {
  HardwareTestMode.runTests();
}


/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = {R3C6, R2C6, R3C7}},
                 {.action = enterHardwareTestMode,
                  // Left Fn + Prog + LED
                  .keys = {R3C6, R0C0, R0C6}},
                 {.action = toggleKeymapSource,
                  // Left Fn + Prog + Shift
                  .keys = {R3C6, R0C0, R3C7}});

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(

  EEPROMSettings,
  EEPROMKeymap,

  Focus,
  FocusSettingsCommand,
  FocusEEPROMCommand,

  BootGreetingEffect,
  HardwareTestMode,
  LEDControl,
  LEDOff,
  LEDRainbowEffect,
  LEDRainbowWaveEffect,
  LEDChaseEffect,
  LEDDigitalRainEffect,
  solidRed,
  solidOrange,
  solidYellow,
  solidGreen,
  solidBlue,
  solidIndigo,
  solidViolet,
  LEDBreatheEffect,
  AlphaSquareEffect,
  StalkerEffect,
  LEDPaletteTheme,
  ColormapEffect,
  Macros,
  HostPowerManagement,
  MagicCombo,
  USBQuirks,
  Qukeys,
  IdleLEDs,
  PersistentIdleLEDs,
  FirmwareVersion,
  LayerNames,
  DefaultLEDModeConfig,
  CharShift,
  Chord
);


void setup() {

  Kaleidoscope.setup();

  BootGreetingEffect.hue = 85;

  AlphaSquare.color = CRGB(255, 0, 0);

  LEDRainbowEffect.brightness(255);
  LEDRainbowWaveEffect.brightness(255);

  HardwareTestMode.setActionKey(R3C6);

  StalkerEffect.variant = STALKER(BlazingTrail);

  EEPROMKeymap.setup(8);

  ColormapEffect.max_layers(8);

  Layer.move(EEPROMSettings.default_layer());

  LayerNames.reserve_storage(17 * 8);

  DefaultLEDModeConfig.activateLEDModeIfUnconfigured(&LEDOff);

  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 1), Key_LeftGui),       // R/cmd
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 2), Key_LeftAlt),       // S/alt
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 3), Key_LeftControl),   // N/ctrl
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 4), Key_LeftShift),     // D/shift
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 11), Key_RightShift),   // A/shift
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 12), Key_RightControl), // E/ctrl
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 13), Key_RightAlt),     // I/alt
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 14), Key_RightGui),     // H/cmd
  )
  Qukeys.setHoldTimeout(1000);
  Qukeys.setOverlapThreshold(50);
  Qukeys.setMinimumHoldTime(200);
  Qukeys.setMinimumPriorInterval(80);
  Qukeys.setMaxIntervalForTapRepeat(150);

  CS_KEYS(
    kaleidoscope::plugin::CharShift::KeyPair(K_Colon, Key_Semicolon),  // 0
    kaleidoscope::plugin::CharShift::KeyPair(Key_Period, K_Ampr),	// 1
    kaleidoscope::plugin::CharShift::KeyPair(Key_Slash, K_Astr),	// 2
    kaleidoscope::plugin::CharShift::KeyPair(K_DQuot, K_Ques),		// 3
    kaleidoscope::plugin::CharShift::KeyPair(Key_Quote, K_Exlm),	// 4
    kaleidoscope::plugin::CharShift::KeyPair(Key_Minus, K_Plus),	// 5
    kaleidoscope::plugin::CharShift::KeyPair(Key_Comma, K_Pipe), 	// 6
    kaleidoscope::plugin::CharShift::KeyPair(K_LParen, K_LT),     // 7
    kaleidoscope::plugin::CharShift::KeyPair(K_RParen, K_GT),     // 8
  );

  CHORDS(
    CHORD(Key_U, Key_Y), Key_Q,
    CHORD(Key_U, Key_K), M(MACRO_QU),
    CHORD(Key_S, Key_N), M(MACRO_SH),
    CHORD(Key_P, Key_M), M(MACRO_PH),
    CHORD(CS(1), CS(2)), M(MACRO_UPDIR),
    CHORD(Key_3, Key_1), M(MACRO_SHBANG),
    CHORD(Key_E, Key_I), K_Unds,
    CHORD(Key_J, Key_G), Key_Z,
    CHORD(Key_D, Key_N), M(MACRO_TH),
    CHORD(Key_C, Key_L), M(MACRO_CH),
    CHORD(Key_G, Key_M), M(MACRO_GH),
    CHORD(Key_W, Key_C), M(MACRO_WH),
    CHORD(Key_P, Key_G), M(MACRO_P4)
  )
}


void loop() {
  Kaleidoscope.loop();
}
