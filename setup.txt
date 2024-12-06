# Quick Reference

## getting started guide

https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/linux-macos-setup.html

## Install and Setup

`sudo apt-get install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0`

Next we need to install the esp-idf repo

```bash
mkdir -p ~/esp
cd ~/esp
git clone -b v5.2.3 --recursive https://github.com/espressif/esp-idf.git
```

After that is complete we need to install the tools we want

This is for esp32

```bash
cd ~/esp/esp-idf
./install.sh esp32
```

This is for all esp32 variants

```bash
cd ~/esp/esp-idf
./install.sh all
```

Next we need to add the environment variables to our bashrc

```bash
alias get_idf='. $HOME/esp/esp-idf/export.sh'
```

## Commands

Creating a project
`idf.py create-project -p . <NAME>`

setting target
`idf.py set-target esp32`

setting up board through IDF menu
`idf.py menuconfig`

Building project
`idf.py build`

Flashing to board
`idf.py -p <PORT> flash`

You can also leave off the port and it will try to determine which port is the correct one.

Monitor connection
`idf.py -p <PORT> monitor`

again you can leave off port and it will find it.

*Exit monitor mode with `ctrl+]`*

## Board Support Packages

You can add libraries to your project as well.
Here is an example of esp_wrover_kit

`idf.py add-dependency esp_wrover_kit`


