#!/bin/bash

file="install_lib.config"

cat $file |
while read line
do
        if [ "$line" =  "" ];then
                continue
        else
                case $line in
                asio)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libasio-dev
                ;;
                libuv)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libuv1-dev
                ;;
                zlib)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y zlib1g-dev
                ;;
                libxml2)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libxml2-dev
                ;;
                cjson)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libcjson-dev
                ;;
                jsoncpp)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libjsoncpp-dev
                ;;
                pcre)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libpcre3-dev
                ;;
                libevent)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libevent-dev
                ;;
                grpc)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libgrpc-dev libgrpc++-dev
                ;;
                curl)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y curl
                ;;
                websocket)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libwebsockets-dev libwebsocketpp-dev
                ;;
                crypto)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libcrypto++-dev
                ;;
                boost)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libboost-all-dev
                ;;
                protobuf)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libprotobuf-dev libprotobuf-c-dev
                ;;
                thrift)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libthrift-dev libthrift-c-glib-dev
                ;;
                http-parser)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libhttp-parser-dev
                ;;
                sqlite)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y sqlite3
                ;;
                log4cpp)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y liblog4cpp5-dev 
                ;;
                iniparser)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libiniparser-dev 
                ;;
                tinyxml)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libtinyxml-dev
                ;;
                freeimage)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libfreeimage-dev
                ;;
                gstreamer)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libgstreamer1.0-dev
                ;;
                ffmpeg)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y ffmpeg
                ;;
                wxwidgets)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libwxgtk3.0-dev
                ;;
                valgrind)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y valgrind
                ;;
                gdb)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y gdb
                ;;
                inotify)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y inotify-tools 
                ;;
                boost.filesystem)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libboost1.67-dev
                ;;
                idictionary)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libidictionary-dev
                ;;
                logservice)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y liblogservice-dev
                ;;
                threadpool)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libthreadpool-dev
                ;;
                transportengine-rpc)
                    echo -e "\e[1;34m install $line !\e[0m"
                    chroot $targetdir apt install -y libtransportengine-rpc-dev
                ;;

                *) echo -e "\e[1;30m unkown lib name $line !\e[0m";;
                esac
        fi
done

