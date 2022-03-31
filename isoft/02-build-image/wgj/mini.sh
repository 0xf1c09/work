#!/bin/bash

targetdir=/home/sugon/build/$1

mkdir -p $targetdir
debootstrap --no-check-gpg --variant=minbase buster $targetdir http://10.15.0.120:8085/mipsrepo

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
chroot $targetdir apt update
chroot $targetdir apt install -y vim net-tools iputils-ping binutils bzip2 procps gawk info less lzma makedev unzip zip tree xz-utils sysvinit-utils lsof
chroot $targetdir apt clean
chroot $targetdir find /var/log -type f -exec rm -rf '{}' ';'
chroot $targetdir iconvconfig
mkdir -p $targetdir/usr/local/test/
cp base_test/* $targetdir/usr/local/test/
chmod 777 $targetdir/usr/local/test/*
echo "alias ls='ls --color=auto'" >> $targetdir/root/.bashrc

tar --exclude-from tar-exclude -C $targetdir -c . | docker import - $1
mkdir -p /home/sugon/build/images/
docker save $1 -o /home/sugon/build/images/$1.tar
gzip -9 /home/sugon/build/images/$1.tar
