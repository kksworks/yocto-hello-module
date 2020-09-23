# Copyright 2017,2018 ???
SUMMARY = "my-module"
LICENSE = "CLOSED"

BB_STRICT_CHECKSUM = "0"

inherit module

# SJA for kernel 4.14
#SRC_URI = "file://brcm-xgbe_${PV}.tar.gz"

SRC_URI = "file://* "
S = "${WORKDIR}/build-src"

RPROVIDES_${PN} += "my-module"

do_package_qa() {
	:
}
