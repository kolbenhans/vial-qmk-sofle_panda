# Sofle Panda - Custom Configuration

This repository contains a highly customized QMK firmware for the **Sofle Panda** (6×4+5 keys split ergonomic keyboard). While the default layout is pre-configured for German QWERTZ, the main focus of this build is the **full Vial integration** and advanced visual feedback.

# 🚀 Sofle Panda - Build Information

> [!IMPORTANT]
> This firmware build uses a custom integration of **Vial-QMK** and requires local modifications to the **Vial-GUI** to unlock all hardware-defined lighting features.

## 🛠 Firmware Base
- **Source:** [vial-kb/vial-qmk](https://github.com/vial-kb/vial-qmk) 
- **Branch:** `merge-2025-12-28`
- **Patches:** Manually integrated [Pull Request #657](https://github.com/vial-kb/vial-qmk/pull/657) (plus the *Starlight Smooth* addition on top).

### Why this branch?
The `merge-2025-12-28` branch was chosen because it includes advanced RGB Matrix animations from qmk that are not yet available in the standard Vial/QMK branches. The following animation files are integrated and functional in this build:
* `flower_blooming_anim.h`
* `pixel_flow_anim.h`
* `riverflow_anim.h`
* `starlight_anim.h`
* `starlight_dual_hue_anim.h`
* `starlight_dual_sat_anim.h`
* `starlight_smooth_anim.h`

## 🌈 Extended RGB Support (Vial-GUI)
To make these effects selectable in the Vial-GUI dropdown menu, the software must be executed locally or compiled to a AppImage from source with the following additions in `src/main/python/editor/rgb_configurator.py`:d

```python
# Add these lines to the VIALRGB_EFFECTS list:
VialRGBEffect(45, "Pixel Flow"),
VialRGBEffect(46, "Flower Blooming"),
VialRGBEffect(47, "Starlight"),
VialRGBEffect(48, "Starlight Smooth"),
VialRGBEffect(49, "Starlight Hue"),
VialRGBEffect(50, "Starlight Sat"),
```
## A updated Vial.AppImage can be found in extended Vial appimage folder

## Key Features

* **Vial Support:** Full compatibility with the [Vial firmware](https://get.vial.today/). Change your keymap, macros, and encoders in real-time without re-flashing.
* **Advanced OLED Logic:** Integrated support for multiple animations, including *Soundmonster*, *Luna*, *BongoCat*, and a custom *Panda* animation.
* **Dynamic RGB Indicators:** Smart per-key lighting that changes based on the active layer to provide instant visual feedback.
* **Dual Encoder Support:** Pre-configured for volume control, media skipping, and RGB adjustments, all customizable via Vial.
* **Default Layout:** Optimized base layer with easy symbol access on the Raise layer.

## Hardware Supported

* **PCBs:** Sofle Panda (Split)
* **Controllers:** RP2040-based controllers (e.g., Pro Micro RP2040)
* **Peripherals:** 2x SSD1306 OLED Displays (128x32), EC11 Rotary Encoders, Per-key RGB & Underglow.

---

## Build Instructions

If you want to modify the source code or the advanced RGB logic, use the following commands after setting up your [QMK environment](https://docs.qmk.fm/#/getting_started_build_tools):

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

The core logic resides in keymaps/vial/keymap.c. While the keymap itself is flexible via Vial, the LED behavior is hard-coded for maximum performance and specific visual cues.

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
