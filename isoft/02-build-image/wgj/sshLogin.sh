#!/bin/bash

# format user:host:password
ssh_host[0]="user:10.15.0.129:qwe123!@#:-----FT_Server_Kylin" 
ssh_host[1]="user:10.15.0.123:Qwe123!@#:-----FT_Server_UOS" 
ssh_host[2]="user:10.15.0.196:qwe123!@#:-----LX_Server_Kylin" 
ssh_host[3]="user:10.15.0.152:Qwe123!@#:-----LX_Server_UOS" 
ssh_host[4]="user:10.15.0.121:qwe123:--------FT_Desktop_Kylin"   
ssh_host[5]="user:10.15.0.114:qwe123:--------FT_Desktop_UOS" 
ssh_host[6]="user:10.15.0.186:qwe123:--------LX_Desktop_Kylin" 
ssh_host[7]="user:10.15.0.124:qwe123:--------LX_Desktop_UOS" 
ssh_host[8]="cetc15:10.15.0.120:123123:------X86_Kylin_server" 
ssh_host[9]="root:10.15.0.115:qwe123!@#:-----FT_Server_Kylin"
ssh_host[10]="user:10.15.0.190:Cetc@1234:----1115_Server_UOS"
ssh_host[11]="cetc:10.15.0.102:123456:-------SW_Desktop_UOS"
ssh_host[12]="cetc:10.15.0.165:123456:-------SW_Desktop_UOS"
ssh_host[13]="user:10.15.0.181:qwe123!@#:----SW_Server_Kylin"
ssh_host[14]="user:10.15.0.179:qwe123!@#:----SW_Server_UOS"
ssh_host[15]="user:10.15.0.131:qwe123:-------SW_Desktop_UOS"
ssh_host[16]="user:10.15.0.194:qwe123:-------SW_Desktop_UOS"
# 1. 打印可登录的服务器IP地址信息
echo "Now you can login following server:"
echo "*************************************************************"
num=0
while [ $num -lt ${#ssh_host[@]} ]
do
    sshMachine="${ssh_host[$num]}"
    sshMachine=(${sshMachine//:/ })
	echo "*	$num. | "  ${ssh_host[$num]} "" 
    let "num=num+1"
done
echo "*************************************************************"

# 2. 获取键盘输入，根据数值选择要登录的服务器名称
read -p "Enter a Number to LOGIN > " char

# 3. 根据服务器名称，登录对应的IP
sshMachine="${ssh_host["$char"]}"
sshMachine=(${sshMachine//:/ })
password="${sshMachine[2]}"
host="${sshMachine[1]}"
user="${sshMachine[0]}"
echo "Trying to Login ..."  $host
sshpass -p "$password" ssh  -q -o StrictHostKeyChecking=no ${user}@${host}
