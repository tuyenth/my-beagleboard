## Para Beagle Board ##
http://www.eewiki.net/display/linuxonarm/BeagleBoard

## Apply Patch ##
https://github.com/Teknoman117/beaglebot/tree/master/encoders/patches

## Para Beagle Bone ##
http://eewiki.net/display/linuxonarm/BeagleBone

https://www.youtube.com/watch?v=HJ9nUqYMjqs

```
mkdir ~/beaglebone
```

### Get Kernel ###
```
cd ~/beaglebone
git clone git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git
```

### Get Build Tool ###
```
cd ~/beaglebone
git clone git://github.com/RobertCNelson/linux-dev.git
cd linux-dev
git checkout origin/am33x-v3.2 -b am33x-v3.2
cp system.sh.sample system.sh
nano system.sh
//define toolchain
//define linux-stable location
//uncomment omap mem line
```

## Para Beagle Bone Black ##
http://eewiki.net/display/linuxonarm/BeagleBone+Black