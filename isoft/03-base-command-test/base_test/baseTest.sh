#!/bin/bash
commands=/usr/local/test/commands.txt
cache=/tmp/test/cache

notFoundCMD=()
noVersionCMD=()

_getType(){
	pkgType='none'
	if test ! -z `which $1`;then
		pkgType='cmd'
	elif test ! -z `type -t $1`;then
		pkgType='builtin'
	elif `dpkg -L $1 >/dev/null 2>&1`;then
		pkgType='package'	
	fi
	echo $pkgType
	return $?	
}

_getPackage(){
	pkgName='none'
	pkgPath=`which $1`
	realName=`readlink $pkgPath`
	if [ -n "$realName" ];then
		pkgName=$(_getPackage $realName)
	elif `dpkg -S $pkgPath >/dev/null 2>&1`;then
		pkgName=`dpkg -S $pkgPath |cut -d ':' -f 1`
	else
		pkgName=`echo $pkgPath|cut -c5-|xargs dpkg -S |cut -d ':' -f 1`
	fi
	echo $pkgName
	return $?	
}

_getVersion(){
	pkgVersion="none"
	echo $pkgVersion
	return $?
}

_start(){
	mkdir -p $cache
	_length=`cat $commands|wc -l`
	i=1
	while read line;do
		if [ -n $line ];then
			echo -ne "\rParsing command lists... $i/$_length"
			pkgType=$(_getType $line)	
			if [ $pkgType == 'cmd' ];then
				pkgName=$(_getPackage $line)
				#echo $line: $pkgName
				echo $line >> $cache/$pkgName
			elif [ $pkgType == 'builtin' ];then
				#echo "$line: a shell builtin"
				echo $line >> $cache/_builtin
			elif [ $pkgType == 'none' ];then
				#echo $line: $pkgType
				echo $line >> $cache/_none
			fi
			let i++
		fi
	done < $commands
	echo -e "\rParsing command lists...  Done"
}

_output(){
	for file in `ls $cache`;do
		if [[ $file != _* ]];then
			echo "Package: $file"
			echo "Version: `dpkg -l $file|tail -n 1|awk '{print $3}'`"
			echo "Package-List:"
			while read line;do
				echo " $line"
			done < $cache/$file
			echo 
		fi
	done 
	if test -f $cache/_builtin; then
		echo -e "\033[33m[Special cases]\033[0m"
		while read line;do
			echo "$line is a shell builtin"
		done < $cache/_builtin
		echo 
	fi
	if test -f $cache/_none; then
		echo -e "\033[31m[NOT FOUND]\033[0m"
		while read line;do
			echo "$line"
		done < $cache/_none
		echo 
	fi
	rm -rf $cache
}

_start
_output
