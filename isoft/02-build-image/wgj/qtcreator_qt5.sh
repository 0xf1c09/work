#!/bin/bash

targetdir=/home/sugon/build/$1

mkdir -p $targetdir
debootstrap --no-check-gpg --variant=minbase buster $targetdir http://10.15.0.120:8085/mipsrepo/


IFS=$'\n'; set -o noglob
slimExcludes=( $(grep -vE '^#|^$' "slimify-excludes" | sort -u) )
slimIncludes=( $(grep -vE '^#|^$' "slimify-includes" | sort -u) )
set +o noglob; unset IFS
findMatchIncludes=()
for slimInclude in "${slimIncludes[@]}"; do
	[ "${#findMatchIncludes[@]}" -eq 0 ] || findMatchIncludes+=( '-o' )
	findMatchIncludes+=( -path "$slimInclude" )
done
findMatchIncludes=( '(' "${findMatchIncludes[@]}" ')' )

for slimExclude in "${slimExcludes[@]}"; do
	chroot "$targetdir" find "$(dirname "$slimExclude")" \
		-depth -mindepth 1 \
		-not \( -type d -o -type l \) \
		-not "${findMatchIncludes[@]}" \
	-exec rm -f '{}' ';'

	while [ "$(chroot "$targetdir" \
				find "$(dirname "$slimExclude")" \
					-depth -mindepth 1 \( -empty -o -xtype l \) \
					-exec rm -rf '{}' ';' -printf '.' \
				| wc -c
		)" -gt 0 ]; do true; done
done

chroot $targetdir sh -c 'echo "deb [trusted=yes] http://10.15.0.120:8085/mipsrepo/ buster main" > /etc/apt/sources.list'
chroot $targetdir sh -c 'apt update'
chroot $targetdir apt install -y vim net-tools iputils-ping binutils bzip2 procps gawk info less lzma makedev unzip zip tree xz-utils sysvinit-utils lsof make g++ \
			qtcreator qt5-default fcitx-frontend-qt5 libqt5concurrent5  libqt5core5a libqt5dbus5 libqt5gui5 libqt5network5 libqt5opengl5 libqt5widgets5 libqt5xml5 \
			libqt5multimediawidgets5 qtmultimedia5-dev phonon libphonon4 libphonon-dev \
                        libavdevice-dev libavfilter-dev libavformat-dev libavcodec-dev libavutil-dev \
                        libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev gtk+-3.0 libcurl4-openssl-dev libc-ares-dev \
                        libsqlite3-dev protobuf-c-compiler protobuf-compiler libprotoc-dev libgmock-dev \
                        libboost-atomic-dev libboost-filesystem-dev libboost-system-dev libboost-program-options-dev gstreamer1.0-libav

cd rt_lib
. deal_libconfig.sh
cd ..
cp lib_installed.json $targetdir/etc

chroot $targetdir apt clean
chroot $targetdir find /var/log -type f -exec rm -rf '{}' ';'
chroot $targetdir iconvconfig

tar --exclude-from tar-exclude -C $targetdir -c . | docker import - $1

#mkdir -p /home/sugon/build/images/
#docker save $1 -o /home/sugon/build/images/$1.tar
#gzip -9 /home/sugon/build/images/$1.tar


