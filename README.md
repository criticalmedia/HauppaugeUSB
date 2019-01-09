
# Hauppauge HD-PVR2 / Colossus2 recorder

A wrapper around the Hauppauge HDPVR2/Colossus2 Linux "[driver](http://www.hauppauge.com/site/support/linux.html?#tabs-3)"

This is currently beta quality, based on an alpha quality driver.

Uses ffmpeg libraries to output video to various ffmpeg compatible protocols (file, udp, tcp, rtmp, etc)

----
## News
The issue with interlaced fields being in the wrong order has been fixed.

AC3 audio codec now works via HDMI.

----
## Installing

### Install dependancies

#### CentOS:

```
sudo yum install boost148-devel devtoolset-7-gcc-c++ ffmpeg-devel 'libusb1-devel >= 1.0.18'
source /opt/rh/devtoolset-7/enable
```

#### Fedora:
```
sudo dnf install make gcc gcc-c++ kernel-devel libstdc++-devel boost-devel libusbx-devel
```

#### Ubuntu
```
sudo apt-get install libboost-log-dev libboost-program-options-dev libusb-1.0-0-dev build-essential
```

### Build it
```
make
sudo make install
```
----
## Using it

### Permissions

hauppauge2 needs permission to use the device file(s).  Create a udev rules
file.  Something like:

```
nano /etc/udev/rules.d/99-Hauppauge.rules
```
And add appropriate rules:
```
# Device 1
SUBSYSTEMS=="usb",ATTRS{idVendor}=="2040",ATTR{serial}=="E505-00-00AF4321",MODE="0660",GROUP="video",SYMLINK+="hdpvr2_1",TAG+="systemd",RUN="/bin/sh -c 'echo -1 > /sys$devpath/power/autosuspend'"

# Device 2
SUBSYSTEMS=="usb",ATTRS{idVendor}=="2040",ATTR{serial}=="E585-00-00AF1234",MODE="0660",GROUP="video",SYMLINK+="colossus2-1",TAG+="systemd",RUN="/bin/sh -c 'echo -1 > /sys$devpath/power/autosuspend'"
```
At the least, you will need to adjust the serial numer(s) to match your
device(s).  Any user which wants to run hauppauge2 needs to be a member of
the GROUP specified.

### Running it

You can get the optional arguments with
```
/usr/sbin/hauppauge2 --help
```
A lot of the options don't work unless just the right combination is
selected.  The program does not currently protect you from choosing bad
combinations, because in many cases they *should* work, but have not been
implemented yet.

----
### Command line examples

#### List detected devices

```
$ /usr/sbin/hauppauge2 --list
[Bus: 5 Port: 1]  2040:0xe585 E585-00-00AF4321 Colossus 2
Number of possible configurations: 1  Device Class: 0  VendorID: 8256  ProductID: 58757
Manufacturer: Hauppauge
Serial: E585-00-00AF4321
Interfaces: 1 ||| Number of alternate settings: 1 | Interface Number: 0 | Number of endpoints: 6 | Descriptor Type: 5 | EP Address: 129 | Descriptor Type: 5 | EP Address: 132 | Descriptor Type: 5 | EP Address: 136 | Descriptor Type: 5 | EP Address: 1 | Descriptor Type: 5 | EP Address: 2 | Descriptor Type: 5 | EP Address: 134 |


[Bus: 3 Port: 4]  2040:0xe505 E505-00-00AF1234 HD PVR 2 Gaming Edition Plus w/SPDIF w/MIC
Number of possible configurations: 1  Device Class: 0  VendorID: 8256  ProductID: 58629
Manufacturer: Hauppauge
Serial: E505-00-00AF1234
Interfaces: 1 ||| Number of alternate settings: 1 | Interface Number: 0 | Number of endpoints: 6 | Descriptor Type: 5 | EP Address: 129 | Descriptor Type: 5 | EP Address: 132 | Descriptor Type: 5 | EP Address: 136 | Descriptor Type: 5 | EP Address: 1 | Descriptor Type: 5 | EP Address: 2 | Descriptor Type: 5 | EP Address: 134 |
```

#### Capture from HDMI video and S/PDIF audio with AC-3 codec
```
/usr/sbin/hauppauge2 -s E585-00-00AF4321 -a 1 -d 2 -o /tmp/test.ts
```

#### Capture from Component video and RCA AAC audio
```
/usr/sbin/hauppauge2 -s E505-00-00AF1234  -i 1 -a 0 -o /tmp/test.ts
```

#### Capture from Component video and RCA AAC audio, output to UDP Multicast
```
/usr/sbin/hauppauge2 -s E505-00-00AF1234  -i 1 -a 0 -o udp://224.0.0.1:5000
```

#### Use a configuration file
The configuration file is just a list of option=value statements which
mimics using the longform on the command line.  A `sample.conf` is included
which you can copy and modify.
```
cp sample.conf Colossus1.conf
nano Colossus1.conf
/usr/sbin/hauppauge2 -c Colossus1.conf
```
----
## Troubleshooting

After a fresh reboot, the Colossus2 will occasionally drop off the USB bus, the
first time it is used.  When hauppauge2 is run, the first thing it sends
out to the log is the Bus and Port of the device.  This is allows you to
reset the USB bus for that device to get it back.  For example, if the first
line in the log is:
```
2018-02-06 15:39:50.822985 C [main] hauppauge2.cpp:266 (main) - Initializing [Bus: 5, Port: 4] E585-00-FFFF4321
```
You can usually get the device back by doing:
```
export BUS=5
echo "0"    | sudo dd of="/sys/bus/usb/devices/usb${BUS}/power/autosuspend_delay_ms"
echo "auto" | sudo dd of="/sys/bus/usb/devices/usb${BUS}/power/control"
echo "on"   | sudo dd of="/sys/bus/usb/devices/usb${BUS}/power/control"
```
After that, the Colossus2 seems to work reliably until the next reboot.

### Review of issues

A user on the MythTV forum has posted a detailed review of possible issues:

https://forum.mythtv.org/viewtopic.php?f=2&t=2417&sid=91dea4e835b50e7564e37eda049773dd

At least some of these issues are dependent on the STB used.
