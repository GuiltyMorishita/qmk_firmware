# ErgoDox EZ void-rift Keymap

## Build

From the repository root:

```sh
env PATH="/opt/homebrew/opt/avr-gcc@8/bin:/opt/homebrew/opt/avr-binutils/bin:$PATH" make QMK_BIN=./tmp/qmk ergodox_ez:void-rift
```

The firmware is written to:

```text
.build/ergodox_ez_void-rift.hex
```

## Flash

```sh
/opt/homebrew/bin/teensy_loader_cli -mmcu=atmega32u4 -w -v .build/ergodox_ez_void-rift.hex
```

When `Waiting for Teensy device...` appears, press the ErgoDox EZ reset button.

## One-Time Setup

If `./tmp/qmk` or `tmp/vendor` is missing, recreate the local QMK CLI wrapper:

```sh
/usr/bin/python3 -m pip install --target tmp/vendor -r requirements.txt
cat > tmp/qmk <<'EOF'
#!/usr/bin/python3
import os
import sys
from pathlib import Path

root = Path(__file__).resolve().parents[1]
os.environ.setdefault("ORIG_CWD", os.getcwd())
sys.path.insert(0, str(root / "tmp" / "vendor"))
sys.path.insert(0, str(root / "lib" / "python"))

import qmk.cli
from milc import cli

cli()
EOF
chmod +x tmp/qmk
```

If AVR/Teensy tools are missing:

```sh
brew tap qmk/qmk
brew tap osx-cross/arm
brew tap osx-cross/avr
brew install qmk/qmk/qmk teensy_loader_cli
```
