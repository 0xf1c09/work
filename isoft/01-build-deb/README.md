# 目录结构
```shell
.
├── pbuilder相关文件
│   ├── hooks
│   │   ├── A01export
│   │   ├── C10shell
│   │   ├── D05repo
│   │   ├── F01login
│   │   └── I01shell
│   ├── pbuilderrc
│   └── sw
│       ├── config
│       │   ├── config.guess
│       │   └── config.sub
│       ├── usr-lib-pbuilder
│       │   ├── pbuilder-checkparams
│       │   └── pbuilder-createbuildenv
│       └── usr-share-debootstrap-scripts
│           └── eagle
├── pools.json
├── README
└── 基于源码构建deb包说明文档.pdf
```

# 基于源码构建deb包说明文档.pdf
编译deb包的基础说明


# pbuilder相关文件
pbuilder使用过程中可能需要的文件

## hooks
一些pbuilder hooks脚本, 文件命名规则可通过 `man 5 pbuilderrc`查看, pbuilder样例在目录/usr/share/doc/pbuilder/examples/中

## pbuilderrc
pbuilder配置文件,

## sw
申威平台下需要修改的文件

### config
编译源码时，可能需要修改的针对sw_64架构的适配，一般用于替换源码内的两个文件

### usr-lib-pbuilder
申威平台中，需要替换pbuilder内的脚本，解决`pbuilder create`不成功的问题

### usr-share-debootstrap-scripts
申威平台中，生成base.tgz包时debootstrap的DISTRIBUTION，解决`pbuilder create`不成功的问题

# pools.json
编译包的仓库以及厂商提供的仓库
