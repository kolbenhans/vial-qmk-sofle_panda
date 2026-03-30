# Sofle Panda - Custom QWERTZ Configuration

![sofle_panda](https://raw.githubusercontent.com/keycapsss/Panda-Split-Keyboard/main/images/panda_top.jpg)

This repository contains my personal QMK firmware configuration for the **Sofle Panda**, a 6×4+5 keys split ergonomic keyboard. It features a specialized German QWERTZ layout, advanced OLED animations, and dynamic RGB indicator logic.

## Key Features

* **German Layout:** Native QWERTZ support with optimized symbol access on the Raise layer.
* **Dynamic Layers:** * `_QWERTZ`: Base typing layer.
    * `_RAISE`: Symbols, navigation, and F-keys.
    * `_NUMPAD`: Dedicated right-hand Numpad with math operators.
    * `_AMBIENT`: RGB control and media keys.
    * `_GAMING`: Performance mode with specialized key bindings and distinct LED indicators.
* **OLED Logic:** Supports multiple animations including Soundmonster, Luna, BongoCat, and the custom Panda animation.
* **Encoder Support:** Volume control, media skipping, and RGB adjustments via the dual rotary encoders.

## Hardware Supported

* **PCBs:** Sofle Panda (Split)
* **Controllers:** Pro Micro, Elite-C, or Nice!Nano (compatible with QMK)
* **Peripherals:** 2x SSD1306 OLED Displays (128x32), EC11 Rotary Encoders, RGB Underglow/Per-key.

---

## Build Instructions

After setting up your [QMK environment](https://docs.qmk.fm/#/getting_started_build_tools), you can compile and flash this layout:

### Compile
```bash
qmk compile -kb sofle_panda -km vial
```
### Flashing
```bash
qmk flash -kb sofle_panda -km vial
```

---

## Customization & RGB Logic

The file `keymaps/vial/keymap.c` contains highly personalized code, specifically within the `rgb_matrix_indicators_advanced_user` function. 

### Layer-Specific Lighting
The keyboard uses dynamic RGB indicators to visualize the active layer:
* **Layer 1 (Raise):** Purple/Orange/Green/Blue accents.
* **Layer 2 (Numpad):** Highlights the numeric block on the right half in Blue.
* **Layer 4 (Gaming):** Tactical highlights (Orange/Green/Red) for gaming-relevant keys.

> [!IMPORTANT]
> If you want to use this keymap as a template, you should manually adjust or remove the LED IDs in the `switch(layer)` block to match your preferences, as these are mapped to my specific physical switch positions.

---

## Hardware Layout & LED Mapping

If you want to customize the per-key lighting, use the following ID map. These IDs correspond to the physical positions in the `rgb_matrix_indicators_advanced_user` function.

### LED Positions (Physical ID Map)

```text
           LEFT HALF                                  RIGHT HALF                                     
 [11] [12] [21] [22] [31] [32]               [68] [67] [58] [57] [48] [47]
 [10] [13] [20] [23] [30] [33]               [69] [66] [59] [56] [49] [46]
 [09] [14] [19] [24] [29] [34]               [70] [65] [60] [55] [50] [45]
 [08] [15] [18] [25] [28] [35]               [71] [64] [61] [54] [51] [44]
           [07] [16] [17] [26] [27]     [63] [62] [53] [52] [43]
