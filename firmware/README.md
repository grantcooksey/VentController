# Title

## Installation

1. Add the DrAzzy packages to the board manager:
`arduino-cli config add board_manager.additional_urls http://drazzy.com/package_drazzy.com_index.json`

2. You can then install the [ATTinyCore](https://github.com/SpenceKonde/ATTinyCore) core:
`arduino-cli core install ATTinyCore:avr`

3. Insert the USPtinyISP stick and compile and upload the sketch:
`make`
