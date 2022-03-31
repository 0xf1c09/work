#!/bin/bash

targetdir=/home/user/build/$1

mkdir -p $targetdir
#debootstrap --no-check-gpg --variant=minbase buster $targetdir http://10.15.0.120:8085/basedeb/
debootstrap --no-check-gpg --variant=minbase bullseye $targetdir https://mirrors.tuna.tsinghua.edu.cn/debian


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

#chroot $targetdir sh -c 'echo "deb [trusted=yes] http://10.15.0.120:8085/basedeb/ buster main" > /etc/apt/sources.list'
chroot $targetdir sh -c 'echo "deb [trusted=yes] https://mirrors.tuna.tsinghua.edu.cn/debian bullseye main" > /etc/apt/sources.list'
chroot $targetdir sh -c 'apt update'
#chroot $targetdir sh -c 'apt install -y qt4* make g++'
#chroot $targetdir apt install -y make g++ qt4-qtconfig qt4-bin-dbg qt4-default qt4-demos qt4-demos-dbg qt4-designer qt4-dev-tools qt4-doc qt4-doc-html qt4-qmake qt4-qmlviewer qt4-linguist-tools
chroot $targetdir apt install -y vim net-tools iputils-ping binutils bzip2 procps gawk info less lzma makedev unzip zip tree xz-utils sysvinit-utils lsof make g++ \
                        qt4-qtconfig qt4-bin-dbg qt4-default qt4-designer qt4-dev-tools qt4-qmake qt4-qmlviewer qt4-linguist-tools fcitx-frontend-qt4 \
                        libqt5multimediawidgets5 qtmultimedia5-dev phonon libphonon4 libphonon-dev \
                        libavdevice-dev libavfilter-dev libavformat-dev libavcodec-dev libavutil-dev \
                        libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev gtk+-3.0 libcurl4-openssl-dev libc-ares-dev \
                        libsqlite3-dev protobuf-c-compiler protobuf-compiler libprotoc-dev libgmock-dev \
                        libboost-atomic-dev libboost-filesystem-dev libboost-system-dev libboost-program-options-dev

#libasio-dev libuv1-dev zlib1g-dev libxml2-dev libcjson-dev libjsoncpp-dev libpcre3-dev libevent-dev libwebsockets-dev libwebsocketpp-dev libcrypto++-dev libprotobuf-c-dev libthrift-dev libthrift-c-glib-dev libhttp-parser-dev sqlite3 liblog4cpp5-dev libiniparser-dev libtinyxml-dev  libfreeimage-dev libgstreamer1.0-dev ffmpeg libwxgtk3.0-dev valgrind gdb inotify-tools liblogservice-dev libthreadpool-dev libtransportengine-rpc-dev libidictionary-dev

cd rt_lib
. deal_libconfig.sh
cd ..
cp lib_installed.json $targetdir/etc

chroot $targetdir apt clean
chroot $targetdir find /var/log -type f -exec rm -rf '{}' ';'
chroot $targetdir iconvconfig

tar --exclude-from tar-exclude -C $targetdir -c . | docker import - $1
#mkdir -p /home/user/build/images/
#docker save $1 -o /home/user/build/images/$1.tar
#gzip -9 /home/user/build/images/$1.tar


